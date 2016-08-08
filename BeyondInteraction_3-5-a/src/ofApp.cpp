#include "ofApp.h"

//--------------------------------------------------------------
ofxBox2d                               box2d;   // the box2d world
vector   <shared_ptr<MyRect> > particles;
ofxBox2dRect center;
ofImage particleImage;
ofImage centerImage;
//--------------------------------------------------------------

//--------------------------------------------------------------

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
    
    for(int i=0; i<particles.size(); i++) {
        //Â∫ßÊ®ô„ÅÆÊõ¥Êñ∞
        particles[i]->update();
        //‰∏≠ÂøÉ„ÅÆÁâ©‰Ωì„Åã„Çâ„ÅÆÂºïÂäõ„ÇíË®àÁÆó
        particles[i]->addAttractionPoint(center.getPosition(), 0.1);
        //ÂÖ®„Å¶„ÅÆ„Éë„Éº„ÉÜ„Ç£„ÇØ„É´ÂêåÂ£´„ÅÆÂºïÂäõ„ÇíË®àÁÆó
        for (int j = i + 1; j < particles.size(); j++) {
            particles[j]->addAttractionPoint(particles[i]->getPosition(), 0.001);
        }
    }
    
    center.setPosition(ofGetWidth()/2, ofGetHeight()/2);
}

//--------------------------------------------------------------
void ofApp::draw(){
    //„Éë„Éº„ÉÜ„Ç£„ÇØ„É´ÂêåÂ£´„ÇíÁµê„Å∂Á∑ö„ÇíÊèè„Åè
    for(int i=0; i<particles.size(); i++) {
        //„Éë„Éº„ÉÜ„Ç£„ÇØ„É´„ÅÆ‰ΩçÁΩÆ„ÇíÂèñÂæó
        ofVec2f p1 (particles[i]->getPosition());
        //ÂÖ®„Å¶„ÅÆ„Éë„Éº„ÉÜ„Ç£„ÇØ„É´Èñì„ÅÆË∑ùÈõ¢„ÇíÁÆóÂá∫
        for (int j = i + 1; j < particles.size(); j++) {
            ofVec2f p2 (particles[j]->getPosition());
            float dist = p2.distance(p1);
            //Ë∑ùÈõ¢„Åå300„Éî„ÇØ„Çª„É´‰ª•ÂÜÖ„Å†„Å£„Åü„Çâ„ÄÅÁ∑ö„ÇíÊèè„Åè
            if (dist < 600) {
                int col = (600 - dist);
                ofSetColor(255, 255, 255, col);
                ofDrawLine(p1.x, p1.y, p2.x, p2.y);
            }
        }
    }
    for(int i=0; i<particles.size(); i++){
        ofVec2f p1 (particles[i]->getPosition());
        ofVec2f p2 (center.getPosition());
        float dist = p2.distance(p1);
        if (dist < 600) {
            int col = (600 - dist);
            ofSetColor(255, 255, 255, col);
            ofDrawLine(p1.x, p1.y, p2.x, p2.y);
        }
    }
    ofSetColor(255, 255, 255);
    for(int i=0; i<particles.size(); i++) {
        //ÂçäÂæÑ„ÇíË®àÁÆó
        float radius = particles[i]->radius;
        //ÁîªÂÉè„ÇíÈÖçÁΩÆ
        particleImage.draw(particles[i]->getPosition() - radius / 2.0, radius, radius);
    }
    
    //Èü≥Èáè„ÅÆÂêàË®à„ÇíÁÆóÂá∫
    float allAmp = 0;
    for (int i = 0; i < particles.size(); i++) {
        allAmp += particles[i]->soundAmp;
    }
    float centerRadius = sin(ofGetElapsedTimef() * 100.0) * allAmp * 20.0 + allAmp * 40.0 + 40.0;
    ofVec2f offset(centerRadius, centerRadius);
    centerImage.draw(center.getPosition() - offset * 2, centerRadius * 4.0, centerRadius * 4.0);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 'c') {
        for (int i = 0; i < particles.size(); i++) {
            particles[i]->destroy();
        }
        particles.clear();
    }
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
    particles.push_back(shared_ptr<MyRect>(new MyRect(particles.size())));
    particles.back().get()->setPhysics(10.0, 0.1, 0.5);
    particles.back().get()->fixture.filter.groupIndex = -1;
    particles.back().get()->setup(box2d.getWorld(), mouseX, mouseY, 10, 10);
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
