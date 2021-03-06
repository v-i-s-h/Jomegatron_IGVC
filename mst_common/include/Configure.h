//----------------------------------------------------------------------
// Configure.h - Configuration File
//
// Description: Contains settings that can affect many modules
//----------------------------------------------------------------------
#ifndef CONFIGURE_H
#define CONFIGURE_H

#include "Topics.h"

//----------------------------------------------------------
// Generic Settings
//----------------------------------------------------------
    //TOPSPEED in Meters/Second
    #define TOPSPEED 4.4704 //2.2352 CMB 4/25/2011

//----------------------------------------------------------
// Midg_II Settings
//----------------------------------------------------------
    #define MIDG_BAUDRATE B115200
    #define MIDG_MODEMDEVICE "/dev/ttyUSB2"
    #define GPS_NO_FIX -10000000

//----------------------------------------------------------
// Motor Settings
//----------------------------------------------------------
    #define WATCHDOG_TIMEOUT    1.0

	#define GEARRATIO 7
    #define CLICKS2METERS (.2459 / 2000 )
    #define WHEELBASE 0.5588

    // Measurements
    #define WHEEL_DIAMETER  WHEEL_RADIUS*2
    #define WHEEL_RADIUS    0.2032 //0.1778 CMB 4/25/2011
    /* Based on WheelBase, not actual width */
    #define ROBOT_RADIUS    0.2794
    #define ROBOT_DIAMETER  ( ROBOT_RADIUS * 2 )

    // Ticks per revolution
    #define ENCODER_RESOLUTION  3000*4 //M.C. 4/11/2011

    #define TWO_WHEEL_DRIVE
      #define NUMBER_OF_MOTORS    2
      #define MOTOR_CHANNELS      2
      #define RIGHT_MOTOR_CHANNEL 0
      #define RIGHT_MOTOR_WARP    1
      #define LEFT_MOTOR_CHANNEL  -1
      #define LEFT_MOTOR_WARP     1

    #define RIGHT_MOTOR_LOCATION    "/dev/ttyUSB2"
    #define LEFT_MOTOR_LOCATION     "/dev/ttyUSB1"

//----------------------------------------------------------
// Navigation Settings
//----------------------------------------------------------
    #define TURN_LIMIT          15
    #define SMEAR_MULT          0.5
    #define LEFT_BNDRY_LIMIT    0.2
    #define RGHT_BNDRY_LIMIT    0.8


#endif
