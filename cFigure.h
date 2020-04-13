#pragma once
#include <memory>
#include <string>


class cFigure
{
public:
    cFigure( const std::string & title );

    virtual ~cFigure();
    virtual std::string getTitle() const;

    virtual double getPerimeter() const = 0;
    virtual double getArea() const = 0;

protected:
    void checkInputData( double val, const std::string & erroeMessage ) const;

private:
    std::string title_;
};

using cFigurePtr = std::shared_ptr< cFigure >;
