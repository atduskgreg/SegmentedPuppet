#ifndef _TEST_APP
#define _TEST_APP


#include "ofMain.h"
#include "ofxOpenNI.h"
#include "ofxOBJModel.h"
#include "GABPuppetLimb.h"

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

		void	setupRecording(string _filename = "");
		void	setupPlayback(string _filename);
		string	generateFileName();
	
		bool				isLive, isTracking, isRecording, isCloud, isCPBkgnd, isMasking;
		
		string				currentFileName;
	
		ofxOpenNIContext	recordContext, playContext;
		ofxDepthGenerator	recordDepth, playDepth;
		ofxImageGenerator	recordImage, playImage;
		ofxUserGenerator	recordUser, playUser;
		ofxOpenNIRecorder	oniRecorder;
  
    ofxOBJModel leftLowerArm;
    ofxOBJModel leftUpperArm;
    ofxOBJModel torsoModel;
    ofxOBJModel lowerLeg;
    ofxOBJModel upperLeg;
    ofxOBJModel headModel;

  
    ofxVec3f leftForearmBegin;
    ofxVec3f leftForearmEnd;

    ofxVec3f rightForearmBegin;
    ofxVec3f rightForearmEnd;
  
    ofxVec3f rightUpperarmBegin;
    ofxVec3f rightUpperarmEnd;
  
    ofxVec3f leftUpperarmBegin;
    ofxVec3f leftUpperarmEnd;
  
    ofxVec3f torsoBegin;
    ofxVec3f torsoEnd;
  
    
    ofxVec3f leftLowerLegBegin;
    ofxVec3f leftLowerLegEnd;

    ofxVec3f rightLowerLegBegin;
    ofxVec3f rightLowerLegEnd;
  
    ofxVec3f leftUpperLegBegin;
    ofxVec3f leftUpperLegEnd;
  
    ofxVec3f rightUpperLegBegin;
    ofxVec3f rightUpperLegEnd;

    ofxVec3f headBegin;
    ofxVec3f headEnd;
  
    GABPuppetLimb leftForearm;
    GABPuppetLimb rightForearm;
    GABPuppetLimb rightUpperarm;
    GABPuppetLimb leftUpperarm;
    GABPuppetLimb torso;

    GABPuppetLimb leftLowerLeg;
    GABPuppetLimb rightLowerLeg;

    GABPuppetLimb leftUpperLeg;
    GABPuppetLimb rightUpperLeg;

    GABPuppetLimb head;


		
};

#endif
