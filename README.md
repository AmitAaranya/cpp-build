# Export the MSI file form C++ Project 


## &rarr; Visual Studio:

We need to install the following extension inside the visual studio, which produce the wix-project file
1. Wix v3 Extension installation <br> <br>
    <img src="wix.png" width="512"/>

2. Heat Wave Extension <br> <br>
    <img src="heatWave.png" width="512"/>

To work the extension, we need to have the Wix v3 install in the windows machine.

### &rarr; Steps required to get a wix-project file (v4) though Visual Studio
1. Add new project to existing project (Wix v3 Setup Project)
2. Build the setup-project
3. Edit the wix3 project file (Include whatever required in MSI file)
4. Convert wix v3 project to v4

## &rarr; Wix toolset project file (Product.wxs)
This xml based file defines the parameters related to MSI file
```xml
<Wix xmlns="http://wixtoolset.org/schemas/v4/wxs">
	<Package Name="wixMSI" Language="1033" Version="1.0.0.0" Manufacturer="AMIT" UpgradeCode="a37ba082-572e-4b37-86e5-e39bf77ffb86" InstallerVersion="200">
		<MajorUpgrade DowngradeErrorMessage="A newer version of [ProductName] is already installed." />
		<Feature Id="ProductFeature" Title="wixMSI" Level="1">
			<ComponentGroupRef Id="ProductComponents" />
		</Feature>
	</Package>
	<Fragment>
			<StandardDirectory Id="ProgramFilesFolder">
				<Directory Id="INSTALLFOLDER" Name="wixMSI" />
			</StandardDirectory>
		</Fragment>
	<Fragment>
		<ComponentGroup Id="ProductComponents" Directory="INSTALLFOLDER">
			<!-- TODO: Remove the comments around this Component element and the ComponentRef below in order to add resources to this installer. -->
			<!-- <Component Id="ProductComponent"> -->
				<!-- TODO: Insert files, registry keys, and other resources here. -->
			<!-- </Component> -->
			<Component Id="DemoWixexe">
				<File Id="wixdemoexe" Name="DemoWix.exe" Source="C:\app\Demowix\Debug\"></File>
			</Component>
		</ComponentGroup>
	</Fragment>
</Wix>
```
## &rarr; Installing the wix v4 tool inside windows container
```docker
# escape=`

# Use the latest Windows Server Core 2022 image.
FROM mcr.microsoft.com/windows/servercore:ltsc2022

SHELL ["PowerShell"]

COPY .\dotnet\ C:\dotnet\
RUN Move-Item -Path C:\dotnet -Destination 'C:\Program Files\dotnet\'

RUN setx path '%path%;C:\Program Files\dotnet'

RUN dotnet tool install --global wix --version 4.0.0-rc.1

RUN setx path '%path%;C:\Users\ContainerAdministrator\.dotnet\tools\'

```


## &rarr; Installing the MSbuild tool (Preview) inside windows container

```docker
# escape=`

# Use the latest Windows Server Core 2022 image.
FROM mcr.microsoft.com/windows/servercore:ltsc2022
# FROM mcr.microsoft.com/windows:ltsc2019

# Restore the default Windows shell for correct batch processing.
SHELL ["cmd", "/S", "/C"]

COPY . C:/

RUN `
    # Download the Build Tools bootstrapper.
    curl -SL --output vs_buildtools2.exe https://aka.ms/vs/17/release/vs_buildtools.exe `
    `
    # Install Build Tools with the Microsoft.VisualStudio.Workload.AzureBuildTools workload, excluding workloads and components with known issues.
    && (start /w vs_buildtools.exe --quiet --wait --norestart --nocache `
        --installPath "%ProgramFiles(x86)%\Microsoft Visual Studio\2022\BuildTools" `
        --add Microsoft.VisualStudio.Workload.AzureBuildTools `
        --add Microsoft.VisualStudio.Workload.NativeDesktop`
        --add Microsoft.VisualStudio.Workload.VCTools --includeRecommended`
        --add Microsoft.VisualStudio.Component.VC.ATL`
        || IF "%ERRORLEVEL%"=="3010" EXIT 0) `
    `
    # Cleanup
    && del /q vs_buildtools.exe

# Define the entry point for the docker container.
# This entry point starts the developer command prompt and launches the PowerShell shell.
ENTRYPOINT ["C:\\Program Files (x86)\\Microsoft Visual Studio\\2022\\BuildTools\\Common7\\Tools\\VsDevCmd.bat", "&&", "powershell.exe", "-NoLogo", "-ExecutionPolicy", "Bypass"]

```

