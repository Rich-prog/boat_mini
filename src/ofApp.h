#pragma once

#include "ofMain.h"
#include "boat.h"
#include "crate.h"
#include "waveMesh.h"
#include "vector"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
		bool checkBounds(vec3 a, vec3 b, float distance);

		Boat boat;
		//Crate crate;

		ofEasyCam cam;
		vec3 cameraPos;
		ofLight light;

		vector<Crate> boxes;

		WaveMesh ocean;
};
