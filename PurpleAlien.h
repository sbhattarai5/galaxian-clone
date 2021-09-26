//File: PurpleAlien.h
//Name: Saurav Bhattarai

#ifndef PURPLEALIEN_H
#define PURPLEALIEN_H
#include "Alien.h"

class PurpleAlien: public Alien
{
    static Image image_;
public:
PurpleAlien(int x, int y, int dx, int dy)
    : Alien(PurpleAlien::image_, x, y, dx, dy)
    {
        score_ += 20;
        full_health_ = 20;
        health_ = full_health_;
    }
};

#endif

