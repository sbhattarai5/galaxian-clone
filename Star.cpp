//File: Star.cpp
//Name: Saurav Bhattarai

#include "Star.h"

void Star::move()
{
    y_ += dy_;
    if (y_ > H)
    {
        x_ = rand() % W;
        y_ = -10;
    }
}
void Star::print(Surface & surface) const
{
    surface.put_circle(x_, y_, r_, rand() % 256, rand() % 256, rand () % 256);
}
void make_stars_fall(Star * stars)
{
    for (int i = 0; i < N_stars; ++i)
    {
        stars[i].move();
    }
    return;
}
void print_stars(Star * const stars, Surface & surface)
{
    for (int i = 0; i < N_stars; ++i)
    {
        stars[i].print(surface);
    }
    return;
}
