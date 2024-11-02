#ifndef ISO_HPP_
    #define ISO_HPP_
    #include <SFML/Graphics.hpp>
    #include <SFML/Window.hpp>
    #include <SFML/System.hpp>
    #include <SFML/Audio.hpp>
    #include "image.hpp"

class ISO {
    public:
        ISO(sf::Vector2f, sf::Vector2f, sf::Vector2f);

        void setDir(sf::Keyboard::Key);
        void resetDir(sf::Keyboard::Key);
        void moove(vector<vector<int>>);
        void blockedMoove(void);
        void input(void);

        sf::Vector2f pos;
        sf::Vector2f dir;
        sf::Vector2f plane;
        Image asset;

    private:
};

#endif /* !ISO_HPP_ */
