//Name: Saurav Bhattarai
//File: Fleet.cpp

#include "Fleet.h"

void Fleet::print(Surface & surface) const
{
    for (int i = 0; i < aliens_fleet_.size(); ++i)
    {
        aliens_fleet_[i]->print(surface);
    }
}

void Fleet::move(std::list< Laser > & laser_list)
{
    bool need_to_change_direction = false;
    for (int i = 0; i < aliens_fleet_.size(); ++i)
    {
        Alien & alien = *(aliens_fleet_[i]);
        if(!alien.isalive()) continue;
        Rect rect_ = alien.get_rect();
        if (rect_.x + rect_.w + alien.dx() <= W -1 && rect_.x + alien.dx() >= 0) continue;
        need_to_change_direction = true;
        break;
    }
    if (need_to_change_direction)
    {
        dx_ = -dx_;
         for (int i = 0; i < aliens_fleet_.size(); ++i)
         {
             aliens_fleet_[i]->dx() *= -1;
         }
    }
    bool change_dy = false;
    if (fleet_y_ != original_fleet_y_) change_dy = true;
    for (int i = 0; i < aliens_fleet_.size(); ++i)
    {
        if (change_dy)
        {
            aliens_fleet_[i]->dy() = 1;
            aliens_fleet_[i]->org_y() += 1;
        }
        else
        {
            aliens_fleet_[i]->dy() = 0;
            if (!isattacking_ && aliens_fleet_[i]->state() == "NORMAL")
            {
                if (rand() % 10 == 0)
                {
                    aliens_fleet_[i]->state() = "ATTACK";
                    isattacking_ = true;
                }
            }
            aliens_fleet_[i]->dy() = 0;
        }
        aliens_fleet_[i]->move(isattacking_, dx_, laser_list);
    }
    if (change_dy) ++fleet_y_;
    
}

std::vector< Alien *> & Fleet::alien_vec()
{
    return aliens_fleet_;
}

int & Fleet:: no_of_aliens_alive()
{
    return no_of_aliens_alive_;
}
