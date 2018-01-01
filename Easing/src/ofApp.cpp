#include "ofApp.h"
// Primitives: float, int, bool, char
//Objects


//float xPos;
//float yPos; //the position of the circles
//float xMouseClick;
//float yMouseClick; // the target, where the mouse click, where you want it to be

//ofMesh (anything with 3D shape), ofCamera, etc.
ofColor mybackground;
ofPoint pos; //ofPoint, anything is x,y,z
ofPoint MouseClick;



//--------------------------------------------------------------
void ofApp::setup(){
    pos.x = ofGetWindowWidth()/2;
    pos.y = ofGetWindowHeight()/2;
    
    mybackground.r = 100;
    mybackground.g = 50;
    mybackground.b = 3;
    // OR mybackground.setHsb(random(255),255,255); //hue,satuation,brightness
    
    ofSetBackgroundColor(mybackground);
    
//    MouseClick.x = pos.x;
//    MouseClick.y = pos.y;
    MouseClick = pos; //does the same thing as above
}

//--------------------------------------------------------------
void ofApp::update(){
//    //change xPos so that it's closer to xMouseClick
//    if(xPos > xMouseClick){
//        xPos-=4;
//    }
//    if(xPos<xMouseClick){
//        xPos+=4;
//    }
//
//    if(yPos > yMouseClick){
//        yPos-=4;
//    }
//    if(yPos<yMouseClick){
//        yPos+=4;
//    }
    
 //IMPORTANT!!!!!!
//    float xDist = MouseClick.x - pos.x; //distance from mouse and the circle
//    float xStep = xDist/10.0;
//    pos.x = pos.x + xStep;
//
//    float yDist = MouseClick.y - pos.y;
//    float yStep = yDist/10.0;
//    pos.y = pos.y + yStep; //xStep = speed
    
    //A more simple way to do above;
//    ofPoint dist = MouseClick - pos;
//    ofPoint step = dist/10.0;
//    pos = pos + step;
    
    //A even more simple way:
    ofSetBackgroundAuto(false);
    pos = pos + (MouseClick - pos)/10.0; //pos += ((MouseClick - pos)/10.0)
    // "10.0" means take 10 steps to reach the point, if I set it as "1", then it takes one step to reach the target (much faster), ".0" defines the number as not a variable.
    //Anytime you do not want loose position, and you're doing a math, you need to put .0 after a number. e.g., 2.0
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(0,0,0);
//    ofDrawCircle(xPos, yPos, 30);
    ofDrawCircle(pos, 30);
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
//    xPos = x;
//    yPos = y;
    MouseClick.x = x;
    MouseClick.y = y;
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
