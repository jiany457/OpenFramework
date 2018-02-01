

#ifndef Fish_hpp
#define Fish_hpp

#include <ofMain.h>

class Fish {
public:
    Fish();
    Fish(int x, int y);
    
    void update(vector<Fish> &fish);
    void draw();
    
    void seek(ofVec2f target);
    void avoid(ofVec2f target);
    void arrive(ofVec2f target);
    
    void flock(vector<Fish> &fish);
    
    ofVec2f steer(ofVec2f target, bool slowdown);
    
    ofVec2f separate(vector<Fish> &fish);
    ofVec2f align(vector<Fish> &fish);
    ofVec2f cohesion(vector<Fish> &fish);
    
    ofVec2f loc,vel,acc;
    
    float r;
    float maxforce;
    float maxspeed;
 
};

#endif
