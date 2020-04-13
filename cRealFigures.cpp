#include "cRealFigures.h"
#include <cmath>

//============================================================
cRectangle::cRectangle( const std::string & title, double x, double y )
    : cFigure( "Rectangle: " + title )
    , x_( x )
    , y_( y )
{
    checkInputData( x_, "cRectangle: invalid argument = " + std::to_string( x_ ) );
    checkInputData( y_, "cRectangle: invalid argument = " + std::to_string( y_ ) );
}

//============================================================
cRectangle::~cRectangle()
{
}

//============================================================
double cRectangle::getPerimeter() const
{
    return x_ + y_;
}

//============================================================
double cRectangle::getArea() const
{
    return x_ * y_;
}

//============================================================
cCircle::cCircle( const std::string & title, double r )
    : cFigure( "Circle: " + title )
    , r_( r )
{
    checkInputData( r_, "cCircle: invalid argument = " + std::to_string( r_ ) );
}

//============================================================
cCircle::~cCircle()
{
}

//============================================================
double cCircle::getPerimeter() const
{
    return M_PI * 2 * r_;
}

//============================================================
double cCircle::getArea() const
{
    return M_PI * r_ * r_;
}


//============================================================
cTriangle::cTriangle( const std::string & title, double a, double b, double c )
    : cFigure( "Triangle: " + title )
    , a_( a )
    , b_( b )
    , c_( c )
{
    checkInputData( a_, "cTriangle: invalid argument = " + std::to_string( a_ ) );
    checkInputData( b_, "cTriangle: invalid argument = " + std::to_string( b_ ) );
    checkInputData( c_, "cTriangle: invalid argument = " + std::to_string( c_ ) );
}

//============================================================
cTriangle::~cTriangle()
{
}

//============================================================
double cTriangle::getPerimeter() const
{
    return a_ + b_ + c_;
}

//============================================================
double cTriangle::getArea() const
{
    const double perimeter = getPerimeter() / 2.0;
    return sqrt( perimeter * ( perimeter - a_ ) * ( perimeter - b_ ) * ( perimeter - c_ ) );
}
