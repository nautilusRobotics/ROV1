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
#define UP_CAMARA      "upcm"  //UP SERVO CAMERA
#define NULL_CMD       "null"  //Null Command
#define DOWN_CAMARA    "dwcm"  //DOWN SERVO CAMERA
#define TOGGLE_LIGHT   "tglh"  //Toggle Robot lights

#define maxESCms 1700
#define minESCms 1300

#define maxControl  1000
#define minControl -1000

#endif /* COM_H_ */
