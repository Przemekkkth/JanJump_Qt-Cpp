#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QGraphicsScene>
#include <QTransform>

#include "game.h"
#include "point.h"
#include <QPixmap>

class QGraphicsPixmapItem;
class QTimer;
class GameScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit GameScene(QObject *parent = nullptr);

signals:


    // QGraphicsScene interface
protected:
    virtual void keyPressEvent(QKeyEvent *event) override;
    virtual void keyReleaseEvent(QKeyEvent *event) override;
private:
    void clampXpos();
    void drawScore();

    Game m_game;
    float m_time_since_last_iteration;
    const float m_iteration_value;

    bool m_leftMove;
    bool m_rightMove;

    int m_heroXpos;
    int m_heroYpos;
    const int m_deltaX;
    float m_deltaY;
    int m_height;

    QGraphicsPixmapItem* m_heroItem;
    QTransform m_heroTransform;
    bool m_facingRight;

    QGraphicsPixmapItem* m_bgIteam;
    QGraphicsPixmapItem* m_platformItem;

    const int m_countOfPlatforms;
    Point m_platforms[10];

    QTimer *m_timer;

    QPixmap m_heroPixmap;
    QPixmap m_numberPixmap;
private slots:
    void update();
};

#endif // GAMESCENE_H
