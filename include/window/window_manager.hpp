#ifndef WINDOW_MANAGER_HPP_
    #define WINDOW_MANAGER_HPP_
    #include <SFML/Graphics.hpp>
    #include <SFML/Window.hpp>
    #include <SFML/System.hpp>
    #include <SFML/Audio.hpp>
    #include <iostream>
    #include <cmath>
    #include "constants.hpp"
    #include "map_manager.hpp"

using namespace std;

class WindowManager {
    public:
        WindowManager(void);

        void eventWindow(void);
        void displayWindow(void);
        void clearWindow(void);
        void updateWindow(void);
        void manageRaycasting(MapManager, sf::Vector2f, sf::Vector2f, sf::Vector2f);
        bool isWindowOpen(void);

        sf::RenderWindow window;
        sf::Event event;
    private:
};

#endif /* !WINDOW_MANAGER_HPP_ */
