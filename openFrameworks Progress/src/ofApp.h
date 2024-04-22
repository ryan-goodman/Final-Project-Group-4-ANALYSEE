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
		std::queue<int> q;
		int promptCounter = 0;
		int state = 0;
		int fade = 0;
		int step = 0;
		int counter = 0;

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

		void drawState9()
		{
			ofSetColor(0);
			otherPrompt.drawString("Merge Sort", ofGetWidth() * 0.75 - otherPromptRect.width / 2, 540);
			ofSetColor(255);
			prompt.drawString("Quick Sort", ofGetWidth() * 0.25 - promptRect.width / 2, 540);
		}

		void drawState11()
		{
			ofSetColor(255);
			for (int i = 0; i < 1920; i++)
			{
				ofDrawLine(i, 1080, i, 1080 - nums[i]);
			}
			passOfMergeSort();
		}

		void prepareState2()
		{
			ofBackground(40);
			ofSetColor(255);
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

		void prepareState10()
		{
			otherPrompt.loadFont("fonts/Kanit/Kanit-Light.ttf", 40);
			otherPromptRect = otherPrompt.getStringBoundingBox("Merge Sort", 0, 0);
		}

		void prepareState11()
		{
			ofSetColor(255);
			std::random_device random;
			std::mt19937 g(random());
			std::shuffle(nums, nums + 1920, random);
			step = 1;
			for (int i = 0; i < 1920; i++)
			{
				q.push(i);
				q.push(i);
			}
		}

		void passOfQuickSort()
		{
			if (!stack.empty())
			{
				int high = stack.top();
				stack.pop();
				int low = stack.top();
				stack.pop();
				ofSetColor(255, 0, 0);
				int index = partition(low, high);
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

		int partition(int low, int high)
		{
			// median of three pivot strategy
			int mid = low + (high - low) / 2;
			if (nums[low] > nums[mid])
			{
				std::swap(nums[low], nums[mid]);
			}
			if (nums[low] > nums[high])
			{
				std::swap(nums[low], nums[high]);
			}
			if (nums[mid] > nums[high])
			{
				std::swap(nums[mid], nums[high]);
			}
			std::swap(nums[mid], nums[high]);
			float pivot = nums[high];
			int i = low - 1;
			for (int j = low; j < high; j++)
			{
				if (nums[j] <= pivot)
				{
					i++;
					ofDrawLine(i, 1080, i, 1080 - nums[i]);
					ofDrawLine(j, 1080, j, 1080 - nums[j]);
					std::swap(nums[i], nums[j]);
				}
			}
			ofDrawLine(i + 1, 1080, i + 1, 1080 - nums[i + 1]);
			ofDrawLine(high, 1080, high, 1080 - nums[high]);
			std::swap(nums[i + 1], nums[high]);
			return i + 1;
		}

		void passOfMergeSort()
		{
			if (q.size() >= 4)
			{
				int firstStart = q.front();
				q.pop();
				int firstEnd = q.front();
				q.pop();
				int secondStart = q.front();
				q.pop();
				int secondEnd = std::min(q.front(), 1919);
				q.pop();
				if (firstEnd > secondStart)
				{
					q.push(firstStart);
					q.push(firstEnd);
					firstStart = secondStart;
					firstEnd = secondEnd;
					secondStart = q.front();
					q.pop();
					secondEnd = q.front();
					q.pop();
					merge(firstStart, firstEnd, secondStart, secondEnd);
				}
				else
				{
					merge(firstStart, firstEnd, secondStart, secondEnd);
				}
				q.push(firstStart);
				q.push(secondEnd);
			}
			else
			{
				while (!q.empty())
				{
					q.pop();
				}
				for (int i = 0; i < 1920; i++)
				{
					ofDrawLine(i, 1080, i, 1080 - nums[i]);
				}
				state = 2;
				prepareState2();
			}
		}
		
		void merge(int firstStart, int firstEnd, int secondStart, int secondEnd)
		{
			std::vector<float> temp;
			temp.reserve(secondEnd - firstStart + 1);
			int firstPos = firstStart, secondPos = secondStart;

			while (firstPos <= firstEnd && secondPos <= secondEnd)
			{
				if (nums[firstPos] <= nums[secondPos])
				{
					temp.push_back(nums[firstPos]);
					firstPos++;
				}
				else
				{
					temp.push_back(nums[secondPos]);
					secondPos++;
				}
			}

			while (firstPos <= firstEnd)
			{
				temp.push_back(nums[firstPos]);
				firstPos++;
			}

			while (secondPos <= secondEnd)
			{
				temp.push_back(nums[secondPos]);
				secondPos++;
			}
	
			for (int i = firstStart; i <= secondEnd; i++)
			{
				nums[i] = temp[i - firstStart];
			}
		}

		bool mouseWithin(int x, int y, float rectWidth, float rectHeight, float rectX, float rectY)
		{
			return (x > rectX - rectWidth / 2 - 25 && x < rectX + rectWidth / 2 + 25
					&& y > rectY - rectHeight && y < rectY + rectHeight);
		}
};