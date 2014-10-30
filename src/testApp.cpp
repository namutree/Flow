#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    // Smooth edges
    ofEnableSmoothing();
    //ofEnableBlendMode(OF_BLENDMODE_SCREEN);
    ofEnableAlphaBlending();
    //ofEnableAntiAliasing();
    
    // Fixed framerate
    ofSetFrameRate(30);
    
    
    smokeUp =0;
    //ofSetBackgroundAuto(false);
    ofBackground(0);
    
    receiver.setup(PORT);
    mesh.setMode(OF_PRIMITIVE_LINES);
    mesh.enableColors();
    mesh.enableIndices();
    
    pulse = 0;
    pulse2 = 0;
    attention = 0;
    meditation = 0;
    breath = 0;
    
}

//--------------------------------------------------------------
void testApp::update(){
    while(receiver.hasWaitingMessages()){
        
        ofxOscMessage p;
        receiver.getNextMessage(&p);
        if (p.getAddress() == "/pulse"){
            pulse = p.getArgAsInt32(0);
        }
        
        ofxOscMessage p2;
        receiver.getNextMessage(&p2);
        if (p2.getAddress() == "/pulse2"){
            pulse2 = p2.getArgAsInt32(0);
        }
        
        ofxOscMessage a;
        receiver.getNextMessage(&a);
        if (a.getAddress() == "/attention"){
            attention = a.getArgAsInt32(0);
        }
        
        ofxOscMessage m;
        receiver.getNextMessage(&m);
        if (m.getAddress() == "/meditation"){
            meditation = m.getArgAsInt32(0);
        }
        
        ofxOscMessage b;
        receiver.getNextMessage(&b);
        if (b.getAddress() == "/breath"){
            breath = b.getArgAsInt32(0);
        }
    }
}


