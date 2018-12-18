#include<string>
#include<boost/python.hpp>

using namespace std;
using namespace boost::python;

//import class

struct World{
    void set(string msg){
        this->msg = msg;
    }
    string greet(){return msg;}
    string msg;
};

BOOST_PYTHON_MODULE(preprocessor)
{
    class_<World>("world")
        .def("greet", &World::greet)
        .def("set", &World::set);
}