
#ifndef Flock_hpp
#define Flock_hpp

#pragma once

#include "ofMain.h"
#include "Fish.hpp"

class Flock {
public:
    void update();
    void draw();
    void addFish();
    void addFish(int x, int y);
    
    vector<Fish> fish;
};

#endif
