//File: SpaceShip.cpp
//Name: Saurav Bhattarai
#include "SpaceShip.h"

Image SpaceShip::image_("images/galaxian/GalaxianGalaxip.gif");
void SpaceShip::move_left()
{
    rect_.x -= dx_;
    if (rect_.x < 0) rect_.x = 0;
}
void SpaceShip::move_right()
{
    rect_.x += dx_;
    if (rect_.x > W - rect_.w) rect_.x = W - rect_.w;
}
void SpaceShip::print(Surface & surface) const
{
    surface.put_image(((SpaceShip::image_)), rect_);
}

void SpaceShip::shoot(std::list< Laser > & laser_list) 
{
    if (last_bullet_fired_ > bullet_delay_)
    {
        laser_list.push_back(Laser(*this));
        last_bullet_fired_ = 0;
    }
}

void SpaceShip::increase_last_bullet_fired_time()
{
    ++last_bullet_fired_;
}
                         
bool & SpaceShip::isalive()
{
    return isalive_;
}

bool SpaceShip::isalive() const
{
    return isalive_;
}
int SpaceShip::score() const { return score_; }
int & SpaceShip::score() { return score_; }

int SpaceShip::lives() const { return lives_; }
int & SpaceShip::lives() { return lives_; }
