#include "crate.h"
#include "iostream"

Crate::Crate() {
	std::cout << "Contructed Crate" << std::endl;
}

Crate:: ~Crate() {

}

//-----------------------------------------------------
void Crate::setup() {
	
	//body.setPosition(500,0,500);
}

//-----------------------------------------------------
void Crate::draw() {
	ofPushMatrix();
	ofTranslate(pos);
	body.drawFaces();
	ofPopMatrix();
}

//-----------------------------------------------------
void Crate::update() {

}

void Crate::setPosition(int range) {
	int x = ofRandom(-range, range);
	int z = ofRandom(-range, range);
	pos = glm::vec3(x, 100, z);
}