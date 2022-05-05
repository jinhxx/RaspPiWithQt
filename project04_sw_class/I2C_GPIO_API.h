#ifndef I2C_GPIO_API_H
#define I2C_GPIO_API_H
//#include <stdio.h>
//#include <wiringPi.h>
#include <wiringPiI2C.h>

class I2C_SHT20 {
    private:
        int fd_SHT20;
        float mTemp;
        float mHumi;
    public:
        I2C_SHT20(int addr);
        ~I2C_SHT20();
        float measureTemp();
        float measureHumi();
};

#endif // I2C_GPIO_API_H
