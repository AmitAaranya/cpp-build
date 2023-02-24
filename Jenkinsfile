pipeline {
  agent any
  stages {
    stage('github-pull') {
      steps {
        git(branch: 'main', credentialsId: 'a3e14212-7f76-4abe-98bd-3d0af0423756', url: 'https://github.com/AmitAaranya/CPP.git')
      }
    }

    stage('Build Stage') {
      parallel {
        stage('MSBuild-1') {
          steps {
            bat "docker run --rm -v ${WORKSPACE}:C:\\app msbuild msbuild c:\\app\\Demowix\\Demowix.vcxproj"
          }
        }

        stage('MSBuild-2') {
          steps {
            bat 'docker run msbuild'
          }
        }

        stage('MSBuild-3') {
          steps {
            sleep 5
          }
        }

        stage('MSBuild-4') {
          steps {
            echo 'Build for forth Independent Parts'
          }
        }

        stage('MSBuild-5') {
          steps {
            echo 'Build for Fifth Independent Parts'
          }
        }

        stage('MSBuild-6') {
          steps {
            echo 'Build for Sixth Independent Parts'
          }
        }

        stage('MSBuild-7') {
          steps {
            echo 'Seventh Stage'
          }
        }

        stage('MSBuild-8') {
          steps {
            echo '8th Build'
          }
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
