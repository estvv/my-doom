#ifndef FPS_HPP_
    #define FPS_HPP_
    #include <SFML/Graphics.hpp>
    #include <SFML/Window.hpp>
    #include <SFML/System.hpp>
    #include <SFML/Audio.hpp>
    #include <cmath>
    #include <vector>
    #include <iostream>
    #include "box.hpp"
    #include "logger.hpp"
    #include "constants.hpp"

using namespace std;

class FPS {
    public:
        FPS(sf::Vector2f, sf::Vector2f, sf::Vector2f);

        void updateMovement(vector<vector<Box>>, double, double);

        sf::Vector2f pos;
        sf::Vector2f dir;
        sf::Vector2f plane;
    private:
};

#endif /* !FPS_HPP_ */
