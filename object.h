#ifndef OBJECT_H
#define OBJECT_H


#include "../toolbox/trigom/vector3d.h"

class object
{
    public:
    virtual ~object(){};
  //  object(){};
    virtual void update() = 0;

    vector3d getPos()const{return _pos;};
    vector3d getVel()const{return _vel;};

    void setPos(vector3d pos){_pos = pos;};
    void setVel(vector3d vel){_vel = vel;};

    bool active() const {return _active;};


    protected:
    private:
        vector3d _pos;
        vector3d _vel;
        bool _active;
};

#endif // OBJECT_H
