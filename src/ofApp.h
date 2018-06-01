#pragma once

#include "ofMain.h"
#include "ofxMidi.h"
#include "vidLayer.h"
#include "ofxCv.h"
#include "ofxCvPiCam.h"
#include "Utils.h"
#include "ofxXmlSettings.h"
#include "ConsoleListener.h"

//for Raspberry Pi


#ifdef TARGET_LINUX_ARM

    //#include "TerminalListener.h"
    #include "ofxRPiCameraVideoGrabber.h"

#endif

//use extern variables to have access across files

extern float camThresh;
extern float camSoftness;
extern float camInvert;
extern float camOpacity;

extern int CAM_DEV_ID;
extern int CAM_W;
extern int CAM_H;
extern int THUMB_W;
extern int THUMB_H;
extern int CAM_FPS;

//debug mode

extern int DEBUG_MODE;

//recording layers
extern int LAYER_COUNT;
extern int FRAME_COUNT;

//render window
extern int WINDOW_W;
extern int WINDOW_H;

//MIDI Controller Numbers
extern int MIDI_PORT;
extern int MIDI_REC;
extern int MIDI_SCALE;
extern int MIDI_XPOS;
extern int MIDI_YPOS;

extern int MIDI_SHADER_BYPASS;
extern int MIDI_SHADER_THRESH;
extern int MIDI_SHADER_SOFT;
extern int MIDI_CHANNEL_SELECT;
extern int MIDI_SHADER_INVERT;
extern int MIDI_SHADER_OPACITY;
extern int MIDI_SHADER_CAM_OPACITY;
extern int MIDI_SHADER_CAM_THRESH;
extern int MIDI_SHADER_CAM_SOFT;
extern int MIDI_SHADER_CAM_INVERT_ON;
extern int MIDI_SHADER_CAM_INVERT_OFF;



//default layer settings
extern float LAYER_SCALE;
extern float SHADER_THRESH;
extern float SHADER_INVERT;
extern float SHADER_SOFT;
extern float SHADER_OPACITY;
extern int SHADER_ACTIVE;
extern int MIDI_KNOB_MODE;

//extern string SHADER_MASK;
extern int USE_OFXCVPI;

//camera settings
extern int EV_COMPENSATION;
extern int FLICKER_CANCELATION;

extern int CAM_SHARPNESS;
extern int CAM_CONTRAST;
extern int CAM_BRIGHTNESS;
extern int CAM_SATURATION;

extern int SERVO_1_IN;
extern int SERVO_2_IN;
extern int SERVO_1_OUT;
extern int SERVO_2_OUT;

class ofApp : public ofBaseApp, public ofxMidiListener {

	public:

		void setup();
		void update();
    void draw();
    void drawCam(int x, int y);
    void drawMIDI();
		void flipKnob();
    void exit();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

    ofTexture nowTexture;
    ofPixels nowPixels;

    int counter;
    float scale = 1;
		bool knobMode;
		ofImage     img;
    float thresh;
    float pThresh;

    // for MIDI
    void newMidiMessage(ofxMidiMessage& eventArgs);

    stringstream text;

    ofxMidiIn midiIn;
    ofxMidiMessage midiMessage;
    ofxMidiOut midiOut;

    // for shader params
    ofShader camShader;
    ofImage camShaderMask;
    ofTexture camShaderMaskTex;

    float camShaderActive;


    // Video layers
    vector < vidLayer > vidLayers;

    // Live Camera

    #ifdef TARGET_LINUX_ARM

            /*
            void onCharacterReceived(KeyListenerEventData& e)
            {
                keyPressed((int)e.character);
            };
            */
            //TerminalListener consoleListener;

            OMXCameraSettings omxCameraSettings;
            ofxRPiCameraVideoGrabber videoGrabber;
            ofxCvPiCam videoGrabber2;


        #elif defined(TARGET_OSX)

            ofxRPiCameraVideoGrabber videoGrabber;

        #endif


        //XML settings related
        ofxXmlSettings XML;



    };
