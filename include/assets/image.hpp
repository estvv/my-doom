#ifndef IMAGE_HPP_
    #define IMAGE_HPP_
    #include <SFML/Graphics.hpp>
    #include <SFML/Window.hpp>
    #include <SFML/System.hpp>
    #include <SFML/Audio.hpp>
    #include <memory>

using namespace std;

class Image {
    public:
        Image(void);
        void display(sf::RenderWindow &);
        void initImage(const string &, sf::Vector2f);

        sf::Sprite sprite;
        shared_ptr<sf::Texture> texture;
    private:
};

#endif /* !IMAGE_HPP_ */
