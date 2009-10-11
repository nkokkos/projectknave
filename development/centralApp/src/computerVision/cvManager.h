#ifndef _CV_MANAGER_H
#define _CV_MANAGER_H



#include "ofMain.h"
#include "ofxCvMain.h"

#include "cvStrokeResampler.h"
#include "cvPacket.h"
#include "ofxNetwork.h"

#include "ofxXmlSettings.h"


enum {
	CV_SENDER, CV_RECEIVER
};



class cvManager {
	
	public:
	
	
	cvManager();
	~cvManager();
		
	//changing cameras or switching from/to the camera mode
	//requires the app to be restarted - mabe we can change this?
	void setupCamera(int deviceNumber, int width, int height);
	void setupVideo(string videoPath);
	void setupCV();

	
	bool isFrameNew();
	
	//do all our openCV allocation
	//---------------------------		
		
	//good for adjusting the color balance, brightness etc
	void openCameraSettings();
	
	void update();
	
	void draw(float x, float y, int w = 640, int h = 480);

	//-------------
	//-------------	
	ofVideoPlayer  	VP;
	ofVideoGrabber 	VG;
	
	int						threshold;
	int						maxBlobSize, minBlobSize;
	
	bool					bUsingVideoGrabber;
	bool					bSetup;	
	int						width, height;
	
	ofxCvColorImage			VideoFrame;
	ofxCvGrayscaleImage		GreyFrame;
	ofxCvGrayscaleImage		PresenceFrame;
	ofxCvGrayscaleImage		PresenceFrameDialate;
	ofxCvContourFinder		Contour;
	
	
	//-----------------------------------
	//		* packet * 
	
	void					fillPacket();
	cvStrokeResampler		SR;
	computerVisionPacket	* packet;
	
	
	//-----------------------------------
	//		* settings * 
	
	ofxXmlSettings			XML;
	int						id;		 // sender?  receiver?
	
	
	//-----------------------------------
	//		* network * 
	
	
	void					setupReceiver();
	void					receiveFromNetwork();
	
	void					setupSender();
	void					sendToNetwork();
	
	bool					bNetworkSetup;
	ofxUDPManager			manager;
	string					IP;
	unsigned short			port;
	unsigned char *			packetData;
	

};



#endif