#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup() {
	
/*	isLive		= true;
	isTracking	= true;
	isRecording = false;
	isCloud		= false;
	isCPBkgnd	= true;
	isMasking   = true;
	*/
  
	setupRecording();

	ofBackground(0, 0, 0);
  
  
  
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
  
  upperLeg.load("upper_leg.obj");
  leftUpperLeg = GABPuppetLimb(upperLeg);
  rightUpperLeg = GABPuppetLimb(upperLeg);
  
  headModel.load("head2.obj");
  head = GABPuppetLimb(headModel);

	
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
		
	} else {
		
		currentFileName = _filename;
		cout << currentFileName << endl;
	}
		
}

/*

void testApp::setupPlayback(string _filename) {
	
	playContext.clear();
	playContext.setupUsingRecording(ofToDataPath(_filename));
	playDepth.setup(&playContext);
	playImage.setup(&playContext);
	playUser.setup(&playContext, &playDepth, &playImage);
	
	
	playDepth.toggleRegisterViewport(&playImage);
	playContext.toggleMirror();
	
}
 */

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
    //torsoBegin = recordUser.getTrackedUsers()[0]->right_shoulder.begin;
    
    // to center of this line
    //torsoBegin = (recordUser.getTrackedUsers()[0]->hip.end - recordUser.getTrackedUsers()[0]->hip.begin) / 2;
    torsoEnd = (recordUser.getTrackedUsers()[0]->hip.end + recordUser.getTrackedUsers()[0]->hip.begin) / 2;
    
    
    
  }
  
}

//--------------------------------------------------------------
void testApp::draw(){
	
	ofSetColor(255, 255, 255);
	
	glPushMatrix();
	glScalef(0.75, 0.75, 0.75);
	
	//if (isLive) {
		
		//recordDepth.draw(0,0,640,480);
		//recordImage.draw(640, 0, 640, 480);
		//if (isTracking) {
			
			//recordUser.draw();
      
      //cout << "x: " << recordUser.getTrackedUser(1)->left_lower_arm.begin.x << endl;
      
              
			/*if(isMasking) {
				glEnable(GL_BLEND);
				glBlendFunc(GL_DST_COLOR, GL_ZERO);
				recordUser.drawUserMasks(640, 0);
				glDisable(GL_BLEND);
			}*/
		//}
		
		/*if (isCloud) {
			recordUser.drawPointCloud(isCPBkgnd);
		}*/
		
/*	} else {
		
		playDepth.draw(0,0,640,480);
		playImage.draw(640, 0, 640, 480);
		if (isTracking) {
			
			playUser.draw();
     
      
			if(isMasking) {
				glEnable(GL_BLEND);
				glBlendFunc(GL_DST_COLOR, GL_ZERO);
				playUser.drawUserMasks(640, 0);
				glDisable(GL_BLEND);
			}
		}
		
		if (isCloud) {
			playUser.drawPointCloud(isCPBkgnd);
		}
		
	}*/
	
	glPopMatrix();
	
	ofSetColor(255, 255, 0);
	/*
	string msg1, msg2, msg3;	//drawBitmapString is limited to some numebr of characters -> is this a bug in 007 or always the case?
	
	msg1 += "Press 's' to start/stop recording\n";
	msg1 += "Press 'p' to toggle playback/live streams\n";
	msg1 += "Press 't' to toggle tracking\n";
	msg2 += "Press 'm' to toggle drawing Masks\n";
	msg2 += "Press 'c' to toggle draw Cloud points\n";
	msg2 += "Press 'b' to toggle Cloud User data (ie., background removal)\n\n";
	
	msg3 += (string)(isTracking ? "TRACKING USERS\n" : "NOT TRACKING USERS\n");
	msg3 += (string)(isLive ? "LIVE STREAM\n" : "PLAY STREAM\n");
	msg3 += (string)(!isRecording ? "READY\n" : "RECORDING\n");
	msg3 += "MASK DRAWING: " + (string)(!isMasking ? "HIDE\n" : (string)(isTracking ? "SHOW\n" : "YOU NEED TO TURN ON TRACKING!!\n"));
	msg3 += "CLOUD DRAWING: " + (string)(isCloud ? "ON\n" : "OFF\n");
	msg3 += "CLOUD USERDATA/BACKGROUND: " + (string)(isCPBkgnd ? "SHOW BACKGROUND\n" : (string)(isTracking ? "SHOW USER\n" : "YOU NEED TO TURN ON TRACKING!!\n"));
	msg3 += "FPS: " + ofToString(ofGetFrameRate()) + "\n";
	
	ofDrawBitmapString(msg1, 20, 500);
	ofDrawBitmapString(msg2, 20, 550);
	ofDrawBitmapString(msg3, 20, 600);
	ofDrawBitmapString(currentFileName, 20, 700);
*/
  
  glPushMatrix();
    ofSetColor(500, 100, 100);
    ofTranslate(500, 200, -100);

  
    ofScale(2,2,-2);

  
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
    
  
  cout << "tB x: " << torsoBegin.x << "\ty: " << torsoBegin.y << "\tz: " << torsoBegin.z << endl;

  
    torso.draw();
  
    leftLowerLeg.draw();
    rightLowerLeg.draw();
  
  leftUpperLeg.draw();
  rightUpperLeg.draw();
  
  head.draw();




  glPopMatrix();
    

  
 
 
  glPopMatrix();
	
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	/*switch (key) {
		case 's':
			if (isRecording) {
				oniRecorder.stopRecord();
				isRecording = false;
				break;
			} else {
				setupRecording(generateFileName());
				oniRecorder.startRecord(currentFileName);
				isRecording = true;
				break;
			}
			break;
		case 'p':
			if (currentFileName != "" && !isRecording && isLive) {
				setupPlayback(currentFileName);
				isLive = false;
			} else {
				isLive = true;
			}
			break;
		case 't':
			isTracking = !isTracking;
			break;
		case 'm':
			isMasking = !isMasking;
			break;
		case 'c':
			isCloud = !isCloud;
			break;
		case 'b':
			isCPBkgnd = !isCPBkgnd;
			break;
		default:
			break;
	}	
   */
}
/*
string testApp::generateFileName() {
	
	string _root = "kinectRecord";
	
	string _timestamp = ofToString(ofGetDay()) + 
						ofToString(ofGetMonth()) +
						ofToString(ofGetYear()) +
						ofToString(ofGetHours()) +
						ofToString(ofGetMinutes()) +
						ofToString(ofGetSeconds());
	
	string _filename = (_root + _timestamp + ".oni");
	
	return _filename;
	
}
 */

//--------------------------------------------------------------
void testApp::keyReleased(int key){
	
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
	
/*	if (isLive && isCloud) {
		recordUser.setPointCloudRotation(x);
	} else if (!isLive && isCloud) {
		playUser.setPointCloudRotation(x);
	}
 */
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