//--------------------------------------------------------------
void testApp::draw(){
    
    int backgroundColor = ofMap(breath,0,255,10,150);
     ofBackgroundGradient(ofColor(backgroundColor),ofColor(0,0,0), OF_GRADIENT_CIRCULAR);
    
    //ofDrawBitmapString(ofToString(mouseX), 100,100);

    
    ofPopMatrix();
    //cam start
    cam.begin();
    cam.setPosition(ofGetWidth()/2,ofGetHeight()/2+700,1000);
    cam.lookAt(ofVec3f(ofGetWidth()/2+100,ofGetHeight()/2,-500));
    ofRotateX(180);
    
    
    
    ofTranslate(0,-ofGetHeight()-50);
    
    //PULSE magenta
    ofPushStyle();
    smokePu.push_back(pulse);
    for (int i=0; i < smokePu.size(); i++) {
        int waveY = ofMap(i,0,smokePu.size(),smokePu.size(),0)*4;
            theFlow.drawMagenta(smokePu[i], ofGetHeight()-waveY-150);
    }
    if (smokePu.size()>ofGetHeight()/3){
        smokePu.erase(smokePu.begin());
    }
    ofPopStyle();
    
    //center pulse line
    //ofSetPolyMode(OF_POLY_WINDING_POSITIVE);
    ofNoFill();
    ofBeginShape( );
    smokePu2.push_back(pulse2);
    ofSetColor(255, 0, 169,50);
     for (int i=0; i < smokePu2.size(); i++) {
         int waveX = (smokePu2.size()-i)*8;
         int waveY = 400 - smokePu2[i];
         ofVertex(waveX-260, ofGetHeight()/2-waveY);
     }
    ofEndShape(false);
    
    ofBeginShape( );
    for (int i=0; i < smokePu2.size(); i++) {
        int waveX = (smokePu2.size()-i)*8;
        int waveY = ofMap(400 - smokePu2[i],-200,200,-185,185);
        ofVertex(waveX-260, ofGetHeight()/2-waveY);
    }
    ofEndShape(false);
    
    ofBeginShape( );
    ofSetColor(255, 255, 0,50);
    for (int i=0; i < smokePu2.size(); i++) {
        int waveX = (smokePu2.size()-i)*8;
        int waveY = ofMap(400 - smokePu2[i],-200,200,-150,150);
        ofVertex(waveX-260, ofGetHeight()/2- waveY);
    }
    ofEndShape(false);
    
    ofBeginShape( );
    for (int i=0; i < smokePu2.size(); i++) {
        int waveX = (smokePu2.size()-i)*8;
        int waveY = ofMap(400 - smokePu2[i],-200,200,-135,135);
        ofVertex(waveX-260, ofGetHeight()/2- waveY);
    }
    ofEndShape(false);
    
    ofFill();
    
    
    if (smokePu2.size()>ofGetWidth()/4){
        smokePu2.erase(smokePu2.begin());
    }
    
    cout <<smokePu2.size() << endl;
    
    //ATTENTION green
    smokeAt.push_back(attention);
    for (int i=0; i < smokeAt.size(); i++) {
        ofSetColor(164, 238, 0);
        int waveY = ofMap(i,0,smokeAt.size(),smokeAt.size(),0)*4;
        theFlow.drawGreen(smokeAt[i], ofGetHeight()-waveY-150);
    }
    
    if (smokeAt.size()>ofGetHeight()/3){
        smokeAt.erase(smokeAt.begin());
    }
   
    
    //Breath white
    smokeBr.push_back(breath);
    for (int i=0; i < smokeBr.size(); i++) {
        ofSetColor(255, 255, 255);
        int waveY = ofMap(i,0,smokeBr.size(),smokeBr.size(),0)*4;
        theFlow.drawBlue(smokeBr[i], ofGetHeight()-waveY-150);
    }
    
    if (smokeBr.size()>ofGetHeight()/3){
        smokeBr.erase(smokeBr.begin());
    }

    
    //MEDITATION blue
    smokeMe.push_back(meditation);
    
    for (int i=0; i < smokeMe.size(); i++) {
        ofSetColor(0, 176, 255);
        int waveY = ofMap(i,0,smokeMe.size(),smokeMe.size(),0)*4;
        theFlow.drawWhite(smokeMe[i], ofGetHeight()-waveY-150);
    }
    
    if (smokeMe.size()>ofGetHeight()/3){
        smokeMe.erase(smokeMe.begin());
    }
    
    
    //cout <<    pulse << " " <<   attention << " " <<  meditation<< " " << breath <<endl;


    //ofDrawBitmapString(ofToString( ofGetFrameRate()), 20,20);
    theFlow.moveTo();
    
    
    
    cam.end();
    
    
ofPushMatrix();
    
    ofPushStyle();
    ofSetColor(255);
    ofDrawBitmapString("Heart Beat: ", ofGetWidth()/2-70,ofGetHeight()-100);
    ofDrawBitmapString(ofToString(smokePu[smokePu.size()-1]), ofGetWidth()/2+80,ofGetHeight()-100);
    ofDrawBitmapString("Attention Level: ", ofGetWidth()/2-70,ofGetHeight()-80);
    ofDrawBitmapString(ofToString(smokeAt[smokeAt.size()-1]), ofGetWidth()/2+80,ofGetHeight()-80);
    ofDrawBitmapString("Breath: ", ofGetWidth()/2-70,ofGetHeight()-60);
    ofDrawBitmapString(ofToString(smokeBr[smokeBr.size()-1]), ofGetWidth()/2+80,ofGetHeight()-60);
    ofDrawBitmapString("Meditation Level: ", ofGetWidth()/2-70,ofGetHeight()-40);
    ofDrawBitmapString(ofToString(smokeMe[smokeMe.size()-1]), ofGetWidth()/2+80,ofGetHeight()-40);
    ofPopStyle();
}

void testApp::lines(int x, int y){
    ofSetColor(255);
    ofLine(ofGetWidth()/5-x/2,y,ofGetWidth()/5+x/2,y);
    
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

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 
    
}
