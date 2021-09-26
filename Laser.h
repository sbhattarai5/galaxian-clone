//Name: Saurav Bhattarai
//File: Laser.h
#ifndef LASER_H
#define LASER_H

#include "Game_obj.h"

class Laser: public Game_obj
{
private:
    int dy_;
    bool isalien_;
public:
    Laser(const Game_obj & obj, bool isalien=false)
        :isalien_(isalien)
    {
        Rect objrect_ = obj.get_rect();
        rect_.x = objrect_.x + (objrect_.w / 2);
        rect_.w = 2;
        rect_.h = 20;
        if (!isalien_)
        {
            dy_ = -2;
            rect_.y = objrect_.y - rect_.h - 3;
        }
        else
        {
            dy_ = 2;
            rect_.y = objrect_.y + objrect_.h;
        }

    }
    bool isalien() const;
    bool move();        
    void print(Surface & surface) const;
};

void move_lasers(std::list< Laser > & laser_list);
void print_lasers(const std::list< Laser > & laser_list, Surface & surface);
#endif

