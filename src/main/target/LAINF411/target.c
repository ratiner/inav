#include <stdbool.h>
#include <platform.h>

#include "drivers/io.h"
#include "drivers/pwm_mapping.h"
#include "drivers/timer.h"

const timerHardware_t timerHardware[] = {
    // DEF_TIM(TIM9, CH2, PA3,   TIM_USE_PPM,   0, 0), // PPM IN
    DEF_TIM(TIM3, CH2, PB5,  TIM_USE_FW_MOTOR | TIM_USE_FW_MOTOR,  0, 0), // S1
    DEF_TIM(TIM3, CH1, PB4,  TIM_USE_FW_MOTOR | TIM_USE_FW_MOTOR,  0, 0), // S2
    
    DEF_TIM(TIM2, CH2, PB3,  TIM_USE_FW_SERVO,  0, 0), // S3
    DEF_TIM(TIM2, CH1, PA15,  TIM_USE_FW_SERVO,  0, 0), // S4
    DEF_TIM(TIM1, CH3, PA10,  TIM_USE_FW_SERVO,  0, 0), // S5
    DEF_TIM(TIM1, CH2, PA9,  TIM_USE_FW_SERVO,  0, 0), // S6
    DEF_TIM(TIM1, CH1, PA8,  TIM_USE_FW_SERVO,  0, 0), // S7
    
    DEF_TIM(TIM2, CH3, PB10,  TIM_USE_FW_SERVO,  0, 0), // S8
    DEF_TIM(TIM3, CH4, PB1,  TIM_USE_FW_SERVO,  0, 0), // S9
    DEF_TIM(TIM3, CH3, PB0,  TIM_USE_FW_SERVO,  0, 0), // S10
    DEF_TIM(TIM5, CH2, PA1,  TIM_USE_FW_SERVO,  0, 0), // S11
    DEF_TIM(TIM5, CH1, PA0,  TIM_USE_FW_SERVO,  0, 0), // S12
};

const int timerHardwareCount = sizeof(timerHardware) / sizeof(timerHardware[0]);