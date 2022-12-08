#pragma once
#include "ofMain.h"

class ofApp : public ofBaseApp
{
public:
	void setup();
	void update();
	void draw();

private:
	void ofDrawDog(int x, int y, int size, int r, int g, int b);
	void ofSetdogColor();
	int windowWidth, windowHeight;
	int dogPosX, dogPosY, dogSize, dogVelocityX, dogVelocityY;
	int dogColorR, dogColorG, dogColorB;
};
