#ifndef BOX_HPP_
    #define BOX_HPP_
    #include <SFML/Graphics.hpp>
    #include <SFML/Window.hpp>
    #include <SFML/System.hpp>
    #include <SFML/Audio.hpp>
    #include "image.hpp"

using namespace std;

class Box {
    public:
        Box(int, sf::Vector2f);

        int type;
        Image asset;

    private:
};

#endif /* !BOX_HPP_ */
