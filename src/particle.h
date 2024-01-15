#pragma once
#include "ofMain.h"
#include "ofVec2f.h"

class particle {
public:
	particle();

	void setup();
	void update(float speed, float noise);
	void draw(float sizeDot); // take in the size of the particle

	ofVec2f pos; // vector for the position of the particle
	ofVec2f vel; // vector for the velocity of the particle (the overall direction)
	ofVec2f frc; // vector for all additional forces that influences the particle
	float drag; // counteracts the overall speed

	ofVec2f uniqueVal; // every particle will have a unique value, this value will influence the "noise"
	float size; // size of the particle
};
