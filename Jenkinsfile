pipeline {
  agent {
        docker { 
          image 'test5' 
          }
    }
  stages {
    stage('docker-build') {
        parallel {
          stage('MSBuild1') {
            steps {
              bat "msbuild"
            }
          }

          stage('MSBuild2') {
            steps {
              bat 'msbuild'
            }
          }

          stage('MSBuild3') {
            steps {
              bat 'msbuild'
            }
          }

      }
    }
  }

}

