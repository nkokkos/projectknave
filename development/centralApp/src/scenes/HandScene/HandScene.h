/*
 *  simpleScene.h
 *  openFrameworks
 *
 *  Created by Zach Lieberman on 9/23/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#pragma once;

#include "ofMain.h"
#include "baseScene.h"
#include "ofxCvGrayscaleAdvanced.h"
#include "HandBall.h"

#include "buildingShapeManager.h"
#include "ofxFBOTexture.h"

#include "ofxDaito.h"


class HandScene : public baseScene {
	
public: 
	
	void setup();
	void update();
	void draw();
	void drawTop();
	void mousePressed(int x, int y, int button);
	void keyPressed(int key);

	
	// Box2d
	ofxBox2d							box2d;
	vector <ofxBox2dLine>				box2dHandShape;
	vector <ofxBox2dLine>				box2dBuilding;
	vector <ofxBox2dCircle>				circles;
	vector <HandBall>					balls;	
	ofxBox2dRect						floor;
	
	// Ferry Building
	FerryBuilding						ferryBuilding;
	
	ofxFBOTexture						FBO;
	
	
	int	handImgW, handImgH;
	
	
	ofxCvGrayscaleAdvanced				handImage;
	ofxCvGrayscaleAdvanced				handImageTemporallyBlurred;
	ofxCvGrayscaleAdvanced				handImageTemporallyBlurredInvert;

	
	int lastFrameRendered;
	
	
	buildingShapeManager			BSM;
	
	
	/*
	 
	 for finding building shapes ! 
	 
	 */
	
	ofImage				roof;
	int width, height;
	ofxCvGrayscaleImage 	grayImage;
	ofxCvContourFinder 	contourFinder;
	int 				threshold;
	bool				bLearnBakground;
	
	
	ofxDaito			DAITO;
	
	
};