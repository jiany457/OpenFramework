//
//  particleA.hpp
//  ClassPractice
//
//  Created by Yujie Jiang on 10/20/17.
//


#pragma once

#include "ofMain.h"

class ParticleA{
public:
    ofPoint pos;
    float n; //angle
    
    ParticleA(){
        
    
        pos.x = ofRandom(1920);
        pos.y = ofRandom(1080);
        
        n = ofRandom(360);
        
    }
    void update(){
           n += ofRandom(0.01,0.08);
            pos.x = pos.x + cos(n)*10;
            pos.y  = pos.y + sin(n)*10;

            if (n>360){
                n = 0;
            }
    
    }
    
    void draw(){
        ofSetColor(sin(ofDegToRad(n))*600,cos(ofDegToRad(n))*300,150);
        ofFill();
            ofDrawCircle(pos.x,pos.y,5);
    }
};

