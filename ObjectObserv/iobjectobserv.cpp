#include "iobjectobserv.h"

void IObjectObserv::addObserver(IObserver *newObserv)
{
    _listObs.append(newObserv);
}

void IObjectObserv::removeObserver(IObserver &remObserv)
{
    _listObs.removeOne(&remObserv);
}

void IObjectObserv::notifyObservers()
{ }

IObjectObserv::IObjectObserv()
{ }

IObjectObserv::~IObjectObserv()
{
    for(auto iter:_listObs)
        delete iter;
}
