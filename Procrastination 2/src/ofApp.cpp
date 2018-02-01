#include "ofApp.h"
int xPos;
int yPos;

int xTime[] = {0,240,480,720,960,1200,1440,1680,1920};
int yTime[] = {0,120,240,360,480,600,720,840,960,1080};

float x;
float y;
int ra;
int n;


int r,g,b,r1,g1,b1;
ofColor colorOne, colorTwo;

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofSetWindowShape(1920, 1080);
    xPos = 550;
    yPos = 200;
    
    r =236;
    g = 149;
    b = 45;
    
    n=0;
    
    ra=350;

ofEnableSmoothing();
    
    ofColor colorOne(r, g, b);
    ofColor colorTwo(r1, g1, b1);
}

//--------------------------------------------------------------
void ofApp::update(){
 yPos++;
    
    n+=yPos*0.01;
    x = 700 + cos(ofDegToRad(n))*ra;
    y = 400 + sin(ofDegToRad(n))*ra;
    if(n>360){
        n=0;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    
//        ofColor colorOne(r--, g--, b);
//        ofColor colorTwo(r1--, g1--, b1);
//        ofBackgroundGradient(colorOne, colorTwo, OF_GRADIENT_LINEAR);
        // Sets the background to a linear gradient
    

    
    if (yPos>500){
        r+=5;
        g-=5;
        b-=50;
    }else{
        r =236;
        g = 149;
        b = 45;
//        r =242;
//        g = 189;
//        b = 174;
    }
    
    ofSetColor(r,g,b);
    ofFill();
    for(int i=9; i>=0;i--){
        for(int j=0; j<11; j++){
            ofDrawRectangle (xTime[i]+200,yTime[j],xTime[i]-600+ofRandom(100,800),yTime[j]-500);
            ofDrawRectangle(xTime[i]+ofRandom(5,100),yTime[j],ofRandom(50,100),yTime[j]+60-500);
            xTime[i] -=2;
            
            if(xTime[i]<-5){
                xTime[i] = + 1920;
            }
        }
    }
 
    //Paper
    ofSetColor(255);
    ofDrawRectangle(500, 130, 400, 550);//How to code directly in the center?
    
    //pen/Triangle
    ofSetColor(0);
//    ofNoFill();
//    ofSetLineWidth(2);
    ofDrawTriangle(xPos, yPos, xPos-10,yPos+30, xPos+10,yPos+30);
//    ofDrawRectangle(xPos-5, yPos+22, 10, 5);
//    ofDrawRectangle(xPos-5,yPos+29,10,40);
    
    //timeLoop
    ofSetCircleResolution(100);
    ofSetColor(255);
    ofNoFill();
    ofDrawCircle(700, 400, 350);
    ofFill();
    ofDrawCircle(x, y, 10);
   
    
    
    
    //get triangle to stay:
    //if (at the pos you want){
    // state = true
    //if (state = true){
    //draw circle
    
//    if(yPos<150 && yPos>120 && state ==false){
//        ofDrawCircle(xPos, yPos, 10);
//        state == true;
//    } else if(yPos>150 && yPos<120 && state ==true){
//        ofDrawCircle(xPos, yPos, 10);
//    }
    
    ofSetColor(0);
    ofFill;
    if(yPos<180 && xPos==550){
           ofDrawCircle(550,180,20);
    }
//    if (state == 1||state ==2||state == 3 || state==4){
//        ofDrawCircle(550,180,10);
////    }
////        if (xPos<580 && xPos>550 && state == 1){
////            state = 2;
////        }
////        if(state==2||state == 3 || state==4){
////            ofDrawCircle(570,180,10);
////        }
////        if (xPos<600 && xPos>570 && state == 2){
////            state = 3;
////        }
////        if(state == 3 || state==4){
////    ofDrawCircle(590,180,10);
////        }

    //flashing typing line
    
//到位打字
    //    if(xPos == 550 && yPos <200&&step ==0){
//        ofSetColor(0);
//        ofDrawCircle(570, 200, 20)
//    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if(yPos<=500){
    if (key == OF_KEY_UP){
        yPos-=20;
        //            speed--;
    }
    }
    
    if(yPos>500){
        if (key == OF_KEY_UP){
        yPos-=10;
    }
    }
    
    if(yPos>600){
        if (key == OF_KEY_UP){
        yPos-=5;
        }
    }
    
    if(yPos>700){
        if (key == OF_KEY_UP){
        yPos-=3;
    }
    }
    
    if(key == OF_KEY_RIGHT){
        xPos+=20;
    }
    if(key == OF_KEY_LEFT){
        xPos-=20;
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
