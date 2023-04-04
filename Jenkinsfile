pipeline {
    agent any
    stages {
        stage('github-pull') {
            parallel {
                stage('Source-code') {
                    steps {
                        git(branch: 'same-proj', url: 'https://github.com/AmitAaranya/CPP.git')
                    }
                }

                stage('Creating Output Folder') {
                    steps {
                        bat "mkdir C:\\output\\${BUILD_NUMBER}_${BUILD_TIMESTAMP}"
                    }
                }
            }
        }

        stage('Build Stage') {
            parallel {
                stage('toolkit-1') {
                    agent {
                        docker { 
                            image 'test1' 
                            reuseNode 'true' 
                            args "-v ${WORKSPACE}\\${STAGE_NAME}:C:\\app"
                        }
                    }
                    steps {
                        bat "msbuild c:\\app\\TeradyneDemo.sln /property:Configuration=Release /property:Platform=x64 /m"
                    }
                }

                stage('toolkit-2') {
                    agent {
                        docker { 
                            image 'test1' 
                            reuseNode 'true' 
                            args "-v ${WORKSPACE}\\${STAGE_NAME}:C:\\app"
                        }
                    }
                    steps {
                        bat "msbuild c:\\app\\TeradyneDemo.sln /property:Configuration=Release /property:Platform=x64 /m"
                    }
                }

                stage('toolkit-3') {
                    agent {
                        docker { 
                            image 'test1' 
                            reuseNode 'true' 
                            args "-v ${WORKSPACE}\\${STAGE_NAME}:C:\\app"
                        }
                    }
                    steps {
                        bat "msbuild c:\\app\\TeradyneDemo.sln /property:Configuration=Release /property:Platform=x64 /m"
                    }
                }

                stage('toolkit-4') {
                    agent {
                        docker { 
                            image 'test1' 
                            reuseNode 'true' 
                            args "-v ${WORKSPACE}\\${STAGE_NAME}:C:\\app"
                        }
                    }
                    steps {
                        bat "msbuild c:\\app\\TeradyneDemo.sln /property:Configuration=Release /property:Platform=x64 /m"
                    }
                }

                stage('toolkit-5') {
                    agent {
                        docker { 
                            image 'test1' 
                            reuseNode 'true' 
                            args "-v ${WORKSPACE}\\${STAGE_NAME}:C:\\app"
                        }
                    }
                    
                    steps {
                        bat "msbuild c:\\app\\TeradyneDemo.sln /property:Configuration=Release /property:Platform=x64 /m"
                    }
                }

                stage('toolkit-6') {
                    agent {
                        docker { 
                            image 'test1' 
                            reuseNode 'true' 
                            args "-v ${WORKSPACE}\\${STAGE_NAME}:C:\\app"
                        }
                    }
                    steps {
                        bat "msbuild c:\\app\\TeradyneDemo.sln /property:Configuration=Release /property:Platform=x64 /m"
                    }
                }

                stage('toolkit-7') {
                    agent {
                        docker { 
                            image 'test1' 
                            reuseNode 'true' 
                            args "-v ${WORKSPACE}\\${STAGE_NAME}:C:\\app"
                        }
                    }
                    steps {
                        bat "msbuild c:\\app\\TeradyneDemo.sln /property:Configuration=Release /property:Platform=x64 /m"
                    }
                }

                stage('toolkit-8') {
                    agent {
                        docker { 
                            image 'test1' 
                            reuseNode 'true' 
                            args "-v ${WORKSPACE}\\${STAGE_NAME}:C:\\app"
                        }
                    }
                    steps {
                        bat "msbuild c:\\app\\TeradyneDemo.sln /property:Configuration=Release /property:Platform=x64 /m"
                    }
                }

            }
        }

        stage('Output File Transfer') {
            parallel {
                stage('toolkit-1') {
                    steps {
                        bat "mkdir C:\\output\\${BUILD_NUMBER}_${BUILD_TIMESTAMP}\\${STAGE_NAME}"
                        bat "move ${WORKSPACE}\\${STAGE_NAME}\\x64\\Release\\*.* C:\\output\\${BUILD_NUMBER}_${BUILD_TIMESTAMP}\\${STAGE_NAME}"
                    }
                }

                stage('toolkit-2') {
                    steps {
                        bat "mkdir C:\\output\\${BUILD_NUMBER}_${BUILD_TIMESTAMP}\\${STAGE_NAME}"
                        bat "move ${WORKSPACE}\\${STAGE_NAME}\\x64\\Release\\*.* C:\\output\\${BUILD_NUMBER}_${BUILD_TIMESTAMP}\\${STAGE_NAME}"
                    }
                }

                stage('toolkit-3') {
                    steps {
                        bat "mkdir C:\\output\\${BUILD_NUMBER}_${BUILD_TIMESTAMP}\\${STAGE_NAME}"
                        bat "move ${WORKSPACE}\\${STAGE_NAME}\\x64\\Release\\*.* C:\\output\\${BUILD_NUMBER}_${BUILD_TIMESTAMP}\\${STAGE_NAME}"
                    }
                }

                stage('toolkit-4') {
                    steps {
                        bat "mkdir C:\\output\\${BUILD_NUMBER}_${BUILD_TIMESTAMP}\\${STAGE_NAME}"
                        bat "move ${WORKSPACE}\\${STAGE_NAME}\\x64\\Release\\*.* C:\\output\\${BUILD_NUMBER}_${BUILD_TIMESTAMP}\\${STAGE_NAME}"
                    }
                }

                stage('toolkit-5') {
                    steps {
                        bat "mkdir C:\\output\\${BUILD_NUMBER}_${BUILD_TIMESTAMP}\\${STAGE_NAME}"
                        bat "move ${WORKSPACE}\\${STAGE_NAME}\\x64\\Release\\*.* C:\\output\\${BUILD_NUMBER}_${BUILD_TIMESTAMP}\\${STAGE_NAME}"
                    }
                }

                stage('toolkit-6') {
                    steps {
                        bat "mkdir C:\\output\\${BUILD_NUMBER}_${BUILD_TIMESTAMP}\\${STAGE_NAME}"
                        bat "move ${WORKSPACE}\\${STAGE_NAME}\\x64\\Release\\*.* C:\\output\\${BUILD_NUMBER}_${BUILD_TIMESTAMP}\\${STAGE_NAME}"
                    }
                }

                stage('toolkit-7') {
                    steps {
                        bat "mkdir C:\\output\\${BUILD_NUMBER}_${BUILD_TIMESTAMP}\\${STAGE_NAME}"
                        bat "move ${WORKSPACE}\\${STAGE_NAME}\\x64\\Release\\*.* C:\\output\\${BUILD_NUMBER}_${BUILD_TIMESTAMP}\\${STAGE_NAME}"
                    }
                }

                stage('toolkit-8') {
                    steps {
                        bat "mkdir C:\\output\\${BUILD_NUMBER}_${BUILD_TIMESTAMP}\\${STAGE_NAME}"
                        bat "move ${WORKSPACE}\\${STAGE_NAME}\\x64\\Release\\*.* C:\\output\\${BUILD_NUMBER}_${BUILD_TIMESTAMP}\\${STAGE_NAME}"
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