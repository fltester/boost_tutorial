#include<string>
#include<iostream>
#include<boost/python.hpp>

using namespace std;
using namespace boost::python;

struct Base{
    virtual ~Base() {};
    virtual string getName() {return "Base";}

    string str;
};

struct Derived : Base{
    string getName() {return "Derived";}
};

void b(Base *base) {cout << base->getName()<< endl;};
void d(Derived *derived) {cout << derived->getName() << endl;};

Base *factory() {return new Derived;}

// namespace boose
// {
//     template <>
//     Base const volatile *get_pointer<class Base const volatile>(
//         class Base const volatile *c)
//         {
//             return c;
//         }
// }

BOOST_PYTHON_MODULE(preprocessor)
{
    class_<Base>("Base")
        .def("getName", &Base::getName)
        .def_readwrite("str", &Base::str);
    
    class_<Derived, bases<Base> > ("Derived")
        .def("getName", &Derived::getName)
        .def_readwrite("str", &Derived::str);
    
    def("b", b);
    def("d", d);

    def("factory", factory, return_value_policy<manage_new_object>());
}