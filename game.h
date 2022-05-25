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
    static const float JUMP_FORCE;
    //var for better jump
    static const int X_OFFSET;
    static const int Y_OFFSET;
    static const QSize HERO_SIZE;
    //
    static const float JUMP_SPEED;
    static const int DEAD_LEVEL;
    static const QSize PLATFORM_SIZE;
};

#endif // GAME_H
