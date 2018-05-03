#ifndef WEATHERSTATION_H
#define WEATHERSTATION_H


#include "iobserver.h"
#include "weatherdata.h"

#include <QThread>
#include <qlist.h>


class IObjectObserv
{
private:
    QList<IObserver *> _listObs;
public:
    void addObserver(IObserver &newObserv);
    void removeObserver(IObserver &remObserv);
    virtual void notifyObservers();
};
class WeatherStation:public IObjectObserv,public QThread
{
private:
    WeatherData _curData;
    int _freqNewData;

public:
    bool _End;
    WeatherStation();
    void run ()override ;
    void end();
    WeatherData curData() const;
};

#endif // WEATHERSTATION_H
