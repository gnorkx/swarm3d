#ifndef world_H
#define world_H

#include<vector>

#include"object.h"
#include"fish.h"

typedef std::vector<object*> object_list;

class world
{
    public:
        world();
        virtual ~world();

        void spawn();
        void spawn(int);

        void clear();
        void update();

        object_list* getObjects() {return &_objects;};

    protected:
    private:
        object_list _objects;

};

#endif // world_H
