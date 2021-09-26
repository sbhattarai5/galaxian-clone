//Name: Saurav Bhattarai
//File: Game_obj.h

#ifndef GAME_OBJ_H
#define GAME_OBJ_H
#include "Includes.h"
#include "Constants.h"
#include "Surface.h"
#include <list>

class Game_obj
{
protected:
    Rect rect_;
public:
    Game_obj(Image & image, int x=0, int y=0)
        : rect_(image.getRect())
    {
        rect_.x = x;
        rect_.y = y; 
    }
    Game_obj()
    {}
    Rect const & get_rect() const;
    Rect & get_rect();
};

bool does_collide(const Game_obj &, const Game_obj &);
#endif
