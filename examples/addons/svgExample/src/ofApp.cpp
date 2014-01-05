#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetVerticalSync(true);
	
	ofBackground(0);
	ofSetColor(255);
	
    ofDirectory dir;
    dir.allowExt("svg");
    dir.listDir(ofToDataPath("."));
    dir.sort();
    
    for(int i = 0; i < dir.size(); i++){
        ofxSVG fooSVG;
        fooSVG.load(dir.getFile(i).path());
        for (int j = 0; j < fooSVG.getNumPath(); j++){
            ofPath p = fooSVG.getPathAt(j);
            // svg defaults to non zero winding which doesn't look so good as contours
            p.setPolyWindingMode(OF_POLY_WINDING_ODD);
            vector<ofPolyline>& lines = p.getOutline();
            vector<ofPolyline> outline;
            for(int k=0;k<(int)lines.size();k++){
                outline.push_back(lines[k].getResampledBySpacing(1));
            }
            outlines.push_back(outline);
        }
        svg.push_back(fooSVG);
    }
    index = 0;
    
    width = svg[index].getWidth();
    height = svg[index].getHeight();
}


//--------------------------------------------------------------
void ofApp::update(){
	step += 0.001;
	if (step > 1) {
		step -= 1;
	}
    
    if(ofGetHeight() != height || ofGetWidth() != width){
        height = svg[index].getHeight();
        width = svg[index].getWidth();
        ofSetWindowShape((int)width, (int)height);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
//	ofDrawBitmapString(ofToString(ofGetFrameRate()),20,20);
//	ofPushMatrix();
//	ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
//	ofRotate(mouseX);
//	float scale = ofMap(mouseY, 0, ofGetHeight(), .5, 10);
//	ofScale(scale, scale, scale);
//	ofTranslate(-250, -250);
//	if(ofGetMousePressed()) {
//		ofNoFill();
//		for (int i = 0; i < (int)outlines.size(); i++){
//            for(int j = 0; i < outlines[i].size(); j++){
//                ofPolyline & line = outlines[i][j];
//                
//                int num = step * line.size();
//                
//                ofBeginShape();
//                for (int j = 0; j < num; j++){
//                    ofVertex(line[j]);
//                }
//                ofEndShape();
//            }
//		}
//	} else {
    ofPushMatrix();
    ofTranslate((ofGetWidth()-svg[index].getWidth())/2, (ofGetHeight()-svg[index].getHeight())/2);
    svg[index].draw();

    ofPopMatrix();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    index  = (index+1)%svg.size();
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){
	
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
void ofApp::windowResized(int w, int h){
	
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
	
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
	
}
