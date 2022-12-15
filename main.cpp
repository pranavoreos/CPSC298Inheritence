//
//  main.cpp
//  Inheritence
//
//  Created by Pranav Saravanan.
//

#include <iostream>

class Shape {
public:
  // Constructor
  Shape(double width, double height, std::string type)
      : m_width(width), m_height(height), m_type(type) {
    std::cout << "Shape constructed" << std::endl;
  }

  // Destructor
  ~Shape() {
    std::cout << "Shape destructed" << std::endl;
  }

  // Pure virtual function to scale the shape by a given factor
  virtual void scale(double factor) = 0;

  // Pure virtual function to compute the area of the shape
  virtual double area() = 0;

  // Pure virtual function to compute the perimeter of the shape
  virtual double perimeter() = 0;

  // Function to display the properties of the shape
  void displayProperties() {
    std::cout << "Type: " << m_type << ", Width: " << m_width << ", Height: " << m_height << std::endl;
  }

protected:
  double m_width;   // The width of the shape
  double m_height;  // The height of the shape
  std::string m_type; // The type of the shape
};

class Rectangle : public Shape {
public:
  // Constructor
  Rectangle(double width, double height) : Shape(width, height, "Rectangle") {}

  // Function to scale the rectangle by a given factor
  void scale(double factor) override {
    m_width *= factor;
    m_height *= factor;
  }

  // Function to compute the area of the rectangle
  double area() override {
    return m_width * m_height;
  }

  // Function to compute the perimeter of the rectangle
  double perimeter() override {
    return 2 * (m_width + m_height);
  }
};

class Circle : public Shape {
public:
  // Constructor
  Circle(double diameter) : Shape(diameter, diameter, "Circle") {}

  // Function to scale the circle by a given factor
  void scale(double factor) override {
    m_width *= factor;
    m_height *= factor;
  }

  // Function to compute the area of the circle
  double area() override {
    return 3.14159 * (m_width / 2) * (m_height / 2);
  }

  // Function to compute the perimeter of the circle
  double perimeter() override {
    return 2 * 3.14159 * (m_width / 2);
  }
};

int main() {
  // Create an array of pointers to Shape with two array elements
  Shape* p_shapes[2];

  // Create a Circle and a Rectangle shape
  Circle circle(2.0);
  Rectangle rectangle(3.0, 2.0);

  // Assign the first (zero'th) element to the pointer to the Circle shape
  // and the second element, index [1], to the pointer to the Rectangle shape
  p_shapes[0] = &circle;
  p_shapes[1] = &rectangle;

  // Iterate over the elements of the p_shapes array of pointers to shapes
  for (int i = 0; i < 2; i++) {
    Shape* p_shape = p_shapes[i];

    // Display the properties of the shape
    p_shape->displayProperties();

    // Compute the area of the shape and print it out
    std::cout << "Area: " << p_shape->area() << std::endl;

    // Compute the perimeter of the shape and print it out
    std::cout << "Perimeter: " << p_shape->perimeter() << std::endl;

    // Scale the shape by a factor of two
    p_shape->scale(2);

    // Display the properties of the shape (again)
    p_shape->displayProperties();

    // Compute the area of the shape and print it out (again)
    std::cout << "Area: " << p_shape->area() << std::endl;

    // Compute the perimeter of the shape and print it out (again)
    std::cout << "Perimeter: " << p_shape->perimeter() << std::endl;
  }

  // Deallocate the Shape objects
  //delete[] p_shapes;

  return 0;
}

