#include <iostream>
#include "strategy.h"
#include "observer.h"

int main()
{
    duck_base *mallard = new MallarDuck();
    mallard->display();
    mallard->performQuack();
    mallard->performFly();
    mallard->setFlyBehavior(new FlyRocketPowered());
    mallard->performFly();
    mallard->setFlyBehavior(new FlyNoWay());
    mallard->performFly();
     
    WetherData *wetherData = new WetherData();

    CurrentConditionsDisplay *curr = new CurrentConditionsDisplay(wetherData);
    ForecastDisplay *forc = new ForecastDisplay(wetherData);
    wetherData->setMeasurements(80, 65, 30.4);
    wetherData->removeObserver(curr);
    wetherData->setMeasurements(1, 23.4, 34.2);
    wetherData->registerObserver(curr);
    wetherData->notyfyObserver();

    //Нужно переделать под умные указатели!!!!

    delete forc;
    delete curr;
    delete wetherData;

    delete mallard;
}