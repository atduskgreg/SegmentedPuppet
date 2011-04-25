/*
 *  puppetLimb.h
 *  segmentedPuppet
 *
 *  Created by Greg Borenstein on 4/24/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "ofxVec3f.h"
#include "ofxOBJModel.h"

class GABPuppetLimb  {
public:
  
  GABPuppetLimb( ofxOBJModel _model );
  GABPuppetLimb();
  
  ofxOBJModel model;

  ofxVec3f startJoint;
  ofxVec3f endJoint;
  
  void updateControl( ofxVec3f _startJoint, ofxVec3f _endJoint);
  void draw();

private:
  ofxVec3f controlOrientation;

};