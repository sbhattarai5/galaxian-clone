//File: Star.h
//Arthur: Saurav Bhattarai
#ifndef STAR_H
#define STAR_H

#include "Includes.h"
#include "Constants.h"
#include "Surface.h"

const int N_stars = 50;
class Star
{
private:
    int r_;
    int x_;
    int y_;
    int dy_;
public:
    Star()
        : x_(rand() % W), y_(rand() % H), r_(rand() % 2 + 1), dy_(1)
    {}
    void move();
    void print(Surface &) const;
};

void make_stars_fall(Star *);
void print_stars(Star * const, Surface &);

#endif

