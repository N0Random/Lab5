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
    bool _End;
    void notifyObservers();
public:
    WeatherStation();
    void run ()override ;
    void end();
    void setFreqNewData(int freqNewData);
};

#endif // WEATHERSTATION_H
