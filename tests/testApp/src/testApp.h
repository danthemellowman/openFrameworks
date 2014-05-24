#pragma once

#include "ofMain.h"

class testApp : public ofBaseApp{
    
public:
    testApp();
    ~testApp();
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
    
    virtual void onTestPass(ofEventArgs & args){}
    virtual void onTestFail(ofEventArgs & args){}
    virtual void onTestTimeout(ofEventArgs & args){}
    virtual void onTestError(ofEventArgs & args){}
    
    virtual void simKeyPressed(int key){}
    virtual void simKeyReleased(int key){}
    virtual void simMouseMoved(int x, int y ){}
    virtual void simMouseDragged(int x, int y, int button){}
    virtual void simMousePressed(int x, int y, int button){}
    virtual void simMouseReleased(int x, int y, int button){}
    virtual void simWindowResized(int w, int h){}
    virtual void simDragEvent(ofDragInfo dragInfo){}
    virtual void simGotMessage(ofMessage msg){}

protected :
    
    string mTestName;
    ofXml mTests;
    ofXml mExpectedResults;

};
