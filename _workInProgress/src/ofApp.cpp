#include "ofApp.h"

Path::Path(float startX_, float startY_, float endX_, float endY_, int level_) {
    startX = startX_;
    startY = startY_;
    endX = endX_;
    endY = endY_;
    level = level_;
    midX = (startX + endX) /2;
    midY = (startY + endY) /2;
}

void Path::draw(float destinationX_, float destinationY_) {
    if (midX<destinationX_) {
        nextStartX =  midX + (destinationX_ - midX) * per;
    } else {
        nextStartX = midX - (midX - destinationX_) * per;
    }
    if (midX<destinationY_) {
        nextStartY =  midY + (destinationY_ - midY) * per;
    } else {
        nextStartY = midY - (midY - destinationY_) * per;
    }
    
    ofSetColor(0, 0, 0);
    ofSetLineWidth(5-level);
    ofDrawLine(startX, startY, endX, endY);
    
    ofSetLineWidth(0.5);
    ofDrawCircle(midX, midY, 15);
    ofDrawLine(midX, midY, nextStartX, nextStartY);
}
//--------------------------------------------------------------
float startX, startY, endX, endY;
vector<Path> penta;
//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);
    for (int i=0; i<360; i+=72) {
        startX = (ofGetWidth()/2) + (400 * cos(i * PI / 180.0));
        startY = (ofGetWidth()/2) + (400 * sin(i * PI / 180.0));
        endX = (ofGetWidth()/2) + (400 * cos((i+72) * PI / 180.0));
        endY = (ofGetWidth()/2) + (400 * sin((i+72) * PI / 180.0));
        Path p(startX, startY, endX, endY, 0);
        penta.push_back(p);
    }
    for (int i=0; i<5; i++) {
        Path q(penta[i].nextStartX, penta[i].nextStartY, penta[i+1].nextStartX, penta[i+1].nextStartY, 1);
        penta.push_back(q);
    }
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    for (int i=0; i<penta.size(); i++) {
        int destination = i+3;
        if (destination >= 5) {
            destination -= 5;
        }
        penta[i].draw(penta[destination].startX, penta[destination].startY);
    }
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
