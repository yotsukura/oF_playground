#include "ofApp.h"

Path::Path(float x, float y, int parent_, int generation_) {
    x1 = x;
    y1 = y;
    parent = parent_;
    generation = generation_;
    length = ofRandom(50, 200);
    alph = 64 * generation / 6;
}

void Path::update(float x, float y) {
    x1 = x;
    y1 = y;
    noiseSeed1 += 0.05;
    noiseSeed2 += 0.05;
    degree += (ofNoise(noiseSeed1) - 0.5) * 30;
    //length += (ofNoise(noiseSeed2) - 0.5) * 10;
    radian = degree * PI / 180.0;
    x2 = x1 + (length * cos(radian));
    y2 = y1 + (length * sin(radian));
}

void Path::drawLine() {
    ofSetColor(0, 0, 0);
    ofSetLineWidth(4);
    ofDrawLine(x1, y1, x2, y2);

}

void Path::drawCircle() {
    ofSetColor(0, 0, 0);
    ofDrawCircle(x2, y2, 8);
    ofSetColor(255, 255, 255);
    ofDrawCircle(x2, y2, 4);
}

//--------------------------------------------------------------
float startX = 0;
float startY = 0;
float centerX, centerY;
vector<Path> tree;
int numChildren = 3;
int numGeneration = 6;
//--------------------------------------------------------------
void ofApp::setup() {
    ofBackground(255);
    Path p(0, 0, -1, 1);
    tree.push_back(p);
    makeChildren();
    centerX = ofGetWidth() / 2;
    centerY = ofGetHeight() / 2;
}

void ofApp::makeChildren() {
    int indexParent = tree.size() -1;
    int generationParent = tree[indexParent].generation;
    for (int i=0; i<numChildren; i++) {
        Path p(tree[indexParent].x2, tree[indexParent].y2, indexParent, (generationParent+1));
        tree.push_back(p);
        if (generationParent < (numGeneration-1) ) {
            makeChildren();
        }
    }
}

//--------------------------------------------------------------
void ofApp::update() {
    for (int i=0; i<tree.size(); i++){
        int p = tree[i].parent;
        if (p < 0) {
            tree[i].update(0, 0);
        } else {
            tree[i].update(tree[p].x2, tree[p].y2);
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw() {
    ofTranslate(centerX, centerY);
    for (int i=0; i<tree.size(); i++) {
        tree[i].drawLine();
        if (tree[i].generation >= numGeneration) {
            //ofDrawCircle(tree[i].x2, tree[i].y2, (tree[i].length / 32));
        }
    }
    for (int i=0; i<tree.size(); i++) {
        tree[i].drawCircle();
        if (tree[i].generation >= numGeneration) {
            //ofDrawCircle(tree[i].x2, tree[i].y2, (tree[i].length / 32));
        }
    }
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
    centerX = x;
    centerY = y;
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