## &rarr; Command associated with Wix-toolset and msbuild

1. For Wix ToolSet

```powershell

wix build -o C:\\app\\wixMSI\\bin\\Release\\Demowix${BUILD_NUMBER}.msi C:\\app\\wixMSI\\Product.wxs

// wix build -o {output file name and location} {wix source file location}

```
2. For MS build Toolset

```powershell
msbuild c:\\app\\Demowix\\Demowix.vcxproj

// msbuild {msbuild project file location}
```
## &rarr; Installing Jenkins
1. Download **war** file from official download page
2. Install the java sdk package based on requirement (java 17)
3. use following command to direcly run jenkins

```powershell
java -jar ./jenkins.war
```
## &rarr; GitHub connection with jenkins

1. Generate the personal Access Token [Settings Developer settings Personal access tokens]
```htm
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
```
2. Add this as **Secret Text** inside the Jenkins Credentials Provider
3. Go to **Dashboard/Manage Jenkins/Configure System** add a GitHub Server and test the connection


## &rarr; Githubs hooks integration with jenkins

1. go to github repository **settings/webhooks**, add a webhooks
2. Enter the jenkins url : **http://[public-ip]:8080/github-webhook/**
3. make sure jenkins accessible at http://[public-ip]:8080/


## &rarr; jenkinsfile

```dockerfile
pipeline {
  agent any
  stages {
    stage('github') {
      steps {
        git branch: 'main', credentialsId: 'a3e14212-7f76-4abe-98bd-3d0af0423756', url: 'https://github.com/AmitAaranya/CPP.git'
      }
    }
    stage('GIT-init-out') {
      steps {
            dir("${env.WORKSPACE}/wixMSI/bin") {
                bat 'git init'
                bat "git remote add origin${BUILD_NUMBER} https://github.com/AmitAaranya/CPP-Output.git"
            }
      }
    }
    stage("MSBuild") {
        steps{
            bat "docker run -v ${WORKSPACE}:C:\\app buildtool1 msbuild c:\\app\\Demowix\\Demowix.vcxproj"
        }
        
    }
    stage("WixBuild") {
        steps{
            bat "docker run -v ${WORKSPACE}:C:\\app demowixc wix build -o C:\\app\\wixMSI\\bin\\Release\\Demowix${BUILD_NUMBER}.msi C:\\app\\wixMSI\\Product.wxs"
        }
        
    }
    stage('Save-output') {
      steps {
          bat "move ${WORKSPACE}\\wixMSI\\bin\\Release\\Demowix${BUILD_NUMBER}.msi*.* C:\\Users\\amit\\Desktop\\CPP-OUTPUT\\"
            
      }
    }
}
post {
        always {
            echo "Clearing the workspace"
            deleteDir()
            dir("${workspace}@tmp") {
                deleteDir()
            }
        }
  }
}
```

### 1. Stage (github-pull): 
- It will pull the C++ application repository (github)

### 2. Stage (GIT-init-wxi): 
- It will initiate the git inside the output folder of WixBuild
- To push the output to different repo

### 3. Stage (MSBuild): 
- Build C++ Application
- Gives the EXE installer 

### 4. Stage (WixBuild): 
- package C++ Application to MSI
- Gives the MSI installer named **Demowix${BUILD_NUMBER}.msi**

### 5. Stage (Save-output): 
- It will save the MSI file into **C:\Users\amit\Desktop\CPP-OUTPUT**

### 6. Stage (post): 
- It remove the working space of jenkins

