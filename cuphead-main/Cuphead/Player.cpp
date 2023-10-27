#include "Player.h"
#include <QRectF>

Player::Player(const QPointF &pos) : position(pos), speedX(4.0), speedY(0), onGround(true), movingLeft(false), movingRight(false), dashSpeed(6.0), isDashing(false), dashDuration(0) {
    sprite = QPixmap(":/image/image/player.jpg");
}

void Player::update() {
    const qreal gravity = 0.5;
    const qreal maxFallSpeed = 10.0;

    if (!onGround) {
        speedY += gravity;
        if (speedY > maxFallSpeed) {
            speedY = maxFallSpeed;
        }
    } else {
        speedY = 0;
    }

    if (movingLeft) {
        position.setX(position.x() + speedX);
    }
    if (movingRight) {
        position.setX(position.x() + speedX);
    }

    position.setY(position.y() + speedY);

    if (position.y() >= 350) {
        position.setY(350);
        onGround = true;
    } else {
        onGround = false;
    }
}

QPointF Player::getVelocity() const {
    return QPointF(speedX, speedY);
}
void Player::moveLeft() {
    speedX = -5;
    movingLeft = true;
    movingRight = false;
}

void Player::moveRight() {
    speedX = 5;
    movingLeft = false;
    movingRight = true;
}

void Player::stopMoving() {
    speedX = 0;
    movingLeft = false;
    movingRight = false;
}



void Player::setVelocity(const QPointF &velocity) {
    speedX = velocity.x();
    speedY = velocity.y();
}

int Player::facingDirection() const {
    // Возвращает 1, если персонаж смотрит направо, и -1, если налево
    return movingRight ? 1 : -1;
}

void Player::draw(QPainter *painter) {
    painter->drawPixmap(position, sprite);
}

QRectF Player::boundingRect() const {
    return QRectF(position, QSizeF(sprite.width(), sprite.height()));
}


void Player::jump() {
    if (onGround) {
        speedY = -15;
        onGround = false;
    }
}

void Player::startDash() {
    if (!isDashing) {
        speedX *= dashSpeed;
        isDashing = true;
        dashDuration = 10; // Set the dash duration (number of frames)
    }
}

void Player::stopDash() {
    if (isDashing) {
        speedX /= dashSpeed;
        isDashing = false;
    }
}

void Player::updateDash() {
    if (isDashing) {
        dashDuration--;
        if (dashDuration <= 0) {
            stopDash();
        }
    }
}
void Player::stopMovingLeft() {
    movingLeft = false;
    if (!movingRight) {
        speedX = 0;
    }
}

void Player::stopMovingRight() {
    movingRight = false;
    if (!movingLeft) {
        speedX = 0;
    }
}

