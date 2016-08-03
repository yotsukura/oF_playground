#include "ofApp.h"

//--------------------------------------------------------------
ofxBox2d                               box2d;   // the box2d world
vector   <shared_ptr<ofxBox2dCircle> > particles; // まだCustomRect定義していない
ofxBox2dRect rect;
ofImage particleImage;
ofImage rectImage;
//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    ofBackgroundHex(0x000000);
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    // init box2d world
    box2d.init();
    box2d.setGravity(0, 0);
    box2d.setFPS(30.0);
    // set image
    particleImage.load("emitter.png");
    rectImage.load("particle.png");
    
    rect.fixture.filter.groupIndex = -1;
    rect.setup(box2d.getWorld(), ofGetWidth()/2, ofGetHeight()/2, 1, 1);
}

//--------------------------------------------------------------
void ofApp::update(){

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
