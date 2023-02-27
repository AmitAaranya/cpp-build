pipeline {
  agent any
  stages {
    stage('github-pull') {
      parallel {
        stage('toolkit-1') {
          steps {
            git(branch: 'parallel-Build', credentialsId: 'a3e14212-7f76-4abe-98bd-3d0af0423756', url: 'https://github.com/AmitAaranya/CPP.git')
          }
        }

        stage('toolkit-2') {
          steps {
            echo 'pull'
          }
        }

        stage('toolkit-3') {
          steps {
            sleep 2
          }
        }

      }
    }

    stage('Build Stage') {
      parallel {
        stage('toolkit-1') {
          steps {
            bat "docker run --rm -v ${WORKSPACE}:C:\\app msbuildtool msbuild c:\\app\\Demowix\\Demowix.vcxproj"
          }
        }

        stage('toolkit-1-2') {
          steps {
            bat 'docker run --rm msbuildtool'
          }
        }

        stage('toolkit-1-3') {
          steps {
            sleep 5
          }
        }

        stage('toolkit-1-4') {
          steps {
            echo 'Build for forth Independent Parts'
          }
        }

        stage('toolkit-1-5') {
          steps {
            echo 'Build for Fifth Independent Parts'
          }
        }

        stage('toolkit-1-6') {
          steps {
            echo 'Build for Sixth Independent Parts'
          }
        }

        stage('toolkit-1-7') {
          steps {
            echo 'Seventh Stage'
          }
        }

        stage('toolkit-1-8') {
          steps {
            echo '8th Build'
          }
        }

      }
    }

  }
}