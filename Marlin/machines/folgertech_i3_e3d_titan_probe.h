// Displayed in the LCD "Ready" message
#define CUSTOM_MACHINE_NAME "Folgertech E3D Titan Probe"

#define TEMP_SENSOR_0 5
#define TEMP_SENSOR_BED 1

#define PIDTEMP
#define  DEFAULT_Kp 19.40
#define  DEFAULT_Ki 1.47
#define  DEFAULT_Kd 63.90

#define PIDTEMPBED
#define  DEFAULT_bedKp 292.16
#define  DEFAULT_bedKi 23.97
#define  DEFAULT_bedKd 890.33


// Travel limits after homing (units are in mm)
#define X_MIN_POS 0
#define Y_MIN_POS 0
#define Z_MIN_POS 0
#define X_MAX_POS 200
#define Y_MAX_POS 200
#define Z_MAX_POS 175

// Mechanical endstop with COM to ground and NC to Signal uses "false" here (most common setup).
#define X_MIN_ENDSTOP_INVERTING true // set to true to invert the logic of the endstop.
#define Y_MIN_ENDSTOP_INVERTING true // set to true to invert the logic of the endstop.
#define Z_MIN_ENDSTOP_INVERTING false // set to true to invert the logic of the endstop.
#define X_MAX_ENDSTOP_INVERTING true // set to true to invert the logic of the endstop.
#define Y_MAX_ENDSTOP_INVERTING true // set to true to invert the logic of the endstop.
#define Z_MAX_ENDSTOP_INVERTING true // set to true to invert the logic of the endstop.
#define Z_MIN_PROBE_ENDSTOP_INVERTING false // set to true to invert the logic of the probe.

/**
 * Default Axis Steps Per Unit (steps/mm)
 * Override with M92
 *                                      X, Y, Z, E0 [, E1[, E2[, E3]]]
 */
#define DEFAULT_AXIS_STEPS_PER_UNIT   { 80, 80, 4000, 418.5 }

/**
 * Default Max Feed Rate (mm/s)
 * Override with M203
 *                                      X, Y, Z, E0 [, E1[, E2[, E3]]]
 */
#define DEFAULT_MAX_FEEDRATE          { 250, 250, 2, 22 }

/**
 * Default Max Acceleration (change/s) change = mm/s
 * (Maximum start speed for accelerated moves)
 * Override with M201
 *                                      X, Y, Z, E0 [, E1[, E2[, E3]]]
 */
#define DEFAULT_MAX_ACCELERATION      { 1000, 1000, 5, 1000 }

/**
 * Default Acceleration (change/s) change = mm/s
 * Override with M204
 *
 *   M204 P    Acceleration
 *   M204 R    Retract Acceleration
 *   M204 T    Travel Acceleration
 */
#define DEFAULT_ACCELERATION          500    // X, Y, Z and E acceleration for printing moves
#define DEFAULT_RETRACT_ACCELERATION  500    // E acceleration for retracts
#define DEFAULT_TRAVEL_ACCELERATION   3000    // X, Y, Z acceleration for travel (non printing) moves

/**
 * Default Jerk (mm/s)
 *
 * "Jerk" specifies the minimum speed change that requires acceleration.
 * When changing speed and direction, if the difference is less than the
 * value set here, it may happen instantaneously.
 */
#define DEFAULT_XJERK                 20.0
#define DEFAULT_YJERK                 20.0
#define DEFAULT_ZJERK                  0.4
#define DEFAULT_EJERK                  5.0


//===========================================================================
//============================= Z Probe Options =============================
//===========================================================================
// @section probes

//
// Probe Type
// Probes are sensors/switches that are activated / deactivated before/after use.
//
// Allen Key Probes, Servo Probes, Z-Sled Probes, FIX_MOUNTED_PROBE, etc.
// You must activate one of these to use Auto Bed Leveling below.
//
// Use M851 to set the Z probe vertical offset from the nozzle. Store with M500.
//

