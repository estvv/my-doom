#include "window_manager.hpp"

WindowManager::WindowManager(void):
    window(sf::VideoMode(WIN_WIDTH, WIN_HEIGHT), "my-doom", sf::Style::Default)
{
    sf::Image icon;

    icon.loadFromFile("./assets/icon.png");
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    window.setFramerateLimit(60);
}

void WindowManager::eventWindow(void)
{
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
    }
}

void WindowManager::displayWindow(void)
{
    window.display();
}

void WindowManager::clearWindow(void)
{
    window.clear(sf::Color::Black);
}

void WindowManager::updateWindow(void)
{
    displayWindow();
    clearWindow();
}

bool WindowManager::isWindowOpen(void)
{
    return window.isOpen();
}

void WindowManager::manageRaycasting(MapManager map, sf::Vector2f pos, sf::Vector2f dir, sf::Vector2f plane)
{
    for (int i = 0; i < WIN_WIDTH; i++) {
        sf::Vector2i draw;
        sf::Vector2i step(1, 1);

        bool hit = false;  // bool to know if vision hit a wall
        bool side = false; // bool to know if the wall hit is a side wall to make him darker

        double ray_dir_x = dir.x + plane.x * (2 * i / double(WIN_WIDTH) - 1);
        double ray_dir_y = dir.y + plane.y * (2 * i / double(WIN_WIDTH) - 1);

        double delta_dist_x = sqrt(1 + (ray_dir_y * ray_dir_y) / (ray_dir_x * ray_dir_x));
        double delta_dist_y = sqrt(1 + (ray_dir_x * ray_dir_x) / (ray_dir_y * ray_dir_y));

        int map_pos_x = int(pos.x);
        int map_pos_y = int(pos.y);

        double side_x = (map_pos_x + 1.0 - pos.x) * delta_dist_x;
        double side_y = (map_pos_y + 1.0 - pos.y) * delta_dist_y;

        int line_height;

        if (ray_dir_x < 0) {
            step.x = -1;
            side_x = (pos.x - map_pos_x) * delta_dist_x;
        }

        if (ray_dir_y < 0) {
            step.y = -1;
            side_y = (pos.y - map_pos_y) * delta_dist_y;
        }

        while (!hit) {
            if (side_x < side_y) {
                side_x += delta_dist_x;
                map_pos_x += step.x;
                side = false;
            } else {
                side_y += delta_dist_y;
                map_pos_y += step.y;
                side = true;
            }
            if (map_pos_x < map.x && map_pos_y < map.y && map.box_map[map_pos_x][map_pos_y].type > 0)
                hit = true;
        }

        if (!side)
            line_height = abs(int(WIN_HEIGHT / fabs((map_pos_x - pos.x + (1 - step.x) / 2) / ray_dir_x)));
        else
            line_height = abs(int(WIN_HEIGHT / fabs((map_pos_y - pos.y + (1 - step.y) / 2) / ray_dir_y)));

        draw.x = -line_height / 2 + WIN_HEIGHT / 2;
        if (draw.x < 0)
            draw.x = 0;

        draw.y = line_height / 2 + WIN_HEIGHT / 2;
        if (draw.y >= WIN_HEIGHT)
            draw.y = WIN_HEIGHT - 1;

        sf::Color color;

        if (map.box_map[map_pos_x][map_pos_y].type == 1)
            color = sf::Color::Red;
        else if (map.box_map[map_pos_x][map_pos_y].type == 2)
            color = sf::Color::Green;
        else if (map.box_map[map_pos_x][map_pos_y].type == 3)
            color = sf::Color::Blue;
        else
            color = sf::Color::White;

        if (side)
            color = sf::Color(color.r / 2, color.g / 2, color.b / 2);

        sf::Vertex line[2] = {sf::Vertex(sf::Vector2f(i, draw.x), color), sf::Vertex(sf::Vector2f(i, draw.y), color)};
        window.draw(line, 2, sf::Lines);
    }
}
