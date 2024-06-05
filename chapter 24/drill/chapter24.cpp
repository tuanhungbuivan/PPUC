#include <functional>

#include "Matrix.h"
#include "MatrixO.h"

#include "std_lib_facilities.h"

using namespace Numeric_lib;

void fct()
{
    Matrix<int,3> a(10,20,30);
    cout<<a.size()<<'\n';
    cout<<a.dim1()<<'\n';
    cout<<a.dim2()<<'\n';
    cout<<a.dim3()<<'\n';
}

int main()
{
    fct();
    
    return 0;
}
