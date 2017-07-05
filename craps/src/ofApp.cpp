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
        if(passline && !passlineBet){
            earn = 0;
            passline = false;
            num = 0;
        }
    }
    if(roll== 3){
        if(passline && !passlineBet){
            earn = 0;
            passline = false;
            num = 0;
        }
    }
    
    if(roll== 4 || roll== 5 || roll== 6 || roll== 8 || roll== 9 || roll== 10){
        
        if(passline && !passlineBet){
            earn = 0;
            passline = false;
            passlineBet = true;
            passlineOdds = true;
            money = money -50*5;
            num = roll;
        }else if(num == roll){
            if(passlineBet){
                earn = earn + 50*2;
                if(roll == 4 || roll == 10){
                    earn = earn + 50*5*3;
                }
                if(roll == 5 || roll == 9){
                    earn = earn + 50*5*2.5;
                }
                if(roll == 6 || roll == 8){
                    earn = earn + 50*5*2.2;
                }
                passlineBet = false;
                passlineOdds = false;
                num = 0;
            }
        }
    }
    
    if(roll== 7){
        if(passline && !passlineBet){
            
            earn = 50*2;
            passline = false;
            num = 0;
        }
        
        if(passlineBet){
            passlineBet = false;
            passlineOdds = false;
            num = 0;
        }
    }
    
    if(roll== 11){
        if(passline && !passlineBet){
            
            earn = 50*2;
            passline = false;
            num = 0;
        }
    }
    if(roll== 12){
        earn = 0;
        if(passline && !passlineBet){
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
