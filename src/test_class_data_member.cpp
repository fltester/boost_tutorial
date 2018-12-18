#include<string>
#include<boost/python.hpp>

using namespace std;
using namespace boost::python;

struct Var{
    Var(string name):name(name), value(){}
    string const name;

    float value;
};

BOOST_PYTHON_MODULE(preprocessor)
{
    class_<Var>("var", init<string>())
        .def_readonly("name", &Var::name)
        .def_readwrite("value", &Var::value);
}