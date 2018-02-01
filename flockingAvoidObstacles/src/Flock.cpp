
#include "Flock.hpp"
#include "ofMain.h"

void Flock::update() {
    for(int i=0; i<fish.size(); i++) {
        fish[i].update(fish);
    }
}

void Flock::draw() {
    for(int i=0; i<fish.size(); i++) {
        fish[i].draw();
    }
}

void Flock::addFish() {
    fish.push_back(Fish());
}

void Flock::addFish(int x, int y) {
    fish.push_back(Fish(x,y));
}
