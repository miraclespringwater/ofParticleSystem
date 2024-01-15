#include "particle.h"
#include "ofAppRunner.h"
#include "ofGraphics.h"
#include "ofMath.h"
#include "ofUtils.h"

particle::particle() {
}

void particle::setup() {
	pos.x = ofRandomWidth();
	pos.y = ofRandomHeight();

	vel.x = ofRandom(-4, 4);
	vel.y = ofRandom(-4, 4);

	frc = ofVec2f(0, 0); // no forces acting upon the particle at initialization

	uniqueVal.x = ofRandom(-1000, 1000);
	uniqueVal.y = ofRandom(-1000, 1000);

	size = ofRandom(3, 5);

	drag = ofRandom(0.97, 0.99);
}

void particle::update(float speed, float noise) {
	// This is where all of the velocity and force updates are happening

	// creating a "organic" force using ofSignedNoise ???
	frc.x = ofSignedNoise(uniqueVal.x, ofGetElapsedTimeMillis());
	frc.y = ofSignedNoise(uniqueVal.y, ofGetElapsedTimeMillis());

	frc *= noise;

	vel *= drag;

	vel += frc;

	// Reset at border

	if (pos.x + vel.x > ofGetWidth()) {
		pos.x -= ofGetWidth();
	} else if (pos.x + vel.x < 0) {
		pos.x += ofGetWidth();
	}

	if (pos.y + vel.y > ofGetWidth()) {
		pos.y -= ofGetHeight();
	} else if (pos.y + vel.y < 0) {
		pos.y += ofGetHeight();
	}

	pos += vel * speed;
}

void particle::draw(float sizeDot) {

	ofDrawCircle(pos.x, pos.y, size * sizeDot);
}
