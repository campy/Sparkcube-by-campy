/*
    This file is part of Repetier-Firmware.

    Repetier-Firmware is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Repetier-Firmware is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Repetier-Firmware.  If not, see <http://www.gnu.org/licenses/>.

*/

#ifndef CONFIGURATION_H
#define CONFIGURATION_H

/**************** LIES MICH************************

     _______  _____  _______  ______ _     _ _______ _     _ ______  _______
     |______ |_____] |_____| |_____/ |____/  |       |     | |_____] |______
     ______| |       |     | |    \_ |    \_ |_____  |_____| |_____] |______

                                                                                                                                                                                  
   Grundlage dieser Firmware bildet der Repetier Onlinekonfigurator zum Zeitpunkt des 
   2. Februars 2015 http://www.repetier.com/firmware/v092/
   
   Aktueller Stand/Changelog:
   
   02.02.15  Erstellung dieser Firmware auf Basis des Online Konfigurators
   03.02.15  Deutsche Kommentare zu den wichtigsten Optionen
   03.02.15  Patch aus Github "Even smoother temperatures for due"
   04.02.15  Totzeitregelung angepasst
   07.02.15  Patch aus Github "Fixed filament used per print"
   07.02.15  Patch aus Github "Fixed printed filament computation" + "Servo control in UI, reduced program size, fixes"
   07.02.15  "Servo control in UI, reduced program size, fixes" entfernt, war fehlerhaft
   07.02.15  "Servo control in UI, reduced program size, fixes" wieder eingeführt und korregiert
   
   
   Diese Firmware wurde speziell auf den sparkcube v1 / v1.1 mit RADDS und DUE angepasst.
   
   Wichtige Einstellungen für abweichende sparkcube Nachbauten sind in Deutsch kommentiert.
   
   Um die Standardeinstellungen dieser Konfiguration zu übernehmen, muss nach dem 
   Upload dieser Firmware die RESET.GCO auf dem Drucker ausgeführt werden. Dieses
   Script überschreibt die EEPROM Einstellungen mit denen aus dieser Konfiguration
   
   Standards in dieser Konfiguration
     
     + Endstops sind Öffner und stecken in Xmax, Ymax, Zmin
     + Peripherie ist angeschlossen wie hier ersichtlich:
       http://www.dr-henschke.de/RADDS_wire.jpg 
     + Thermistoren für Hotend und Bett sind Semitec-104GT
     + Schrittmotortreiber sind auf 128 Mikroschritte eingestellt
     + 1,8° Schrittmotoren, bei 0,9° Motoren müssen die STEPS_PER_MM verdoppelt werden
     + RADDS-LCD
     
     bei Fragen oder Problemen zu dieser Version, Email an 32bit@the-sparklab.de
*/


#define NUM_EXTRUDER 1
#define MOTHERBOARD 402

#include "pins.h"

// ################## EDIT THESE SETTINGS MANUALLY ################
// ################ END MANUAL SETTINGS ##########################

#define FAN_BOARD_PIN -1

//#define EXTERNALSERIAL  use Arduino serial library instead of build in. Requires more ram, has only 63 byte input buffer.
// Uncomment the following line if you are using arduino compatible firmware made for Arduino version earlier then 1.0
// If it is incompatible you will get compiler errors about write functions not beeing compatible!
//#define COMPAT_PRE1
#define MIXING_EXTRUDER 0

