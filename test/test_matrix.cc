#include <iostream>
#include <string>
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
    mat3.print();

    Matrix<long double> mat4(2, 3, 1);
    mat4(0,1) = 2.0;
    mat4(0,2) = 3.0;
    mat4(1,0) = 4.0;
    mat4(1,1) = 5.0;
    mat4(1,2) = 6.0;
    std::cout << "Original matrix: " << std::endl;
    mat4.print();
    Matrix<long double> mat5(3, 2, 0);
    mat5 = mat4.transpose();
    std::cout << "Transposed matrix" << std::endl;
    mat5.print();
    std::cout << "Multiplying original and transposed matrices:" << std::endl;
    Matrix<long double> matProd = mat4*mat5;
    matProd.print();
    std::cout << "Adding -10.0 to every element of matrix product:" << std::endl;
    matProd = matProd + -10.0;
    matProd.print();

    std::cout << "Saving new matrix to file called 'matrix.txt'." << std::endl;
    matProd.save("matrix.txt");    
    return 0;
}
