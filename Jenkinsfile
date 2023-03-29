pipeline {
    agent any
    stages {
        stage('github-pull') {
            parallel {
                stage('Source-code') {
                    steps {
                        git(branch: 'parallelBuild', url: 'https://github.com/AmitAaranya/CPP.git')
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
                            image 'test5' 
                            reuseNode 'true' 
                            args "-v ${WORKSPACE}\\${STAGE_NAME}:C:\\app"
                        }
                    }
                    steps {
                        bat "msbuild c:\\app\\Demowix\\Demowix.vcxproj /property:Configuration=Release /property:Platform=x64"
                    }
                }

                stage('toolkit-2') {
                    agent {
                        docker { 
                            image 'test5' 
                            reuseNode 'true' 
                            args "-v ${WORKSPACE}\\${STAGE_NAME}:C:\\app"
                        }
                    }
                    steps {
                        bat "msbuild c:\\app\\Demowix\\Demowix.vcxproj /property:Configuration=Release /property:Platform=x64"
                    }
                }

                stage('toolkit-3') {
                    agent {
                        docker { 
                            image 'test5' 
                            reuseNode 'true' 
                            args "-v ${WORKSPACE}\\${STAGE_NAME}:C:\\app"
                        }
                    }
                    steps {
                        bat "msbuild c:\\app\\Demowix\\Demowix.vcxproj /property:Configuration=Release /property:Platform=x64"
                    }
                }

                stage('toolkit-4') {
                    agent {
                        docker { 
                            image 'test5' 
                            reuseNode 'true' 
                            args "-v ${WORKSPACE}\\${STAGE_NAME}:C:\\app"
                        }
                    }
                    steps {
                        bat "msbuild c:\\app\\Demowix\\Demowix.vcxproj /property:Configuration=Release /property:Platform=x64"
                    }
                }

                stage('toolkit-5') {
                    agent {
                        docker { 
                            image 'test5' 
                            reuseNode 'true' 
                            args "-v ${WORKSPACE}\\${STAGE_NAME}:C:\\app"
                        }
                    }
                    
                    steps {
                        bat "msbuild c:\\app\\Demowix\\Demowix.vcxproj /property:Configuration=Release /property:Platform=x64"
                    }
                }

                stage('toolkit-6') {
                    agent {
                        docker { 
                            image 'test5' 
                            reuseNode 'true' 
                            args "-v ${WORKSPACE}\\${STAGE_NAME}:C:\\app"
                        }
                    }
                    steps {
                        bat "msbuild c:\\app\\Demowix\\Demowix.vcxproj /property:Configuration=Release /property:Platform=x64"
                    }
                }

                stage('toolkit-7') {
                    agent {
                        docker { 
                            image 'test5' 
                            reuseNode 'true' 
                            args "-v ${WORKSPACE}\\${STAGE_NAME}:C:\\app"
                        }
                    }
                    steps {
                        bat "msbuild c:\\app\\SimpleRnD\\SimpleRnD.vcxproj /property:Configuration=Release /property:Platform=x64"
                    }
                }

                stage('toolkit-8') {
                    agent {
                        docker { 
                            image 'test5' 
                            reuseNode 'true' 
                            args "-v ${WORKSPACE}\\${STAGE_NAME}:C:\\app"
                        }
                    }
                    steps {
                        bat "msbuild c:\\app\\TeradyneDemo\\TeradyneDemo.vcxproj /property:Configuration=Release /property:Platform=x64"
                    }
                }

            }
        }

        stage('Output File Transfer') {
            parallel {
                stage('toolkit-1') {
                    steps {
                        bat "mkdir C:\\output\\${BUILD_NUMBER}_${BUILD_TIMESTAMP}\\${STAGE_NAME}"
                        bat "move ${WORKSPACE}\\${STAGE_NAME}\\DemoWix\\x64\\Release\\*.* C:\\output\\${BUILD_NUMBER}_${BUILD_TIMESTAMP}\\${STAGE_NAME}"
                    }
                }

                stage('toolkit-2') {
                    steps {
                        bat "mkdir C:\\output\\${BUILD_NUMBER}_${BUILD_TIMESTAMP}\\${STAGE_NAME}"
                        bat "move ${WORKSPACE}\\${STAGE_NAME}\\DemoWix\\x64\\Release\\*.* C:\\output\\${BUILD_NUMBER}_${BUILD_TIMESTAMP}\\${STAGE_NAME}"
                    }
                }

                stage('toolkit-3') {
                    steps {
                        bat "mkdir C:\\output\\${BUILD_NUMBER}_${BUILD_TIMESTAMP}\\${STAGE_NAME}"
                        bat "move ${WORKSPACE}\\${STAGE_NAME}\\DemoWix\\x64\\Release\\*.* C:\\output\\${BUILD_NUMBER}_${BUILD_TIMESTAMP}\\${STAGE_NAME}"
                    }
                }

                stage('toolkit-4') {
                    steps {
                        bat "mkdir C:\\output\\${BUILD_NUMBER}_${BUILD_TIMESTAMP}\\${STAGE_NAME}"
                        bat "move ${WORKSPACE}\\${STAGE_NAME}\\DemoWix\\x64\\Release\\*.* C:\\output\\${BUILD_NUMBER}_${BUILD_TIMESTAMP}\\${STAGE_NAME}"
                    }
                }

                stage('toolkit-5') {
                    steps {
                        bat "mkdir C:\\output\\${BUILD_NUMBER}_${BUILD_TIMESTAMP}\\${STAGE_NAME}"
                        bat "move ${WORKSPACE}\\${STAGE_NAME}\\DemoWix\\x64\\Release\\*.* C:\\output\\${BUILD_NUMBER}_${BUILD_TIMESTAMP}\\${STAGE_NAME}"
                    }
                }

                stage('toolkit-6') {
                    steps {
                        bat "mkdir C:\\output\\${BUILD_NUMBER}_${BUILD_TIMESTAMP}\\${STAGE_NAME}"
                        bat "move ${WORKSPACE}\\${STAGE_NAME}\\DemoWix\\x64\\Release\\*.* C:\\output\\${BUILD_NUMBER}_${BUILD_TIMESTAMP}\\${STAGE_NAME}"
                    }
                }

                stage('toolkit-7') {
                    steps {
                        bat "mkdir C:\\output\\${BUILD_NUMBER}_${BUILD_TIMESTAMP}\\${STAGE_NAME}"
                        bat "move ${WORKSPACE}\\${STAGE_NAME}\\SimpleRnD\\x64\\Release\\*.* C:\\output\\${BUILD_NUMBER}_${BUILD_TIMESTAMP}\\${STAGE_NAME}"
                    }
                }

                stage('toolkit-8') {
                    steps {
                        bat "mkdir C:\\output\\${BUILD_NUMBER}_${BUILD_TIMESTAMP}\\${STAGE_NAME}"
                        bat "move ${WORKSPACE}\\${STAGE_NAME}\\TeradyneDemo\\x64\\Release\\*.* C:\\output\\${BUILD_NUMBER}_${BUILD_TIMESTAMP}\\${STAGE_NAME}"
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
