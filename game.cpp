#include "game.h"

QSize Game::RESOLUTION;
float Game::DELAY;

Game::Game()
{
    PATH_TO_BACKGROUND_PIXMAP = ":/images/background.png";
    PATH_TO_DOODLE_PIXMAP = ":/images/doodle.png";
    PATH_TO_PLATFORM_PIXMAP = ":/images/platform.png";
}

void Game::init()
{
    RESOLUTION = QSize(400, 533);

    DELAY = 0.2f;
}
