pipeline {
  agent any
  stages {
    stage('docker-build') {
        parallel {
          stage('MSBuild1') {
            agent {
              docker { 
                image 'test5' 
                reuseNode 'true'
                }
            }
            steps {
              bat "msbuild"
            }
          }

          stage('MSBuild2') {
            agent {
            docker { 
              image 'test5' 
              reuseNode 'true'
              }
          }
            steps {
              bat 'msbuild'
            }
          }



      }
    }
  }

}

