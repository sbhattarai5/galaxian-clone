//File: Game_obj.cpp
//Name: Saurav Bhattarai

#include "Game_obj.h"

Rect const & Game_obj::get_rect() const
{
    return rect_;
}
Rect & Game_obj::get_rect() { return rect_; }
bool does_collide(const Game_obj & obj1, const Game_obj & obj2)
{
    Rect rect1 = obj1.get_rect();
    Rect rect2 = obj2.get_rect();
    if ((((rect2.x >= rect1.x) && (rect2.x < rect1.x + rect1.w)) ||
        ((rect2.x + rect2.w >= rect1.x) && (rect2.x + rect2.w < rect1.x + rect1.w)) ||
        ((rect1.x >= rect2.x) && (rect1.x + rect1.w < rect2.x + rect2.w))) &&
        (((rect2.y >= rect1.y) && (rect2.y < rect1.y + rect1.h)) ||
        ((rect2.y + rect2.h >= rect1.y) && (rect2.y + rect2.h < rect1.y + rect1.h)) ||
         ((rect1.y >= rect2.y) && (rect1.y + rect1.h < rect2.y + rect2.h)))) return true;
    return false;
}

