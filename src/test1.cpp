#include<string>
#include<boost/python.hpp>

using namespace std;
using namespace boost::python;

// import function

char const * greet(){
    return "hello, world";
}

BOOST_PYTHON_MODULE(preprocessor)
{
    def("great", greet);
}