#pragma once

#include <QWidget>
#include <QKeyEvent>
#include <QTimer>
#include <QPainter>
#include "Player.h"
#include "Boss.h"
#include "Projectile.h"
#include <QPushButton>

class Game : public QWidget {
    Q_OBJECT

public:
    explicit Game(QWidget *parent = nullptr);
    void keyPressEvent(QKeyEvent *event) override;
    void paintEvent(QPaintEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;
     QPixmap background;

private:
    Player player;
    Boss boss;
    QPixmap sprite;
    QVector<Projectile> projectiles;
    int playerLives;
    enum class GameState { Playing, GameOver, Victory };
    GameState gameState;
    QSet<int> activeKeys;
    QPushButton *pauseButton;

\

    void gameLoop();
    void checkCollisions();
    void checkProjectileCollisions();
    void updateLivesDisplay();
    void togglePause();
};
