//Name: Saurav Bhattarai
//File: GamePlay.cpp
#include "GamePlay.h"
#include <cstring>

void check_collison(Fleet * fleet, std::list< Laser > & laser_list, SpaceShip & spaceship, std::list< Explosion > & explosions, bool & reset)
{
    std::vector< Alien *> & alien_list = fleet->alien_vec();
    for (auto it = laser_list.begin(); it != laser_list.end();)
    {
        bool laser_collided = false;
        if (it->isalien())
        {
            if(does_collide((*it), spaceship) && !reset)
            {
                    spaceship.lives() -= 1;
                    reset = true;
                    laser_collided = true;
            } 
        }
        else
        {
                for (int i = 0; i < alien_list.size(); ++i)
                {
                    if ((alien_list[i])->isalive())
                    {
                        if (does_collide((*it), *(alien_list[i])))
                        {
                            alien_list[i]->health() -= 10;
                            if (alien_list[i]->health() <= 0)
                            {
                            alien_list[i]->isalive() = false;
                            spaceship.score() += alien_list[i]->score();
                            --fleet->no_of_aliens_alive();
                            explosions.push_back((*alien_list[i]));
                        }
                        laser_collided = true;
                        break;
                    }
                }   
            }
        }
        if (!laser_collided) ++it;
        else it = laser_list.erase(it);
    }
    for (int i = 0; i < alien_list.size(); ++i)
    {
        Alien * alien = alien_list[i];
        if (!alien->isalive()) continue;
        if (does_collide(*(alien), spaceship) && !reset)
        {
            alien->isalive() = false;
            spaceship.lives() -= 1;
            reset = true;
            break;
        }

    }
    return;
}
void draw_health(Fleet * fleet, Surface & surface)
{
    std::vector< Alien *> const & alien_list = fleet->alien_vec();
    for (int i = 0; i< alien_list.size(); ++i)
    {
        Alien * alien = alien_list[i];
        if (alien -> isalive())
        {
            Rect rect_ = alien->get_rect();
            surface.put_rect(rect_.x + 5, rect_.y - 3, (1.0 * alien->health()/alien->full_health()) * (rect_.w - 10), 3, ((1.0*(alien->full_health() - alien->health())/alien->full_health())*255), (1.0*alien->health()/alien->full_health()) * 255, 0);
        }

    }
    return;
}
void print_new_level(int level, Surface & surface)
{
    Font font("fonts/FreeSans.ttf", 32);
    char text[] = "More Aliens are coming";
    char level_char = '1' + level;
    char level_text[] = {'L', 'e', 'v', 'e', 'l' , ' ', level_char, '\0'};
    Image image(font.render(level_text, WHITE));
    Rect rect = image.getRect();
    rect.y = H/2 - rect.h;
    rect.x = W/2 - rect.w/2;
    surface.put_image(image, rect);
    Image image2(font.render(text, WHITE));
    rect = image2.getRect();
    rect.y = H/2 + 5;
    rect.x = W/2 - rect.w/2;
    surface.put_image(image2, rect);
    return;
}
void print_score(const SpaceShip & spaceship, Surface & surface)
{
    Font font("fonts/FreeSans.ttf", 20);
    char text[] = "Score: ";
    char rev_score_text[10];
    int score = spaceship.score();
    int len = 0;
    while (score != 0)
    {
        rev_score_text[len] = '0' + (score % 10);
        score /= 10;
        ++len;
    }
    rev_score_text[len] = '\0';
    char score_text[10];
    for (int i = len - 1; i >= 0; --i)
    {
        score_text[len - i - 1] = rev_score_text[i];
    }
    score_text[len] ='\0';
    if (len == 0)
    {
        score_text[0] = '0';
        score_text[1] = '\0';
    }
    Image image(font.render(text, WHITE));
    Rect rect = image.getRect();   
    surface.put_image(image, rect);
    Image image2(font.render(score_text, WHITE));
    Rect rect2 = image2.getRect();
    rect2.x += rect.w;
    surface.put_image(image2, rect2);
    return;
}

void draw_explosion(std::list< Explosion > & explosions, Surface & surface)
{
    int i = 0;
    for (auto it = explosions.begin(); it != explosions.end();)
    {
        if(it->state() == 15)
        {
            it = explosions.erase(it);
            continue;
        }
        else
        {
            const Rect & rect = it->get_rect();
            surface.put_circle(rect.x + rect.w/2, rect.y + rect.h/2, it->state() + 1, rand() % 255, rand() % 255, rand() % 255);
            ++(it->state());
        }
        ++it;
        ++i;
    }
    return;
}
      
void draw_lives(int lives, Image * img, Surface & surface)
{
    Rect rect = img->getRect();
    rect.x = W;
    for (int i = 0; i < lives; ++i)
    {
        rect.x -= (rect.w - 2);
        surface.put_image(*img,rect);
        rect.x -= 5;
    }
    return;
}
