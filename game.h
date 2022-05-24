#ifndef GAME_H
#define GAME_H
#include <QSize>
#include <QString>


class Game
{
public:
    Game();
    static void init();
    static QSize RESOLUTION;
    QString PATH_TO_BACKGROUND_PIXMAP;
    QString PATH_TO_HERO_PIXMAP;
    QString PATH_TO_PLATFORM_PIXMAP;
    static float DELAY;
};

#endif // GAME_H
