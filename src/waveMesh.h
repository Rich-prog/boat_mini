#include "ofMain.h"
#include "ofxGUI.h"

class WaveMesh
{
public:
	WaveMesh();
	~WaveMesh();
	void setup();
	void draw();
	void update();
	
	void setTarget(glm::vec3* _target);
	void setObjectHeight(float* x, float* y, float* z);
	
	int spacing = 50;

private:
	float time;
	float noiseRange = 5, noiseHeight = 200;
	int width = 100, height = 100;

	float noiseScale = 0.001;

	of3dPrimitive surface;
	ofMaterial material;

	glm::vec3 currentPos;
	
	glm::vec3 target;

};