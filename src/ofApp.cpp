#include "ofApp.h"

// KEY FOR APPLICATION STATE
// 0. Intro screen with starfield
// 1. Screen fading white to select screen
// 2. Select screen with options

// 3. Mouse hovering over visualize a sort
// 4. Mouse being held down over visualize a sort
// 5. Pick a sort to visualize

// 6. Mouse hovering over Quick Sort
// 7. Mouse being held down over Quick Sort
// 8. Sort with Quick Sort

//--------------------------------------------------------------
// get everything ready when the program begins
void ofApp::setup()
{
	ofBackground(0);
	for (int i = 0; i < 250; i++)
	{
		stars[i] = Star();
	}
	for (int i = 0; i < 1920; i++)
	{
		nums[i] = i * 0.5625;
	}
	name.load("fonts/Roboto_Slab/static/RobotoSlab-SemiBold.ttf", 72);
	nameRect = name.getStringBoundingBox("ANALYSEE", 0, 0);
	prompt.load("fonts/Kanit/Kanit-Light.ttf", 40);
	promptRect = prompt.getStringBoundingBox("PRESS ANY KEY TO START", 0, 0);
	ofSetColor(255);
	ofNoFill();
	ofEnableSmoothing();
}

//--------------------------------------------------------------
void ofApp::update()
{

}

//--------------------------------------------------------------
void ofApp::draw()
{
	if (state == 0)
	{
		drawState0();
	}
	else if (state == 1)
	{
		drawState1();
	}
	else if (state == 2)
	{
		drawState2();
	}
	else if (state == 3)
	{
		drawState3();
	}
	else if (state == 4)
	{
		// the simple code for drawing doesn't change between 3 and 4
		// the size of the text changes which is handled elsewhere by loading a different font size
		drawState3();
	}
	else if (state == 5)
	{
		drawState5();
	}
	else if (state == 6)
	{
		drawState6();
	}
	else if (state == 7)
	{
		// the simple code for drawing doesn't change between 6 and 7
		// the size of the text changes which is handled elsewhere by loading a different font size
		drawState6();
	}
	else if (state == 8)
	{
		drawState8();
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
	// move forward if any button is pressed during intro screen
	if (state == 0)
	{
		state = 1;
	}
	// insta move forward if any button is pressed during fade
	else if (state == 1)
	{
		fade = 255;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y)
{
	if (state == 2)
	{
		// mouse hovering over Visualize a Sort
		if (mouseWithin(x, y, promptRect.width, promptRect.height, ofGetWidth() * 0.75, 725 - promptRect.height / 4))
		{
			state = 3;
		}
	}
	else if (state == 3)
	{
		// mouse just left Visualize a Sort
		if (!(mouseWithin(x, y, promptRect.width, promptRect.height, ofGetWidth() * 0.75, 725 - promptRect.height / 4)))
		{
			state = 2;
		}
	}
	else if (state == 5)
	{
		// mouse is hovering over Quick Sort
		if (mouseWithin(x, y, promptRect.width, promptRect.height / 2, ofGetWidth() * 0.25, 540 - promptRect.height / 4))
		{
			state = 6;
		}
	}
	else if (state == 6)
	{
		// mouse just left Quick Sort
		if (!(mouseWithin(x, y, promptRect.width, promptRect.height / 2, ofGetWidth() * 0.25, 540 - promptRect.height / 4)))
		{
			state = 5;
		}
	}
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{
	// mouse pressed/held while hovering over "Visualize a sort"
	if (state == 3)
	{
		state = 4;
		prepareState4();
	}
	// mouse pressed/held over Quick Sort
	else if (state == 6)
	{
		state = 7;
		prepareState7();
	}
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{
	if (state == 4)
	{
		state = 5;
		prepareState5();
	}
	else if (state == 7)
	{
		state = 8;
		prepareState8();
	}
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y)
{

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y)
{

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h)
{

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg)
{

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo)
{ 

}