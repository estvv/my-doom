#ifndef ALL_HPP_
    #define ALL_HPP_
    #include <SFML/Graphics.hpp>
    #include <SFML/Window.hpp>
    #include <SFML/System.hpp>
    #include <SFML/Audio.hpp>
    #include "window_manager.hpp"
    #include "player.hpp"
    #include "map_manager.hpp"
    #include "logger.hpp"
    #include "enums.hpp"

class All {
    public:
        All(void);

        void gameLoop(void);
        void manageEvent(void);
        void manageView(void);
        void manageDisplay(void);

        WindowManager window_manager;
        Player player;
        MapManager map_manager;
        dimension view;
        sf::Clock clock;
        sf::Time fps;
        double time;
        double oldTime;
    private:
};

#endif /* !ALL_HPP_ */
