#include <iostream>
#include "image.hpp"
#include "constants.hpp"
#include <cstdio>

using namespace std;

Image::Image(void) :
    texture(make_shared<sf::Texture>())
{
}

void Image::initImage(const string &filepath, sf::Vector2f pos)
{
    if (not (*texture).loadFromFile(filepath)) {
        cerr << "Problem with " + filepath + "." << endl;
        exit(84);
    }
    sprite.setTexture(*texture);
    sprite.setScale(sf::Vector2f(WIN_WIDTH / (MAP_MAX_SIZE * SPRITE_SIZE), WIN_HEIGHT / (MAP_MAX_SIZE * SPRITE_SIZE)));
    sprite.setPosition(sf::Vector2f(pos.x * SPRITE_SIZE * sprite.getScale().x, pos.y * SPRITE_SIZE * sprite.getScale().y));
}

void Image::display(sf::RenderWindow &window)
{
    window.draw(sprite);
}
