#include "camera.h"

Camera::Camera(QVector3D position,double FoV)
{
    this->FoV=FoV;
    this->position=position;
}
void Camera::move(double dx,double dy,double dz)
{
    this->position+=QVector3D(dx,dy,dz);
}
QVector3D Camera::getPosition()
{
    return this->position;
}

QMatrix4x4 Camera::getTransformationMatrix()
{
    double dist =this->position.length();
    double rotAboutY=-std::atan2(this->position.x(),this->position.z()),
            rotAboutX=std::atan2(this->position.y(),std::abs(this->position.z())),rotAboutZ=0;

    return transform::ScaleMatrix(1/dist/std::tan(3.1415/180*this->FoV/2))*transform::PerspectiveMatrix(dist)*transform::RotationMatrix(rotAboutY,rotAboutX,rotAboutZ);
}
void Camera::setFoV(double FoV)
{
    this->FoV=FoV;
}
double Camera::getFoV()
{
    return this->FoV;
}
double Camera::getDistance()
{
    return this->position.length();
}
void Camera::setDistance(double dist)
{
    this->position*=dist/position.length();
}
