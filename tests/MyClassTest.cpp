#include <gtest/gtest.h>

#include "MyLib/MyClass.hpp"

TEST(MyClass, testDefaultValueA) {
  MyLib::MyClass instance;

  ASSERT_EQ(instance.getA(), 0);
}

TEST(MyClass, testSetValueA) {
  MyLib::MyClass instance;
  instance.setA(42);
  ASSERT_EQ(instance.getA(), 42);
}
