#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    receiver.setup( PORT);
    mouseX = 0;
    mouseY = 0;
    mouseButtonState = "";
    ofBackground(0, 0, 0);
}

//--------------------------------------------------------------
void ofApp::update(){
    while(receiver.hasWaitingMessages()) {
        ofxOscMessage m;
        receiver.getNextMessage(&m);
        if(m.getAddress()=="/mouse/position"){
            circleX = m.getArgAsFloat(0);
            //remoteMouseX = m.getArgAsInt32(0);
            //remoteMouseY = m.getArgAsInt32(1);
        }
        else if(m.getAddress() == "mouse/button") {
            mouseButtonState = m.getArgAsString(0);
        }
        dumpOSC(m);
    }
}

void ofApp::dumpOSC(ofxOscMessage m) {
    string msgString;
    msgString = m.getAddress();
    for (int i=0; i<m.getNumArgs(); i++){
        msgString += " ";
        if(m.getArgType(i) == OFXOSC_TYPE_INT32)
            msgString += ofToString(m.getArgAsInt32(i));
        else if(m.getArgType(i) == OFXOSC_TYPE_FLOAT)
            msgString += ofToString(m.getArgAsFloat(i));
        else if(m.getArgType(i) == OFXOSC_TYPE_STRING)
            msgString += m.getArgAsString(i);
    }
    cout << msgString << endl;
 }
//--------------------------------------------------------------
void ofApp::draw(){
    int radius = 200;
//    if(mouseButtonState == "down") {
//        radius = 2000;
//        ofSetColor(255, 127, 0);
//    } else {
//        radius = 10;
//        ofSetColor(0, 127, 255);
//    }
    ofSetColor(255, 127, 0);
    ofDrawCircle((ofGetWidth()/2), (ofGetHeight()/2), (radius*circleX));
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
