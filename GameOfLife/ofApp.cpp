#include "ofApp.h"

int cellSize = 5;
int counter = 0;
int numX, numY;
int dispStyle = 1;

Cell::Cell() { //constructor
	if (ofRandom(2) >1) {
		stateNext = 1;
	}
	else {
		stateNext = 0;
	}
}

void Cell::reset() {
	if (ofRandom(2) >1) {
		stateNext = 1;
	}
	else {
		stateNext = 0;
	}
}

void Cell::setPos(float _x, float _y) {
	x = _x;
	y = _y;
}

int Cell::getState() {
	return state;
}

void Cell::setStateNeighbor(int _x, int _y, int _state) {
	stateNeighbor[_x][_y] = _state;
}

void Cell::calcNextState() {
	// Calc Living Cell //
	int num_livingCell = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (stateNeighbor[i][j] == 1) {
				num_livingCell++;
			}
		}
	}
	if (stateNeighbor[1][1] == 1) { num_livingCell--; } //except me

														////// Rule: Game of Life //////
	int myFate;
	// 0: still die  //
	// 1: reborn     //
	// 2: die        //
	// 3: still live //
	if (state == 1) {
		if ((num_livingCell == 2) || (num_livingCell == 3)) { myFate = 3; } // still live
		else { myFate = 2; } // die
	}
	else {
		if (num_livingCell == 3) { myFate = 1; } // reborn
		else { myFate = 0; } // still die
	}

	if (age > 50) {
		age = 0;
	}

	switch (myFate) {
	case 0: // still die
		stateNext = 0;
		age = 0;
		myFriends = 0;
		break;
	case 1: // reborn
		stateNext = 1;
		age = 1;
		myFriends = num_livingCell;
		break;
	case 2: // die
		stateNext = 0;
		age = 0;
		myFriends = 0;
		break;
	case 3: // still live
		stateNext = 1;
		age++;
		myFriends += num_livingCell;
		break;
	}
}

void Cell::draw() {
	state = stateNext;
	if (dispStyle == 0) {
		if (state == 1) {
			if (myFriends < 20) {
				ofFill();
				ofSetColor(0, 0, 0, 10);
				ofDrawCircle(x, y, cellSize + age);
			}
			else if ((myFriends >= 20)&&(myFriends < 150)) {
				ofFill();
				ofSetColor(146, 168, 209, 70);
				ofDrawCircle(x, y, cellSize + age);
			}
			else if (myFriends >= 150) {
				ofFill();
				ofSetColor(247, 202, 201, 70);
				ofDrawCircle(x, y, cellSize + age);
			}
		}
	}
	else {
		if (state == 1) {
			ofNoFill();
			ofSetColor(0);
			ofDrawRectangle(x, y, cellSize, cellSize);
		}
		else {
			ofFill();
			ofSetColor(0);
			ofDrawRectangle(x, y, cellSize, cellSize);
		}
	}
}

//--------------------------------------------------------------
void ofApp::setup() {
	ofBackground(255);
	setWindow();
}

void ofApp::setWindow() {
	numX = floor(ofGetWidth() / cellSize);
	numY = floor(ofGetHeight() / cellSize);

	cellArray.resize(numX);
	for (int x = 0; x<numX; x++) {
		cellArray[x].resize(numY);
	}

	for (int x = 0; x<numX; x++) {
		for (int y = 0; y<numY; y++) {
			cellArray[x][y].setPos((x*cellSize + 0.5*cellSize), (y*cellSize + 0.5*cellSize));
		}
	}
}

//--------------------------------------------------------------
void ofApp::update() {
	counter++;
	if (counter == 2) {
		counter = 0;
		for (int x = 0; x < numX; x++) {
			for (int y = 0; y < numY; y++) {

				int left = x - 1;
				if (left < 0) { left = numX - 1; }
				int right = x + 1;
				if (right == numX) { right = 0; }
				int above = y - 1;
				if (above < 0) { above = numY - 1; }
				int below = y + 1;
				if (below == numY) { below = 0; }

				int addressX[3] = { left, x, right };
				int addressY[3] = { above, y, below };

				for (int i = 0; i < 3; i++) {
					for (int j = 0; j < 3; j++) {
						cellArray[x][y].setStateNeighbor(i, j, (cellArray[addressX[i]][addressY[j]].getState()));
					}
				}
			}
		}

		for (int x = 0; x < numX; x++) {
			for (int y = 0; y < numY; y++) {
				cellArray[x][y].calcNextState();
			}
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw() {
	for (int x = 0; x<numX; x++) {
		for (int y = 0; y<numY; y++) {
			cellArray[x][y].draw();
		}
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	if (key == 'r') {
		dispStyle = 1 - dispStyle;
		for (int x = 0; x<numX; x++) {
			for (int y = 0; y<numY; y++) {
				cellArray[x][y].reset();
			}
		}
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {
	setWindow();
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
