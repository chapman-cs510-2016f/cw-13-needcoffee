#include <boost/numeric/ublas/io.hpp>
#include <boost/numeric/ublas/matrix.hpp>



using namespace boost::numeric::ublas;

class ComplexPlane
{

template<typename T>
complix<T>::complix(unsigned int _rows, unsigned int _cols, const T& _initial) {

    long double xmin;
    long double xmax;
    int xlen;
    long double ymin;
    long double ymax;
    int ylen;

    matrix<std::complex<long double> > plane;


    void refresh();
    void zoom();
    void set_f();
    void print();
};