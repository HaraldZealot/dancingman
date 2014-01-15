#ifndef DANCINGMAN_H
#define DANCINGMAN_H

class QPainter;

class DancingMan
{
public:
    DancingMan();
    void drawSelf(QPainter &painter) noexcept;


    double getHeadAngle() const noexcept {return headAngle;}
    void setHeadAngle(double value) noexcept {headAngle = value;}

    double getBodyAngle() const;
    void setBodyAngle(double value) noexcept {bodyAngle = value;}

    double getLeftHandAngle() const;
    void setLeftHandAngle(double value) noexcept {leftHandAngle = value;}

    double getRightHandAngle() const;
    void setRightHandAngle(double value) noexcept {rightHandAngle = value;}

    double getLeftLegTangent() const;
    void setLeftLegTangent(double value) noexcept {leftLegTangent = value;}

    double getRightLegTangent() const;
    void setRightLegTangent(double value) noexcept {leftLegTangent = value;}

private:
    double headAngle;
    double bodyAngle;
    double leftHandAngle;
    double rightHandAngle;
    double leftLegTangent;
    double rightLegTangent;

    static const double headLength;
    static const double bodyLength;
    static const double handLength;
    static const double legLength;
};

#endif // DANCINGMAN_H
