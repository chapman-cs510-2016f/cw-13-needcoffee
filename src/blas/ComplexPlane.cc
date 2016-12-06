#include <boost/numeric/ublas/storage.hpp>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>


std::complex<long double> ;

ComplexPlane::ComplexPlane()
{

    // Implementation of default constructor
    // set up min/max/len
    : xmin(-10)
    , xmax(10)
    , xlen(20)
    , ymin(-10)
    , ymax(10)
    , ylen(20)

{};

    using namespace boost::numeric::ublas;
    slice real (xmin, xmax, xlen);
    slice imag (ymin, ymax, ylen);

    for (unsigned r = 0; r < real.size(); ++ r) {
        for (unsigned c = 0; c < imag.size(); ++ c){
            this-> plane(real,imag) = real(r)+imag(c)*1i;
        }
    }
}
