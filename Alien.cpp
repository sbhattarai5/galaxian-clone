//Name: Saurav Bhattarai
//File: Alien.cpp

#include "Alien.h"
#include <cmath>

void Alien::print(Surface & surface) const
{
    if (isalive_)
        surface.put_image(image_, rect_);
}

void Alien::move(bool & isattacking, int fleet_dx, std::list< Laser> & laser_list)
{
    if (state_ == "NORMAL")
    {
        org_x_ += dx_;
        rect_.x += dx_;
        rect_.y += dy_;
    }
    if (state_ == "ATTACK")
    {
        if (last_shooted_ < 30) ++last_shooted_;
        else
        {
            if (isalive_) shoot(laser_list);
            last_shooted_ = 0;
        }
        org_x_ += fleet_dx;
        rect_.y += 1;
        dx_ = 10 * sin(rect_.y/10.0);
        rect_.x = org_x_ + dx_;
        if (rect_.x >= W) rect_.x = W - 1;
        if (rect_.x < 0) rect_.x = 0;
        if(rect_.y >= H)
        {
                rect_.y = -20;
                state_ = "BACKTOPOSITION";
        }   
    }
    if (state_ == "BACKTOPOSITION")
    {
        org_x_ += fleet_dx;
        if (rect_.x > org_x_) rect_.x -= 1;
        if (rect_.x < org_x_) rect_.x += 1;
        if (rect_.y > org_y_) rect_.y -= 1;
        if (rect_.y < org_y_) rect_.y += 1;
        if (rect_.x == org_x_ && rect_.y == org_y_)
        {
            state_ = "NORMAL";
            last_shooted_ = 0;
            isattacking = false;
            dy_ = 0;
            dx_ = fleet_dx;
        }
    }
}

void Alien::shoot(std::list< Laser > & laser_list) const
{
    laser_list.push_back(Laser(*this, true));
}

bool Alien::isalive() const
{
    return isalive_;
}
bool & Alien::isalive()
{
    return isalive_;
}
int Alien::health() const
{
    return health_;
}
int & Alien::health()
{
    return health_;
}
int Alien::full_health() const
{
    return full_health_;
}
int Alien::x() const
{
    return rect_.x;
}
int Alien::y() const
{
    return rect_.y;
}
int & Alien::x()
{
    return rect_.x;

}
int & Alien::y() 
{
    return rect_.y;
}
int Alien::dx() const
{
    return dx_;
}
int Alien::dy() const
{
    return dy_;
}
int & Alien::dx() 
{
    return dx_;
}
int & Alien::dy() 
{
    return dy_;
}
std::string Alien::state() const
{
    return state_;
}
std::string & Alien::state()
{
    return state_;
}
int Alien::score() const
{
    return score_;
}
int Alien::org_x() const
{
    return org_x_;
}
int Alien::org_y() const
{
    return org_y_;
}
int & Alien::org_x()
{
    return org_x_;
}
int & Alien::org_y() 
{
    return org_y_;
}
void Alien::attack()
{
    state_ = "ATTACK";
}

