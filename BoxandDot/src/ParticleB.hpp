//
//  particleB.hpp
//  ClassPractice
//
//  Created by Yujie Jiang on 10/20/17.
//


#pragma once

#include "ofMain.h"

class ParticleB{
    
public:

    
    ofPoint fall;
    
    ParticleB(){
            fall.x = ofRandom(1920);
            fall.y = ofRandom(1080);
        
    }
    
    void update(){
        fall += 5;
        if(fall.y>1080){
            fall.y=0;
        }
        if(fall.x>1920){
            fall.x=0;
        }
    
    }
    
    void draw(){
        ofSetColor(235,182,148);
        ofNoFill();
        ofDrawRectangle(fall.x,fall.y, 30, 30);
    
    }
};
