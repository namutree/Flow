//
//  flow.cpp
//  humanBioFlow
//
//  Created by John Choi on 3/20/14.
//
//

#include "flow.h"

Flow::Flow(){
    // Initial x position of the ball
    x = ofRandom( ofGetWindowWidth() );
    // Initial y position of the ball
    y = ofGetWindowHeight() ;

}

void Flow::moveTo(){
    
    zMove +=PI/180;
    xMove +=PI/180;
    
    
}

void Flow::remove(){
    
}

void Flow::drawMagenta(int _x, int _y){
    x= _x;
    y= _y;

    int alphaValue = ofMap(y,ofGetHeight(),0,255,0);
    alphaValue = ofClamp(alphaValue, 0, 255);
    
    ofSetColor(255, 0, 169,alphaValue);
    ofSetLineWidth(.5);
    float sinwave =x/2*sin(ofMap(y, ofGetHeight(), 0, 0, 4*PI));
    
    // to make it move big circle. mult 2 to x to make it x-long ellipse
    float x1 = 300*sin(xMove)*2;
    float z1 = 300*cos(zMove);
    
    //line
    ofLine(ofGetWidth()/2-x/2+x1, y+1, sinwave+z1, ofGetWidth()/2+x/2+x1, y+1, -sinwave+z1);
    
    // orthogonal line by adding and substracting dist
    float dist = ofDist(ofGetWidth()/2-x/2+x1, sinwave+z1, ofGetWidth()/2+x/2+x1, -sinwave+z1)/1.414;
    ofLine(ofGetWidth()/2-x/2+x1, y+1, sinwave+z1-dist , ofGetWidth()/2+x/2+x1, y+1, -sinwave+z1+dist);
    
    // rectangular point
    ofSetColor(255, 0, 169, ofRandom(20,200));
    ofRect(ofGetWidth()/2+x/2+x1, y, -sinwave+z1, ofRandom(1,3), ofRandom(1,2));
    ofRect(ofGetWidth()/2-x/2+x1, y, sinwave+z1 , ofRandom(1,3), ofRandom(1,5));
    ofRect(ofGetWidth()/2-x/2+x1, y+1, sinwave+z1-dist,  ofRandom(1,3), ofRandom(1,5));
    ofRect(ofGetWidth()/2+x/2+x1, y+1, -sinwave+z1+dist, ofRandom(1,5), ofRandom(1,3));
    
    //center
    ofRect(ofGetWidth()/2+x1, y, z1, 1, ofRandom(1,3));
 

}


void Flow::drawGreen(int _x, int _y){
    x= _x;
    y= _y;
    
    int alphaValue = ofMap(y,ofGetHeight(),0,255,0);
    alphaValue = ofClamp(alphaValue, 0, 255);
    ofSetColor(164, 238, 0,alphaValue);
    
    float sinwave =x/2*sin(ofMap(y, ofGetHeight(), 0, 0, 4*PI)+PI/7);
    
    float x1 = 300*sin(xMove+PI/2)*2;
    float z1 = 300*cos(zMove+PI/2);
    
    //line
    ofLine(ofGetWidth()/2-x/2+x1, y+1, sinwave+z1, ofGetWidth()/2+x/2+x1, y+1, -sinwave+z1);
    
    // orthogonal line by adding and substracting dist
    float dist = ofDist(ofGetWidth()/2-x/2+x1, sinwave+z1, ofGetWidth()/2+x/2+x1, -sinwave+z1)/1.414;
    ofLine(ofGetWidth()/2-x/2+x1, y+1, sinwave+z1-dist , ofGetWidth()/2+x/2+x1, y+1, -sinwave+z1+dist);
    

    ofSetColor(164, 238, 0, 200);
    ofRect(ofGetWidth()/2+x/2+x1, y, -sinwave+z1, ofRandom(1,3), ofRandom(1,2));
    ofRect(ofGetWidth()/2-x/2+x1, y, sinwave+z1 , ofRandom(1,3), ofRandom(1,5));
    ofRect(ofGetWidth()/2-x/2+x1, y+1, sinwave+z1-dist,  ofRandom(1,3), ofRandom(1,5));
    ofRect(ofGetWidth()/2+x/2+x1, y+1, -sinwave+z1+dist, ofRandom(1,5), ofRandom(1,3));
    
    //center
    ofRect(ofGetWidth()/2+x1, y, z1, 1, ofRandom(1,3));
    
}

