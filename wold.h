#ifndef world_H
#define world_H

#include<vector>

#include"object.h"
#include"fish.h"

class world
{
    public:
        world();
        ~world();

        void spawn(object*);
        void clear();
        void update();

    protected:
    private:
        std::vector<object*> _objects;

};

#endif // world_H
