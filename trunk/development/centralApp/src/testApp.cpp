#include "testApp.h"





//--------------------------------------------------------------
void testApp::setup(){
	
	CVM.setupVideo("testMovies/crowd-motionTest-wide-960pixelby240.mov");
<<<<<<< .mine
	FB.setupBuilding("building.jpg");

=======
	
>>>>>>> .r40
	SM.setup();
	SM.gotoScene(TREE_SCENE);
	
	drawMode = DRAW_SCENE;
	
}

//--------------------------------------------------------------
void testApp::update(){
	
	CVM.update();
	
	SM.passInFerryBuilding(&FB);
	SM.passInPacket(CVM.packet);
	SM.update();
	
	
}

//--------------------------------------------------------------
void testApp::draw(){
	
	
	FB.draw();
	
	
	if (drawMode == DRAW_CV){
		CVM.draw(0,0,900,300);
	} else if (drawMode == DRAW_SCENE) {
		SM.draw();
	}
	
	
	
	
	ofSetColor(0, 0, 0);
	string info = "	FPS: "+ofToString(ofGetFrameRate());
	info += "\n		left / right key to change draw";
	info += "\n		up / down to change scenes.";
	info += "\n		Scene: "+ofToString(SM.currentScene)+"/"+ofToString(SM.numScenes);
	
	ofDrawBitmapString(info, 20, 20);
}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){
	
	SM.keyPressed(key);
	
	
	switch (key){
			
		case OF_KEY_RIGHT:
			drawMode ++;
			drawMode %= 2;
			break;
		case OF_KEY_LEFT:
			drawMode --;
			if (drawMode < 0) drawMode += 2;	
			break;
			
		case OF_KEY_UP:
			SM.nextScene();
			break;
		case OF_KEY_DOWN:
			SM.prevScene();
			break;
	}
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
	SM.keyReleased(key);
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
	SM.mouseMoved(x, y);	
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
	SM.mouseDragged(x, y, button);
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	SM.mousePressed(x, y, button);
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
	SM.mouseReleased(x, y, button);
}

//--------------------------------------------------------------
void testApp::resized(int w, int h){
	
}

