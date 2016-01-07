#include "ofApp.h"

//--------------------------------------------------------------
// macro //
#define ArraySize(array)	(sizeof(array) / sizeof(array[0]))
// variable //
int state = 1;
int interval = 20;
float degree = 0;
float clock0[3];
float clock1[3];
float start[3];
float noiseInterval0 = 0.01;
float noiseInterval1 = 0.1;
//--------------------------------------------------------------

void ofApp::setup() {
	ofBackground(0);
	ofSetFrameRate(30);
	ofFill();
	ofSetSphereResolution(10);
	for (int i = 0; i < ArraySize(clock0); i++) { clock0[i] = ofRandom(20); }
	for (int i = 0; i < ArraySize(start); i++) { start[i] = ofRandom(10); }
}

//--------------------------------------------------------------
void ofApp::update() {
	for (int i = 0; i < ArraySize(clock0); i++) { clock0[i] += noiseInterval0; }
	for (int i = 0; i < ArraySize(start); i++) { start[i] += (ofNoise(clock0[i]) * 0.5) - 0.25; }
	degree++;
}

//--------------------------------------------------------------
void ofApp::draw() {
	if (state == 3) { drawPNoise3D(); }
	else if (state == 2) { drawPNoise2D(); }
	else if (state == 1) { drawPNoise1D(); }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	if (key == '3') { state = 3; }
	else if (key == '2') { state = 2; }
	else if (key == '1') { state = 1; }
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

void ofApp::drawPNoise3D() {
	cam.begin();

	ofRotateX(100);
	ofRotateY(200);
	clock1[0] = start[0];

	for (int z = 0; z < 300; z += interval) {
		clock1[0] += noiseInterval1;
		clock1[1] = start[1];
		for (int y = 0; y < 300; y += interval) {
			clock1[1] += noiseInterval1;
			clock1[2] = start[2];
			for (int x = 0; x < 300; x += interval) {
				clock1[2] += noiseInterval1;
				float k = ofNoise(clock1[2], clock1[1], clock1[0]);
				ofPushMatrix();

				ofTranslate((x - 150), (y - 150), (z - 150));
				ofSetColor((255 * k), (255 * k), (255 * k), 10);
				ofDrawBox(interval);

				ofPopMatrix();
			}
		}
	}
	cam.end();
}

void ofApp::drawPNoise2D() {
	clock1[1] = start[1];
	for (int y = 0; y < (ofGetHeight() + interval); y += interval) {
		clock1[1] += noiseInterval1;
		clock1[2] = start[2];
		for (int x = 0; x < (ofGetWidth() + interval); x += interval) {
			clock1[2] += noiseInterval1;
			float k = ofNoise(clock1[2], clock1[1]);
			ofPushMatrix();

			ofTranslate(x, y);

			ofRotate(k * 360);
			ofSetColor(255, 255, 255, 170);
			ofDrawTriangle(0, 0, (interval/1.41), -4, (interval/1.41), 4);

			ofPopMatrix();
		}
	}
}

void ofApp::drawPNoise1D() {
	clock1[2] = start[2];
	for (int x = 0; x < (ofGetWidth() + interval / 2); x += (interval / 2)) {
		clock1[2] += noiseInterval1;
		ofSetColor(255);
		float noise = (300 * ofNoise(clock1[2])) - 150;
		ofDrawCircle(x, (ofGetHeight() / 2 + noise), 2);
	}
}