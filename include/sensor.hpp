#ifndef SENSOR_H
#define SENSOR_H

#include <corecrt_math_defines.h>

/**
 * @struct Sensor
 * @brief A struct representing a sensor on a robot.
 */
struct Sensor {
    /**
     * @brief The angle offset of the sensor in radians.
     * 
     * This is the angle between the direction the robot is facing and the direction the sensor is pointing.
     * A positive value means the sensor is pointing to the right of the direction the robot is facing.
     * This value is set to 45 degrees (PI/4 radians).
     */
    static constexpr double sensorAngleOffset = M_PI / 4;

    /**
     * @brief The angle of the sensor's field of view in radians.
     * 
     * This is the angle between the two lines that define the edges of the sensor's field of view.
     * This value is set to 30 degrees (30 * PI/180 radians).
     */
    static constexpr double sensorAngle = 30 * (M_PI / 180);
};

#endif // SENSOR_H
