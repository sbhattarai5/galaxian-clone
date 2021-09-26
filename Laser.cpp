//File: Laser.cpp
//Name: Saurav Bhattarai

#include "Laser.h"

bool Laser::move()
{
    rect_.y += dy_;
    if (rect_.y < 0 || rect_.y > H) return false;
    return true;
}

void Laser::print(Surface & surface) const
{
    surface.put_rect(rect_.x, rect_.y, rect_.w, rect_.h, 255, 255, 255);
}
void move_lasers(std::list< Laser > & laser_list)
{
    std::list< Laser >::iterator it;
    for (it = laser_list.begin(); it != laser_list.end();)
    {
        if (it->move())
        {
            ++it;
        }
        else
        {
            it = laser_list.erase(it);
        }
    }
    return;
}
void print_lasers(const std::list< Laser > & laser_list, Surface & surface)
{
    std::list< Laser >::const_iterator it;
    for (it = laser_list.begin(); it != laser_list.end(); ++it)
    {
        it->print(surface);
    }
}

bool Laser::isalien() const { return isalien_; }
