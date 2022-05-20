#ifndef GAME_H
#define GAME_H
#include <QSize>
#include <QPixmap>


class Game
{
public:
    Game();
    static void init();
    static QSize RESOLUTION;
    QPixmap BACKGROUND_PIXMAP;
    QPixmap DOODLE_PIXMAP;
    QPixmap PLATFORM_PIXMAP;
    static float DELAY;
};

#endif // GAME_H
