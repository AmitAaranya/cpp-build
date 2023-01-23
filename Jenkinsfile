pipeline {
  agent any
  stages {
    stage('github') {
      steps {
        git(url: 'https://github.com/AmitAaranya/CPP.git', branch: 'main')
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
    stage('GIT-push') {
      steps {
          bat 'whoami'
          bat 'git config --global user.email "amitaaranya@gmail.com"'
            bat 'git config --global user.name "Amit Aaranya"'
            bat "git add ."
            bat 'git commit -m "New MSI build push"'
            // bat 'git remote add new1  https://github.com/AmitAaranya/CPP'
            bat "git push -u origin main"
      }
    }
  }
}


