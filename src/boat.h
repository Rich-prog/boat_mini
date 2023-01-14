#pragma once
#include "ofMain.h"
#include "ofxAssimpModelLoader.h"

using namespace glm;

class Boat {
public:
	Boat();
	~Boat();

	void setup();
	void draw();
	void update();

	vec3 pos = vec3(0.0, 0.0, 0.0);
	vec3 acc = vec3(0.0, 0.0, 0.0);
	float rotateAcc = 0;

private:
	ofxAssimpModelLoader model;
	
	
	vec3 vel = vec3(0.0, 0.0, 0.0);
	
	float rotateVel = 0.0;
	float rotation = 0.0;
};