void Flow::drawBlue(int _x, int _y){
    x= _x;
    y= _y;
    
    int alphaValue = ofMap(y,ofGetHeight(),0,255,0);
    alphaValue = ofClamp(alphaValue, 0, 255);
    ofSetColor(0, 176, 255,alphaValue);
    
    float sinwave =x/2*sin(ofMap(y, ofGetHeight(), 0, 0, 4*PI)+PI/9);
    
    float x1 = 300*sin(xMove+PI)*2;
    float z1 = 300*cos(zMove+PI);
    
    //line
    ofLine(ofGetWidth()/2-x/2+x1, y+1, sinwave+z1, ofGetWidth()/2+x/2+x1, y+1, -sinwave+z1);
    
    // orthogonal line by adding and substracting dist
    float dist = ofDist(ofGetWidth()/2-x/2+x1, sinwave+z1, ofGetWidth()/2+x/2+x1, -sinwave+z1)/1.414;
    ofLine(ofGetWidth()/2-x/2+x1, y+1, sinwave+z1-dist , ofGetWidth()/2+x/2+x1, y+1, -sinwave+z1+dist);
    
    ofSetColor(0, 176, 255, 200);
    ofRect(ofGetWidth()/2+x/2+x1, y, -sinwave+z1, ofRandom(1,3), ofRandom(1,2));
    ofRect(ofGetWidth()/2-x/2+x1, y, sinwave+z1 , ofRandom(1,3), ofRandom(1,5));
    ofRect(ofGetWidth()/2-x/2+x1, y+1, sinwave+z1-dist,  ofRandom(1,3), ofRandom(1,5));
    ofRect(ofGetWidth()/2+x/2+x1, y+1, -sinwave+z1+dist, ofRandom(1,5), ofRandom(1,3));
    
    //center
    ofRect(ofGetWidth()/2+x1, y, z1, 1, ofRandom(1,3));
    

}


void Flow::drawWhite(int _x, int _y){
    x= _x;
    y= _y;
    
    int alphaValue = ofMap(y,ofGetHeight(),0,255,0);
    alphaValue = ofClamp(alphaValue, 0, 255);
    ofSetColor(255, 255, 255,alphaValue);
    
    float sinwave =x/2*sin(ofMap(y, ofGetHeight(), 0, 0, 4*PI)+PI/11);
    
    float x1 = 300*sin(xMove+PI*3/2)*2;
    float z1 = 300*cos(zMove+PI*3/2);
    
    //line
    ofLine(ofGetWidth()/2-x/2+x1, y+1, sinwave+z1, ofGetWidth()/2+x/2+x1, y+1, -sinwave+z1);
    
    // orthogonal line by adding and substracting dist
    float dist = ofDist(ofGetWidth()/2-x/2+x1, sinwave+z1, ofGetWidth()/2+x/2+x1, -sinwave+z1)/1.414;
    ofLine(ofGetWidth()/2-x/2+x1, y+1, sinwave+z1-dist , ofGetWidth()/2+x/2+x1, y+1, -sinwave+z1+dist);
    
    
    ofSetColor(255, 255, 255, 200);
    ofRect(ofGetWidth()/2+x/2+x1, y, -sinwave+z1, ofRandom(1,3), ofRandom(1,2));
    ofRect(ofGetWidth()/2-x/2+x1, y, sinwave+z1 , ofRandom(1,3), ofRandom(1,5));
    ofRect(ofGetWidth()/2-x/2+x1, y+1, sinwave+z1-dist,  ofRandom(1,3), ofRandom(1,5));
    ofRect(ofGetWidth()/2+x/2+x1, y+1, -sinwave+z1+dist, ofRandom(1,5), ofRandom(1,3));
    
    //center
    ofRect(ofGetWidth()/2+x1, y, z1, 1, ofRandom(1,3));
    

}

