//File: AquaAlien.h
//Name: Saurav Bhattarai

#ifndef AQUAALIEN_H
#define AQUAALIEN_H
#include "Alien.h"

class AquaAlien: public Alien
{
private:
    static Image image_;
public:
AquaAlien(int x, int y, int dx, int dy)
    : Alien(AquaAlien::image_, x, y, dx, dy)
    {
        score_ += 10;
        full_health_ = 10;
        health_ = full_health_;
    }
};

#endif


