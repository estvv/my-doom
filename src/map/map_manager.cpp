#include "map_manager.hpp"

using namespace std;

MapManager::MapManager()
{
}

ifstream *MapManager::openFile(const char *filename)
{
    ifstream *file = new ifstream(filename);

    if (!file) {
        cerr << "can't open file." << endl;
        return nullptr;
    }
    return file;
}

void MapManager::parseFile(ifstream *file)
{
    string line;
    sf::Vector2f pos(0, 0);

    if (not *file)
        return;
    while (getline(*file, line)) {
        vector<Box> row;
        for (size_t i = 0; i < line.size(); i += 1) {
            if (line[i] == '\n')
                continue;
            row.push_back(Box(line[i] - '0', pos));
            pos.x += 1;
        }
        pos.x = 0;
        pos.y += 1;
        box_map.push_back(row);
    }
    file->close();
}

void MapManager::initMap(const char *filename)
{
    parseFile(openFile(filename));
    y = box_map.size();
    x = box_map[0].size();
}

void MapManager::displayMap(sf::RenderWindow &window)
{
    for (size_t i = 0; i < box_map.size(); i++) {
        for (size_t j = 0; j < box_map[i].size(); j++) {
            if (box_map[i][j].type != 0)
                box_map[i][j].asset.display(window);
        }
    }
}
