#include "ofMain.h"
#include "ofApp.h"
#include "Consts.h"


//========================================================================
int main( ){
	ofSetupOpenGL(WINDOW_W,WINDOW_H,OF_WINDOW);			// <-------- setup the GL context
    
    #ifdef TARGET_LINUX_ARM
        ofGLESWindowSettings settings;
        settings.glesVersion = 2;
        ofCreateWindow(settings);

    #elif defined(TARGET_OSX)
        ofGLWindowSettings settings;
        settings.setGLVersion(3,2);
    
    #endif
    

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());

}
