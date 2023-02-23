pipeline {
  agent any
  stages {
    stage('github') {
      steps {
        git(branch: 'main', credentialsId: 'a3e14212-7f76-4abe-98bd-3d0af0423756', url: 'https://github.com/AmitAaranya/CPP.git')
      }
    }

    stage('GIT-pull-wxi') {
      steps {
        dir(path: "${env.WORKSPACE}/wixMSI/bin") {
          bat 'git init'
          bat "git remote add origin${BUILD_NUMBER} https://github.com/AmitAaranya/CPP-Output.git"
        }

      }
    }

    stage('MSBuild') {
      parallel {
        stage('MSBuild') {
          steps {
            bat "docker run -v ${WORKSPACE}:C:\\app buildtool1 msbuild c:\\app\\Demowix\\Demowix.vcxproj"
          }
        }

        stage('') {
          steps {
            bat 'docker run msbuild'
          }
        }

      }
    }

    stage('WixBuild') {
      steps {
        bat "docker run -v ${WORKSPACE}:C:\\app demowixc wix build -o C:\\app\\wixMSI\\bin\\Release\\Demowix${BUILD_NUMBER}.msi C:\\app\\wixMSI\\Product.wxs"
      }
    }

    stage('GIT-push') {
      steps {
        bat 'git config --global user.email "amitaaranya@gmail.com"'
        bat 'git config --global user.name "Amit Aaranya"'
        dir(path: "${env.WORKSPACE}/wixMSI/bin") {
          bat "git pull origin${BUILD_NUMBER} master"
          bat 'git add .'
          bat 'git commit -m "New MSI build push"'
          bat "git push --set-upstream origin${BUILD_NUMBER} master"
          bat "git remote rm origin${BUILD_NUMBER}"
        }

      }
    }

  }
  post {
    always {
      echo 'Clearing the workspace'
      deleteDir()
      dir("${workspace}@tmp") {
        deleteDir()
      }

    }

  }
}