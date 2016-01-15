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
#define STOP_ROBOT     "stop"  //Stop the robot wait for reStart
#define CHECK_ROBOT    "Gcrb"  // Check if the robot is online
#define GO_ROBOT       "goro"  //Move robot fordward-backwards
#define UPDOWN_ROBOT   "upro"  //Move robot up-down
#define RIGHT_ROBOT    "rgro"  //Move robot right
#define LEFT_ROBOT     "lfro"  //Move robot left
#define GET_DEPTH      "Gdpt"  //Request the depth value of the robot
#define GET_BATTERY    "Gbtt"   //Request the battery Status of the robot
#define PAN_CAMARA     "pncm"  //PAN CAMERA
#define TILT_CAMARA    "ticm"  //TILT CAMERA
#define CENTER_CAMARA  "ctcm"  //TILT CAMERA
#define NULL_CMD       "null"  //null COMMNAD
#define TOGGLE_LIGHT   "tglh"  //Toggle Robot lights
#define OFF_LIGHT      "tglh2000"  //OFF Robot lights
#define ON_LIGHT       "tglh1000"  //ON Robot lights
#define REQUEST_KEY    "G"         //request init key

#define MOTOR_1        "mvm1"  //Move only motor 1
#define MOTOR_2        "mvm2"  //Move only motor 2
#define MOTOR_3        "mvm3"  //Move only motor 3
#define MOTOR_4        "mvm4"  //Move only motor 4

#define TILT_UP        "ticmA"
#define TILT_DOWN      "ticmB"
#define TILT_STOP      "ticmC"

#define PAN_UP         "pncmD"
#define PAN_DOWN       "pncmE"
#define PAN_STOP       "pncmF"

#define ceroOffsetEsc  32
#define ceroOffsetEsc1 70

#define maxESCms 1670
#define minESCms 1330

#define maxControl  1000
#define minControl -1000

#endif /* COM_H_ */
