//File: YellowAlien.h
//Name: Saurav Bhattarai

#ifndef YELLOWALIEN_H
#define YELLOWLIEN_H
#include "Alien.h"

class YellowAlien: public Alien
{
    static Image image_;
public:
    YellowAlien(int x, int y, int dx, int dy)
    : Alien(YellowAlien::image_, x, y, dx, dy)
    {
        score_ += 50;
        full_health_ = 50;
        health_ = full_health_;
    }
};

#endif

