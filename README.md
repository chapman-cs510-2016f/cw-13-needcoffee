# CS510 CW 13

**Author(s):** _Alexis Ford and Afnan Alqahtani_

[![Build Status](https://travis-ci.org/chapman-cs510-2016f/cw-13-needcoffee.svg?branch=master)](https://travis-ci.org/chapman-cs510-2016f/cw-13-needcoffee)

**Due date:** 2016/12/06

## Specification

**Note: Remember this is a C++ project.**

Complete the following exercises, saving your solutions in the indicated files. 

1. Recall the following references, which will still be useful throughout the rest of the course.
    * [C++ Tutorial](http://www.cplusplus.com/doc/tutorial/)
    * [C++ Essentials](https://tfetimes.com/wp-content/uploads/2015/09/CppEssentials.pdf)
    * [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html)
1. In this assignment, you will look briefly at the set of [Boost C++ Libraries](http://www.boost.org/users/history/version_1_62_0.html). In particular, you will use the [uBLAS (Basic Linear Algebra Library)](http://www.boost.org/doc/libs/1_62_0/libs/numeric/ublas/doc/index.html), which is a standard workhorse for numerical programming in C++. Skim through the documentation to get a feel for the large range of functionality that these libraries provide.
1. Examine the source code in ```src/blas``` carefully. 
    1. In a Jupyter notebook ```BLAS.ipynb```, explain the code in detail. How does this code compare in complexity to the code you wrote for Stack and Queue?
    1. Explain what the notation ```<type>``` means in, e.g., ```complex<long double>```.
    1. Are BLAS matrices row-major or column-major? How can you tell based on how the code is written?
    1. Write a new program that uses BLAS to create a complex plane in a similar way to your python code from before. Print the resulting matrix of complex numbers to the screen in a pretty way to demonstrate that your code works.
1. Examine the source code in ```src/matrix``` carefully. This code is a rudimentary implementation of what the BLAS matrix class may look like, using templates.
    1. In a Jupyter notebook ```Matrix.ipynb```, explain the code in detail.
    1. Explain what a template is in C++, and what it allows that is impossible in C.
    1. Explain what operator-overloading is, and which operators are overloaded here.
    1. Create a new method ```print()``` that prints the matrix to the screen. You may use the code in ```test_matrix.cc``` to get you started. Refactor ```test_matrix.cc``` to use your new method.
    1. Create a new method that multiplies two matrices together, by overloading the * operator. Test this method in ```test_matrix.cc```.
    1. Create a new method that adds a scalar value of type T to the matrix element-by-element, by overloading the + operator. Test this method in ```test_matrix.cc```.
    1. Create a new method ```save(string filename)``` that saves the matrix to a comma-separated-value (CSV) file, with one row per line.
    1. Use [valgrind](http://valgrind.org/docs/manual/quick-start.html) to verify that you have no memory leaks in your final working program. (You will have to edit the primary Makefile to change the CXXFLAGS to enable -g for debugging.)


## Assessment

Analyze in this section what you found useful about this assignment in your own words. Include any lingering questions or comments that you may have.

**CHANGEME**

## Honor Pledge

I pledge that all the work in this repository is my own with only the following exceptions:

* Content of starter files supplied by the instructor;
* Code borrowed from another source, documented with correct attribution in the code and summarized here.

Signed,

**Alexis Ford and Afnan Alqahtani**
