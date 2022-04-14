#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

        void textureTile(int x, int y, int degrees, float scale, ofColor color, bool fill);
		
};