#define DRIVE_SYSTEM 1                    
#define XAXIS_STEPS_PER_MM 640                     //Alle 3 STEPS_PER_MM Werte müssen für 0.9° Schrittmotoren verdoppelt werden
#define YAXIS_STEPS_PER_MM 640                
#define ZAXIS_STEPS_PER_MM 25600                    //25600 für M6 Gewindestange, 12800 für TR8x2 oder TR10x2
#define EXTRUDER_FAN_COOL_TEMP 50
#define PDM_FOR_EXTRUDER 0
#define PDM_FOR_COOLER 0
#define DECOUPLING_TEST_MAX_HOLD_VARIANCE 40
#define DECOUPLING_TEST_MIN_TEMP_RISE 0
#define RETRACT_ON_PAUSE 2
#define PAUSE_START_COMMANDS ""
#define PAUSE_END_COMMANDS ""
#define EXT0_X_OFFSET 0
#define EXT0_Y_OFFSET 0
#define EXT0_STEPS_PER_MM 810
#define EXT0_TEMPSENSOR_TYPE 8                        //Thermistor am Hotend: 8 Semitec-GT104
#define EXT0_TEMPSENSOR_PIN TEMP_0_PIN
#define EXT0_HEATER_PIN HEATER_0_PIN
#define EXT0_STEP_PIN ORIG_E0_STEP_PIN
#define EXT0_DIR_PIN ORIG_E0_DIR_PIN
#define EXT0_INVERSE 0
#define EXT0_ENABLE_PIN E0_ENABLE_PIN
#define EXT0_ENABLE_ON 1
#define EXT0_MAX_FEEDRATE 80
#define EXT0_MAX_START_FEEDRATE 20
#define EXT0_MAX_ACCELERATION 5000
#define EXT0_HEAT_MANAGER 3
#define EXT0_WATCHPERIOD 1
#define EXT0_PID_INTEGRAL_DRIVE_MAX 220
#define EXT0_PID_INTEGRAL_DRIVE_MIN 40
#define EXT0_PID_PGAIN_OR_DEAD_TIME 6
#define EXT0_PID_I 2
#define EXT0_PID_D 40
#define EXT0_PID_MAX 255
#define EXT0_ADVANCE_K 0
#define EXT0_ADVANCE_L 0
#define EXT0_ADVANCE_BACKLASH_STEPS 0
#define EXT0_WAIT_RETRACT_TEMP 150
#define EXT0_WAIT_RETRACT_UNITS 0
#define EXT0_SELECT_COMMANDS ""
#define EXT0_DESELECT_COMMANDS ""
#define EXT0_EXTRUDER_COOLER_PIN ORIG_FAN2_PIN
#define EXT0_EXTRUDER_COOLER_SPEED 150
#define EXT0_DECOUPLE_TEST_PERIOD 12000

#define FEATURE_RETRACTION 1
#define AUTORETRACT_ENABLED 0
#define RETRACTION_LENGTH 3
#define RETRACTION_LONG_LENGTH 13
#define RETRACTION_SPEED 40
#define RETRACTION_Z_LIFT 0
#define RETRACTION_UNDO_EXTRA_LENGTH 0
#define RETRACTION_UNDO_EXTRA_LONG_LENGTH 0
#define RETRACTION_UNDO_SPEED 20
#define FILAMENTCHANGE_X_POS 180
#define FILAMENTCHANGE_Y_POS 10
#define FILAMENTCHANGE_Z_ADD  1
#define FILAMENTCHANGE_REHOME 1
#define FILAMENTCHANGE_SHORTRETRACT 1
#define FILAMENTCHANGE_LONGRETRACT 1

#define RETRACT_DURING_HEATUP true
#define PID_CONTROL_RANGE 20
#define SKIP_M109_IF_WITHIN 2
#define SCALE_PID_TO_MAX 0
#define TEMP_HYSTERESIS 0
#define EXTRUDE_MAXLENGTH 160
#define NUM_TEMPS_USERTHERMISTOR0 0
#define USER_THERMISTORTABLE0 {}
#define NUM_TEMPS_USERTHERMISTOR1 0
#define USER_THERMISTORTABLE1 {}
#define NUM_TEMPS_USERTHERMISTOR2 0
#define USER_THERMISTORTABLE2 {}
#define GENERIC_THERM_VREF 5
#define GENERIC_THERM_NUM_ENTRIES 33
#define HEATER_PWM_SPEED 0

// ############# Heated bed configuration ########################

