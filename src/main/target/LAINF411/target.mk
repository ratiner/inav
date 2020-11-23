F411_TARGETS    += $(TARGET)
FEATURES        += VCP

TARGET_SRC = \
            drivers/accgyro/accgyro_mpu6050.c \
            drivers/barometer/barometer_bmp280.c \
            drivers/barometer/barometer_ms56xx.c \
            drivers/compass/compass_hmc5883l.c \
            drivers/pitotmeter_adc.c \
            drivers/max7456.c