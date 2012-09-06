#pragma once

#include "ofMain.h" 

class Ball {

	public:
		Ball(float _x, float _y, float _mWidth, float _mHeight , float vx ,float vy, int _c) {
            x = _x;
            y = _y;
            xDir = vx;//ofRandom(-5, 5);
            yDir = vy;//ofRandom(-5, 5);
            d = 10;
            mWidth  = _mWidth;
            mHeight = _mHeight;
			c = _c;
        }
    
        //--------------------------------------
        // Moves and changes direction if it hits a wall.
        void calc() {
            if (x < 0 || x > mWidth)  xDir *= -1;
            if (y < 0 || y > mHeight) yDir *= -1;
            x += xDir;
            y += yDir;
        }
        
        //--------------------------------------
        void draw() {
            ofSetHexColor(c);
            ofFill();
            ofCircle(x, y, d);
            ofSetColor(0);
            ofNoFill();
            ofCircle(x, y, d);
        }

    private:
		float x; 
		float y; 
		float xDir;
		float yDir;
        float d;
        float mWidth;
        float mHeight;
	int c;
    
};