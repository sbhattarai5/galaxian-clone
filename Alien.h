//Name: Saurav Bhattarai
//File: Alien.h

#ifndef ALIEN_H
#define ALIEN_H
#include "Game_obj.h"
#include "Laser.h"
#include <string>

class Alien: public Game_obj
{
protected:
    int full_health_;
    int health_;
    std::string state_;
    Image & image_;
    bool isalive_;
    int dx_;
    int dy_;
    int score_;
    int org_x_;
    int org_y_;
    int last_shooted_;
public:
    Alien(Image & image, int x, int y, int dx, int dy)
        : image_(image), Game_obj(image, x, y), full_health_(0), health_(0), state_("NORMAL"), isalive_(true), dx_(dx), dy_(dy)
        , score_(0), org_x_(x), org_y_(y), last_shooted_(0)
    {}
    void print(Surface &) const;
    void move(bool &, int, std::list< Laser> &);
    void attack();
    void shoot(std::list< Laser > &) const;
    bool isalive() const;
    bool & isalive();
    int health() const;
    int & health();
    int full_health() const;
    int x() const;
    int y() const;
    int & x();
    int & y();
    int org_x() const;
    int org_y() const;
    int & org_x();
    int & org_y(); 
    int dx() const;
    int dy() const;
    int & dx();
    int & dy();
    int score() const;
    std::string state() const;
    std::string & state();
    
};

#endif

