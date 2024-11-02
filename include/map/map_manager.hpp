#ifndef MAP_MANAGER_HPP_
    #define MAP_MANAGER_HPP_
    #define mapWidth 24
    #define mapHeight 24
    #include <SFML/Graphics.hpp>
    #include <SFML/Window.hpp>
    #include <SFML/System.hpp>
    #include <SFML/Audio.hpp>
    #include <vector>
    #include <iostream>
    #include <fstream>
    #include <cctype>
    #include <cstdlib>
    #include <climits>
    #include "box.hpp"

using namespace std;

class MapManager {
    public:
        MapManager(void);

        ifstream *openFile(const char *);
        void parseFile(ifstream *);
        void initMap(const char *);
        void displayMap(sf::RenderWindow &);

        vector<vector<Box>> box_map;
        int x;
        int y;
    private:
};

#endif /* !MAP_MANAGER_HPP_ */
