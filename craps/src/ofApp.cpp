#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){
    if(!passline){
        passline = true;
        money = money -50;
    }
    int dice0 = ofRandom(6)+1;
    int dice1 = ofRandom(6)+1;
    
    int roll = dice0+dice1;
    int earn =0;
    if(roll== 2){
        earn = 0;
        if(passline){
            passline = false;
        }
    }
    if(roll== 3){
        earn = 0;
        if(passline){
            passline = false;
        }
    }
    
    if(roll== 7){
        earn = 50*2;
        if(passline){
            passline = false;
        }
    }
    
    if(roll== 11){
        earn = 50*2;
        if(passline){
            passline = false;
        }
    }
    if(roll== 12){
        earn = 0;
        if(passline){
            passline = false;
        }
    }
    money += earn;
    ofLog(OF_LOG_NOTICE,ofToString(roll));
    ofLog(OF_LOG_NOTICE,ofToString(money));
    

}

//--------------------------------------------------------------
void ofApp::draw(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
