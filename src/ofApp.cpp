#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	ofDisableAlphaBlending();
	ofEnableDepthTest();

	boat.setup();
	ocean.setup();
	cam.setDistance(1200);
	
	for (int i = 0; i < 10; i++) {
		Crate tempbox;
		tempbox.setPosition(5000);
		boxes.push_back(tempbox);
	}
}

//--------------------------------------------------------------
void ofApp::update(){
	
	//apply physics
	boat.update();
	ocean.setObjectHeight(&boat.pos.x , &boat.pos.y, &boat.pos.z);
	
	ocean.setTarget(&boat.pos); //move ocean to position of the boat
	ocean.update();

	//move position of camera
	cameraPos.x = ofLerp(cameraPos.x, boat.pos.x, 0.05);
	cameraPos.z = ofLerp(cameraPos.z, boat.pos.z + 2000, 0.05);
	cameraPos.y = ofLerp(cameraPos.y, boat.pos.y + 500, 0.05);
	cam.setPosition(cameraPos);
	cam.setTarget(boat.pos);

	//when boat collides with box, change its position
	for (int i = 0; i < boxes.size(); i++) {
		ocean.setObjectHeight(&boxes[i].pos.x, &boxes[i].pos.y, &boxes[i].pos.z);

		bool collision = checkBounds(boat.pos, boxes[i].pos, 400);
		if (collision){ 
			boxes[i].setPosition(5000);
		}	
	}

	//get framerate
	std::stringstream strm;
	strm << "fps: " << ofGetFrameRate();
	ofSetWindowTitle(strm.str());
}

//--------------------------------------------------------------
void ofApp::draw(){
	
	cam.begin();
	
	//debug grid
	ofDrawGrid(5000, 5, true, false, true, false);

	//translate to position of the boat
	ofPushMatrix();
	ofTranslate(boat.pos.x, 0, boat.pos.z);
	ocean.draw();
	ofPopMatrix();

	//translate to position of boat, rotated
	ofPushMatrix();
	ofTranslate(boat.pos.x, boat.pos.y, boat.pos.z);
	boat.draw();
	ofPopMatrix();

	for (int i = 0; i < boxes.size(); i++) {
		boxes[i].draw();
	}

	cam.end();
}

bool ofApp::checkBounds(vec3 a, vec3 b, float distance) {
	if (a.x < b.x - distance) return false;
	if (a.y < b.y - distance) return false;
	if (a.z < b.z - distance) return false;

	if (a.x > b.x + distance) return false;
	if (a.y > b.y + distance) return false;
	if (a.z > b.z + distance) return false;

	std::cout << "COLLIDED" << std::endl;
	return true;
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == 'w' || key == OF_KEY_UP)    boat.acc.x = 0.2;
	if (key == 'd' || key == OF_KEY_RIGHT) boat.rotateAcc = -0.0005;
	if (key == 's' || key == OF_KEY_DOWN)  boat.acc.x = -0.05;
	if (key == 'a' || key == OF_KEY_LEFT)  boat.rotateAcc = +0.0005;
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	if (key == 'w' || key == OF_KEY_UP)    boat.acc.x = 0.0;
	if (key == 'd' || key == OF_KEY_RIGHT) boat.rotateAcc = 0.0;
	if (key == 's' || key == OF_KEY_DOWN)  boat.acc.x = 0.0;
	if (key == 'a' || key == OF_KEY_LEFT)  boat.rotateAcc = 0.0;
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