#define HAVE_HEATED_BED 1
#define HEATED_BED_MAX_TEMP 140
#define SKIP_M190_IF_WITHIN 3
#define HEATED_BED_SENSOR_TYPE 8
#define HEATED_BED_SENSOR_PIN TEMP_1_PIN
#define HEATED_BED_HEATER_PIN HEATER_1_PIN
#define HEATED_BED_SET_INTERVAL 5000
#define HEATED_BED_HEAT_MANAGER 3
#define HEATED_BED_PID_INTEGRAL_DRIVE_MAX 255
#define HEATED_BED_PID_INTEGRAL_DRIVE_MIN 80
#define HEATED_BED_PID_PGAIN_OR_DEAD_TIME   25
#define HEATED_BED_PID_IGAIN   33
#define HEATED_BED_PID_DGAIN 290
#define HEATED_BED_PID_MAX 255
#define HEATED_BED_DECOUPLE_TEST_PERIOD 300000
#define MIN_EXTRUDER_TEMP 150
#define MAXTEMP 295
#define MIN_DEFECT_TEMPERATURE -10
#define MAX_DEFECT_TEMPERATURE 310

// ################ Endstop configuration #####################
#define ENDSTOP_X_MIN_INVERTING false            //False für Öffner, True für Schließer Endschalter
#define ENDSTOP_Y_MIN_INVERTING false
#define ENDSTOP_Z_MIN_INVERTING false
#define ENDSTOP_X_MAX_INVERTING false
#define ENDSTOP_Y_MAX_INVERTING false
#define ENDSTOP_Z_MAX_INVERTING false

#define ENDSTOP_PULLUP_X_MIN true                //True für mechanische Endschalter
#define ENDSTOP_PULLUP_Y_MIN true
#define ENDSTOP_PULLUP_Z_MIN true
#define ENDSTOP_PULLUP_X_MAX true
#define ENDSTOP_PULLUP_Y_MAX true
#define ENDSTOP_PULLUP_Z_MAX true

#define MIN_HARDWARE_ENDSTOP_X false              //True definiert, wo Endschalter sich befinden
#define MIN_HARDWARE_ENDSTOP_Y false
#define MIN_HARDWARE_ENDSTOP_Z true
#define MAX_HARDWARE_ENDSTOP_X true
#define MAX_HARDWARE_ENDSTOP_Y true
#define MAX_HARDWARE_ENDSTOP_Z false

#define max_software_endstop_r true
#define min_software_endstop_x true
#define min_software_endstop_y true
#define min_software_endstop_z false
#define max_software_endstop_x false
#define max_software_endstop_y false
#define max_software_endstop_z true
#define ENDSTOP_X_BACK_MOVE 2
#define ENDSTOP_Y_BACK_MOVE 2
#define ENDSTOP_Z_BACK_MOVE 1
#define ENDSTOP_X_RETEST_REDUCTION_FACTOR 3
#define ENDSTOP_Y_RETEST_REDUCTION_FACTOR 3
#define ENDSTOP_Z_RETEST_REDUCTION_FACTOR 2
#define ENDSTOP_X_BACK_ON_HOME 1
#define ENDSTOP_Y_BACK_ON_HOME 1
#define ENDSTOP_Z_BACK_ON_HOME 0
#define ALWAYS_CHECK_ENDSTOPS 0

// ################# XYZ movements ###################

#define X_ENABLE_ON 1                               //1 für RAPS128/Silencioso 0 für alle anderen Treiber
#define Y_ENABLE_ON 1
#define Z_ENABLE_ON 1
#define DISABLE_X 0
#define DISABLE_Y 0
#define DISABLE_Z 0
#define DISABLE_E 0
#define INVERT_X_DIR 0
#define INVERT_Y_DIR 0
#define INVERT_Z_DIR 0
#define X_HOME_DIR 1                                //In diese Richtung wird gehomed: 1 Max, -1 Min
#define Y_HOME_DIR 1
#define Z_HOME_DIR -1
#define X_MAX_LENGTH 195                             //Wieviel Verfahrweg hat der Drucker?
#define Y_MAX_LENGTH 200
#define Z_MAX_LENGTH 120
#define X_MIN_POS 0
#define Y_MIN_POS 0
#define Z_MIN_POS 0
#define DISTORTION_CORRECTION 0
#define DISTORTION_CORRECTION_POINTS 5
#define DISTORTION_CORRECTION_R 100
#define DISTORTION_PERMANENT 1
#define DISTORTION_UPDATE_FREQUENCY 15
#define DISTORTION_START_DEGRADE 0.5
#define DISTORTION_END_HEIGHT 1
#define DISTORTION_EXTRAPOLATE_CORNERS 0

// ##########################################################################################
// ##                           Movement settings                                          ##
// ##########################################################################################

