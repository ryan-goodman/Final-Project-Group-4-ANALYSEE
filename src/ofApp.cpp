#include "ofApp.h"

// KEY FOR APPLICATION STATE
// 0. Intro screen with starfield
// 1. Screen fading white to select screen
// 2. Select screen with options

//--------------------------------------------------------------
// get everything ready when the program begins
void ofApp::setup()
{
	ofBackground(0);
	for (int i = 0; i < 250; i++)
	{
		stars[i] = Star();
	}
	//ofSetFrameRate(some static amount);
	ofSetColor(255);
	name.load("fonts/Roboto_Slab/static/RobotoSlab-SemiBold.ttf", 72);
	nameRect = name.getStringBoundingBox("ANALYSEE", 0, 0);
	prompt.load("fonts/Kanit/Kanit-Light.ttf", 40);
	promptRect = prompt.getStringBoundingBox("PRESS ANY KEY TO START", 0, 0);
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
		name.drawString("ANALYSEE", ofGetWidth() / 2 - nameRect.width / 2, 400);
		prompt.drawString("PRESS ANY KEY TO START", ofGetWidth() / 2 - promptRect.width / 2, 700);
		for (int i = 0; i < 250; i++)
		{
			stars[i].displayStar();
		}
	}
	else if (state == 1)
	{
		// still fading
		if (fade < 255)
		{
			ofBackground(fade);
			fade++;
			name.drawString("ANALYSEE", ofGetWidth() / 2.0 - nameRect.width / 2, 400);
			prompt.drawString("PRESS ANY KEY TO START", ofGetWidth() / 2.0 - promptRect.width / 2, 700);
			for (int i = 0; i < 250; i++)
			{
				stars[i].displayStar();
			}
		}
		// done fading
		else
		{
			ofBackground(40);
			state = 2;
		}
		
	}
	else if (state == 2)
	{

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
void ofApp::mouseMoved(int x, int y )
{

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{

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