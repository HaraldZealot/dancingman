#include "dancingman.h"
#include <QPainter>

const double DancingMan::headLength = ;
const double DancingMan::bodyLength = 1.6180339887498948482;
const double DancingMan::handLength;
const double DancingMan::legLength = 1.0;

DancingMan::DancingMan()
{
}

void DancingMan::drawSelf(QPainter &painter)
{

}
double DancingMan::getHeadAngle() const
{
    return headAngle;
}

void DancingMan::setHeadAngle(double value)
{
    headAngle = value;
}

double DancingMan::getHeadAngle() const
{
    return headAngle;
}

void DancingMan::setHeadAngle(double value)
{
    headAngle = value;
}
double DancingMan::getBodyAngle() const
{
    return bodyAngle;
}

void DancingMan::setBodyAngle(double value)
{
    bodyAngle = value;
}
double DancingMan::getLeftHandAngle() const
{
    return leftHandAngle;
}

void DancingMan::setLeftHandAngle(double value)
{
    leftHandAngle = value;
}
double DancingMan::getRightHandAngle() const
{
    return rightHandAngle;
}

void DancingMan::setRightHandAngle(double value)
{
    rightHandAngle = value;
}
double DancingMan::getLeftLegTangent() const
{
    return leftLegTangent;
}

void DancingMan::setLeftLegTangent(double value)
{
    leftLegTangent = value;
}
double DancingMan::getRightLegTangent() const
{
    return rightLegTangent;
}

void DancingMan::setRightLegTangent(double value)
{
    rightLegTangent = value;
}






double DancingMan::getHeadLength()
{
    return headLength;
}