#define FEATURE_BABYSTEPPING 1
#define BABYSTEP_MULTIPLICATOR 128

#define DELTA_SEGMENTS_PER_SECOND_PRINT 180 // Move accurate setting for print moves
#define DELTA_SEGMENTS_PER_SECOND_MOVE 70 // Less accurate setting for other moves

// Delta settings
#define DELTA_HOME_ON_POWER 0

#define DELTASEGMENTS_PER_PRINTLINE 24
#define STEPPER_INACTIVE_TIME 360L
#define MAX_INACTIVE_TIME 0L
#define MAX_FEEDRATE_X 250
#define MAX_FEEDRATE_Y 250
#define MAX_FEEDRATE_Z 10
#define HOMING_FEEDRATE_X 40
#define HOMING_FEEDRATE_Y 40
#define HOMING_FEEDRATE_Z 10
#define HOMING_ORDER HOME_ORDER_XYZ
#define ENABLE_BACKLASH_COMPENSATION 0
#define X_BACKLASH 0
#define Y_BACKLASH 0
#define Z_BACKLASH 0
#define RAMP_ACCELERATION 1
#define STEPPER_HIGH_DELAY 0
#define DIRECTION_DELAY 0
#define STEP_DOUBLER_FREQUENCY 80000
#define ALLOW_QUADSTEPPING 1
#define DOUBLE_STEP_DELAY 1 // time in microseconds
#define MAX_HALFSTEP_INTERVAL 1999
#define MAX_ACCELERATION_UNITS_PER_SQ_SECOND_X 1200
#define MAX_ACCELERATION_UNITS_PER_SQ_SECOND_Y 1200
#define MAX_ACCELERATION_UNITS_PER_SQ_SECOND_Z 100
#define MAX_TRAVEL_ACCELERATION_UNITS_PER_SQ_SECOND_X 1200
#define MAX_TRAVEL_ACCELERATION_UNITS_PER_SQ_SECOND_Y 1200
#define MAX_TRAVEL_ACCELERATION_UNITS_PER_SQ_SECOND_Z 100
#define MAX_JERK 20
#define MAX_ZJERK 0.3
#define PRINTLINE_CACHE_SIZE 32
#define MOVE_CACHE_LOW 10
#define LOW_TICKS_PER_MOVE 250000
#define FEATURE_TWO_XSTEPPER 0
#define X2_STEP_PIN   ORIG_E1_STEP_PIN
#define X2_DIR_PIN    ORIG_E1_DIR_PIN
#define X2_ENABLE_PIN E1_ENABLE_PIN
#define FEATURE_TWO_YSTEPPER 0
#define Y2_STEP_PIN   ORIG_E1_STEP_PIN
#define Y2_DIR_PIN    ORIG_E1_DIR_PIN
#define Y2_ENABLE_PIN E1_ENABLE_PIN
#define FEATURE_TWO_ZSTEPPER 0
#define Z2_STEP_PIN   ORIG_E1_STEP_PIN
#define Z2_DIR_PIN    ORIG_E1_DIR_PIN
#define Z2_ENABLE_PIN E1_ENABLE_PIN
#define FEATURE_DITTO_PRINTING 0
#define USE_ADVANCE 0
#define ENABLE_QUADRATIC_ADVANCE 0


// ################# Misc. settings ##################

#define BAUDRATE 115200
#define ENABLE_POWER_ON_STARTUP 1
#define POWER_INVERTING 0
#define KILL_METHOD 1
#define ACK_WITH_LINENUMBER 1
#define WAITING_IDENTIFIER "wait"
#define ECHO_ON_EXECUTE 1
#define EEPROM_MODE 1
#define PS_ON_PIN ORIG_PS_ON_PIN

/* ======== Servos =======
Control the servos with
M340 P<servoId> S<pulseInUS>   / ServoID = 0..3  pulseInUs = 500..2500
Servos are controlled by a pulse width normally between 500 and 2500 with 1500ms in center position. 0 turns servo off.
WARNING: Servos can draw a considerable amount of current. Make sure your system can handle this or you may risk your hardware!
*/
#define FEATURE_SERVO 0
#define SERVO0_PIN 11
#define SERVO1_PIN -1
#define SERVO2_PIN -1
#define SERVO3_PIN -1
#define SERVO0_NEUTRAL_POS  -1
#define SERVO1_NEUTRAL_POS  -1
#define SERVO2_NEUTRAL_POS  -1
#define SERVO3_NEUTRAL_POS  -1
#define UI_SERVO_CONTROL 0
#define FAN_KICKSTART_TIME  200

        #define FEATURE_WATCHDOG 1

