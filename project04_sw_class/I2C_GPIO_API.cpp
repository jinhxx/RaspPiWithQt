#include <wiringPi.h>
#include "I2C_GPIO_API.h"

// SHT20 관련 설정
#define SHT20_I2C_CMD_MEASURE_TEMP  0xF3
#define SHT20_I2C_CMD_MEASURE_HUMI  0xF5
#define SHT20_I2C_CMD_SOFT_RESET    0xFE

I2C_SHT20::I2C_SHT20(int addr) {
    fd_SHT20 = wiringPiI2CSetup(addr);

    wiringPiI2CWrite(fd_SHT20, SHT20_I2C_CMD_SOFT_RESET);
    delay(50);
}

float I2C_SHT20::measureTemp() {
    mTemp = 0.0;
    int aData[2];
    int value;

    wiringPiI2CWrite(fd_SHT20, SHT20_I2C_CMD_MEASURE_TEMP);
    delay(260);

    aData[0] = wiringPiI2CRead(fd_SHT20);   // 상위비트
    aData[1] = wiringPiI2CRead(fd_SHT20);   // 하위비트

    // 측정된 데이터를 계산
    value = (aData[0]<<8) | aData[1];
    mTemp = -46.85 + 175.72/65536*(int)value;

    return mTemp;
}

float I2C_SHT20::measureHumi() {
    mHumi = 0.0;
    int aData[2];
    int value;

    wiringPiI2CWrite(fd_SHT20, SHT20_I2C_CMD_MEASURE_HUMI);
    delay(260);

    aData[0] = wiringPiI2CRead(fd_SHT20);   // 상위비트
    aData[1] = wiringPiI2CRead(fd_SHT20);   // 하위비트

    // 측정된 데이터를 계산
    value = (aData[0]<<8) | aData[1];
    mHumi = -6.0 + 125.0/65536*(int)value;

    return mHumi;
}
