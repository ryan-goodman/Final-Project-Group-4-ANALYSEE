#pragma once
#include <cmath>

class Star
{
private:
	// stars start at random position on screen
	float x = rand() % ofGetWidth();
	float y = rand() % ofGetWidth();
	// proportion of x and y from center when star first appears
	// ranges are from -1 to 1
	// you could continuously update each time
	// but this method creates a starfield with more depth
	float dx = x / (ofGetWidth() / 2) - 1;
	float dy = y / (ofGetHeight() / 2) - 1;
	
public:
	void displayStar()
	{
		// store old position
		float oldX = x;
		float oldY = y;
		// update position
		// x is multiplied by an additional 1.78 because of 1920x1080 aspect ratio
		x += dx * 20 * 1.78;
		y += dy * 20;
		// draw line from previous to current
		ofDrawLine(oldX, oldY, x, y);
		// if stars go off screen, reset everything
		if (y < 0 || y > ofGetHeight() || x < 0 || x > ofGetWidth())
		{
			y = rand() % (ofGetHeight() / 2) + ofGetHeight() / 4;
			x = rand() % (ofGetWidth() / 2) + ofGetWidth() / 4;
			dx = x / (ofGetWidth() / 2) - 1;
			dy = y / (ofGetHeight() / 2) - 1;
		}
	}
};