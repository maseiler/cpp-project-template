#include "MyLib/MyClass.hpp"

#include <boost/throw_exception.hpp>
#include <stdexcept>

MyLib::MyClass::MyClass() = default;

MyLib::MyClass::MyClass(int a) {
  if (a < 0) BOOST_THROW_EXCEPTION(std::out_of_range("Invalid initial value"));
  this->a = a;
}

int MyLib::MyClass::getA() const { return a; }

void MyLib::MyClass::setA(int newA) { this->a = newA; }
