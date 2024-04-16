#pragma once

#include "ofMain.h"
#include "Star.h"

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

		Star stars[250];
		ofTrueTypeFont name;
		ofTrueTypeFont prompt;
		ofRectangle nameRect;
		ofRectangle promptRect;
		int state = 0;
		int fade = 0;
};
