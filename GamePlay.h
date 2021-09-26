//Name: Saurav Bhattarai
//File: GamePlay.h

#ifndef GAMEPLAY_H
#define GAMEPLAY_H
#include "Fleet.h"
#include <list>
#include "SpaceShip.h"
#include "Explosions.h"
#include "Laser.h"

void check_collison(Fleet *, std::list< Laser > &, SpaceShip &, std::list< Explosion > &, bool &);
void draw_health(Fleet *, Surface & surface);
void print_new_level(int level, Surface & surface);
void print_score(const SpaceShip &, Surface &);
void draw_explosion(std::list< Explosion > & explosions, Surface & surface);
void draw_lives(int lives, Image * img, Surface & surface);
#endif



