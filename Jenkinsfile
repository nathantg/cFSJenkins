pipeline {
    agent any
    
    options {
        skipDefaultCheckout(true)
    }
    
    environment {
        TO_PORT = '1238'
        ROVER_TYPE = 'lrm'
        COMPILER = 'cpu1'
        /* Change if location of cross compiler is changed */
        //ARM_ROOT = '/home/canadensys/work/toolchains/gcc-linaro-6.5.0-2018.12-x86_64_arm-linux-gnueabihf/arm-linux-gnueabihf'
        ARM_ROOT = '/home/canadensys/work/toolchains/gcc-linaro-6.5.0-2018.12-x86_64_arm-linux-gnueabihf/arm-linux-gnueabihf'
        /* Targets for build artifacts to be sent to via SSH */
        DEPLOY_TARGET_1 = 'Nathan Beaglebone'
        DEPLOY_TARGET_2 = 'Beaglebone 2'
        DEPLOY_TARGET_3 = 'Beaglebone 3'
        /* Directory on the target relative to the user directory to send the build artifacts to */
        REMOTE_DIR = '/nathan/lrm/Jenkins_cFS_deploy'
        /* The directory relative to the Jenkins workspace where the files to be deployed to target are located */
        SOURCE_DIR = 'build/**/*'
        /* SonarQube Server URL */
        SONARQUBE_URL = 'http://192.168.8.29:9000' 
    }
    
    stages {
        stage('Checkout SCM') {
            steps {
                cleanWs()
                checkout scm
            }
        }
        stage('Preparation') {
            steps {
                sh 'make distclean'
                sh 'make SIMUATION=$COMPILER prep'
                sh '''
                  mkdir -p .sonar
                  curl -sSLo .sonar/build-wrapper-linux-x86.zip ${SONARQUBE_URL}/static/cpp/build-wrapper-linux-x86.zip 
                  unzip -o .sonar/build-wrapper-linux-x86.zip -d .sonar/
                '''
            }
        } 
        stage('Build') {
            steps {
                sh '.sonar/build-wrapper-linux-x86/build-wrapper-linux-x86-64 --out-dir bw-output make --build build/ --config Release'
                //sh 'make'
                //sh 'make install'
            }
        }
        stage('Static Code Analysis') {
            when { anyOf {branch "release"; branch "test"; branch "sonarqube"} }
            steps {
                script {
                    def scannerHome = tool 'SonarScanner'; // Name of the SonarQube Scanner you created in "Global Tool Configuration" section
                    withSonarQubeEnv() {
                        sh "${scannerHome}/sonar-scanner-4.7.0.2747-linux/bin/sonar-scanner"
                    }
                }
            }
        }
        stage('Unit Testing') {
            when { anyOf {branch "release"; branch "test"} }
            steps {
                echo 'make test'
            }
        }
        stage('Coverage Testing') {
            when { anyOf {branch "release"; branch "test"} }
            steps {
                echo 'make icov'
            }
        }
        stage('Deploy') {     
            when { anyOf {branch "release"; branch "test"; branch "feature-*"; branch "dev-nathan"} }
            steps {
                //sh 'scp -r build debian@192.168.8.24:/home/debian/nathan/lrm'
                sshPublisher(
                    continueOnError: false, failOnError: true,
                    publishers: [
                        sshPublisherDesc(configName: DEPLOY_TARGET_1, 
                                         transfers: [
                                             sshTransfer(cleanRemote: false, excludes: '',
                                                         //execCommand: 'sh ./core-cpu1',
                                                         execTimeout: 120000, 
                                                         flatten: false, 
                                                         makeEmptyDirs: false, 
                                                         noDefaultExcludes: false, 
                                                         patternSeparator: '[, ]+', 
                                                         remoteDirectory: REMOTE_DIR, 
                                                         remoteDirectorySDF: false, 
                                                         removePrefix: '', 
                                                         sourceFiles: SOURCE_DIR)/*, 
                                             sshTransfer(cleanRemote: false, excludes: '',
                                                         execCommand: './core-cpu1',
                                                         execTimeout: 120000, 
                                                         flatten: false, 
                                                         makeEmptyDirs: false, 
                                                         noDefaultExcludes: false, 
                                                         patternSeparator: '[, ]+', 
                                                         remoteDirectory: '${REMOTE_DIR}/build/exe/cpu1', 
                                                         remoteDirectorySDF: false, 
                                                         removePrefix: '', 
                                                         sourceFiles: '')       */                                    
                                         ], 
                                         usePromotionTimestamp: false, useWorkspaceInPromotion: false, verbose: false) 
                    ]
                ) 
            }
        }
    }
}
