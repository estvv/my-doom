#include "all.hpp"
#include <string>
#include <math.h>
#include <iostream>

extern Logger logger;

All::All(void):
    window_manager(),
    player(),
    map_manager(),
    view(FPS_VIEW),
    clock()
{
}

void All::gameLoop(void)
{
    map_manager.initMap("./maps/map.map");

    while (window_manager.isWindowOpen()) {
        manageEvent();
        manageView();
        manageDisplay();
    }
}

void All::manageEvent(void)
{
    window_manager.eventWindow();
}

void All::manageView(void)
{
    if (view == FPS_VIEW) {
        window_manager.manageRaycasting(map_manager, player.pos, player.dir, player.plane);
        fps = clock.getElapsedTime();
        clock.restart();
        player.fps_view.updateMovement(map_manager.box_map, fps.asSeconds() * 5.0, fps.asSeconds() * 3.0);
        player.update(view);
    } else {
        map_manager.displayMap(window_manager.window);
        player.update(view);
    }
}

void All::manageDisplay(void)
{
    window_manager.updateWindow();
}
