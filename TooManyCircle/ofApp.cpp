#include "ofApp.h"

// myCircle //
myEllipse::myEllipse() {
	a = ofRandom(10, 200);
	b = ofRandom(10, 200);
	c = ofRandom(-50, 50);
	d = ofRandom(-50, 50);
	rotateDegree = ofRandom(0, 360);
	rotateX = ofRandom(0, 1);
	rotateY = ofRandom(0, 1);
}

void myEllipse::draw() {
	ofRotate(rotateDegree, rotateX, rotateY, 0);

	ofPoint current((a+c), d, 0);
	ofPoint previous;
	for (int degree = 0; degree < (360 + 5); degree += 5) {
		double radian = degree * PI / 180.0;
		previous = current;

		current.x = a * cos(radian) + c;
		current.y = b * sin(radian) + d;
		ofSetColor(0);
		ofDrawLine(previous, current);
	}
}

// ofApp //
vector<myEllipse> crowd;
float degree = 0;
//--------------------------------------------------------------
void ofApp::setup() {
	ofSetBackgroundAuto(false);
	ofBackground(255);

	for (int i = 0; i < 60; i++) {
		myEllipse e;
		crowd.push_back(e);
	}
}

//--------------------------------------------------------------
void ofApp::update() {
	degree += 1;
}

//--------------------------------------------------------------
void ofApp::draw() {
	ofSetColor(255, 20);
	ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());

	cam.begin();
	ofTranslate(0, 0, 0);
	ofRotateX(degree);

	for (int i = 0; i < crowd.size(); i++) {
		crowd[i].draw();
	}

	cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

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

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
