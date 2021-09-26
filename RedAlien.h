//File: RedAlien.h
//Name: Saurav Bhattarai

#ifndef REDALIEN_H
#define REDALIEN_H
#include "Alien.h"

class RedAlien: public Alien
{
    static Image image_;
public:
RedAlien(int x, int y, int dx, int dy)
    : Alien(RedAlien::image_, x, y, dx, dy)
    {
        score_ += 30;
        full_health_ = 30;
        health_ = full_health_;
    }
};

#endif

