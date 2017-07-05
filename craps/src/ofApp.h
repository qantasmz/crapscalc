#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    
    int money = 3000;
    int max = 0;
    int maxTime = 0;
    int cnt = 0;
    
    bool comeout = true;
    
    bool passline = false;
    bool passlineBet = false;
    bool passlineOdds = false;
    
    bool come = false;
    bool comeBet = false;
    bool comeOdds = false;
    int num = 0;
    int comeNum = 0;
    
    bool stop = false;
    bool end = false;
    
    int bet = 10;
};
