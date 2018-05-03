#ifndef WEATHERSTATION_H
#define WEATHERSTATION_H




#include "iobjectobserv.h"

#include <QThread>
#include <qlist.h>

#include <Observers/iobserver.h>

class WeatherStation:public IObjectObserv,public QThread
{
private:
    WeatherData _curData;
    int _freqNewData;
    void notifyObservers();
public:
    bool _End;
    WeatherStation();
    void run ()override ;
    void end();
};

#endif // WEATHERSTATION_H
