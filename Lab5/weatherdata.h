#ifndef WEATHERDATA_H
#define WEATHERDATA_H


class WeatherData
{
    int Temperature;
    float Humidity;
    int Pressure;
public:
    WeatherData();
    WeatherData(int temp,float hum, int pres);

    void measurementsChanged(const WeatherData Data);
    void measurementsChanged(int temp,float hum, int pres);

    int getTemperature() const;
    void setTemperature(int value);
    float getHumidity() const;
    void setHumidity(float value);
    int getPressure() const;
    void setPressure(int value);
    WeatherData &operator =(WeatherData &right);
};

#endif // WEATHERDATA_H
