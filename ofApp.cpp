#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(25);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);
	ofSetCircleResolution(60);

	this->seed_value = ofRandom(1000);
}

//--------------------------------------------------------------
void ofApp::update() {

	if (ofGetFrameNum() % 25 < 5) {
	
		this->seed_value = ofRandom(10000);
	}

	ofSeedRandom(this->seed_value);
}


//--------------------------------------------------------------
void ofApp::draw() {

	int span = 72;
	for (int x = span * 1.5; x < ofGetWindowWidth() - span * 0.5; x += span) {

		for (int y = span * 1.5; y < ofGetWindowHeight() - span * 0.5; y += span) {

			auto center = glm::vec2(x, y);
			auto radius = span * 0.4;
			auto flag = ofRandom(100) < 50 ? true : false;

			for (int draw_radius = radius; draw_radius > 0;) {

				flag ? ofSetColor(39, 39, 239) : ofSetColor(239);
				ofDrawCircle(center, draw_radius);

				flag = !flag;

				auto tmp_radius = draw_radius;
				draw_radius *= ofRandom(0.5, 0.9);
			}
		}
	}

	/*
	int start = 45;
	if (ofGetFrameNum() > start) {

		ostringstream os;
		os << setw(4) << setfill('0') << ofGetFrameNum() - start;
		ofImage image;
		image.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
		image.saveImage("image/cap/img_" + os.str() + ".jpg");
		if (ofGetFrameNum() - start >= 25 * 20) {

			std::exit(1);
		}
	}
	*/
}


//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}