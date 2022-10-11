//  CS 134 - In-Class exercise - Getting started with Particle Physics
//
//  Kevin M. Smith - CS 134 - SJSU CS

#include "ofApp.h"






//--------------------------------------------------------------
//  Setup Application data
//
void ofApp::setup(){
	cam.setDistance(10);
	cam.setNearClip(.1);
	cam.setFov(65.5);   // approx equivalent to 28mm in 35mm format
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
    

	// some simple sliders to play with parameters
	//
	gui.setup();
	gui.add(velocity.setup("Initial Velocity", ofVec3f(0, 20, 0), ofVec3f(-100,-100, 0), ofVec3f(100, 100, 100)));	
	gui.add(lifespan.setup("Lifespan", 2.0, .1, 10.0));
	gui.add(rate.setup("Rate", 1.0, .5, 60.0));
	gui.add(damping.setup("Damping", .99, .1, 1.0));
    gui.add(gravity.setup("Gravity", ofVec3f(0, 10, 0), ofVec3f(0,0,0), ofVec3f(0,100,0)));
	gui.add(radius.setup("Radius", .1, .01, .3));
    gui.add(turbmin.setup("turbmin", ofVec3f(0,0,0), ofVec3f(-100,-100,0),ofVec3f(100,100,100)));
    gui.add(turbmax.setup("turbmax", ofVec3f(0,0,0), ofVec3f(-100,-100,0),ofVec3f(100,100,100)));
    //make vec3 sliders for min and max for turbulence 
    //assign the values of these sliders to the pointer to turbulence using the .set function
    //
    //turb.set(min,max)
	bHide = false;

	//
	// setup any objects you've created here...

    emitter.start();
    force = new GravityForce(ofVec3f(0, 0, 0));
    turb = new TurbulenceForce(ofVec3f(0),ofVec3f(0));
    emitter.sys->addForce(turb);
    emitter.sys->addForce(force);
}

//--------------------------------------------------------------
//
void ofApp::update() {
	//
	// update objects you've created here
    
    emitter.update();
    emitter.setRate(rate);
    emitter.setLifespan(lifespan);
    emitter.setParticleRadius(radius);
    emitter.setVelocity(ofVec3f(velocity->x,velocity->y,velocity->z));
    turb->set(ofVec3f(turbmin->x,turbmin->y,turbmin->z),ofVec3f(turbmax->x,turbmax->y,turbmax->z));
    force->set(ofVec3f(gravity->x,gravity->y,gravity->z));
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetBackgroundColor(ofColor::black);

	// draw the GUI
	if (!bHide) gui.draw();

	// begin drawing inthe camera
	//
	cam.begin();

	// draw a grid
	//
	ofPushMatrix();
	ofRotate(90, 0, 0, 1);
	ofSetLineWidth(1);
	ofSetColor(ofColor::dimGrey);
	ofDrawGridPlane();
	ofPopMatrix();

	//
	// draw any other objects here...
	//
    emitter.draw();


	//  end drawing in the camera
	// 
	cam.end();

	// draw screen data
	//
	string str;
	str += "Frame Rate: " + std::to_string(ofGetFrameRate());
	ofSetColor(ofColor::white);
	ofDrawBitmapString(str, ofGetWindowWidth() -170, 15);
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){

	switch (key) {
	case 'C':
	case 'c':
		if (cam.getMouseInputEnabled()) cam.disableMouseInput();
		else cam.enableMouseInput();
		break;
	case 'F':
	case 'f':
		ofToggleFullscreen();
		break;
	case 'h':
		bHide = !bHide;
	case ' ':
		break;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
