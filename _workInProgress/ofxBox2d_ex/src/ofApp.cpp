#include "ofApp.h"

//--------------------------------------------------------------
ofxBox2d                               box2d;   // the box2d world
vector   <shared_ptr<ofxBox2dCircle> > particles; // まだCustomRect定義していない
ofxBox2dRect center;
ofImage particleImage;
ofImage centerImage;
//--------------------------------------------------------------
class MyRect : public ofxBox2dRect {
public:
    MyRect(int _num);
    void update();
    
    int num;
    float radius;
    ofSoundPlayer sound;
    float soundSpeed;
    float soundAmp;
    float soundLfo;
};
//--------------------------------------------------------------
MyRect::MyRect(int _num){
    num = _num;
    float notes[] = {1.0, 5.0/4.0, 4.0/3.0, 3.0/2.0};
    float base[] = {8.0, 4.0, 2.0, 1.0, 0.5};
    sound.load("ambientSound.wav");
    soundSpeed = notes[num%4] / base[num%5];
    sound.setSpeed(soundSpeed);
    sound.setLoop(true);
    soundAmp = 0;
    sound.play();
    soundLfo = ofRandom(0.5, 2.0);
}

void MyRect::update() {
    radius = sin(ofGetElapsedTimef() * 10.0 * soundLfo) * 20 + 40;
    ofVec2f pos = getPosition();
    float distance = pos.distance(ofPoint(ofGetWidth()/2, ofGetHeight()/2));
    soundAmp = (1.0 - distance/400.0)*0.2;
    if (soundAmp < 0) {
        soundAmp = 0;
    }
    sound.setVolume(soundAmp);
}
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
    centerImage.load("particle.png");
    
    center.fixture.filter.groupIndex = -1;
    center.setup(box2d.getWorld(), ofGetWidth()/2, ofGetHeight()/2, 1, 1);
}

//--------------------------------------------------------------
void ofApp::update(){
    box2d.update();
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    centerImage.draw(center.getPosition(), 100, 100);
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
