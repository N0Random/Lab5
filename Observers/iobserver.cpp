#include "iobserver.h"
#include <ObjectObserv/iobjectobserv.h>
#include <qdir.h>
#include <qtextstream.h>

IObserver::IObserver()
{ }

IObserver::~IObserver()
{}

void IObserver::update(QObject &data)
{ }

QTextEdit *DisplayEditText::display() const
{
    return _display;
}

DisplayEditText::DisplayEditText():IObserver()
{
    _display=new QTextEdit();
}
DisplayEditText::~DisplayEditText()
{
    delete _display;
}

void DisplayEditText::update(QObject &data)
{
    _dataWeather = (WeatherData &) data;
    QString out;
    out="Temperature:"+QString::number(_dataWeather.getTemperature())
            +"\n Humidity:"+QString::number(_dataWeather.getHumidity())
            +"\n Pressure:"+QString::number(_dataWeather.getPressure())+"\n";
   _display->append(out);
}

DisplayLineEdit::DisplayLineEdit():IObserver()
{
    _display=new QLineEdit();
}
DisplayLineEdit::~DisplayLineEdit()
{
    delete _display;
}
void DisplayLineEdit::update(QObject &data)
{
      _dataWeather = (WeatherData &) data;
      QString out;
      out="Temperature:"+QString::number(_dataWeather.getTemperature())
              +" Humidity:"+QString::number(_dataWeather.getHumidity())
              +" Pressure:"+QString::number(_dataWeather.getPressure());
      _display->setText(out);
}
QLineEdit *DisplayLineEdit::display() const
{
    return _display;
}

DisplayDocTxt::DisplayDocTxt(QString Name):IObserver()
{_Name=Name;}

DisplayDocTxt::~DisplayDocTxt()
{
    if(!_display.isEmpty())
    {
        QDir dir;
        QString Path=dir.absolutePath();
        QFile file(Path+"/"+_Name);
        if(file.exists())
            file.open(QIODevice::Append | QIODevice::Text);
        else
            file.open(QIODevice::WriteOnly | QIODevice::Text);
        QTextStream writeStream(&file);
        QString Out = _display.join("/n");
        writeStream<<Out;
        file.close();
    }
}

void DisplayDocTxt::update(QObject &data)
{
    _dataWeather = (WeatherData &) data;


    QString out;
    out="Temperature:"+QString::number(_dataWeather.getTemperature())
            +"\n Humidity:"+QString::number(_dataWeather.getHumidity())
            +"\n Pressure:"+QString::number(_dataWeather.getPressure());
   _display.append(out);

}
