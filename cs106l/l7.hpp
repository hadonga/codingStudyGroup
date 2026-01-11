
// header file defines the interface for the StanfordID class
#include <iostream>
#include <string>

// the only difference between struct and class in C++ is the default access specifier.
// struct is a class where members are public by default.
// in a class, members are private by default.

// struct StanfordID {
//   std::string name;
//   std::string sunet;
//   int idNumber;
//   };

class StanfordID {
  private:
    std::string name_;
    std::string sunet_;
    int idNumber_;

  public:
    StanfordID(); //default constructor declaration
    StanfordID(std::string name, std::string sunet, int idNumber); //constructor declaration
    std::string getName();
    std::string getSunet();
    int getID();
  };

class Shape{
public:
  virtual double area() const = 0; // pure virtual function
};

class Circle : public Shape {
public:
  Circle(double radius) : radius_(radius) {};
  // 上述写法 member initializer list更加高效，推荐使用。 
  // Circle(double radius){
  //   radius_ = radius;
  // }

  double area() const {
    return 3.14159 * radius_ * radius_;
  }
private:
  double radius_;
};

class Rectangle : public Shape {
public:
  Rectangle(double witdh, double height){
    this->_width = witdh;
    this->_height = height;
  }
  double area() const{
    return _width * _height;
  }
private:
  double _width;
  double _height;
};

// 菱形继承示例：没有虚拟继承时，Final继承两个Base，导致value重复。
// 使用virtual继承，Base只被继承一次。

class Base {
public:
    int value;
    Base(int v) : value(v) {}
};

class Derived1 : virtual public Base {
public:
    Derived1(int v) : Base(v) {}
};

class Derived2 : virtual public Base {
public:
    Derived2(int v) : Base(v) {}
};

class Final : public Derived1, public Derived2 {
public:
    Final(int v) : Base(v), Derived1(v), Derived2(v) {}  // Base只初始化一次
    void show() {
        std::cout << "Value: " << value << std::endl;
    }
};


