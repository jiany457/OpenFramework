#include "ofApp.h"

//--------------------------------------------------------------

bool isMouseMoving() {

    static ofPoint pmouse;
    ofPoint mouse(ofGetMouseX(),ofGetMouseY());
    bool mouseIsMoving = (mouse!=pmouse);
    pmouse = mouse;
    return mouseIsMoving;
}

void ofApp::setup(){
//    ofBackground(0,0,0);
//    ofSetFrameRate(60);
    serial.setup(0,9600);
    
    //General
    ofSetWindowShape(800, 800);
    //    ofSetFullscreen(true);
    
    //Gui Controller
    gui.setup();
    gui.add(info1.setup("waves", 2.75, 0, 10));
    gui.add(info2.setup("height", 0, 0, 10));
    gui.add(info3.setup("wake speed", 1, 0, 10));
    gui.add(diam.setup("diameter", 13, 10, 100));
    gui.add(hueWave.setup("wave Hue", 141, 0, 255));
    gui.add(satWave.setup("wave Saturation", 153, 0, 255));
    gui.add(balWave.setup("wave Balance", 255, 0, 255));
    //    gui.add(drainSpeed.setup("drain speed", 0, 0, ofGetWindowHeight()));
    
    //    audio.loadSound("faucet.mp3");
    
    //Wave
    t=0;

    theSand.load("sand.jpg");
    over.load("gameover.png");
    
    //Potentiometer
    waveBegin = ofGetWindowHeight()-(ofGetWindowHeight()*0.9);
    alpha = 0;
    
    
    for(int i=0; i<100; i++) {
        float x = ofRandom(-50, 50+(ofGetWidth()/5));
        float y = ofRandom(-50, 50+(ofGetHeight()/5));

        flock.addFish(x, y);

    }
}

//--------------------------------------------------------------
void ofApp::update(){
    while(serial.available()) {
        char b = serial.readByte();
        
        if (b=='\n') {
            radius = ofToInt(buffer);
            buffer = "";
        } else {
            buffer += b;
        }
    }
    //
    //    cout << radius << endl;
    //
    //Wave
    diameter = ofGetWindowWidth()*diam/800;
    d = ofGetWindowWidth()*(diam*18/30)/800;
    
    slider1 = ofGetWindowWidth()*info1/800;
    slider2 = ofGetWindowWidth()*info2/800;
    slider3 = ofGetWindowWidth()*info3/800;
    
    t++;
    
    
    waveSpeed = ofMap(mouseX, 0, ofGetWindowWidth(), 0, 4);
    waveBegin += waveSpeed;
    
    alpha += waveSpeed;
    
    cout << waveBegin <<endl;
    
    if (isMouseMoving()) {
        for(int i=0; i<flock.fish.size(); i++) {
            flock.fish[i].avoid(ofPoint(mouseX,mouseY));
//            flock.boids[i].avoid(ofPoint(800,500));

           
        }
    }
    flock.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
     background.draw(0,0);
    flock.draw();
    waveCol.setHsb(hueWave, satWave, balWave);
    ofSetColor(waveCol);
    
    
    freq = ofMap(slider1,1,10,0.3,3);
    ampl = ofMap(slider2,1,10, ofGetWindowHeight()/10, ofGetWindowHeight()/2);
    n = ofGetWindowWidth()/d;
    offset = t * ofMap(slider3,1,10,0.01,0.05);
    
    
    
    
    if(waveBegin>ofGetWindowHeight()+80){
        ofBackground(0,38,53);
        over.draw((ofGetWindowWidth()/2)-400,(ofGetWindowHeight()/2)-400,800,800);
    }
    
    if(waveSpeed>=2){
        //        audio.play();
    }
    
    //SAND//
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2.0, ofGetHeight()/2.0);
    
    //    ofRotateX(rot.x);
    //    ofRotateY(rot.y);
    
    for(int y=0; y<theSand.getHeight(); y++)
    {
        for(int x=0; x<theSand.getWidth(); x++)
        {
            ofColor c = theSand.getColor(x, y);
            if(c.a > 0)
            {
                float b = c.getBrightness();
                float z = ofMap(b, 0, 255, -100, 100);
                ofSetColor(c,alpha);
                
                float _x = x - (theSand.getWidth()/2.0);
                float _y = y - (theSand.getHeight()/2.0);
                ofDrawRectangle(_x, _y, z, 1, 1);
            }
        }
    }
    ofPopMatrix();
      gui.draw();
   
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 'r'){
        waveBegin = ofGetWindowHeight()-(ofGetWindowHeight()*0.9);
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
  mX = x;
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
//    flock.addBoid(x,y);
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
