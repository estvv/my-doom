#include "iso.hpp"
#include "constants.hpp"
#include "map_manager.hpp"

bool isMovingNorth = false;
bool isMovingSouth = false;
bool isMovingWest = false;
bool isMovingEast = false;
sf::Keyboard::Key lastY = SOUTH;
sf::Keyboard::Key lastX = EAST;

ISO::ISO(sf::Vector2f _pos, sf::Vector2f _dir, sf::Vector2f _plane):
    pos(_pos),
    dir(_dir),
    plane(_plane)
{
}

void ISO::blockedMoove(void)
{
    return;
}

void ISO::moove(vector<vector<int>> box_map)
{
    int rdm = box_map[0][0];
    rdm = rdm;
    return;
    // bool can_moove = true;
    // sf::Vector2f new_pos = sf::Vector2f(asset.sprite.getPosition().x + dir.x, asset.sprite.getPosition().y + dir.y);
    // sf::FloatRect box;

    // // for (size_t i = 0; i < box_map.size(); i++) {
    // //     for (size_t j = 0; j < box_map[i].size(); j++) {
    // //         if (nextMooveIsBox(box_map[i][j].asset.sprite.getGlobalBounds(), new_pos))
    // //             can_moove = false;
    // //     }
    // // }
    // if (can_moove)
    //     asset.sprite.move(dir);
    // else
    //     blockedMoove();
}

bool nextMooveIsBox(sf::FloatRect box, sf::Vector2f new_pos)
{
    return (box.contains(sf::Vector2f(new_pos.x, new_pos.y)) or box.contains(sf::Vector2f(new_pos.x + 32, new_pos.y)) or
            box.contains(sf::Vector2f(new_pos.x, new_pos.y + 32)) or box.contains(sf::Vector2f(new_pos.x + 32, new_pos.y + 32)));
}

void ISO::input(void)
{
    return;
}

void ISO::setDir(sf::Keyboard::Key key)
{
    if (key == NORTH) {
        lastY = NORTH;
        isMovingNorth = true;
        dir.y = -SPEED;
    }
    if (key == SOUTH) {
        lastY = SOUTH;
        isMovingSouth = true;
        dir.y = SPEED;
    }
    if (key == WEST) {
        lastX = WEST;
        isMovingWest = true;
        dir.x = -SPEED;
    }
    if (key == EAST) {
        lastX = EAST;
        isMovingEast = true;
        dir.x = SPEED;
    }
    if (key == NORTH && key == SOUTH)
        dir.y = 0;
    if (key == WEST && key == EAST)
        dir.x = 0;
}

void ISO::resetDir(sf::Keyboard::Key key)
{
    if (key == NORTH) {
        isMovingNorth = false;
        dir.y = isMovingSouth ? SPEED : 0;
    }
    if (key == SOUTH) {
        isMovingSouth = false;
        dir.y = isMovingNorth ? -SPEED : 0;
    }
    if (key == WEST) {
        isMovingWest = false;
        dir.x = isMovingEast ? SPEED : 0;
    }
    if (key == EAST) {
        isMovingEast = false;
        dir.x = isMovingWest ? -SPEED : 0;
    }
}
