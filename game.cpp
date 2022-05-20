#include "game.h"

QSize Game::RESOLUTION;
float Game::DELAY;

Game::Game()
{
    Q_ASSERT(BACKGROUND_PIXMAP.load(":/images/background.png"));
    Q_ASSERT(DOODLE_PIXMAP.load(":/images/doodle.png"));
    Q_ASSERT(PLATFORM_PIXMAP.load(":/images/platform.png"));
}

void Game::init()
{
    RESOLUTION = QSize(400, 533);

    DELAY = 0.2f;
}
