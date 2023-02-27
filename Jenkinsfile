pipeline {
  agent any
  parallel {
  stages {
    stage('github-pull') {
      
        stage('toolkit-1') {
          steps {
            git(branch: 'main', credentialsId: 'a3e14212-7f76-4abe-98bd-3d0af0423756', url: 'https://github.com/AmitAaranya/CPP.git')
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
    stages {
    stage('github-pull-2') {
      
        stage('toolkit-1') {
          steps {
            git(branch: 'main', credentialsId: 'a3e14212-7f76-4abe-98bd-3d0af0423756', url: 'https://github.com/AmitAaranya/CPP.git')
          }
        }

        stage('toolkit-22') {
          steps {
            echo 'pull'
          }
        }

        stage('toolkit-32') {
          steps {
            sleep 2
          }
        }

      }
    }
  }
}
