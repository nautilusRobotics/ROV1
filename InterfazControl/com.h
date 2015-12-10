/*
 * Com.h
 *
 *  Created on: Jul 14, 2015
 *      Author: nautilus
 */

#ifndef COM_H_
#define COM_H_

#define CLOSE_ROBOT    "clse"  //kill the robot and server process
#define POWEROFF_ROBOT "pwof"  //Turn off the robot
#define FORWARD_ROBOT "goro"  //Move robot straight
#define BACK_ROBOT     "back"  //Move robot back
#define UP_ROBOT       "upro"  //Move robot up
#define DOWN_ROBOT     "dwnr"  //Move robot down
#define RIGHT_ROBOT    "rgro"  //Move robot right
#define LEFT_ROBOT     "lfro"  //Move robot left
#define GET_DEPTH      "gdpt"  //Request the depth value of the robot
#define PAN_CAMARA     "pncm"  //PAN CAMERA
#define TILT_CAMARA    "ticm"  //TILT CAMERA
#define CENTER_CAMARA  "ctcm"  //TILT CAMERA
#define NULL_CMD       "null"  //null COMMNAD
#define TOGGLE_LIGHT   "tglh"  //Toggle Robot lights
#define OFF_LIGHT      "tglh2000"  //OFF Robot lights
#define ON_LIGHT       "tglh1000"  //ON Robot lights


#define TILT_UP        "ticmA"
#define TILT_DOWN      "ticmB"
#define TILT_STOP      "ticmC"

#define PAN_UP         "pncmD"
#define PAN_DOWN       "pncmE"
#define PAN_STOP       "pncmF"

#define maxESCms 1670
#define minESCms 1330

#define maxControl  1000
#define minControl -1000

#endif /* COM_H_ */
