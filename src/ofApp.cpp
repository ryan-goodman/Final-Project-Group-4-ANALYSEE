#include "ofApp.h"

// KEY FOR APPLICATION STATE
// 0. Intro screen with starfield
// 1. Screen fading white to select screen
// 2. Select screen with options

// 3. Mouse hovering over visualize a sort
// 4. Mouse being held down over visualize a sort

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
		name.drawString("ANALYSEE", ofGetWidth() / 2.0 - nameRect.width / 2, 400);
		if (promptCounter < 120)
		{
			prompt.drawString("PRESS ANY KEY TO START", ofGetWidth() / 2.0 - promptRect.width / 2, 800);
		}
		promptCounter++;
		if (promptCounter > 240)
		{
			promptCounter = 0;
		}
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
			if (promptCounter < 120)
			{
				prompt.drawString("PRESS ANY KEY TO START", ofGetWidth() / 2.0 - promptRect.width / 2, 800);
			}
			promptCounter++;
			if (promptCounter > 240)
			{
				promptCounter = 0;
			}
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
			prompt.load("fonts/Kanit/Kanit-Light.ttf", 40);
			promptRect = prompt.getStringBoundingBox("Visualize a sort", 0, 0);
		}

	}
	else if (state == 2)
	{
		name.drawString("ANALYSEE", ofGetWidth() / 2.0 - nameRect.width / 2, 400);
		// ofDrawRectangle(ofGetWidth() * 0.75 - promptRect.width / 2 - 25, 725 - promptRect.height, promptRect.width + 50, promptRect.height + 50);
		prompt.drawString("Visualize a sort", ofGetWidth() * 0.75 - promptRect.width / 2, 750);
	}
	else if (state == 3)
	{
		ofSetColor(0);
		prompt.drawString("Visualize a sort", ofGetWidth() * 0.75 - promptRect.width / 2, 750);
		ofSetColor(255);
		name.drawString("ANALYSEE", ofGetWidth() / 2.0 - nameRect.width / 2, 400);
	}
	else if (state == 4)
	{
		ofSetColor(0);
		prompt.drawString("Visualize a sort", ofGetWidth() * 0.75 - promptRect.width / 2, 750);
		ofSetColor(255);
		name.drawString("ANALYSEE", ofGetWidth() / 2.0 - nameRect.width / 2, 400);
	}
	else if (state == 5)
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
	else if (state == 2)
	{
		// do nothing
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
		// mouse is within the "Visualize a sort" box
		if (x > ofGetWidth() * 0.75 - promptRect.width / 2 - 25 && x < ofGetWidth() * 0.75 - promptRect.width / 2 - 25 + promptRect.width + 50
			&& y > 725 - promptRect.height && y < 725 - promptRect.height + promptRect.height + 50)
		{
			state = 3;
		}
	}
	if (state == 3)
	{
		if (!(x > ofGetWidth() * 0.75 - promptRect.width / 2 - 25 && x < ofGetWidth() * 0.75 - promptRect.width / 2 - 25 + promptRect.width + 50
			&& y > 725 - promptRect.height && y < 725 - promptRect.height + promptRect.height + 50))
		{
			state = 2;
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
	if (state == 3)
	{
		prompt.loadFont("fonts/Kanit/Kanit-Light.ttf", 30);
		promptRect = prompt.getStringBoundingBox("Visualize a sort", 0, 0);
		state = 4;
	}
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{
	if (state == 4)
	{
		state = 5;
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