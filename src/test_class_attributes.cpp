#include<string>
#include<boost/python.hpp>

using namespace std;
using namespace boost::python;

struct Num{
    Num(){}
    float get() const {return val;}
    void set(float val) {this->val = val;}
    float val;
};

BOOST_PYTHON_MODULE(preprocessor)
{
    class_<Num>("Num")
        .add_property("rovalue", &Num::get)
        .add_property("value", &Num::get, &Num::set);
}