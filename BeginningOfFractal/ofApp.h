#pragma once

#include "ofMain.h"

class Path {
public:
    float x1, y1;
    float x2, y2;
    float noiseSeed1 = ofRandom(10);
    float noiseSeed2 = ofRandom(10);
    float length;
    double degree = ofRandom(120);
    double radian;
    
    int parent;
    int generation;
    float alph;
    
    Path(float x, float y, int parent_, int generation_);
    void update(float x, float y);
    void drawLine();
    void drawCircle();
};

class ofApp : public ofBaseApp {
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y);
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    void makeChildren();
};
