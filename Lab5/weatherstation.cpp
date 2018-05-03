#include "weatherstation.h"

#include <QTime>

WeatherData WeatherStation::curData() const
{
    return _curData;
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

void IObjectObserv::addObserver(IObserver &newObserv)
{
    _listObs.append(&newObserv);
}

void IObjectObserv::removeObserver(IObserver &remObserv)
{
    _listObs.removeOne(&remObserv);
}

void IObjectObserv::notifyObservers()
{
    for(auto iter : _listObs)
        iter->update();
}
