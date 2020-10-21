/*
 * This file is part of Cleanflight.
 *
 * Cleanflight is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Cleanflight is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Cleanflight.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdint.h>

#include "platform.h"

#include "drivers/bus.h"
#include "drivers/sensor.h"
#include "drivers/system.h"
#include "drivers/time.h"

#include "drivers/accgyro/accgyro_mpu.h"

#include "drivers/compass/compass.h"
#include "drivers/compass/compass_mpu925x_ak8963.h"
#include "drivers/compass/compass_ak8963.h"

#if defined(USE_MAG_MPU925X_AK8963)

#define DETECTION_MAX_RETRY_COUNT   5

#define MPU9250_BIT_RESET               0x80

static bool mpu925xDeviceDetect(busDevice_t * dev)
{
    uint8_t tmp;
    uint8_t attemptsRemaining = DETECTION_MAX_RETRY_COUNT;

    busSetSpeed(dev, BUS_SPEED_INITIALIZATION);

    busWrite(dev, MPU_RA_PWR_MGMT_1, MPU9250_BIT_RESET);

    do {
        delay(150);

        busRead(dev, MPU_RA_WHO_AM_I, &tmp);

        switch (tmp) {
            case MPU9250_WHO_AM_I_CONST:
            case MPU9255_WHO_AM_I_CONST:
                // Compatible chip detected
                return true;

            default:
                // Retry detection
                break;
        }

        if (!attemptsRemaining) {
            return false;
        }
    } while (attemptsRemaining--);

    return false;
}

bool mpu925Xak8963CompassDetect(magDev_t * mag)
{
  mag->busDev = busDeviceInit(BUSTYPE_ANY, DEVHW_MPU925X_AK8963, mag->magSensorToUse, OWNER_COMPASS);
  if (mag->busDev == NULL) {
      return false;
  }

  // check if mpu9250 is present
  if (!mpu925xDeviceDetect(mag->busDev)) {
      busDeviceDeInit(mag->busDev);
      return false;
  }

  // set bypass mode on mpu9250
  busWrite(mag->busDev, MPU_RA_INT_PIN_CFG, 0x02);
  delay(150);
  busDeviceDeInit(mag->busDev);

  // now we have ak8963 alike on the bus
  return ak8963Detect(mag);
}

#endif