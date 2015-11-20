#include "world.h"

world::world()
{
    //ctor
}

world::~world()
{
    //dtor
    for(auto o: _objects)
        delete o;
}

void world::spawn()
{
    fish* tmp_fish = new fish(this);
    tmp_fish -> setPos({rnd0(3),rnd0(3),rnd0(3)});
    tmp_fish -> setVel({rnd0(3),rnd0(3),rnd0(3)});
    _objects.push_back(tmp_fish);

}

void world::spawn(int n)
{

    for(int i =0; i<n; i++)
        spawn();

}

void world::update()
{
    for(auto o : _objects)
    {
        o->update();
        std::cout<<"Pos: "<<o->getPos()<<std::endl;
        std::cout<<"Vel: "<<o->getVel()<<std::endl;
    }
}
