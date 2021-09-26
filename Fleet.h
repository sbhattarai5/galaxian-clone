//Name: Saurav Bhattarai
//File: Fleet.h

#ifndef FLEET_H
#define FLEET_H
#include "RedAlien.h"
#include "AquaAlien.h"
#include "PurpleAlien.h"
#include "YellowAlien.h"
#include <vector>

class Fleet
{
private:
    int no_of_aliens_alive_;
    int no_of_yellow_aliens_;
    int no_of_red_aliens_;
    int no_of_purple_aliens_;
    int no_of_aqua_aliens_;
    int no_of_aqua_row_;
    int aqua_alien_per_col_;
    bool isattacking_ = false;
    int fleet_y_;
    int original_fleet_y_;
    int dx_;
    std::vector< Alien * > aliens_fleet_;
    std::vector< YellowAlien * > yellow_aliens_fleet_;
    std::vector< RedAlien * > red_aliens_fleet_;
    std::vector< PurpleAlien * > purple_aliens_fleet_;
    std::vector< AquaAlien * > aqua_aliens_fleet_;
public:
    Fleet(int no_of_yellow_aliens)
        : no_of_yellow_aliens_(no_of_yellow_aliens), no_of_red_aliens_(no_of_yellow_aliens * 2), no_of_purple_aliens_(no_of_yellow_aliens * 4), no_of_aqua_aliens_(no_of_yellow_aliens * 4),
        no_of_aqua_row_(2), no_of_aliens_alive_(0), dx_(1),
        aqua_alien_per_col_(no_of_yellow_aliens * 4), fleet_y_(0), original_fleet_y_(40)
    {
        int subtract = 0;
        if (no_of_yellow_aliens > 1) subtract = (H - (H/2));
        int col_gaps_between_alien = (W - (W/4)) / (no_of_yellow_aliens * 4);
        int row_gaps_between_alien = (H - (H/2))/ 5;
        int y = 40 - subtract;
        std::cout << y << std::endl;
        fleet_y_ = y;
        for (int i = 0; i < no_of_yellow_aliens_; ++i)
        {
            YellowAlien * yellowalien = new YellowAlien((W - no_of_yellow_aliens_ * col_gaps_between_alien)/2 + i * col_gaps_between_alien, y, 1, 0);
            aliens_fleet_.push_back(yellowalien);
            yellow_aliens_fleet_.push_back(yellowalien);
            ++no_of_aliens_alive_;
        }
        y += row_gaps_between_alien;
        for (int i = 0; i < no_of_red_aliens_; ++i)
        {
            RedAlien * redalien = new RedAlien((W - no_of_red_aliens_ * col_gaps_between_alien)/2 + i * col_gaps_between_alien, y, 1, 0);
            aliens_fleet_.push_back(redalien);
            red_aliens_fleet_.push_back(redalien);
            ++no_of_aliens_alive_;
        }
        y += row_gaps_between_alien;
        for (int i = 0; i < no_of_purple_aliens_; ++i)
        {
            PurpleAlien * purplealien = (new PurpleAlien((W - no_of_purple_aliens_ * col_gaps_between_alien)/2 + i * col_gaps_between_alien, y, 1, 0));
            aliens_fleet_.push_back(purplealien);
            purple_aliens_fleet_.push_back(purplealien);
            ++no_of_aliens_alive_;
        }
        for (int i = 0; i < no_of_aqua_row_; ++i)
        {
            y += row_gaps_between_alien;
            for (int j = 0; j < aqua_alien_per_col_; ++j)
            {
                AquaAlien * aquaalien = (new AquaAlien((W - aqua_alien_per_col_ * col_gaps_between_alien)/2 + j * col_gaps_between_alien, y, 1, 0));
                aliens_fleet_.push_back(aquaalien);
                aqua_aliens_fleet_.push_back(aquaalien);
                ++no_of_aliens_alive_;
            }
        }
    }
    void print(Surface &) const;
    void move(std::list< Laser > &);
    std::vector< Alien * > & alien_vec();
    int & no_of_aliens_alive();
    ~Fleet()
    {
        for (int i = 0; i < aliens_fleet_.size(); ++i)
        {
            delete aliens_fleet_[i];
        }
    }
};




#endif




