#include "weatherdata.h"

int WeatherData::getTemperature() const
{
    return Temperature;
}

void WeatherData::setTemperature(int value)
{
    Temperature = value;
}

float WeatherData::getHumidity() const
{
    return Humidity;
}

void WeatherData::setHumidity(float value)
{
    Humidity = value;
}

int WeatherData::getPressure() const
{
    return Pressure;
}

void WeatherData::setPressure(int value)
{
    Pressure = value;
}

WeatherData& WeatherData::operator =(WeatherData &right)
{
    measurementsChanged(right);
    return *this;
}

WeatherData::WeatherData()
{
    Temperature = 0;
    Humidity = 0;
    Pressure =  0;
}

WeatherData::WeatherData(int temp, float hum, int pres)
{
    measurementsChanged(temp,hum,pres);
}

void WeatherData::measurementsChanged(const WeatherData Data)
{
    Temperature = Data.getTemperature();
    Humidity = Data.getHumidity();
    Pressure = Data.getPressure();
}

void WeatherData::measurementsChanged(int temp, float hum, int pres)
{
    Temperature =temp;
    Humidity = hum;
    Pressure = pres;
}
