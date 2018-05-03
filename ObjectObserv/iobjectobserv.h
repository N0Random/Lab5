#ifndef IOBJECTOBSERV_H
#define IOBJECTOBSERV_H

#include <Observers/iobserver.h>


class IObjectObserv
{
protected:
    QList<IObserver *> _listObs;
    virtual void notifyObservers();
public:
    IObjectObserv();
    ~IObjectObserv();
    void addObserver(IObserver *newObserv);
    void removeObserver(IObserver &remObserv);

};

#endif // IOBJECTOBSERV_H
