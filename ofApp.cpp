#include "ofApp.h"

void ofApp::setup(){
	ofBackground(0);

	// Enable or disable audio for video sources globally
	// Set this to false to save resources on the Raspberry Pi
	ofx::piMapper::VideoSource::enableAudio = true;
	ofx::piMapper::VideoSource::useHDMIForAudio = false;

	// Add our CustomSource to list of fbo sources of the piMapper
	// FBO sources should be added before piMapper.setup() so the
	// piMapper is able to load the source if it is assigned to
	// a surface in XML settings.
    movingRectSource1 = new MovingRectSource();
    piMapper.registerFboSource(movingRectSource1);
    movingRectSource1->setColor(ofColor(255,0,0)); //call the functions to differentiate the buffer, after "registering it"
    movingRectSource1->setName("red moving rect");

    movingRectSource2 = new MovingRectSource();
    piMapper.registerFboSource(movingRectSource2);
    movingRectSource2->setColor(ofColor(0,255,0)); //call the functions to differentiate the buffer, after "registering it"
    movingRectSource2->setName("green moving rect");

    customSource = new CustomSource();
    piMapper.registerFboSource(customSource);

    arcGrid = new ArcGrid();
    piMapper.registerFboSource(arcGrid);
    arcGrid->setName("arc grid");

	piMapper.setup();

	// The info layer is hidden by default, press <i> to toggle
	// piMapper.showInfo();
	
	ofSetFullscreen(Settings::instance()->getFullscreen());
	ofSetEscapeQuitsApp(false);

    dummyObjects.load("dummy-objects.png");
}

void ofApp::update(){
	piMapper.update();
}

void ofApp::draw(){
    dummyObjects.draw(200,200);
    piMapper.draw();
}

void ofApp::keyPressed(int key){
	piMapper.keyPressed(key);
}

void ofApp::keyReleased(int key){
	piMapper.keyReleased(key);
}

void ofApp::mousePressed(int x, int y, int button){
	piMapper.mousePressed(x, y, button);
}

void ofApp::mouseReleased(int x, int y, int button){
	piMapper.mouseReleased(x, y, button);
}

void ofApp::mouseDragged(int x, int y, int button){
	piMapper.mouseDragged(x, y, button);
}
