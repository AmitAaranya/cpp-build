pipeline {
  agent {
      docker { 
        image 'test5' 
        reuseNode 'true'
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



      }
    }
  }

}

