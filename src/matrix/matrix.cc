// Pre-processor directives to prevent redundant library loading
#ifndef CW13_MATRIX_CPP_
#define CW13_MATRIX_CPP_

// include the header declarations
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "matrix.h"

//*************
//
// CONSTRUCTORS
//
//*************

// Default constructor
template<typename T> 
Matrix<T>::Matrix(unsigned int _rows, unsigned int _cols, const T& _initial) {
    // use vector method to resize outer vector of rows to length _rows
    mat.resize(_rows);
    for (unsigned int i=0; i<mat.size(); i++) {
        // for each row, resize to length _cols of columns
        // and initialize elements to value _initial
        mat[i].resize(_cols, _initial);
    }
    // set private fields rows and cols properly
    rows = _rows;
    cols = _cols;
}

// "Rule of 3" memory management:
// 1) Copy-constructor
template<typename T> Matrix<T>::Matrix(const Matrix<T>& rhs) {
    // Simply set private fields according to fields
    // of existing Matrix<T> object
    mat = rhs.mat;
    rows = rhs.get_rows();
    cols = rhs.get_cols();
}

// 2) Destructor
// No memory is dynamically allocated in the class,
// so just use default compiler cleanup of memory 
template<typename T> Matrix<T>::~Matrix() {}

// 3) Assignment operator
template<typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& rhs) {
    // If assigning to itself, just return itself
    if (&rhs == this)
        return *this;
  
    // Acquire new rows and cols
    unsigned int new_rows = rhs.get_rows();
    unsigned int new_cols = rhs.get_cols();
  
    // resize to new number of rows
    mat.resize(new_rows);
    // resize each row to new number of cols
    for (unsigned int i=0; i<mat.size(); i++) {
        mat[i].resize(new_cols);
    }
  
    // assign each element 
    for (unsigned int i=0; i<new_rows; i++) {
        for (unsigned int j=0; j<new_cols; j++) {
            mat[i][j] = rhs(i, j);
        }
    }
  
    // store new number of rows and columns
    rows = new_rows;
    cols = new_cols;
  
    // return newly modified object
    return *this;
}



//*************
//
// ACCESSORS
//
//*************


// Access individual elements (non-const: read + write)
template<typename T>
T& Matrix<T>::operator() (const unsigned int &row, const unsigned int &col) {
    return this->mat[row][col];
}

// Access individual elements (const: read only)
template<typename T>
const T& Matrix<T>::operator() (const unsigned int &row, const unsigned int &col) 
const {
    return this->mat[row][col];
}

// Get number of rows
template<typename T>
unsigned int Matrix<T>::get_rows() const {
    return this->rows;
}

// Get number of cols
template<typename T>
unsigned int Matrix<T>::get_cols() const {
    return this->cols;
}



//*********************
//
// OPERATOR OVERLOADING
//
//*********************


// Addition of two matrices
template<typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& rhs) {
    // Create new matrix to store result, initialize to zero
    Matrix result(rows, cols, 0.0);
  
    // Add each matrix element-by-element
    for (unsigned int i=0; i<rows; i++) {
        for (unsigned int j=0; j<cols; j++) {
            result(i,j) = this->mat[i][j] + rhs(i,j);
        }
    }
  
    return result;
}

//Matrix multiplication
template<typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>& rhs)
{
    if(this->cols != rhs.get_rows())
    {
        //can only multiply if cols of first equal to rows of second
        throw "Invalid matrix dimensions.";
    }    
    Matrix result(this->rows, rhs.get_cols(), 0.0);
    //keep track of sum of products for each new element of results
    T elemProdSum = 0;
    //i and j depend on dimensions of result matrix
    for (unsigned int i=0; i<result.get_rows(); i++) 
    {
        for (unsigned int j=0; j<result.get_cols(); j++) 
        {
            //k depends on cols of first = rows of second
            for (unsigned int k=0; k<(this->cols); k++)
            {
                //each row of first with each column of second
                elemProdSum += (this->mat[i][k])*rhs(k,j);
            }
            result(i,j) = elemProdSum;
            //reset sum
            elemProdSum = 0;
        }
    }
    return result;   
}
template<typename T>
Matrix<T> Matrix<T>::operator+(const T& scalar)
{
    Matrix result(this->rows, this->cols, 0.0);
    for (unsigned int i=0; i<this->rows; i++) 
    {
        for (unsigned int j=0; j<this->cols; j++) 
        {
            result(i,j) = this->mat[i][j] + scalar;
        }
    }
    return result;
}

//**********************
//
//  Additional Methods
//
//**********************


//Print method
template<typename T>
void Matrix<T>::print() const
{
    for (unsigned int i=0; i < rows; i++)
    {
        for (unsigned int j=0; j < cols; j++)
        {
            std::cout << this->mat[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

//Transpose method
template<typename T>
Matrix<T> Matrix<T>::transpose() const
{
    Matrix tMat(this->cols, this->rows, 0.0);
    for (unsigned int i=0; i<this->rows; i++) 
    {
        for (unsigned int j=0; j<this->cols; j++) 
        {
            tMat(j,i) = this->mat[i][j];
        }
    }

    return tMat;
}

//Save matrix to file
template<typename T>
void Matrix<T>::save(std::string filename) const
{
    std::ofstream output_file;

    output_file.open(filename.c_str());

    // check that file opened successfully
    if ( !output_file.is_open() )
    {
        std::cerr << "Error: Could not open file" << std::endl;
    }
    else
    {
        for (unsigned int i=0; i < this->rows; i++)
        {
            for (unsigned int j=0; j < this->cols; j++)
            {
                //if-else statement to prevent "," after last element of row
                if (j != (this->cols) - 1)
                    output_file << this->mat[i][j] << ",";
                //if-else also works to add newline
                else
                    output_file << this->mat[i][j] << "\n";
            }
        }
        output_file.close();
    }
}





#endif // CW13_MATRIX_CPP_
