#ifndef IOBSERVER_H
#define IOBSERVER_H


#include <SimpleObject/weatherdata.h>

#include <qlineedit.h>
#include <qtextedit.h>


class IObjectObserv;
class IObserver
{
public:
    IObserver();
    virtual ~IObserver();
    virtual void update(QObject &data);
};

class DisplayEditText:public IObserver
{

private:
    QTextEdit *_display;
    WeatherData _dataWeather;
public:
    DisplayEditText();
    ~DisplayEditText();
    void update(QObject &data);
    QTextEdit *display() const;
};


class DisplayLineEdit:public IObserver
{

private:
    QLineEdit *_display;
    WeatherData _dataWeather;
public:
    DisplayLineEdit();
    ~DisplayLineEdit();
    void update(QObject &data);

    QLineEdit *display() const;
};
class DisplayDocTxt:public IObserver
{

private:
    QString _Name;
    QStringList _display;
    WeatherData _dataWeather;
public:
    DisplayDocTxt(QString Name);
    ~DisplayDocTxt();
    void update(QObject &data);
};
#endif // IOBSERVER_H
