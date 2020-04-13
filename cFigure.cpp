#include "cFigure.h"
#include <exception>
#include <stdexcept>

//============================================================
cFigure::cFigure( const std::string & title )
    : title_( title )
{
}

//============================================================
cFigure::~cFigure()
{
}

//============================================================
std::string cFigure::getTitle() const
{
    return title_;
}

//============================================================
void cFigure::checkInputData( double val, const std::string & erroeMessage ) const
{
    if ( val <= 0 )
    {
        throw std::invalid_argument( erroeMessage );
    }
}
