#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	lastFrameTime = ofGetElapsedTimef();
	client.setup("mpe_client_settings.xml", true); //false means you can use backthread
	client.start();
	//ofSetWindowShape(client.getLWidth(),
	//				 client.getLHeight());
	ofSetWindowPosition(client.getXoffset(),client.getYoffset());
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	
	ofxMPERegisterEvents(this);
	
	ofSetBackgroundAuto(false);
	//	ofSetupScreenOrtho(640, 480, OF_ORIENTATION_UNKNOWN, true, -1000, 1000);
	//ofSetupScreenOrtho(ofGetWidth()	, ofGetHeight(),OF_ORIENTATION_UNKNOWN, true, -1000, 1000);
	//	Ball* ball = new Ball(ofRandom(0, client.getMWidth()),
	//						  ofRandom(0, client.getMHeight()),
	//						  client.getMWidth(),
	//						  client.getMHeight());
	//	//Ball* ball = new Ball(x, y, client.getMWidth(), client.getMHeight());
	//	//        balls.push_back(ball);
	//    balls.push_back(ball);
}

//--------------------------------------------------------------
void testApp::update(){
}

//--------------------------------------------------------------
void testApp::draw(){
	//don't use this
}

//--------------------------------------------------------------
void testApp::mpeFrameEvent(ofxMPEEventArgs& event)
{
	client.placeScreen();
	ofClear(0, 0, 0, 0);
	ofPushStyle();
	ofColor bg = ofColor(client.getFrameCount()*10 % 255);
	
	ofSetColor(bg);
	ofRect(0, 0, client.getMWidth(),client.getMHeight());
	ofSetColor(255,0,0);
	ofRect(0, client.getMHeight()/2,client.getMWidth()*rnd, 20);
	ofCircle(client.getFrameCount()*10 % client.getMWidth(),client.getMHeight()/2,60);
	
	ofPopStyle();
	ofPushStyle();
	for (int i = 0; i < balls.size(); i++) {
        balls[i]->calc();
        balls[i]->draw();
    }
	ofPopStyle();
	
	if(client.getID()==0)
	{
		client.broadcast("random;"+ofToString(ofRandomf(),6));

	}
	/*
	 float now = ofGetElapsedTimef();
	 cout << "fps would be " << 1./(now - lastFrameTime) << endl;
	 lastFrameTime = now;
	 */
}

//--------------------------------------------------------------
void testApp::mpeMessageEvent(ofxMPEEventArgs& event){
	//received a message from the server
	
	string msg = event.message;
	cout << msg << endl;
	vector<string> xy = ofSplitString(msg, ";");
	if(xy[0]=="ball")
	{
        float x = ofToInt(xy[1]);
        float y = ofToInt(xy[2]);
		float vx = ofToInt(xy[3]);
		float vy = ofToInt(xy[4]);
		float c = ofToInt(xy[5]);
        Ball* ball = new Ball(x, y, client.getMWidth(), client.getMHeight(),vx,vy,c);
        balls.push_back(ball);
		
	}
	else if (xy[0] == "random")
	{
		rnd = ofToFloat(xy[1]);
	}
}


void testApp::mpeResetEvent(ofxMPEEventArgs& event){
	//triggered if the server goes down, another client goes offline, or a reset was manually triggered in the server code
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	
	
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
	
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
	
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
	
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	x += client.getXoffset();
    y += client.getYoffset();
	
    client.broadcast("ball;"+ofToString(x) + ";" +
					 ofToString(y) + ";" +
					 ofToString((int)ofRandom(-5 ,5))+";" + 
					 ofToString((int)ofRandom(-5 ,5))+";" + 
					 ofToString((int)ofRandom(0xffffff)));
	
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
	
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
	
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){
	
}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 
	
}