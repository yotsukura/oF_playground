#pragma once

#include "ofMain.h"
#include "ofxOsc.h"

#define PORT 2346

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
    void dumpOSC(ofxOscMessage m);
		
private:
    ofxOscReceiver receiver;
    float param0 = 0;
    float param1 = 0;
    float state1 = 0;
    float state2 = 0;
    bool flag0 = false;
    bool flag1 = false;
    bool flag2 = false;
};
