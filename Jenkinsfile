pipeline {
  agent any
  stages {
    stage('github-pull') {
      parallel {
        stage('toolkit-1') {
          steps {
            git(branch: 'main', credentialsId: 'a3e14212-7f76-4abe-98bd-3d0af0423756', url: 'https://github.com/AmitAaranya/CPP.git')
          }
        }
      }
    }

    stage('Build Stage') {
      parallel {
        stage('toolkit-1') {
          steps {
            bat "docker run --rm -v ${WORKSPACE}\\${STAGE_NAME}:C:\\app msbuildtool msbuild c:\\app\\Demowix\\Demowix.vcxproj /property:Configuration=Release /property:Platform=x64"
          }
        }

        stage('toolkit-2') {
          steps {
            bat "docker run --rm -v ${WORKSPACE}\\${STAGE_NAME}:C:\\app msbuildtool msbuild c:\\app\\Demowix\\Demowix.vcxproj /property:Configuration=Release /property:Platform=x64"
          }
        }

        stage('toolkit-3') {
          steps {
            bat "docker run --rm -v ${WORKSPACE}\\${STAGE_NAME}:C:\\app msbuildtool msbuild c:\\app\\Demowix\\Demowix.vcxproj /property:Configuration=Release /property:Platform=x64"
          }
        }

        stage('toolkit-4') {
          steps {
            bat "docker run --rm -v ${WORKSPACE}\\${STAGE_NAME}:C:\\app msbuildtool msbuild c:\\app\\Demowix\\Demowix.vcxproj /property:Configuration=Release /property:Platform=x64"
          }
        }

        stage('toolkit-5') {
          steps {
            bat "docker run --rm -v ${WORKSPACE}\\${STAGE_NAME}:C:\\app msbuildtool msbuild c:\\app\\Demowix\\Demowix.vcxproj /property:Configuration=Release /property:Platform=x64"
          }
        }

        stage('toolkit-6') {
          steps {
            bat "docker run --rm -v ${WORKSPACE}\\${STAGE_NAME}:C:\\app msbuildtool msbuild c:\\app\\Demowix\\Demowix.vcxproj /property:Configuration=Release /property:Platform=x64"
          }
        }

        stage('toolkit-7') {
          steps {
            bat "docker run --rm -v ${WORKSPACE}\\${STAGE_NAME}:C:\\app msbuildtool msbuild c:\\app\\SimpleRnD\\SimpleRnD.vcxproj /property:Configuration=Release /property:Platform=x64"
          }
        }

        stage('toolkit-8') {
          steps {
            bat "docker run --rm -v ${WORKSPACE}\\${STAGE_NAME}:C:\\app msbuildtool msbuild c:\\app\\SimpleRnD\\SimpleRnD.vcxproj /property:Configuration=Release /property:Platform=x64"
          }
        }

      }
    }

  }
}