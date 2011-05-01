#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup() {

  
  
	setupRecording();

	//ofBackground(0, 0, 0, 0);
  
  syphonServer.setName("Segmented Puppet");

  
  leftLowerArm.load("left_lower_arm2.obj");
  
  leftForearm = GABPuppetLimb(leftLowerArm);
  rightForearm = GABPuppetLimb(leftLowerArm);


  leftUpperArm.load("left_upper_arm.obj");
  rightUpperarm = GABPuppetLimb(leftUpperArm);
  leftUpperarm = GABPuppetLimb(leftUpperArm);
  
  torsoModel.load("torso2.obj");
  torso = GABPuppetLimb(torsoModel);
  
  lowerLeg.load("lower_leg2.obj");
  leftLowerLeg = GABPuppetLimb(lowerLeg);
  rightLowerLeg = GABPuppetLimb(lowerLeg);
  
  upperLeg.load("upper_leg2.obj");
  leftUpperLeg = GABPuppetLimb(upperLeg);
  rightUpperLeg = GABPuppetLimb(upperLeg);
  
  headModel.load("head_oriented.obj");
  head = GABPuppetLimb(headModel);

    ofSetFrameRate(60);
}


void testApp::setupRecording(string _filename) {
	
	if (!recordContext.isInitialized()) {
		
		recordContext.setup();
		recordContext.setupUsingXMLFile();
		recordDepth.setup(&recordContext);
		recordImage.setup(&recordContext);
		
		recordUser.setup(&recordContext, &recordDepth, &recordImage);
		
		recordDepth.toggleRegisterViewport(&recordImage);
		recordContext.toggleMirror();
		
		oniRecorder.setup(&recordContext, &recordDepth, &recordImage);	
		
	} 		
}


//--------------------------------------------------------------
void testApp::update(){
  recordContext.update();
	recordUser.update();
  
  if (recordUser.getTrackedUsers().size() > 0) {
    
    
    leftForearmBegin  = recordUser.getTrackedUsers()[0]->left_lower_arm.begin;
    leftForearmEnd    = recordUser.getTrackedUsers()[0]->left_lower_arm.end;
    
    rightForearmBegin = recordUser.getTrackedUsers()[0]->right_lower_arm.begin;
    rightForearmEnd   = recordUser.getTrackedUsers()[0]->right_lower_arm.end;
    
    rightUpperarmBegin = recordUser.getTrackedUsers()[0]->right_upper_arm.begin;
    rightUpperarmEnd   = recordUser.getTrackedUsers()[0]->right_upper_arm.end;
    
    
    leftUpperarmBegin = recordUser.getTrackedUsers()[0]->left_upper_arm.begin;
    leftUpperarmEnd   = recordUser.getTrackedUsers()[0]->left_upper_arm.end;
    
    leftLowerLegBegin = recordUser.getTrackedUsers()[0]->left_lower_leg.begin;
    leftLowerLegEnd = recordUser.getTrackedUsers()[0]->left_lower_leg.end;
    
    rightLowerLegBegin = recordUser.getTrackedUsers()[0]->right_lower_leg.begin;
    rightLowerLegEnd = recordUser.getTrackedUsers()[0]->right_lower_leg.end;
    
    
    leftUpperLegBegin = recordUser.getTrackedUsers()[0]->left_upper_leg.begin;
    leftUpperLegEnd = recordUser.getTrackedUsers()[0]->left_upper_leg.end;
    
    rightUpperLegBegin = recordUser.getTrackedUsers()[0]->right_upper_leg.begin;
    rightUpperLegEnd = recordUser.getTrackedUsers()[0]->right_upper_leg.end;
    
    
    headBegin = recordUser.getTrackedUsers()[0]->neck.begin;
    headEnd = recordUser.getTrackedUsers()[0]->neck.end;
    
    
    ofxVec3f shoudlerLine = recordUser.getTrackedUsers()[0]->right_shoulder.begin + recordUser.getTrackedUsers()[0]->left_shoulder.begin;
    torsoBegin = shoudlerLine / 2;
    
    torsoEnd = (recordUser.getTrackedUsers()[0]->hip.end + recordUser.getTrackedUsers()[0]->hip.begin) / 2;
    
    
    
  }
  
}

//--------------------------------------------------------------
void testApp::draw(){
	
	

	
	  
  glPushMatrix();
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  // LIGHTING ================
  glEnable(GL_LIGHTING);
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_LIGHT0);    
  glEnable(GL_NORMALIZE);
  
  
    ofSetColor(150, 150, 150);


    ofTranslate(-1000, -1000, -200);

    ofScale(6,6,-1);


  
    leftForearm.updateControl(leftForearmBegin, leftForearmEnd);
    rightForearm.updateControl(rightForearmBegin, rightForearmEnd);

    rightUpperarm.updateControl(rightUpperarmBegin, rightUpperarmEnd);
    leftUpperarm.updateControl(leftUpperarmBegin, leftUpperarmEnd);
  
    torso.updateControl(torsoBegin, torsoEnd);

    leftLowerLeg.updateControl(leftLowerLegBegin, leftLowerLegEnd);
    rightLowerLeg.updateControl(rightLowerLegBegin, rightLowerLegEnd);
  
    leftUpperLeg.updateControl(leftUpperLegBegin, leftUpperLegEnd);
    rightUpperLeg.updateControl(rightUpperLegBegin, rightUpperLegEnd);

    head.updateControl(headBegin, headEnd);

  
    leftForearm.draw();
    rightForearm.draw();
    rightUpperarm.draw();
    leftUpperarm.draw();
    
  
  //cout << "tB x: " << torsoBegin.x << "\ty: " << torsoBegin.y << "\tz: " << torsoBegin.z << endl;

  
    torso.draw();
  
    leftLowerLeg.draw();
    rightLowerLeg.draw();
  
    leftUpperLeg.draw();
    rightUpperLeg.draw();
  
    head.draw();

  // LIGHTING ================
  glDisable(GL_LIGHTING);
  glDisable(GL_DEPTH_TEST);
  glDisable(GL_LIGHT0);    
  glDisable(GL_NORMALIZE);
  glPopMatrix();
  


  glPopMatrix();
  
  syphonServer.publishScreen();

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

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

