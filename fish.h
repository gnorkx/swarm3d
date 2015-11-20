#ifndef FISH_H
#define FISH_H

#include "object.h"
#include "world.h"
#include "../toolbox/random/random.h"
class world;

class fish : public object
{
    public:
        fish(world*);
        ~fish();


        using object::getVel;
        using object::getPos;
        using object::setVel;
        using object::setPos;

        void update();

        void setWorld(world *w){_world = w;};
        world* getWorld() {return _world;};



    protected:
    private:

        void getObjInSight(std::vector<object*>&);
        bool inFOV(object*);
        vector3d getNewVel(std::vector<object*>&);
        vector3d getRandomVel();





        static const double _dT;
        static const double _vMax;
        static const double _vMin;
        static world* _world;
        std::vector<object*> _vInSight;
};

#endif // FISH_H
