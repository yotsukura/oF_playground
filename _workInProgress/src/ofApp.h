#pragma once

#include "ofMain.h"

class Path {
public:
    float per = 0.2;
    float startX, startY;
    float endX, endY;
    float midX, midY;
    float nextStartX, nextStartY;
    int level;
    
    Path(float startX_, float startY_, float endX_, float endY_, int level_);
    void setNext(float destinationX_, float destinationY_);
    void draw();
};

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
		
};
