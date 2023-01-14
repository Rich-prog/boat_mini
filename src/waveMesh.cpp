#include "waveMesh.h"

using namespace glm;

//contructor
WaveMesh::WaveMesh()
{

}

//destructor
WaveMesh::~WaveMesh()
{

}

//-----------------------------------------------------
void WaveMesh::setup()
{
	//create a vertex grid
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {

			int xPos = i * spacing;
			int yPos = j * spacing;
			vec3 position = vec3(xPos, 0, yPos);
			surface.getMesh().addVertex(position);
			surface.getMesh().addColor(ofColor(0, 255, 0));
		}
	}

	//triangulate faces
	for (int x = 0; x < width - 1; x++) {
		for (int y = 0; y < height - 1; y++) {
			surface.getMesh().addIndex(x + y * width);
			surface.getMesh().addIndex((x + 1) + y * width);
			surface.getMesh().addIndex(x + (y + 1) * width);

			surface.getMesh().addIndex((x + 1) + y * width);
			surface.getMesh().addIndex((x + 1) + (y + 1) * width);
			surface.getMesh().addIndex(x + (y + 1) * width);
		}
	}

	//reposition surface
	surface.setPosition(-width * spacing / 2 + (spacing / 2), 0, -height * spacing / 2 + (spacing / 2));

	//set colours
	material.setDiffuseColor(ofColor(255, 255, 255));
	material.setShininess(1);
}

//-----------------------------------------------------
//draw the ocean object
void WaveMesh::draw()
{
	surface.draw();
	//surface.drawVertices();
	//surface.drawWireframe();
}

//-----------------------------------------------------
void WaveMesh::update()
{
	time = ofGetSystemTimeMillis() / 200.0;
	//set constraints of the waves

	int i = 0;
	vec3 vert;
	float noiseX, noiseZ;
	int h, s, b, a;
	ofColor color;

	for (int z = 0; z < height; z++) {
		for (int x = 0; x < width; x++) {
			
			vert = surface.getMesh().getVertex(i);
	
			//calculate noise
			noiseX = ofMap(x + (target.z/spacing), 0, width,  0, noiseRange);
			noiseZ = ofMap(z + (target.x/spacing) + time, 0, height, 0, noiseRange);
			vert.y = ofNoise(noiseX, noiseZ) * noiseHeight;

			//apply noise
			surface.getMesh().setVertex(i, vert);

			//calculate colour
			h = 100;
			s = 255;
			b = ofMap(vert.y, 0, noiseHeight, 0, 255);
			a = 255;

			//apply colour
			color.setHsb(h, s, b, a);
			surface.getMesh().setColor(i,color);
			i++;
		}
	}
}

//-----------------------------------------------------
void WaveMesh::setObjectHeight(float* x, float* y, float* z) {

	//calculate noise
	vec3 offsetPos = vec3(*x + (spacing * width / 2), *y, *z + (spacing * height / 2));
	float noiseX = ofMap(offsetPos.z / spacing, 0, 100, 0, noiseRange);
	float noiseZ = ofMap(offsetPos.x / spacing + time, 0, 100, 0, noiseRange);
	*y = ofNoise(noiseX, noiseZ) * noiseHeight;
}

void WaveMesh::setTarget(glm::vec3* _target) {
	target = *_target;
};