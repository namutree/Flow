//
//  flow.h
//  humanBioFlow
//
//  Created by John Choi on 3/20/14.
//
//

#ifndef humanBioFlow_flow_h
#define humanBioFlow_flow_h

#include "ofMain.h"

class Flow {
public:
    // Constructor
    Flow();
    
    // Methods
    void moveTo();
    void drawMagenta(int _x, int _y);
    void drawGreen(int _x, int _y);
    void drawBlue(int _x, int _y);
    void drawWhite(int _x, int _y);
    void remove();
    
    // Properties
    int x;
    int y;
    ofColor color;

    
    
    float xMove;
    float zMove;
        
};


#endif
