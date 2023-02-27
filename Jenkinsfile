pipeline {
  agent any
  stages {
    stage('github-pull') {
      parallel {
        stage('Source-code') {
          steps {
            git(branch: 'parallelBuild', credentialsId: 'a3e14212-7f76-4abe-98bd-3d0af0423756', url: 'https://github.com/AmitAaranya/CPP.git')
          }
        }

        stage('Creating Output Folder') {
          steps {
            bat "mkdir C:\\output\\${BUILD_NUMBER}"
          }
        }
      }
    }

    stage('Build Stage') {
      parallel {
        stage('toolkit-1') {
          steps {
            bat "docker run --rm -v ${WORKSPACE}\\${STAGE_NAME}:C:\\app msbuildtool msbuild c:\\app\\Demowix\\Demowix.vcxproj /property:Configuration=Release /property:Platform=x64"
            bat "mkdir C:\\output\\${BUILD_NUMBER}\\${STAGE_NAME}"
            bat "move ${WORKSPACE}\\${STAGE_NAME}\\DemoWix\\x64\\Release\\*.* C:\\output\\${BUILD_NUMBER}\\${STAGE_NAME}"
          }
        }

        stage('toolkit-2') {
          steps {
            bat "docker run --rm -v ${WORKSPACE}\\${STAGE_NAME}:C:\\app msbuildtool msbuild c:\\app\\Demowix\\Demowix.vcxproj /property:Configuration=Release /property:Platform=x64"
            bat "mkdir C:\\output\\${BUILD_NUMBER}\\${STAGE_NAME}"
            bat "move ${WORKSPACE}\\${STAGE_NAME}\\DemoWix\\x64\\Release\\*.* C:\\output\\${BUILD_NUMBER}\\${STAGE_NAME}"
          }
        }

        stage('toolkit-3') {
          steps {
            bat "docker run --rm -v ${WORKSPACE}\\${STAGE_NAME}:C:\\app msbuildtool msbuild c:\\app\\Demowix\\Demowix.vcxproj /property:Configuration=Release /property:Platform=x64"
            bat "mkdir C:\\output\\${BUILD_NUMBER}\\${STAGE_NAME}"
            bat "move ${WORKSPACE}\\${STAGE_NAME}\\DemoWix\\x64\\Release\\*.* C:\\output\\${BUILD_NUMBER}\\${STAGE_NAME}"
          }
        }

        stage('toolkit-4') {
          steps {
            bat "docker run --rm -v ${WORKSPACE}\\${STAGE_NAME}:C:\\app msbuildtool msbuild c:\\app\\Demowix\\Demowix.vcxproj /property:Configuration=Release /property:Platform=x64"
            bat "mkdir C:\\output\\${BUILD_NUMBER}\\${STAGE_NAME}"
            bat "move ${WORKSPACE}\\${STAGE_NAME}\\DemoWix\\x64\\Release\\*.* C:\\output\\${BUILD_NUMBER}\\${STAGE_NAME}"
          }
        }

        stage('toolkit-5') {
          steps {
            bat "docker run --rm -v ${WORKSPACE}\\${STAGE_NAME}:C:\\app msbuildtool msbuild c:\\app\\Demowix\\Demowix.vcxproj /property:Configuration=Release /property:Platform=x64"
            bat "mkdir C:\\output\\${BUILD_NUMBER}\\${STAGE_NAME}"
            bat "move ${WORKSPACE}\\${STAGE_NAME}\\DemoWix\\x64\\Release\\*.* C:\\output\\${BUILD_NUMBER}\\${STAGE_NAME}"
          }
        }

        stage('toolkit-6') {
          steps {
            bat "docker run --rm -v ${WORKSPACE}\\${STAGE_NAME}:C:\\app msbuildtool msbuild c:\\app\\Demowix\\Demowix.vcxproj /property:Configuration=Release /property:Platform=x64"
            bat "mkdir C:\\output\\${BUILD_NUMBER}\\${STAGE_NAME}"
            bat "move ${WORKSPACE}\\${STAGE_NAME}\\DemoWix\\x64\\Release\\*.* C:\\output\\${BUILD_NUMBER}\\${STAGE_NAME}"
          }
        }

        stage('toolkit-7') {
          steps {
            bat "docker run --rm -v ${WORKSPACE}\\${STAGE_NAME}:C:\\app msbuildtool msbuild c:\\app\\SimpleRnD\\SimpleRnD.vcxproj /property:Configuration=Release /property:Platform=x64"
            bat "mkdir C:\\output\\${BUILD_NUMBER}\\${STAGE_NAME}"
            bat "move ${WORKSPACE}\\${STAGE_NAME}\\SimpleRnD\\x64\\Release\\*.* C:\\output\\${BUILD_NUMBER}\\${STAGE_NAME}"
          }
        }

        stage('toolkit-8') {
          steps {
            bat "docker run --rm -v ${WORKSPACE}\\${STAGE_NAME}:C:\\app msbuildtool msbuild c:\\app\\SimpleRnD\\SimpleRnD.vcxproj /property:Configuration=Release /property:Platform=x64"
            bat "mkdir C:\\output\\${BUILD_NUMBER}\\${STAGE_NAME}"
            bat "move ${WORKSPACE}\\${STAGE_NAME}\\SimpleRnD\\x64\\Release\\*.* C:\\output\\${BUILD_NUMBER}\\${STAGE_NAME}"
          }
        }

      }
    }

  }

  post {
        always {
            echo "Clearing the workspace"
            deleteDir()
            dir("${workspace}@tmp") {
                deleteDir()
            }
        }
  }
}
