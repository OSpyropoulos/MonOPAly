#include "graphics.h"
#include "Game.h"
#include "Config.h"

using namespace graphics;

void update(float ms)
{
    Game* game = reinterpret_cast<Game*>(getUserData());
    game->update();

}

void draw()
{
    Game* game = reinterpret_cast<Game*>(getUserData());
    game->draw();
}

int main()
{
    Game maingame;
    createWindow(CANVAS_WIDTH, CANVAS_HEIGHT,"Monopaly");

    setUserData(&maingame);

    setDrawFunction(draw);
    setUpdateFunction(update);

    setCanvasSize(CANVAS_WIDTH, CANVAS_HEIGHT);
    setCanvasScaleMode(CANVAS_SCALE_FIT);

    startMessageLoop();

    maingame.init();
    return 0;

}