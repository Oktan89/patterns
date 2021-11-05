#include <iostream>
#include "strategy.h"

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

        
    delete mallard;
}