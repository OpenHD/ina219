#include <iostream>
#include "src/ina219.h"
#include <math.h>

constexpr float SHUNT_OHMS = 0.1f;
constexpr int PORT= 2;
constexpr float MAX_EXPECTED_AMPS = 3.2f;
constexpr uint16_t RANGE = RANGE_16V;
constexpr uint8_t GAIN = GAIN_8_320MV;
constexpr uint8_t BUS_ADC = ADC_12BIT;
constexpr uint8_t SHUNT_ADC = ADC_12BIT;

int main(int argc, char *argv[])
{
    INA219 i(SHUNT_OHMS, MAX_EXPECTED_AMPS);
    i.configure(RANGE, GAIN, BUS_ADC, SHUNT_ADC);

    float voltage = roundf(i.voltage() * 1000) / 1000;
    float current = roundf(i.current() * 1000) / 1000;
    std::cout << voltage << "," << current << std::endl;

    return 0;
}
