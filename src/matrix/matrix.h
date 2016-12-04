#ifndef CW13_MATRIX_H_
#define CW13_MATRIX_H_

// Most useful standard library implementation of a vector
// Seasoned C++ programmers swear by this data structure
#include <vector>
#include <string>
#include <sstream>
#include <fstream>

// A template allows an arbitrary type T to be passed into a class as a
// parameter, so a single class definition can apply to different types 
template <typename T> class Matrix {
    private:
        // Implementation section
        //
        // A matrix is a vector of vectors, each storing type T
        std::vector<std::vector<T> > mat;
        // Also store the number of rows and columns 
        unsigned int rows;
        unsigned int cols;
  
    public:
        // Interface section
        //
        // Default constructor, make matrix entries all one value of type T
        Matrix(unsigned int _rows, unsigned int _cols, const T& _initial);
    
        // "Rule of 3" memory management:
        // 1) Copy-constructor
        Matrix(const Matrix<T> &rhs);
        // 2) Destructor ~ deallocates memory
        virtual ~Matrix();
        // 3) Assignment = operator 
        Matrix<T>& operator=(const Matrix<T>& rhs);
    
        // Addition + operator between matrices
        Matrix<T> operator+(const Matrix<T>& rhs);
    
        //Overload * for matrix multiplication
        Matrix<T> operator*(const Matrix<T>& rhs);

        //Overload + to add scalar element-wise
        Matrix<T> operator+(const T& scalar);

        // Selection operator (i,j) to access elements
        T& operator()(const unsigned int &row, const unsigned int &col);
        const T& operator()(const unsigned int &row, const unsigned int &col) const;
    
        // Accessor methods for row and column sizes
        unsigned int get_rows() const;
        unsigned int get_cols() const;

        //Print method
        void print() const;

        //Transpose method
        //Intended to use this for matrix multiplication,
        //but ended up not needing to. Decided to keep it
        //in because it's a common matrix operation anyway
        Matrix<T> transpose() const;

        //Saves matrix to CSV file, with one row per line.
        void save(std::string filename) const;
};


// C++ requires seeing both the source code and declarations simultaneously
// when dealing with templates (arbitrary types T)
// This requires the header to include the source, and vice versa, which is 
// one major reason for the #ifdef conventions to prevent infinite include loops
#include "matrix.cc"

#endif // CW13_MATRIX_H_ 
