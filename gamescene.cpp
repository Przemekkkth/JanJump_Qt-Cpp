#include "gamescene.h"
#include "game.h"
#include <QKeyEvent>
#include <QGraphicsPixmapItem>
#include <QTimer>

GameScene::GameScene(QObject *parent)
    : QGraphicsScene{parent}, m_iteration_value(1000.0f/60.0f),
      m_leftMove(false), m_rightMove(false), m_heroXpos(100), m_heroYpos(100),
      m_deltaX(3), m_deltaY(0.2f), m_height(200), m_facingRight(true), m_countOfPlatforms(10)
{
    Game::init();
    setSceneRect(0, 0, m_game.RESOLUTION.width(), m_game.RESOLUTION.height());
//
    m_heroItem = new QGraphicsPixmapItem(QPixmap(m_game.PATH_TO_DOODLE_PIXMAP));
    m_heroTransform = m_heroItem->transform();
    addItem(m_heroItem);
    m_timer = new QTimer(this);
    connect(m_timer, &QTimer::timeout, this, &GameScene::update);
    m_timer->start(m_iteration_value);

    for (int i= 0; i < m_countOfPlatforms;i++)
    {
        m_platforms[i].x = rand() % Game::RESOLUTION.width();
        m_platforms[i].y = rand() % Game::RESOLUTION.height();
    }
}

void GameScene::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_Left:
        m_leftMove = true;
        break;
    case Qt::Key_Right:
        m_rightMove = true;
        break;

    }

    QGraphicsScene::keyPressEvent(event);
}

void GameScene::keyReleaseEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_Left:
    case Qt::Key_Right:
        m_rightMove = false;
        m_leftMove = false;
        break;

    }
    QGraphicsScene::keyReleaseEvent(event);
}

void GameScene::update()
{
    clear();
    m_heroItem = new QGraphicsPixmapItem(QPixmap(m_game.PATH_TO_DOODLE_PIXMAP));
    m_bgIteam = new QGraphicsPixmapItem(QPixmap(m_game.PATH_TO_BACKGROUND_PIXMAP).scaled(Game::RESOLUTION.width(), Game::RESOLUTION.height()));
    m_platformItem = new QGraphicsPixmapItem(QPixmap(m_game.PATH_TO_PLATFORM_PIXMAP));
    //platform resolution 68x14
    addItem(m_bgIteam);


    addItem(m_platformItem);


    m_time_since_last_iteration += m_iteration_value;
    if(m_time_since_last_iteration > Game::DELAY)
    {
        m_time_since_last_iteration = 0;
        if(m_leftMove)
        {
            m_heroXpos -= m_deltaX;
            if(m_heroTransform.m11() != -1)
            {
               m_heroTransform = m_heroTransform.scale(-1, 1);
               m_facingRight = false;
               m_heroXpos += m_heroItem->boundingRect().width();
            }

        }
        else if(m_rightMove)
        {
            m_heroXpos += m_deltaX;
            if(m_heroTransform.m11() != 1)
            {
               m_heroTransform = m_heroItem->transform();
               m_facingRight = true;
               m_heroXpos -= m_heroItem->boundingRect().width();
            }
        }

        m_deltaY += 0.2f;
        m_heroYpos += m_deltaY;
        if ( m_heroYpos > 500)
        {
            m_deltaY = -10;
        }

        if (m_heroYpos < m_height)
        {
            for (int i= 0; i < m_countOfPlatforms; i++)
            {
                m_heroYpos = m_height;
                m_platforms[i].y = m_platforms[i].y - m_deltaY;
                if (m_platforms[i].y > Game::RESOLUTION.height())
                {
                    m_platforms[i].y = 0;
                    m_platforms[i].x = rand() % Game::RESOLUTION.width();
                }
            }
        }

        for (int i = 0 ; i < m_countOfPlatforms; i++)
        {
            if(m_facingRight)
            {
                if ( (m_heroXpos + 50 > m_platforms[i].x) && (m_heroXpos + 20 < (m_platforms[i].x + m_platformItem->boundingRect().width()))
                && (m_heroYpos + 70 > m_platforms[i].y) && (m_heroYpos + 70 < (m_platforms[i].y + m_platformItem->boundingRect().height())) && (m_deltaY > 0))
                {
                    m_deltaY = -10;
                }
            }
            else
            {
                if ( (m_heroXpos - 50 > m_platforms[i].x) && (m_heroXpos - 20 < (m_platforms[i].x + m_platformItem->boundingRect().width()))
                && (m_heroYpos + 70 > m_platforms[i].y) && (m_heroYpos + 70 < (m_platforms[i].y + m_platformItem->boundingRect().height())) && (m_deltaY > 0))
                {
                    m_deltaY = -10;
                }
            }
        }

    }


    for(int i = 0; i < m_countOfPlatforms; ++i)
    {
        QGraphicsPixmapItem* platform_item = new QGraphicsPixmapItem(QPixmap(m_game.PATH_TO_PLATFORM_PIXMAP));
        platform_item->setPos(m_platforms[i].x, m_platforms[i].y);
        addItem(platform_item);
    }
    m_heroItem->setTransform(m_heroTransform);
    m_heroItem->setPos(m_heroXpos, m_heroYpos);
    addItem(m_heroItem);
}
