#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    total = sessions;
    money = defmoney;
}

//--------------------------------------------------------------
void ofApp::update(){
    
    
    if(total == sessions){
        text.open("log.csv",ofFile::Append);
        text << "time,lastnum,result,maximumRoll,maximum,minimum";
        text << "\n";
    }
    
    while(total >0){
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
                
                
                
                if(come && !comeBet){
                    earn = 0;
                    come = false;
                    comeBet = true;
                    comeOdds = true;
                    if(roll == 4||roll == 10){
                        money = money -bet*odds*0.6;
                    }
                    if(roll == 5||roll == 9){
                        money = money -bet*odds*0.8;
                    }
                    if(roll == 6||roll == 8){
                        money = money -bet*odds;
                    }
                    comeNum = roll;
                }else if(comeNum == roll){
                    if(comeBet){
                        earn = earn + bet*2;
                        if(roll == 4 || roll == 10){
                            earn = earn + bet*odds*0.6*3;
                        }
                        if(roll == 5 || roll == 9){
                            earn = earn + bet*odds*0.8*2.5;
                        }
                        if(roll == 6 || roll == 8){
                            earn = earn + bet*odds*2.2;
                        }
                        //ofLog(OF_LOG_NOTICE,"comehit! : "+ofToString(roll));
                        comeBet = false;
                        comeOdds = false;
                        comeNum = 0;
                    }
                }
                
                if(passline && !passlineBet){
                    earn = 0;
                    passline = false;
                    passlineBet = true;
                    passlineOdds = true;
                    
                    come = true;
                    
                    money = money -bet;
                    
                    money = money -bet*odds;
                    num = roll;
                }else if(num == roll){
                    if(passlineBet){
                        earn = earn + bet*2;
                        if(roll == 4 || roll == 10){
                            earn = earn + bet*odds*3;
                        }
                        if(roll == 5 || roll == 9){
                            earn = earn + bet*odds*2.5;
                        }
                        if(roll == 6 || roll == 8){
                            earn = earn + bet*odds*2.2;
                        }
                        //ofLog(OF_LOG_NOTICE,"placehit! : "+ofToString(roll));
                        passlineBet = false;
                        passlineOdds = false;
                        num = 0;
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
            /*
             ofLog(OF_LOG_NOTICE,"num : "+ofToString(num));
             ofLog(OF_LOG_NOTICE,"come : "+ofToString(comeNum));
             ofLog(OF_LOG_NOTICE,"roll : "+ofToString(roll));
             ofLog(OF_LOG_NOTICE,"earn : "+ofToString(earn));
             ofLog(OF_LOG_NOTICE,"money : "+ofToString(money));
             */
            if(money > max){
                max = money;
                maxTime= cnt;
            }
            if(money < min){
                min = money;
            }
            cnt += 1;
        }
        if(money > winnum){
            stop = true;
            if(!end){
                total -= 1;
                ofLog(OF_LOG_NOTICE,"maximumRoll : "+ofToString(maxTime));
                ofLog(OF_LOG_NOTICE,"maximum : "+ofToString(max));
                end = true;
                
                text.open("log.csv",ofFile::Append);
                text << ofToString(cnt);
                text << ",";
                text << ofToString(money);
                text << ",";
                text << "win";
                text << ",";
                text << ofToString(maxTime);
                text << ",";
                text << ofToString(max);
                text << ",";
                text << ofToString(min);
                text << "\n";
                
                /*
                text.open("log.csv",ofFile::Append);
                text << "time : "+ofToString(cnt);
                text << "\n";
                text << "lastnum : "+ofToString(money);
                text << "\n";
                text << "win!";
                text << "\n";
                text << "maximumRoll : "+ofToString(maxTime);
                text << "\n";
                text << "maximum : "+ofToString(max);
                text << "\n";
                text << "minimum : "+ofToString(min);
                text << "\n";
                text << "=================";
                text << "\n";
                 */
                
                winCnt += 1;
                
                money = defmoney;
                max = 0;
                min = 10000;
                maxTime = 0;
                cnt = 0;
                
                
                passline = false;
                passlineBet = false;
                passlineOdds = false;
                
                come = false;
                comeBet = false;
                comeOdds = false;
                num = 0;
                comeNum = 0;
                
                stop = false;
                end = false;
                
            }else{
            }
        }else if(money <0){
            stop = true;
            if(!end){
                total -= 1;
                
                ofLog(OF_LOG_NOTICE,"maximumRoll : "+ofToString(maxTime));
                ofLog(OF_LOG_NOTICE,"maximum : "+ofToString(max));
                end = true;
                
                text.open("log.csv",ofFile::Append);
                text << ofToString(cnt);
                text << ",";
                text << ofToString(money);
                text << ",";
                text << "lose";
                text << ",";
                text << ofToString(maxTime);
                text << ",";
                text << ofToString(max);
                text << ",";
                text << ofToString(min);
                text << "\n";
                /*
                text.open("log.csv",ofFile::Append);
                text << "time : "+ofToString(cnt);
                text << "\n";
                text << "lastnum : "+ofToString(money);
                text << "\n";
                text << "lose!!!!!";
                text << "\n";
                text << "maximumRoll : "+ofToString(maxTime);
                text << "\n";
                text << "maximum : "+ofToString(max);
                text << "\n";
                text << "minimum : "+ofToString(min);
                text << "\n";
                text << "=================";
                text << "\n";
                */
                
                loseCnt += 1;
                money = defmoney;
                max = 0;
                min = 10000;
                maxTime = 0;
                cnt = 0;
                
                
                passline = false;
                passlineBet = false;
                passlineOdds = false;
                
                come = false;
                comeBet = false;
                comeOdds = false;
                num = 0;
                comeNum = 0;
                
                stop = false;
                end = false;
                
            }else{
            }
        }else if(cnt == limit){
            stop = true;
            if(!end){
                total -= 1;
                
                ofLog(OF_LOG_NOTICE,"maximumRoll : "+ofToString(maxTime));
                ofLog(OF_LOG_NOTICE,"maximum : "+ofToString(max));
                end = true;
                
                
                text.open("log.csv",ofFile::Append);
                text << ofToString(cnt);
                text << ",";
                text << ofToString(money);
                text << ",";
                text << "end";
                text << ",";
                text << ofToString(maxTime);
                text << ",";
                text << ofToString(max);
                text << ",";
                text << ofToString(min);
                text << "\n";
                
                
                /*
                text.open("log.csv",ofFile::Append);
                text << "time : "+ofToString(cnt);
                text << "\n";
                text << "lastnum : "+ofToString(money);
                text << "\n";
                text << "lose";
                text << "\n";
                text << "maximumRoll : "+ofToString(maxTime);
                text << "\n";
                text << "maximum : "+ofToString(max);
                text << "\n";
                text << "minimum : "+ofToString(min);
                text << "\n";
                text << "=================";
                text << "\n";
                 */
                if(money >defmoney){
                    winCnt += 1;
                }else{
                    loseCnt += 1;
                }
                money = defmoney;
                max = 0;
                min = 10000;
                maxTime = 0;
                cnt = 0;
                
                
                passline = false;
                passlineBet = false;
                passlineOdds = false;
                
                come = false;
                comeBet = false;
                comeOdds = false;
                num = 0;
                comeNum = 0;
                
                stop = false;
                end = false;
                
            }else{
            }
        }
    }
    
    ofLog(OF_LOG_NOTICE,"win :" +ofToString(winCnt));
    ofLog(OF_LOG_NOTICE,"lose :" +ofToString(loseCnt));
    ofLog(OF_LOG_NOTICE,"END!!");

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
