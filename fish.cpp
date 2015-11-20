#include "fish.h"

const double fish::_dT = 0.01;
const double fish::_vMax = 2;
const double fish::_vMin = 0.1;
world* fish::_world = nullptr;


fish::fish(world* w)
{
    //ctor
    setWorld(w);
}

fish::~fish()
{
    //dtor
}

void fish::update()
{

    getObjInSight(_vInSight);
    if(_vInSight.size()>0)
    {
        setVel( getNewVel(_vInSight) );
    }
    else
    {
        setVel( getRandomVel() );
    }

    setPos( getPos() +_dT*getVel() );

}

void fish::getObjInSight(std::vector<object*> &v)
{
    v.clear();
    std::vector<object*>* objs = getWorld()->getObjects();
    for(auto o:*objs)
    {
        if(!o->active()) continue;
        if(inFOV(o)) v.push_back(o);
    }
}

bool fish::inFOV(object *o)
{
    vector3d diff = getPos() - o->getPos();
    double cosTh =  getVel().cosTheta(o->getVel());
    if( diff.abs()<20 && cosTh>0.5 )
        return true;
    else
        return false;
}

vector3d fish::getNewVel(std::vector<object*> &v)
{
    vector3d meanVel;
    vector3d meanPos;
    vector3d meanDiff;
    for(auto o:v)
    {
        meanVel+= o->getVel();
        meanPos+= o->getPos();
        meanDiff+= getPos() - o->getPos();
    }
    meanVel.scale(1./v.size());
    meanPos.scale(1./v.size());
    meanDiff.scale(1./v.size());


    double wPos = 0.1, wForce = 0.1;
    vector3d newVel =  meanVel + wPos*(meanPos-getPos()) + wForce/(meanDiff.abs()+0.001)*meanDiff;
    newVel.scale(1./(1+wPos+wForce));

    //cant change direction immediately:
    newVel = getVel() + _dT*newVel;

    float abs = newVel.abs();
    if(abs>_vMax) newVel.scale(_vMax/abs);
    else if(abs<_vMin) newVel.scale(_vMin/abs);
    return newVel;

}

vector3d fish::getRandomVel()
{
    if(rnd()>0.6) return getVel();
    vector3d newVel = getVel() + vector3d(rnd0(2),rnd0(2),rnd0(2));
    float abs = newVel.abs();
    if(abs>_vMax) newVel.scale(0.9*_vMax/abs);
    else if(abs<_vMin) newVel.scale(0.9*_vMin/abs);
    return newVel;
}
