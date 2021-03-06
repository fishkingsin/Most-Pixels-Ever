#pragma once

#include "ofMain.h"
#include "ofxMostPixelsEver.h"
#include "Ball.h"
class testApp : public ofBaseApp{

  public:
	void setup();
	void update();
	void draw();

	void keyPressed  (int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);
	
	mpeClientTCP client;
	
	void mpeFrameEvent(ofxMPEEventArgs& event);
	void mpeMessageEvent(ofxMPEEventArgs& event);
	void mpeResetEvent(ofxMPEEventArgs& event);
	float lastFrameTime;
	vector<Ball*> balls;
	float rnd;
};

