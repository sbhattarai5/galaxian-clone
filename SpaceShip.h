//File: SpaceShip.h
//Arthur: Saurav Bhattarai
#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "Game_obj.h"
#include "Laser.h"

class SpaceShip : public Game_obj 
{
private:
    int health_;
    bool isalive_;
    int dx_;
    int score_;
    static Image image_;
    int last_bullet_fired_;
    int bullet_delay_;
    int lives_;
public:
    SpaceShip()
        : Game_obj(SpaceShip::image_), dx_(2), health_(100), last_bullet_fired_(0), bullet_delay_(30), isalive_(true)
        , score_(0), lives_(3)
    {
        rect_.x = W / 2 - rect_.w / 2;
        rect_.y = H - 1 - rect_.h;
    }
    void move_left();
    void move_right();
    void shoot(std::list< Laser > &);
    void print(Surface &) const;
    void increase_last_bullet_fired_time();
    bool isalive() const;
    bool & isalive();
    int score() const;
    int & score();
    int lives() const;
    int & lives();
};


#endif

