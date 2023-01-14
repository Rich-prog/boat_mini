#include "boat.h"

using namespace glm;

Boat::Boat() {

}

Boat::~Boat() {

}

//--------------------------------------------------------------
void Boat::setup() {
	model.loadModel("boatModel.dae", 20);
	model.setPosition(pos.x,pos.y,pos.z);
	model.setRotation(1, 180, 0, 0, 1);
}

//--------------------------------------------------------------
void Boat::draw() {
	//ofPushMatrix();
	//ofTranslate(pos.x, pos.y, pos.z);
	ofRotateYRad(rotation);
	model.drawFaces();
	//ofPopMatrix();
}

//--------------------------------------------------------------
void Boat::update() {
	//update rotation
	rotateVel += rotateAcc;
	rotation += rotateVel;
	//constrain the values
	rotateVel = ofClamp(rotateVel, -0.02, 0.02);

	//update velocty
	vel = vel + acc;
	vel.x = ofClamp(vel.x, -20, 20);
	vel.z = ofClamp(vel.z, -20, 20);
	//rotate velocity
	vec3 rotatedVec = rotate(vel, rotation, glm::vec3(0.0f, 1.0f, 0.0f));
	//update position
	pos = pos + rotatedVec;
}

/*
* void Boat::setSpacing(int* _spacing) {
	//spacing = *_spacing;
}
*/

/*
void Boat::calculateHeight(float* noiseRange, float* noiseHeight, int* spacing, int* width, int* height) {
	//calculate noise
	vec3 offsetPos = vec3(pos.x + (*spacing * *width/2), pos.y, pos.z + (*spacing * *height/2));
	float noiseX = ofMap(offsetPos.z / *spacing, 0, 100, 0, *noiseRange);
	float noiseZ = ofMap(offsetPos.x / *spacing, 0, 100, 0, *noiseRange);
	pos.y = ofNoise(noiseX, noiseZ) * *noiseHeight;
}


void Boat::calculateHeight(float noiseRange, float noiseHeight, int spacing, int width, int height) {
	//calculate noise
	vec3 offsetPos = vec3(pos.x + (spacing * width/2), pos.y, pos.z + (spacing * height/2));
	float noiseX = ofMap(offsetPos.z / spacing, 0, 100, 0, noiseRange);
	float noiseZ = ofMap(offsetPos.x / spacing, 0, 100, 0, noiseRange);
	pos.y = ofNoise(noiseX, noiseZ) * noiseHeight;
}
*/

