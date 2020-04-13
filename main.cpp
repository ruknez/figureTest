#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

#include "cFigure.h"
#include "cRealFigures.h"

//============================================================
cFigurePtr createFigure( std::istream & inputStream )
{
    std::string type;
    std::string figureTitle;

    inputStream >> type;
    inputStream >> figureTitle;

    if ( type == "RECT" )
    {
        int width, height;
        inputStream >> width >> height;
        return std::make_shared< cRectangle >( figureTitle, width, height );
    }
    else if ( type == "TRIANGLE" )
    {
        int side_one, side_two, side_three;
        inputStream >> side_one >> side_two >> side_three;
        return std::make_shared< cTriangle >( figureTitle, side_one, side_two, side_three );
    }
    else if ( type == "CIRCLE" )
    {
        int radius;
        inputStream >> radius;
        return std::make_shared< cCircle >( figureTitle, radius );
    }
    throw std::logic_error( "I cannot parsing input data \"" + type + "\"\n" );
}

//============================================================
std::vector< cFigurePtr > createFigureVec( const std::string & dataFileName )
{
    std::vector< cFigurePtr > tmpFigureVec;

    std::ifstream inputData( dataFileName, std::ifstream::in );
    if ( !inputData.is_open() )
    {
        throw std::logic_error( "I cannot open file \"" + dataFileName + "\" \n" );
    }

    for ( std::string line; getline( inputData, line ); )
    {
        try
        {
            std::istringstream stringStreamInput( line );
            tmpFigureVec.push_back( createFigure( stringStreamInput ) );
        }
        catch ( const std::invalid_argument & ex )
        {
            std::cerr << ex.what() << std::endl;
        }
    }

    return tmpFigureVec;
}

//============================================================
int main( int argc, char ** argv )
{
    std::string fileName = "fileWithData";
    if ( argc == 2 )
    {
        fileName = argv[ 2 ];
    }

    try
    {
        auto figureVec = createFigureVec( fileName );
        for ( const auto & figure : figureVec )
        {
            if ( figure )
                std::cout << figure->getTitle() << std::endl;
        }
    }
    catch ( const std::logic_error & ex )
    {
        std::cerr << ex.what() << std::endl;
    }
    catch ( ... )
    {
        std::cerr << "SMT wrong (((" << std::endl;
    }


    return 0;
}
