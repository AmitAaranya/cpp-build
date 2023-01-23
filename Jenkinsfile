pipeline {
  agent any
  stages {
    stage('github') {
      steps {
        git branch: 'main', credentialsId: 'a3e14212-7f76-4abe-98bd-3d0af0423756', url: 'https://github.com/AmitAaranya/CPP.git'
      }
    }
    
    stage("New pull") {
        steps {
            bat "dir"
            dir("${env.WORKSPACE}/wixMSI") {
            bat 'git init'
            bat 'git remote rm origin'
            bat 'git remote add origin https://github.com/AmitAaranya/CPP-Output.git'
            bat 'git pull origin main'
            }
            bat "dir"
        } 
        
    }
    stage("MSBuild") {
        steps{
            bat 'docker run -v C:\\Users\\amit\\.jenkins\\workspace\\cpp-pipeline-2\\:C:\\app buildtool1 msbuild c:\\app\\Demowix\\Demowix.vcxproj'
        }
        
    }
    stage("WixBuild") {
        steps{
            bat "docker run -v C:\\Users\\amit\\.jenkins\\workspace\\cpp-pipeline-2\\:C:\\app demowixc wix build -o C:\\app\\wixMSI\\bin\\Release\\Demowix${BUILD_NUMBER}.msi C:\\app\\wixMSI\\Product.wxs"
        }
        
    }
    stage('GIT-push') {
      steps {
          bat 'git config --global user.email "amitaaranya@gmail.com"'
            bat 'git config --global user.name "Amit Aaranya"'
            
            // bat 'git remote add origin https://github.com/AmitAaranya/CPP-Output.git'
            // bat "git add ."
            // bat 'git commit -m "New MSI build push"'
            // bat 'git remote add new1  https://github.com/AmitAaranya/CPP'
            // bat "git push -u origin main" 
            dir("${env.WORKSPACE}/wixMSI") {
                bat "git add ."
                bat 'git commit -m "New MSI build push"'
                bat "git push --set-upstream origin master"
            }
      }
    }
  }
}
