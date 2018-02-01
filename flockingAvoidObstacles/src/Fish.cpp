
#include "Fish.hpp"

Fish::Fish() {
     ofEnableNormalizedTexCoords();
    loc.set(ofGetWidth()/2.0+ofRandom(-50,50),ofGetHeight()/2.0+ofRandom(-50,50));
    vel.set(0,0);
    acc.set(0,0);
    r = 5.0;
    maxspeed = 4;
    maxforce = 0.1;

   
}

Fish::Fish(int x, int y) {
//     ofEnableNormalizedTexCoords();
    loc.set(ofGetWidth()/2.0+ofRandom(-50,50),ofGetHeight()/2.0+ofRandom(-50,50));
    vel.set(0,0);
    acc.set(0,0);
    r = 5.0;
    maxspeed = 4;
    maxforce = 0.1;

   
}

// Method to update location
void Fish::update(vector<Fish> &fish) {
    
    this->flock(fish);
    
    // after flock(), acc is set based on 3 rules
    
    vel += acc;   // Update velocity
    vel.x = ofClamp(vel.x, -maxspeed, maxspeed);  // Limit speed
    vel.y = ofClamp(vel.y, -maxspeed, maxspeed);  // Limit speed
    loc += vel;
    acc.set(0,0);
    
    if (loc.x < -r) loc.x = ofGetWidth()+r;
    if (loc.y < -r) loc.y = ofGetHeight()+r;

    if (loc.x > ofGetWidth()+r) loc.x = -r;
    if (loc.y > ofGetHeight()+r) loc.y = -r;
}

void Fish::seek(ofVec2f target) {
    acc += steer(target, false);
}

void Fish::avoid(ofVec2f target) {
    acc -= steer(target, false);
}

void Fish::arrive(ofVec2f target) {
    acc += steer(target, true);
}

// A method that calculates a steering vector towards a target
// Takes a second argument, if true, it slows down as it approaches the target
ofVec2f Fish::steer(ofVec2f target, bool slowdown) {
    ofVec2f steer;  // The steering vector
    ofVec2f desired = target - loc;  // A vector pointing from the location to the target
    
    float d = ofDist(target.x, target.y, loc.x, loc.y); // Distance from the target is the magnitude of the vector
    
    
    // If the distance is greater than 0, calc steering (otherwise return zero vector)
    if (d > 0) {
        
        desired /= d; // Normalize desired
        // Two options for desired vector magnitude (1 -- based on distance, 2 -- maxspeed)
        if ((slowdown) && (d < 50.0)) {
            desired *= maxspeed * (d/50.0f);
        } else {
            desired *= maxspeed;
        }
        // Steering = Desired minus Velocity
        steer = desired - vel;
        steer.x = ofClamp(steer.x, -maxforce, maxforce); // Limit to maximum steering force
        steer.y = ofClamp(steer.y, -maxforce, maxforce);
        
    }
    return steer;
}

void Fish::draw() {
    // Draw a triangle rotated in the direction of velocity
    float angle = (float)atan2(-vel.y, vel.x);
    float theta =  -1.0*angle;
    float heading2D = ofRadToDeg(theta)+90;
    
  

    ofPushStyle();
    ofPushMatrix();
    ofTranslate(loc.x, loc.y);
    ofRotateZ(heading2D);
    ofSetColor(27+ofRandom(-20,20),168+ofRandom(-20,20),190+ofRandom(-20,20));
    ofFill();
    ofDrawCircle(loc.x, loc.y, r);
   
    ofPopMatrix();
    ofPopStyle();

    
  
}

void Fish::flock(vector<Fish> &fish) {
    ofVec2f sep = separate(fish);
    ofVec2f ali = align(fish);
    ofVec2f coh = cohesion(fish);
    
    // Arbitrarily weight these forces
    sep *= 1.5;
    ali *= 1.0;
    coh *= 0.1;
    
    acc += sep + ali + coh;
}

// Separation
// Method checks for nearby boids and steers away
ofVec2f Fish::separate(vector<Fish> &fish) {
    float desiredseparation = 50.0f;
    ofVec2f steer;
    int count = 0;
    
    // For every boid in the system, check if it's too close
    for (int i = 0 ; i < fish.size(); i++) {
        Fish &other = fish[i];
        
        float d = ofDist(loc.x, loc.y, other.loc.x, other.loc.y);
        
        // If the distance is greater than 0 and less than an arbitrary amount (0 when you are yourself)
        if ((d > 0) && (d < desiredseparation)) {
            // Calculate vector pointing away from neighbor
            ofVec2f diff = loc - other.loc;
            diff /= d;            // normalize
            diff /= d;        // Weight by distance
            steer += diff;
            count++;            // Keep track of how many
        }
    }
    // Average -- divide by how many
    if (count > 0) {
        steer /= (float)count;
    }
    
    // As long as the vector is greater than 0
    //float mag = sqrt(steer.x*steer.x + steer.y*steer.y);
    
    float mag = sqrt(steer.x*steer.x + steer.y*steer.y);
    if (mag > 0) {
        // Implement Reynolds: Steering = Desired - Velocity
        steer /= mag;
        steer *= maxspeed;
        steer -= vel;
        steer.x = ofClamp(steer.x, -maxforce, maxforce);
        steer.y = ofClamp(steer.y, -maxforce, maxforce);
    }
    return steer;
}

// Alignment
// For every nearby boid in the system, calculate the average velocity
ofVec2f Fish::align(vector<Fish> &fish) {
    float neighbordist = 50.0;
    ofVec2f steer;
    int count = 0;
    for (int i = 0 ; i < fish.size(); i++) {
        Fish &other = fish[i];
        
        float d = ofDist(loc.x, loc.y, other.loc.x, other.loc.y);
        if ((d > 0) && (d < neighbordist)) {
            steer += (other.vel);
            count++;
        }
    }
    if (count > 0) {
        steer /= (float)count;
    }
    
    // As long as the vector is greater than 0
    float mag = sqrt(steer.x*steer.x + steer.y*steer.y);
    if (mag > 0) {
        // Implement Reynolds: Steering = Desired - Velocity
        steer /= mag;
        steer *= maxspeed;
        steer -= vel;
        steer.x = ofClamp(steer.x, -maxforce, maxforce);
        steer.y = ofClamp(steer.y, -maxforce, maxforce);
    }
    return steer;
}

// Cohesion
// For the average location (i.e. center) of all nearby boids, calculate steering vector towards that location
ofVec2f Fish::cohesion(vector<Fish> &fish) {
    float neighbordist = 50.0;
    ofVec2f sum;   // Start with empty vector to accumulate all locations
    int count = 0;
    for (int i = 0 ; i < fish.size(); i++) {
        Fish &other = fish[i];
        float d = ofDist(loc.x, loc.y, other.loc.x, other.loc.y);
        if ((d > 0) && (d < neighbordist)) {
            sum += other.loc; // Add location
            count++;
        }
    }
    if (count > 0) {
        sum /= (float)count;
        return steer(sum, false);  // Steer towards the location
    }
    return sum;
}
