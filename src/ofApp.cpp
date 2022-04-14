#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofColor offWhite(220);
    ofSetFrameRate(60);
    ofSetBackgroundColor(offWhite);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    int numOfTilesX = 11;
    int numOfTilesY = 10;
    int spacingX = ofGetWidth() / numOfTilesX;
    int spacingY = ofGetHeight() / numOfTilesY;
    int startX = spacingX / 2;
    int startY = spacingY / 2;

    for (int i = 0; i < numOfTilesX; i++)
    {
        for (int j = 0; j < numOfTilesY; j++)
        {
            int locX = startX + i * spacingX;
            int locY = startY + j * spacingY;

            ofColor black = ofColor(42);
            ofColor nearBlack = ofColor(5, 15);
            ofColor nearWhite = ofColor(250, 95);
            ofColor darkGray = ofColor(42, 200);
            ofColor blue = ofColor(80, 200, 250, 100);
            ofColor green = ofColor(100, 250, 180, 100);
            ofColor red = ofColor(200, 150, 150, 100);
            ofColor yellow = ofColor(220, 220, 82, 200);
            
            if (i % 2 != 0) {
                int rot = j % 2 == 0 ? 180 : 0;
                
                for (int k = 0; k < 3; k++) {
                    textureTile(locX, locY, rot, 1.8 - k * 0.5, nearWhite, true);
                }
                
                for (int k = 0; k < 3; k++) {
                    textureTile(locX, locY + 5, rot, 1.8 - k * 0.5, nearBlack, true);
                }
                
                if (j % 2 == 0) {
                    textureTile(locX + 2, locY - 0, 180, .6, yellow, true);
                    textureTile(locX + 2, locY - 2, 180, 1, yellow, true);
                } else {
                    textureTile(locX - 0, locY + 5, 0, .6, darkGray, true);
                    textureTile(locX - 0, locY + 7, 0, .8, darkGray, true);
                }
                
            } else {
                textureTile(locX, locY + 20, 180, 3.80, nearWhite, true);
                textureTile(locX - 20, locY - 20, 180, 3.80, blue, true);
                textureTile(locX + 20, locY - 20, 180, 3.80, green, true);
                textureTile(locX, locY + 20, 0, 3.80, red, true);
                
                if (j % 2 == 0) {
                    textureTile(locX, locY, 0, 5, black, false);
                    textureTile(locX - 1, locY - 1, 0, 5, black, false);
                    textureTile(locX, locY, 180, 5, black, false);
                } else {
                    textureTile(locX, locY, 0, 5, black, false);
                    textureTile(locX, locY, 180, 5, black, false);
                    textureTile(locX + 1, locY + 1, 180, 5, black, false);
                }
            }
        }
    }
}

void ofApp::textureTile(int x, int y, int degrees, float scale, ofColor color, bool fill){
    ofPushMatrix();
    ofPushStyle();

    ofTranslate(x,y);
    ofRotateDeg(degrees);
    ofScale(scale);

    ofSetColor(color);
    if(fill){
        ofFill();
    }else{
        ofNoFill();
    }

    //Do your own drawing here
    ofDrawTriangle(0,-20,-20,20,20,20);

    ofPopStyle();
    ofPopMatrix();
}
