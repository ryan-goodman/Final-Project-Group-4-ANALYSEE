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

		void drawState0()
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

		void drawState1()
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
				state = 2;
				prepareState2();
			}
		}

		void drawState2()
		{
			name.drawString("ANALYSEE", ofGetWidth() / 2.0 - nameRect.width / 2, 400);
			prompt.drawString("Visualize a sort", ofGetWidth() * 0.75 - promptRect.width / 2, 750);
		}

		void drawState3()
		{
			ofSetColor(0);
			prompt.drawString("Visualize a sort", ofGetWidth() * 0.75 - promptRect.width / 2, 750);
			ofSetColor(255);
			name.drawString("ANALYSEE", ofGetWidth() / 2.0 - nameRect.width / 2, 400);
		}

		void drawState5()
		{
			prompt.drawString("Quick Sort", ofGetWidth() * 0.25 - promptRect.width / 2, 540);
			otherPrompt.drawString("Merge Sort", ofGetWidth() * 0.75 - otherPromptRect.width / 2, 540);
		}

		void drawState6()
		{
			ofSetColor(0);
			prompt.drawString("Quick Sort", ofGetWidth() * 0.25 - promptRect.width / 2, 540);
			ofSetColor(255);
			otherPrompt.drawString("Merge Sort", ofGetWidth() * 0.75 - otherPromptRect.width / 2, 540);
		}

		void drawState8()
		{
			ofSetColor(255);
			for (int i = 0; i < 1920; i++)
			{
				ofDrawLine(i, 1080, i, 1080 - nums[i]);
			}
			passOfQuickSort();
		}

		void prepareState2()
		{
			ofBackground(40);
			prompt.load("fonts/Kanit/Kanit-Light.ttf", 50);
			promptRect = prompt.getStringBoundingBox("Visualize a sort", 0, 0);
		}

		void prepareState4()
		{
			prompt.loadFont("fonts/Kanit/Kanit-Light.ttf", 40);
			promptRect = prompt.getStringBoundingBox("Visualize a sort", 0, 0);
		}

		void prepareState5()
		{
			ofSetColor(255);
			prompt.load("fonts/Kanit/Kanit-Light.ttf", 50);
			otherPrompt.load("fonts/Kanit/Kanit-Light.ttf", 50);
			promptRect = prompt.getStringBoundingBox("Quick Sort", 0, 0);
			otherPromptRect = otherPrompt.getStringBoundingBox("Merge Sort", 0, 0);
		}

		void prepareState7()
		{
			prompt.loadFont("fonts/Kanit/Kanit-Light.ttf", 40);
			promptRect = prompt.getStringBoundingBox("Quick Sort", 0, 0);
		}

		void prepareState8()
		{
			ofSetColor(255);
			std::random_device random;
			std::mt19937 g(random());
			std::shuffle(nums, nums + 1920, random);
			stack.push(0);
			stack.push(1919);
		}

		int partition(float arr[], int low, int high)
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

		void passOfQuickSort()
		{
			if (!stack.empty())
			{
				int high = stack.top();
				stack.pop();
				int low = stack.top();
				stack.pop();
				int index = partition(nums, low, high);
				if (index - 1 > low)
				{
					stack.push(low);
					stack.push(index - 1);
				}
				if (index + 1 < high)
				{
					stack.push(index + 1);
					stack.push(high);
				}
			}
			else
			{
				state = 2;
				prepareState2();
			}
		}

		bool mouseWithin(int x, int y, float rectWidth, float rectHeight, float rectX, float rectY)
		{
			return (x > rectX - rectWidth / 2 - 25 && x < rectX + rectWidth / 2 + 25
					&& y > rectY - rectHeight && y < rectY + rectHeight);
		}
};