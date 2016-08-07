#pragma once

#include "ofMain.h"
#include "ofxBox2d.h"

class MyRect : public ofxBox2dRect {
public:
    MyRect(int _num){
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
    };
    void update(){
        radius = sin(ofGetElapsedTimef() * 10.0 * soundLfo) * 40 + 80;
        ofVec2f pos = getPosition();
        float distance = pos.distance(ofPoint(ofGetWidth()/2, ofGetHeight()/2));
        soundAmp = (1.0 - distance/400.0)*0.2;
        if (soundAmp < 0) {
            soundAmp = 0;
        }
        sound.setVolume(soundAmp);
    };
    
    int num;
    float radius;
    ofSoundPlayer sound;
    float soundSpeed;
    float soundAmp;
    float soundLfo;
};

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
};
