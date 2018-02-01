#include "ofApp.h"


//sys2:
//ofPoint fall[NUM_FALL];
//int j;
//
//float d;

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowShape(1920, 1080);
    ofBackground(0);
    ofEnableSmoothing();
    ofSetWindowTitle("connection");
    
//     Particle system 1;
    for(int i=0;i<50;i++){
        particleA[i] = ParticleA();
    }
    
    //Particle system 2;
    for(int i=0;i<50;i++){
        particleB[i] = ParticleB();
    }
    
       
}

//--------------------------------------------------------------
void ofApp::update(){
    //sys1:
    for(int i=0;i<50;i++){
        particleA[i].update();
    }
    
    for(int i=0;i<50;i++){
        particleB[i].update();
    }
}
    

//--------------------------------------------------------------
void ofApp::draw(){

    for(int i=0;i<50;i++){
        particleA[i].draw();
    }
    
    for(int i=0;i<50;i++){
        particleB[i].draw();
    }
    
    //sys2:
//    ofSetColor(235,182,148);
//    ofNoFill();
//    for(int j=0; j<NUM_FALL; j++){
//        ofDrawRectangle(fall[j].x,fall[j].y, 30, 30);
//    }
//
    //connection
//    for(int i=0;i<50;i++){
//        for(int j=0; j<30; j++){
//
//            if(((pos[i].x-fall[j].x)<=0.3 && (pos[i].x-fall[j].x)>-0.3)||((pos[i].y-fall[j].y)<=0.3&&(pos[i].y-fall[j].y)>-0.3)){
//                ofDrawLine(pos[i].x, pos[i].y,fall[j].x, fall[j].y);
//            }
//        }
//    }
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
