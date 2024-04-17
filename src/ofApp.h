#pragma once

#include "ofMain.h"
#include "Star.h"
#include <algorithm>
#include <random>

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
		int passOfQuickSort(float arr[], int low, int high)
		{
			float pivot = arr[high];
			int i = low - 1;
			for (int j = low; j < high; j++)
			{
				if (arr[j] <= pivot)
				{
					i++;
					ofSetColor(255, 0, 0);
					ofDrawLine(i, 1080, i, 1080 - arr[i]);
					ofDrawLine(j, 1080, j, 1080 - arr[j]);
					std::swap(arr[i], arr[j]);
				}
			}
			ofSetColor(255, 0, 0);
			ofDrawLine(i + 1, 1080, i + 1, 1080 - arr[i + 1]);
			ofDrawLine(high, 1080, high, 1080 - arr[high]);
			std::swap(arr[i + 1], arr[high]);
			return i + 1;
		}

		Star stars[250];
		float nums[1920];
		ofTrueTypeFont name;
		ofTrueTypeFont prompt;
		ofTrueTypeFont otherPrompt;
		ofRectangle nameRect;
		ofRectangle promptRect;
		ofRectangle otherPromptRect;
		std::stack<int> stack;
		int promptCounter = 0;
		int state = 0;
		int fade = 0;
};
