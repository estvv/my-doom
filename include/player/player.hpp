#ifndef PLAYER_HPP_
    #define PLAYER_HPP_
    #include <SFML/Graphics.hpp>
    #include <SFML/Window.hpp>
    #include <SFML/System.hpp>
    #include <SFML/Audio.hpp>
    #include <vector>
    #include "iso.hpp"
    #include "fps.hpp"
    #include "enums.hpp"

class Player {
    public:
        Player(void);

        void update(dimension);

        sf::Vector2f pos;
        sf::Vector2f dir;
        sf::Vector2f plane;
        ISO iso_view;
        FPS fps_view;
    private:
};

#endif /* !PLAYER_HPP_ */
