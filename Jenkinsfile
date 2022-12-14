pipeline {
    agent any
    
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
        
    }
    
    stages {
        stage('Preparation') {
            steps {
                sh 'make distclean'
                sh 'env'
                sh 'make SIMUATION=$COMPILER prep'
                sh 'env'
            }
        } 
        stage('Build') {
            steps {
                sh 'make'
                sh 'make install'
            }
        }
        stage('Static Code Analysis') {
            when { anyOf {branch "release"; branch "test"} }
            steps {
                echo 'Perform static code analysis'
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
                sshPublisher(
                    continueOnError: false, failOnError: true,
                    publishers: [
                        sshPublisherDesc(configName: DEPLOY_TARGET_1, 
                                         transfers: [
                                             sshTransfer(cleanRemote: false, excludes: '',
                                                         execTimeout: 120000, 
                                                         flatten: false, 
                                                         makeEmptyDirs: false, 
                                                         noDefaultExcludes: false, 
                                                         patternSeparator: '[, ]+', 
                                                         remoteDirectory: REMOTE_DIR, 
                                                         remoteDirectorySDF: false, 
                                                         removePrefix: '', 
                                                         sourceFiles: SOURCE_DIR)], 
                                         usePromotionTimestamp: false, useWorkspaceInPromotion: false, verbose: false),
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
                                                         sourceFiles: '')], 
                                         usePromotionTimestamp: false, useWorkspaceInPromotion: false, verbose: false)
                    
                    ]) /*
                sshPublisher(
                    continueOnError: false, failOnError: true,
                    publishers: [
                        sshPublisherDesc(configName: DEPLOY_TARGET_2, 
                                         transfers: [
                                             sshTransfer(cleanRemote: false, excludes: '',
                                                         execTimeout: 120000, 
                                                         flatten: false, 
                                                         makeEmptyDirs: false, 
                                                         noDefaultExcludes: false, 
                                                         patternSeparator: '[, ]+', 
                                                         remoteDirectory: REMOTE_DIR, 
                                                         remoteDirectorySDF: false, 
                                                         removePrefix: '', 
                                                         sourceFiles: SOURCE_DIR)], 
                                         usePromotionTimestamp: false, useWorkspaceInPromotion: false, verbose: false)]) 
                sshPublisher(
                    continueOnError: false, failOnError: true,
                    publishers: [
                        sshPublisherDesc(configName: DEPLOY_TARGET_3, 
                                         transfers: [
                                             sshTransfer(cleanRemote: false, excludes: '',
                                                         execTimeout: 120000, 
                                                         flatten: false, 
                                                         makeEmptyDirs: false, 
                                                         noDefaultExcludes: false, 
                                                         patternSeparator: '[, ]+', 
                                                         remoteDirectory: REMOTE_DIR, 
                                                         remoteDirectorySDF: false, 
                                                         removePrefix: '', 
                                                         sourceFiles: SOURCE_DIR)], 
                                         usePromotionTimestamp: false, useWorkspaceInPromotion: false, verbose: false)]) */
            }
        }
    }
}
