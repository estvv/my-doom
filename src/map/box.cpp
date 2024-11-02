#include "box.hpp"

Box::Box(int _type, sf::Vector2f _pos):
    type(_type)
{
    if (type == 1)
        asset.initImage("./assets/wall_red.png", _pos);
    if (type == 2)
        asset.initImage("./assets/wall_green.png", _pos);
    if (type == 3)
        asset.initImage("./assets/wall_blue.png", _pos);
    if (type == 4)
        asset.initImage("./assets/wall_white.png", _pos);
}
