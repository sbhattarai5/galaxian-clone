//FileName: Explosions.h
//Arthur: Saurav Bhattarai

#ifndef EXPLOSIONS_H
#define EXPLOSIONS_H
#include "Game_obj.h"
#include <vector>

class Explosion 
{
public:
    Explosion(Game_obj & obj)
        : obj_(obj), state_(0)
    {}
    int state() const;
    int & state();
    Rect const & get_rect() const;
private:
    Game_obj & obj_;
    int state_;
};

#endif

