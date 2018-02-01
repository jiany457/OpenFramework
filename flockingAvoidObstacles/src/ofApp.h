#pragma once

#include "ofMain.h"
#include "Flock.hpp"
#include "ofxGui.h"

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
		ofImage background;

    Flock flock;
    
    ofSerial serial;
    string buffer;
    int radius;
    
    float diameter;
    float d = 30;
    float t=0;
    float slider1;
    float slider2;
    float slider3;
    float freq;
    float ampl;
    float n;
    float offset;
    float mX;
    float imageW;
    float imageH;
    
    float alpha;
    float waveBegin;
    float waveSpeed;
    float wavePos;
    
    float Height = ofGetWindowHeight();
    float Width = ofGetWindowWidth();
    
    ofxPanel gui;
    ofxFloatSlider info1;
    ofxFloatSlider info2;
    ofxIntSlider info3;
    ofxIntSlider diam;
    ofxIntSlider hueWave;
    ofxIntSlider satWave;
    ofxIntSlider balWave;
    ofxFloatSlider drainSpeed;
    
    ofColor waveCol;
    
    ofImage aridImage;
    ofImage over;
    ofImage theSand;
    
    ofSoundPlayer audio;
    ofColor myColor;
    
    
};


