#pragma once
#include <typeinfo>
#include <iostream>

typedef enum {
	E_CONTROLLER_ANALOG_LEFT_X = 0,
	E_CONTROLLER_ANALOG_LEFT_Y,
	E_CONTROLLER_ANALOG_RIGHT_X,
	E_CONTROLLER_ANALOG_RIGHT_Y
} controller_analog_e_t;

typedef enum {
	E_CONTROLLER_DIGITAL_L1 = 6,
	E_CONTROLLER_DIGITAL_L2,
	E_CONTROLLER_DIGITAL_R1,
	E_CONTROLLER_DIGITAL_R2,
	E_CONTROLLER_DIGITAL_UP,
	E_CONTROLLER_DIGITAL_DOWN,
	E_CONTROLLER_DIGITAL_LEFT,
	E_CONTROLLER_DIGITAL_RIGHT,
	E_CONTROLLER_DIGITAL_X,
	E_CONTROLLER_DIGITAL_B,
	E_CONTROLLER_DIGITAL_Y,
	E_CONTROLLER_DIGITAL_A
} controller_digital_e_t;

typedef enum {
	SENSOR_DIGITAL_A = 1,
	SENSOR_DIGITAL_B,
	SENSOR_DIGITAL_C,
	SENSOR_DIGITAL_D,
	SENSOR_DIGITAL_E,
	SENSOR_DIGITAL_F,
	SENSOR_DIGITAL_G,
	SENSOR_DIGITAL_H
} sensor_digital_e_t;

typedef enum {
	ANALOG_LEFT_X  = 0,
	ANALOG_LEFT_Y  ,
	ANALOG_RIGHT_X ,
	ANALOG_RIGHT_Y ,
	DIGITAL_L1	   = 6,
	DIGITAL_L2	   ,
	DIGITAL_R1	   ,
	DIGITAL_R2	   ,
	DIGITAL_UP	   ,
	DIGITAL_DOWN   ,
	DIGITAL_LEFT   ,
	DIGITAL_RIGHT  ,
	DIGITAL_X	   ,
	DIGITAL_B	   ,
	DIGITAL_Y	   ,
	DIGITAL_A	   ,
	SENSOR_A	   = 21,
	SENSOR_B	   ,
	SENSOR_C	   ,
	SENSOR_D	   ,
	SENSOR_E	   ,
	SENSOR_F	   ,
	SENSOR_G	   ,
	SENSOR_H
} Input_Event ;

inline std::int32_t get_analog(controller_analog_e_t analog)
{
	return 0;
}

inline std::int32_t get_digital(controller_digital_e_t digital)
{
	return 1;
}

inline std::int32_t get_value(sensor_digital_e_t sensor)
{
	return 2;
}

inline std::int32_t GetInputValue(Input_Event event)
{
	if (event < DIGITAL_L1)
	{
		return get_analog(static_cast<controller_analog_e_t>(event));
	}
	if (event < SENSOR_A)
	{
		return get_digital(static_cast<controller_digital_e_t>(event));
	}
	
	return get_value(static_cast<sensor_digital_e_t>(event-20));
}