// A Fix-Mounted Probe either doesn't deploy or needs manual deployment.
// For example an inductive probe, or a setup that uses the nozzle to probe.
// An inductive probe must be deactivated to go below
// its trigger-point if hardware endstops are active.
#define FIX_MOUNTED_PROBE

// Z Probe to nozzle (X,Y) offset, relative to (0, 0).
// X and Y offsets must be integers.
//
//    +-- BACK ---+
//    |           |
//  L |    (+) P  | R <-- probe (20,20)
//  E |           | I
//  F | (-) N (+) | G <-- nozzle (10,10)
//  T |           | H
//    |    (-)    | T
//    |           |
//    O-- FRONT --+
//  (0,0)
#define X_PROBE_OFFSET_FROM_EXTRUDER -8
#define Y_PROBE_OFFSET_FROM_EXTRUDER 44
#define Z_PROBE_OFFSET_FROM_EXTRUDER 0


#define Z_SAFE_HOMING
#define Z_SAFE_HOMING_X_POINT ((X_MIN_POS + X_MAX_POS) / 2)    // X point for Z homing when homing all axis (G28).
#define Z_SAFE_HOMING_Y_POINT ((Y_MIN_POS + Y_MAX_POS) / 2)    // Y point for Z homing when homing all axis (G28).


// Enable Z_MIN_PROBE_USES_Z_MIN_ENDSTOP_PIN to use the Z_MIN_PIN for your Z_MIN_PROBE.
// The Z_MIN_PIN will then be used for both Z-homing and probing.
#define Z_MIN_PROBE_USES_Z_MIN_ENDSTOP_PIN

// To use a probe you must enable one of the two options above!

// Enable Z Probe Repeatability test to see how accurate your probe is
#define Z_MIN_PROBE_REPEATABILITY_TEST

/**
 * Z probes require clearance when deploying, stowing, and moving between
 * probe points to avoid hitting the bed and other hardware.
 * Servo-mounted probes require extra space for the arm to rotate.
 * Inductive probes need space to keep from triggering early.
 *
 * Use these settings to specify the distance (mm) to raise the probe (or
 * lower the bed). The values set here apply over and above any (negative)
 * probe Z Offset set with Z_PROBE_OFFSET_FROM_EXTRUDER, M851, or the LCD.
 * Only integer values >= 1 are valid here.
 *
 * Example: `M851 Z-5` with a CLEARANCE of 4  =>  9mm from bed to nozzle.
 *     But: `M851 Z+1` with a CLEARANCE of 2  =>  2mm from bed to nozzle.
 */
#define Z_CLEARANCE_DEPLOY_PROBE   5 // Z Clearance for Deploy/Stow
#define Z_CLEARANCE_BETWEEN_PROBES 2 // Z Clearance between probe points

// Invert the stepper direction. Change (or reverse the motor connector) if an axis goes the wrong way.
#define INVERT_X_DIR true // I installed the motor on the wrong side
#define INVERT_Y_DIR false
#define INVERT_Z_DIR true // The motors are upside down

#define MIN_SOFTWARE_ENDSTOPS false  // If true, axis won't move to coordinates less than HOME_POS.
#define MAX_SOFTWARE_ENDSTOPS true  // If true, axis won't move to coordinates greater than the defined lengths below.

#define AUTO_BED_LEVELING_BILINEAR
#define DEBUG_LEVELING_FEATURE

#define ABL_GRID_MAX_POINTS_X 5
#define ABL_GRID_MAX_POINTS_Y ABL_GRID_MAX_POINTS_X
#define LEFT_PROBE_BED_POSITION 0
#define RIGHT_PROBE_BED_POSITION 192
#define FRONT_PROBE_BED_POSITION 44
#define BACK_PROBE_BED_POSITION 200
#define MIN_PROBE_EDGE 10


// Homing speeds (mm/m)
#define HOMING_FEEDRATE_XY (40*60)
#define HOMING_FEEDRATE_Z  (2*60)
