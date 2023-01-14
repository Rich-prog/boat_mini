#pragma once
#include "ofMain.h"

class Crate {
public:
	Crate();
	~Crate();

	void setup();
	void draw();
	void update();
	void setPosition(int range);

	glm::vec3 pos;

private:
	ofBoxPrimitive body;
};