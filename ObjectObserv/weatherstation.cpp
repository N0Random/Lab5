#include "weatherstation.h"

#include <QTime>

void WeatherStation::notifyObservers()
{
    for(auto iter : _listObs)
        iter->update(_curData);
}

WeatherStation::WeatherStation()
{
    _freqNewData=10;
    _End=false;
}

void WeatherStation::run()
{
    while(!_End)
    {
        int temp =-30+rand()%60;
        float hum = rand() % 30;
        int pres = 700+rand() %100;
        _curData.measurementsChanged(temp,hum,pres);
        notifyObservers();
        sleep( _freqNewData );
    }
}

void WeatherStation::end()
{
    _End=true;
}


