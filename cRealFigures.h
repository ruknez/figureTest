#pragma once
#include "cFigure.h"

//============================================================
class cRectangle final : public cFigure
{
public:
    cRectangle( const std::string & title, double x, double y );
    virtual ~cRectangle() override;

    virtual double getPerimeter() const override;
    virtual double getArea() const override;

private:
    double x_;
    double y_;
};

//============================================================
class cCircle final : public cFigure
{
public:
    cCircle( const std::string & title, double r );
    virtual ~cCircle() override;

    virtual double getPerimeter() const override;
    virtual double getArea() const override;

private:
    double r_;
};

//============================================================
class cTriangle final : public cFigure
{
public:
    cTriangle( const std::string & title, double a, double b, double c );
    virtual ~cTriangle() override;

    virtual double getPerimeter() const override;
    virtual double getArea() const override;

private:
    double a_;
    double b_;
    double c_;
};
