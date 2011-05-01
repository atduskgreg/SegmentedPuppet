/*
 *  puppetLimb.cpp
 *  segmentedPuppet
 *
 *  Created by Greg Borenstein on 4/24/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "GABPuppetLimb.h"


GABPuppetLimb::GABPuppetLimb() {
  //GABPuppetLimb::GABPuppetLimb( ofxVec3f(0,1,0) );
}

GABPuppetLimb::GABPuppetLimb( ofxOBJModel _model ) {
  model = _model;
}

void GABPuppetLimb::updateControl( ofxVec3f _startJoint, ofxVec3f _endJoint){
  startJoint = _startJoint;
  endJoint = _endJoint;
  
  controlOrientation = endJoint - startJoint;
}


void GABPuppetLimb::draw() {
  ofPushMatrix();
  
    ofxVec3f modelOrientation = ofxVec3f(0,1,0);


  ofTranslate(startJoint.x, startJoint.y, startJoint.z);

    // Axis-Angle algorithm derived from: http://www.euclideanspace.com/maths/algebra/vectors/angleBetween/index.htm
    float angle =   acos(modelOrientation.dot(controlOrientation.normalize()));
  
    ofxVec3f axis = modelOrientation.cross(controlOrientation.normalize()).normalize(); 
  
    ofRotate(ofRadToDeg(angle), axis.x, axis.y, axis.z);
  
  
  /*  ofPoint modelMin;
    ofPoint modelMax;
  
    model.getBounds(&modelMin, &modelMax);
  
    float modelLength = modelMax.y - modelMin.y;
    float jointLength = endJoint.y - startJoint.y;
  
    ofScale(1, jointLength/modelLength, 1 );
   */
    model.draw();
  ofPopMatrix();
}