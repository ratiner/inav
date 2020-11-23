#pragma once

#define TARGET_BOARD_IDENTIFIER "LA41"

#define USBD_PRODUCT_STRING  "LainF411"

#define LED0                    PC13
#define LED1                    PC14

#define BEEPER                  PB2
#define BEEPER_INVERTED

// *************** Ports *****************************
#define USE_I2C
#define USE_I2C_DEVICE_1
#define I2C1_SCL                PB8
#define I2C1_SDA                PB9
#define DEFAULT_I2C_BUS         BUS_I2C1

#define USE_SPI
#define USE_SPI_DEVICE_1
#define SPI1_SCK_PIN            PB13
#define SPI1_MISO_PIN           PB14
#define SPI1_MOSI_PIN           PB15

// *************** Gyro & ACC **********************
#define USE_BARO
#define BARO_I2C_BUS            BUS_I2C1
#define USE_BARO_MS5611

#define USE_IMU_MPU6050
#define IMU_MPU6050_ALIGN       CW90_DEG
#define MPU6050_I2C_BUS         BUS_I2C1

#define USE_MPU_DATA_READY_SIGNAL

#define USE_MAG
#define MAG_I2C_BUS             BUS_I2C1
#define USE_MAG_HMC5883
#define MAG_HMC5883_ALIGN       CW90_DEG

//#define TEMPERATURE_I2C_BUS     BUS_I2C1
//#define TEMPERATURE_SPI_BUS     BUS_SPI1

// *************** SPI2 OSD *****************************
//#define USE_SPI_DEVICE_2
//#define SPI2_SCK_PIN            PB13
//#define SPI2_MISO_PIN           PB14
//#define SPI2_MOSI_PIN           PB15

//#define USE_OSD
//#define USE_MAX7456
//#define MAX7456_SPI_BUS         BUS_SPI2
//#define MAX7456_CS_PIN          PB12

// *************** UART *****************************
#define USE_VCP
#define VBUS_SENSING_PIN        PC15
#define VBUS_SENSING_ENABLED

#define USE_UART1
#define UART1_TX_PIN            PB6
#define UART1_RX_PIN            PB7

#define USE_UART2
#define UART2_TX_PIN            PA2
#define UART2_RX_PIN            PA3

//#define USE_UART6     USED BY USB PORT
//#define UART6_TX_PIN            PA11
//#define UART6_RX_PIN            PA12

#define SERIAL_PORT_COUNT       3

#define DEFAULT_RX_TYPE         RX_TYPE_SERIAL
#define SERIALRX_PROVIDER       SERIALRX_SBUS
#define SERIALRX_UART           SERIAL_PORT_USART1

// *************** ADC *****************************
#define USE_ADC
#define ADC_INSTANCE                ADC1
#define ADC1_DMA_STREAM             DMA2_Stream0
#define ADC_CHANNEL_1_PIN           PA6
#define ADC_CHANNEL_2_PIN           PA7
#define VBAT_ADC_CHANNEL            ADC_CHN_1
#define CURRENT_METER_ADC_CHANNEL   ADC_CHN_2

// ***************  OTHERS *************************
#define DEFAULT_FEATURES        (FEATURE_TX_PROF_SEL | FEATURE_OSD | FEATURE_CURRENT_METER | FEATURE_VBAT | FEATURE_TELEMETRY | FEATURE_SOFTSERIAL )

#define USE_DSHOT
#define USE_ESC_SENSOR

#define USE_SERIALSHOT
#define USE_SERIAL_4WAY_BLHELI_INTERFACE

#define TARGET_IO_PORTA         0xffff
#define TARGET_IO_PORTB         0xffff
#define TARGET_IO_PORTC         0xffff
#define TARGET_IO_PORTD         (BIT(2))

#define MAX_PWM_OUTPUT_PORTS       12

#ifdef USE_USB_MSC
# undef USE_USB_MSC
#endif