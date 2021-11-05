#pragma once
#include <iostream>

//-------------------------------------------
class IFlyBehavior
{
public:
    virtual void fly() = 0;
    virtual ~IFlyBehavior() {}
};

class FlyWithWings : public IFlyBehavior
{
public:
    void fly() override
    {
        std::cout << "I`m flying!!" << std::endl;
    }
};

class FlyNoWay : public IFlyBehavior
{
public:
    void fly() override
    {
        std::cout << "I can`t fly" << std::endl;
    }
};

class FlyRocketPowered : public IFlyBehavior
{
public:
    void fly() override
    {
        std::cout << "I`m flying witch a rocket!" << std::endl;
    }
};
//--------------------------------------------
class IQuackBehavior
{
public:
    virtual void quck() = 0;
    virtual ~IQuackBehavior() {}
};

class Quck : public IQuackBehavior
{
public:
    void quck() override
    {
        std::cout << "Quack" << std::endl;
    }
};

class MuteQuck : public IQuackBehavior
{
public:
    void quck() override
    {
        std::cout << "<< Silence >>" << std::endl;
    }
};

class Squeak : public IQuackBehavior
{
public:
    void quck() override
    {
        std::cout << "Squeak" << std::endl;
    }
};
//-----------------------------------------------
//Базовый класс для уток ))
class duck_base
{
protected:
    IFlyBehavior *_flybehavior;
    IQuackBehavior *_quackbehavior;

public:
    duck_base() : _flybehavior(nullptr), _quackbehavior(nullptr)
    {
        std::cout << "duck_base()" << std::endl;
        _quackbehavior = new Quck;
        _flybehavior = new FlyWithWings();
    }

    void setFlyBehavior(IFlyBehavior *fb)
    {
        if (_flybehavior)
            delete _flybehavior;
        _flybehavior = fb;
    }

    void setQuckBehavior(IQuackBehavior *qb)
    {
        if (_quackbehavior)
            delete _quackbehavior;
        _quackbehavior = qb;
    }

    virtual void display() = 0;

    void performFly()
    {
        _flybehavior->fly();
    }

    void performQuack()
    {
        _quackbehavior->quck();
    }

    void swim()
    {
        std::cout << "All duck float, even decoys!" << std::endl;
    }

    virtual ~duck_base()
    {
        std::cout << "~duck_base()" << std::endl;
        delete _quackbehavior;
        delete _flybehavior;
    }
};

//------------------------------------------------
//Множество объектов различных уток
class MallarDuck : public duck_base
{
public:
    MallarDuck()
    {
        std::cout << "MallarDuck()" << std::endl;
    }
    void display() override
    {
        std::cout << "I`m a real Mallar duck" << std::endl;
    }

    ~MallarDuck()
    {
        std::cout << "~MallarDuck()" << std::endl;
    }
};