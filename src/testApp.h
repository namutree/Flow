#pragma once

#include "ofMain.h"
#include "flow.h"
#include "ofxOsc.h"

// listen on port 12345
#define PORT 12345
#define NUM_MSG_STRINGS 20

class testApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    void lines(int x, int y);
    
    Flow theFlow;
    vector<int> smokePu;
    vector<int> smokePu2;
    vector<int> smokeAt;
    vector<int> smokeMe;
    vector<int> smokeBr;
    
    int smokeUp;
    
    float t;
    
    ofxOscReceiver receiver;
    
    int pulse, pulse2, attention, meditation, breath;
    
    ofMesh mesh;
    
    ofCamera cam;

};
