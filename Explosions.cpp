//FileName: Explosion.cpp
//Name: Saurav Bhattarai
#include "Explosions.h"

int Explosion::state() const { return state_; }
int & Explosion::state() { return state_; }
const Rect & Explosion::get_rect() const { return obj_.get_rect(); }
