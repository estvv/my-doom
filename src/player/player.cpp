#include "player.hpp"

Player::Player(void):
    pos(22, 12),
    dir(-1, 0),
    plane(0, 0.66),
    iso_view(pos, dir, plane),
    fps_view(pos, dir, plane)
{
}

void Player::update(dimension dim)
{
    if (dim == FPS_VIEW) {
        pos = fps_view.pos;
        dir = fps_view.dir;
        plane = fps_view.plane;
    } else {
        pos = iso_view.pos;
        dir = iso_view.dir;
        plane = iso_view.plane;
    }
}
