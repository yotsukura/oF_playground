#include "ofApp.h"

vector<ofVec4f> points;
//--------------------------------------------------------------
void ofApp::setup(){
    receiver.setup( PORT);
    ofBackground(0, 0, 0);
    ofSetCircleResolution(64);
}

//--------------------------------------------------------------
void ofApp::update(){
    while(receiver.hasWaitingMessages()) {
        ofxOscMessage m;
        receiver.getNextMessage(&m);
        if(m.getAddress()=="/param"){
            param0 = m.getArgAsFloat(0);
        }
        if(m.getAddress()=="/Velocity1"){
            int param1 = m.getArgAsInt32(0);
            if(param1>0) {
                flag0 = true;
            }
        }
        if(m.getAddress()=="/state1"){
            state1 = m.getArgAsFloat(0);
            if(state1>0) {
                //flag1 = true;
            }
        }
        if(m.getAddress()=="/state2"){
            state2 = m.getArgAsFloat(0);
            if(state2>0) {
                //flag2 = true;
            }
        }
        dumpOSC(m);
    }
    if(state1>0) {
        for(int i=0; i<points.size(); i++) {
            points[i].x = points[i].x + ofRandom(10)-5;
            points[i].y = points[i].y + ofRandom(10)-5;
        }
        //flag1 = false;
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
    if(flag0==true) {
        ofVec4f p(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight()), ofRandom(10, 40), ofRandom(50, 200));
        points.push_back(p);
        flag0 = false;
    }
    
    float size = 1800 * param0;
    if (state2>0) {
        ofSetColor(210, 230, 255, 200);
    } else {
        ofSetColor(255, 255, 255, 200);
    }
    //ofSetColor(255, 255, 255, 200);
    ofDrawRectangle((ofGetWidth()-size+(ofRandom(-0.2, 0.2)*size))/2, (ofGetHeight()-size+(ofRandom(-0.2, 0.2)*size))/2, size, size);
    //ofDrawCircle((ofGetWidth()/2), (ofGetHeight()/2), (radius*param0));
    
    for(int i=0; i<points.size(); i++) {
        if (state2>0) {
            ofSetColor(210, 230, 255, points[i].w);
        } else {
            ofSetColor(255, 255, 255, points[i].w);
        }
        ofDrawCircle(points[i].x, points[i].y, points[i].z);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    switch(key){
        case 'r' :
            points.clear();
    }
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
