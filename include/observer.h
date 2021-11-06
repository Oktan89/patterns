#pragma once
#include <iostream>
#include <vector>

class IObserver
{
public:
    virtual void update(double temp, double humidity, double pressure) = 0;
    virtual ~IObserver(){}
};

class ISubject
{
public:
    virtual void registerObserver(IObserver *o) = 0;
    virtual void removeObserver(IObserver *o) = 0;
    virtual void notyfyObserver() = 0;
    virtual ~ISubject(){}
};

class IDisplayElement
{
public:
    virtual void display() = 0;
    virtual ~IDisplayElement(){}
};

//Субъект
class WetherData : public ISubject
{
    std::vector<IObserver*> _observers;
    double _temperature;
    double _humidity;
    double _pressure;
    
public:

    WetherData(){}
    
    void registerObserver(IObserver *o) override
    {
        _observers.push_back(o);
    }

    //Пересмореть алгоритм и контейнер
    void removeObserver(IObserver *o) override 
    {   std::int32_t i = 0;
        for(auto &obs : _observers)
        {
            if(obs == o)
                _observers.erase(_observers.begin() + i);
            ++i;
        }
    }

    void notyfyObserver() override
    {
        for(const auto &obs : _observers)
            obs->update(_temperature, _humidity, _pressure);
    }

    void measurementsChanged()
    {
        notyfyObserver();
    }

    void setMeasurements(double temperature, double humidity, double pressure)
    {
        _temperature = temperature;
        _humidity = humidity;
        _pressure = pressure;
        measurementsChanged();
    }
    //Другие методы WetherData
};

//Наблюдатели

class CurrentConditionsDisplay : public IObserver, IDisplayElement
{
    double _temperature;
    double _humidity;
    double _pressure;
    ISubject *_wetherData;
public:
    CurrentConditionsDisplay(ISubject *wetherData)
    {
        _wetherData = wetherData;
        _wetherData->registerObserver(this);
    }

    void update(double temperature, double humidity, double pressure) override
    {
        _temperature = temperature;
        _humidity = humidity;
        _pressure = pressure;
        display();
    }

    void display() override
    {
        std::cout << "Current condition: " 
            <<_temperature << " degrees and humidity " 
            << _humidity << ", pressure % " << _pressure
            <<std::endl;
    }
};

class ForecastDisplay : public IObserver, IDisplayElement
{
    double _temperature;
    double _humidity;
    double _pressure;
    ISubject *_wetherData;
public:
    ForecastDisplay(ISubject *wetherData)
    {
        _wetherData = wetherData;
        _wetherData->registerObserver(this);
    }

    void update(double temperature, double humidity, double pressure) override
    {
        _temperature = temperature;
        _humidity = humidity;
        _pressure = pressure;
        display();
    }

    void display() override
    {
        std::cout << "Forecast: " 
            <<_temperature << " degrees and humidity " 
            << _humidity << ", pressure % " << _pressure
            <<std::endl;
    }
};