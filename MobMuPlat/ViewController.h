//
//  ViewController.h
//  MobMuPlat
//
//  Created by Daniel Iglesia on 11/15/12.
//  Copyright (c) 2012 Daniel Iglesia. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <CoreMotion/CoreMotion.h>
#import <CoreLocation/CoreLocation.h>
#import "PdAudioController.h"
#import "PdBase.h"


#import "JSONKit.h"

#import "SettingsViewController.h"
#import "MeControl.h"
#import "PGMidi.h"
#import "VVOSC.h"


//@class OSCManager, OSCInPort, OSCOutPort;



@interface ViewController : UIViewController<PdReceiverDelegate, UIAccelerometerDelegate,  SettingsViewControllerDelegate, ControlDelegate, UIScrollViewDelegate, AudioSettingsDelegate, PGMidiDelegate, PGMidiSourceDelegate, OSCDelegateProtocol, PdMidiReceiverDelegate, CLLocationManagerDelegate>{
    
    
    UIButton * settingsButton;
    UILabel* patchOnlyLabel;
    UIView* scrollInnerView;
    
    NSMutableArray* allGUIControl;
    UIScrollView* scrollView;
    
    OSCManager *manager;
	OSCInPort *inPort;
	OSCOutPort *outPort;
    //for disconnect/reconnect
    int currPortNumber;
    
    //midi
    PGMidi *midi;
    PGMidiSource *currMidiSource;
    PGMidiDestination *currMidiDestination;
    int currMidiSourceIndex;
    int currMidiDestinationIndex;
	
    
    BOOL isLandscape;
    BOOL hasStatusBar;
    
    void* openPDFile;
    AVCaptureDevice *avCaptureDevice;//for flash
    
    //audio settings
    int samplingRate;
    BOOL inputOrMixing;
    
    
    UINavigationController *navigationController;
    
    //new
    CMMotionManager* motionManager;
    CLLocationManager *locationManager;
    //CLLocation *currLocation;//to send into patches on initial request for data (if start/stop doesn't send a point? it does)
}


-(void)connectPorts;
-(void)disconnectPorts;

@property BOOL backgroundAudioEnabled;
@property (retain) PdAudioController* audioController;
@property (retain) SettingsViewController* settingsVC;

@property float accelFrequency;
@property float gyroFrequency;
@property float motionFrequency;

@end
