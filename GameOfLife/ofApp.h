#pragma once

#include "ofMain.h"

class Cell {
private:
	int state;
	int stateNext;
	int stateNeighbor[3][3];
	int myFriends;
	int age;
	float x;
	float y;
public:
	Cell(); //constructor
	void reset();
	void setPos(float x, float y);
	int getState();
	void setStateNeighbor(int x, int y, int state);
	void calcNextState();
	void draw();
};

class ofApp : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();
	void setWindow();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);

	vector< vector<Cell> > cellArray;
};
