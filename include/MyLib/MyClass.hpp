#ifndef CPP_TEMPLATE_INCLUDE_MYLIB_MYCLASS_HPP_
#define CPP_TEMPLATE_INCLUDE_MYLIB_MYCLASS_HPP_

namespace MyLib {

class MyClass {
 public:
  MyClass();
  explicit MyClass(int a);
  [[nodiscard]] int getA() const;
  void setA(int newA);

 private:
  int a = 0;
};

}  // namespace MyLib
#endif  // CPP_TEMPLATE_INCLUDE_MYLIB_MYCLASS_HPP_
