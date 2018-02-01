
#include "Sparkle.hpp"

// ---------------------------------------------------------
void Sparkle::setup(ofPoint _pos) {
    pos = _pos;
//    pos.x += ofRandom(-10, 10);
//    pos.y += ofRandom(-10, 10);
//    vel.x = ofRandom(-100, 100);
//    vel.y = ofRandom(-100, 100);
    color.set(0, 255, 255);
//    rNoise.x = ofRandomf();
//    rNoise.y = ofRandomf();
    acc.y = 9.8;
}

// ---------------------------------------------------------
void Sparkle::update(float deltaTime) {
//    vel += acc;
//    pos += vel * deltaTime;
   
//    vel *= friction;

    color.setHue(color.getHue() + (deltaTime * 30.0));

    radius = ofMap(ofNoise(rNoise), 0, 1, 1, 3);
    bounds.set(0, 0, ofGetWidth()+radius, ofGetHeight()+radius);
//    rNoise.y += 1;
}

// ---------------------------------------------------------
void Sparkle::draw() {
    ofSetColor(color);
    ofDrawRectangle(pos, radius,radius);
}

// ---------------------------------------------------------
bool Sparkle::outOfBounds() {
    return !bounds.inside(pos);
}
