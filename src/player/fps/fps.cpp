#include "fps.hpp"

extern Logger logger;

FPS::FPS(sf::Vector2f _pos, sf::Vector2f _dir, sf::Vector2f _plane):
    pos(_pos),
    dir(_dir),
    plane(_plane)
{
}

void FPS::updateMovement(vector<vector<Box>> box_map, double moveSpeed, double rotSpeed)
{
    sf::Vector2f prev_dir(dir);
    sf::Vector2f prev_plane(plane);

    if (sf::Keyboard::isKeyPressed(WEST)) {
        dir.x = dir.x * cos(rotSpeed) - dir.y * sin(rotSpeed);
        dir.y = prev_dir.x * sin(rotSpeed) + dir.y * cos(rotSpeed);

        plane.x = plane.x * cos(rotSpeed) - plane.y * sin(rotSpeed);
        plane.y = prev_plane.x * sin(rotSpeed) + plane.y * cos(rotSpeed);

        logger.info("Left rotation");
    }
    else if (sf::Keyboard::isKeyPressed(EAST)) {
        dir.x = dir.x * cos(-rotSpeed) - dir.y * sin(-rotSpeed);
        dir.y = prev_dir.x * sin(-rotSpeed) + dir.y * cos(-rotSpeed);

        plane.x = plane.x * cos(-rotSpeed) - plane.y * sin(-rotSpeed);
        plane.y = prev_plane.x * sin(-rotSpeed) + plane.y * cos(-rotSpeed);

        logger.info("Right rotation");
    }
    else if (sf::Keyboard::isKeyPressed(NORTH)) {
        if (box_map[int(pos.x + dir.x * moveSpeed)][int(pos.y)].type == 0)
            pos.x += dir.x * moveSpeed;
        if (box_map[int(pos.x)][int(pos.y + dir.y * moveSpeed)].type == 0)
            pos.y += dir.y * moveSpeed;

        logger.info("Forward movement");
    }
    else if (sf::Keyboard::isKeyPressed(SOUTH)) {
        if (box_map[int(pos.x - dir.x * moveSpeed)][int(pos.y)].type == 0)
            pos.x -= dir.x * moveSpeed;
        if (box_map[int(pos.x)][int(pos.y - dir.y * moveSpeed)].type == 0)
            pos.y -= dir.y * moveSpeed;

        logger.info("Backward movement");
    }
}
