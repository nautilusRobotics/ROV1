/*
 * Com.h
 *
 *  Created on: Jul 14, 2015
 *      Author: nautilus
 */

#ifndef COM_H_
#define COM_H_

#define CLOSE_ROBOT    "clse0000"  //kill the robot and server process
#define POWEROFF_ROBOT "pwof0000"  //Turn off the robot
#define STOP_ROBOT     "stop0000"  //Stop the robot wait for reStart
#define CHECK_ROBOT    "Gcrb0000"  // Check if the robot is online
#define START_ROBOT    "strt0000"  //Enable ESC's
#define CENTER_CAMARA  "ctcm0000"  //TILT CAMERA
#define NULL_CMD       "null0000"  //null COMMNAD
#define GET_DEPTH      "Gdpt0000"  //Request the depth value of the robot
#define GET_BATTERY    "Gbtt0000"  //Request the battery Status of the robot
#define REQUEST_KEY           "G"  //request init key
#define REQUEST_KEY_CHAR      'G'  //request init key

#define GO_ROBOT       "goro"  //Move robot fordward-backwards
#define UPDOWN_ROBOT   "upro"  //Move robot up-down
#define RIGHT_ROBOT    "rgro"  //Move robot right
#define LEFT_ROBOT     "lfro"  //Move robot left

#define PAN_CAMARA     "pncm"  //PAN CAMERA
#define TILT_CAMARA    "ticm"  //TILT CAMERA

#define TOGGLE_LIGHT   "tglh"  //Toggle Robot lights
#define OFF_LIGHT      "tglh2000"  //OFF Robot lights
#define ON_LIGHT       "tglh1000"  //ON Robot lights


#define MOTOR_1        "mvm1"  //Move only motor 1
#define MOTOR_2        "mvm2"  //Move only motor 2
#define MOTOR_3        "mvm3"  //Move only motor 3
#define MOTOR_4        "mvm4"  //Move only motor 4

#define TILT_UP        "ticmA000"
#define TILT_DOWN      "ticmB000"
#define TILT_STOP      "ticmC000"

#define PAN_UP         "pncmD000"
#define PAN_DOWN       "pncmE000"
#define PAN_STOP       "pncmF000"

#define ceroOffsetEsc  32
#define ceroOffsetEsc1 70

#define maxESCms 1670
#define minESCms 1330

#define maxControl  1000
#define minControl -1000

#endif /* COM_H_ */
