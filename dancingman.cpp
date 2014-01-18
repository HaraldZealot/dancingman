#include "dancingman.h"
#include <QPainter>
#include <cmath>

const double DancingMan::headLength = 0.3819660112501051518;
const double DancingMan::bodyLength = 1.0;
const double DancingMan::handLength = 0.6180339887498948482;
const double DancingMan::legLength = 1.6180339887498948482;

DancingMan::DancingMan():
    headAngle(0.0),
    bodyAngle(0.0),
    leftHandAngle(1.0),
    rightHandAngle(1.0),
    leftLegTangent(0.5),
    rightLegTangent(0.5)
{
}

void DancingMan::drawSelf(QPainter &painter) noexcept
{
    double scale = 64.0; //pixel
    double headAngleLimit = 15.0; //degree
    double bodyAngleLimit = 30.0; //degree
    double handAngleLimit = 80.0; //degree
    double handAngleOrigin = 95.0; //degree from body

    painter.save();
    painter.setPen(QPen(QBrush(Qt::green), 5.0));
    double x, y;

    // left leg
    y = scale * legLength / sqrt(leftLegTangent * leftLegTangent + 1.0);
    x = leftLegTangent * y;
    painter.drawLine(QPointF(0.0, 0.0), QPointF(-x, -y));

    // right leg
    y = scale * legLength / sqrt(rightLegTangent * rightLegTangent + 1.0);
    x = rightLegTangent * y;
    painter.drawLine(QPointF(0.0, 0.0), QPointF(x, -y));

    // body
    QPointF neck(0.0, scale * bodyLength);
    QTransform bodyRotattion;
    bodyRotattion.rotate(bodyAngleLimit * bodyAngle);
    neck = bodyRotattion.map(neck);
    painter.drawLine(QPointF(0.0, 0.0), neck);

    // head
    QPointF head(0.0, scale * headLength);
    QTransform headRotation;
    headRotation.rotate(-headAngleLimit * headAngle);
    head = (headRotation * bodyRotattion).map(head);
    painter.drawLine(neck, neck + head);

    // left hand
    QPointF leftFinger(scale * handLength * sin(M_PI * handAngleOrigin / 180.0), -scale * handLength * cos(M_PI * handAngleOrigin / 180.0));
    QTransform leftHandRotation;
    leftHandRotation.rotate(-handAngleLimit * leftHandAngle);
    leftFinger = (leftHandRotation * bodyRotattion).map(leftFinger);
    painter.drawLine(neck, neck + leftFinger);

    // right hand
    QPointF rightFinger(-scale * handLength * sin(M_PI * handAngleOrigin / 180.0), -scale * handLength * cos(M_PI * handAngleOrigin / 180.0));
    QTransform rightHandRotation;
    rightHandRotation.rotate(handAngleLimit * rightHandAngle);
    rightFinger = (rightHandRotation * bodyRotattion).map(rightFinger);
    painter.drawLine(neck, neck + rightFinger);


    painter.restore();
}