// #################### Z-Probing #####################

#define FEATURE_Z_PROBE 0
#define Z_PROBE_BED_DISTANCE 10
#define Z_PROBE_PIN -1
#define Z_PROBE_PULLUP 0
#define Z_PROBE_ON_HIGH 0
#define Z_PROBE_X_OFFSET 0
#define Z_PROBE_Y_OFFSET 0
#define Z_PROBE_WAIT_BEFORE_TEST 0
#define Z_PROBE_SPEED 2
#define Z_PROBE_XY_SPEED 150
#define Z_PROBE_SWITCHING_DISTANCE 1
#define Z_PROBE_REPETITIONS 1
#define Z_PROBE_HEIGHT 40
#define Z_PROBE_START_SCRIPT ""
#define Z_PROBE_FINISHED_SCRIPT ""
#define FEATURE_AUTOLEVEL 1
#define Z_PROBE_X1 20
#define Z_PROBE_Y1 20
#define Z_PROBE_X2 160
#define Z_PROBE_Y2 20
#define Z_PROBE_X3 100
#define Z_PROBE_Y3 160
#define FEATURE_AXISCOMP 0
#define AXISCOMP_TANXY 0
#define AXISCOMP_TANYZ 0
#define AXISCOMP_TANXZ 0

#ifndef SDSUPPORT 
#define SDSUPPORT 0
#define SDCARDDETECT -1
#define SDCARDDETECTINVERTED 0
#endif
#define SD_EXTENDED_DIR 1
#define SD_RUN_ON_STOP ""
#define SD_STOP_HEATER_AND_MOTORS_ON_STOP 1
#define ARC_SUPPORT 1
#define FEATURE_MEMORY_POSITION 1
#define FEATURE_CHECKSUM_FORCED 0
#define FEATURE_FAN_CONTROL 1
#define FEATURE_CONTROLLER 7//7
#define UI_LANGUAGE 1
#define UI_PRINTER_NAME "sparkcube"
#define UI_PRINTER_COMPANY "sparklab"
#define UI_PAGES_DURATION 4000
#define UI_ANIMATION 0
#define UI_SPEEDDEPENDENT_POSITIONING 0
#define UI_DISABLE_AUTO_PAGESWITCH 1
#define UI_AUTORETURN_TO_MENU_AFTER 60000
#define FEATURE_UI_KEYS 0
#define UI_ENCODER_SPEED 1
#define UI_KEY_BOUNCETIME 10
#define UI_KEY_FIRST_REPEAT 500
#define UI_KEY_REDUCE_REPEAT 50
#define UI_KEY_MIN_REPEAT 50
#define FEATURE_BEEPER 1
#define CASE_LIGHTS_PIN -1
#define CASE_LIGHT_DEFAULT_ON 1
#define UI_START_SCREEN_DELAY 1000
#define UI_DYNAMIC_ENCODER_SPEED 1
#define BEEPER_SHORT_SEQUENCE 2,2
#define BEEPER_LONG_SEQUENCE 8,8
#define UI_SET_PRESET_HEATED_BED_TEMP_PLA 60
#define UI_SET_PRESET_EXTRUDER_TEMP_PLA   190
#define UI_SET_PRESET_HEATED_BED_TEMP_ABS 110
#define UI_SET_PRESET_EXTRUDER_TEMP_ABS   240
#define UI_SET_MIN_HEATED_BED_TEMP  30
#define UI_SET_MAX_HEATED_BED_TEMP 140
#define UI_SET_MIN_EXTRUDER_TEMP   170
#define UI_SET_MAX_EXTRUDER_TEMP   290
#define UI_SET_EXTRUDER_FEEDRATE 2
#define UI_SET_EXTRUDER_RETRACT_DISTANCE 3

#endif
