#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){
    if(!stop){
        
        if(!passline &&  !passlineBet && num == 0){
            passline = true;
            money = money -bet;
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
            
            if(come && !comeBet){
                earn = 0;
                come = false;
                comeNum = 0;
            }
        }
        if(roll== 3){
            if(passline && !passlineBet){
                earn = 0;
                passline = false;
                num = 0;
            }
            if(come && !comeBet){
                earn = 0;
                come = false;
                comeNum = 0;
            }
        }
        
        if(roll== 4 || roll== 5 || roll== 6 || roll== 8 || roll== 9 || roll== 10){
            
            if(passline && !passlineBet){
                earn = 0;
                passline = false;
                passlineBet = true;
                passlineOdds = true;
                
                come = true;
                
                money = money -bet;
                
                money = money -bet*5;
                num = roll;
            }else if(num == roll){
                if(passlineBet){
                    earn = earn + bet*2;
                    if(roll == 4 || roll == 10){
                        earn = earn + bet*5*3;
                    }
                    if(roll == 5 || roll == 9){
                        earn = earn + bet*5*2.5;
                    }
                    if(roll == 6 || roll == 8){
                        earn = earn + bet*5*2.2;
                    }
                    passlineBet = false;
                    passlineOdds = false;
                    num = 0;
                }
            }
            
            if(come && !comeBet){
                earn = 0;
                come = false;
                comeBet = true;
                comeOdds = true;
                
                money = money -bet*5;
                comeNum = roll;
            }else if(comeNum == roll){
                if(comeBet){
                    earn = earn + bet*2;
                    if(roll == 4 || roll == 10){
                        earn = earn + bet*5*3;
                    }
                    if(roll == 5 || roll == 9){
                        earn = earn + bet*5*2.5;
                    }
                    if(roll == 6 || roll == 8){
                        earn = earn + bet*5*2.2;
                    }
                    comeBet = false;
                    comeOdds = false;
                    comeNum = 0;
                }
            }
        }
        
        if(roll== 7){
            if(passline && !passlineBet){
                
                earn = bet*2;
                passline = false;
                num = 0;
            }
            
            if(come && !comeBet){
                earn = bet*2;
                come = false;
                comeNum = 0;
            }
            
            if(passlineBet){
                passlineBet = false;
                passlineOdds = false;
                num = 0;
            }
            if(comeBet){
                comeBet = false;
                comeOdds = false;
                comeNum = 0;
            }
        }
        
        if(roll== 11){
            if(passline && !passlineBet){
                
                earn = bet*2;
                passline = false;
                num = 0;
            }
            
            if(come && !comeBet){
                earn = bet*2;
                come = false;
                comeNum = 0;
            }
        }
        if(roll== 12){
            if(passline && !passlineBet){
                earn = 0;
                passline = false;
                num = 0;
            }
            if(come && !comeBet){
                earn = 0;
                come = false;
                comeNum = 0;
            }
        }
        money += earn;
        ofLog(OF_LOG_NOTICE,"roll : "+ofToString(roll));
        ofLog(OF_LOG_NOTICE,"earn : "+ofToString(earn));
        ofLog(OF_LOG_NOTICE,"money : "+ofToString(money));
        if(money > max){
            max = money;
            maxTime= cnt;
        }
        cnt += 1;
    }
    if(money > 6000){
        stop = true;
        if(!end){
            ofLog(OF_LOG_NOTICE,"maximumRoll : "+ofToString(maxTime));
            ofLog(OF_LOG_NOTICE,"maximum : "+ofToString(max));
            end = true;
        }else{
        }
    }
    if(money <0){
        stop = true;
        if(!end){
            ofLog(OF_LOG_NOTICE,"maximumRoll : "+ofToString(maxTime));
            ofLog(OF_LOG_NOTICE,"maximum : "+ofToString(max));
            end = true;
        }else{
        }
    }
    

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
