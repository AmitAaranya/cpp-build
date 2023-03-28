pipeline {
  agent {
        docker { image 'test3' }
    }
  stages {
    stage('github') {
      steps {
        git(branch: 'docker-agent', credentialsId: 'a3e14212-7f76-4abe-98bd-3d0af0423756', url: 'https://github.com/AmitAaranya/CPP.git')
      }
    }
  }
  
  stages {
    stage('docker-build') {
      steps {
        bat "mabuild --version"
      }
    }
  }
  

  }
