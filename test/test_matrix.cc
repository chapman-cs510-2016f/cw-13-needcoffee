#include <iostream>
#include "../src/matrix/matrix.h"

int main() {
    // Define two 10x10 matrices with element types of long double
    // The first has all elements set to 1.0
    Matrix<long double> mat1(10, 10, 1.0);
    // The second has all elements set to 2.0
    Matrix<long double> mat2(10, 10, 2.0);
  
    // Set a few elements differently as a test of accessors
    mat1(3,4) = 10.0;
    mat2(1,2) = -15.0;
  
    // Define a third matrix as the sum of the first two
    Matrix<long double> mat3 = mat1 + mat2;
  
    // Print out the third matrix as a text array
    for (int i=0; i<mat3.get_rows(); i++) {
        for (int j=0; j<mat3.get_cols(); j++) {
            std::cout << mat3(i,j) << "\t";
        }
        std::cout << std::endl;
    }
  
    return 0;
}
