module;
module math; // lack of "export" marks this file as Module-Implementation-File

// Preamble
import print;

// Implementations
double add(double a, double b) {
  return a + b;
}

// Pointer constructor
Point::Point(double x, double y) : m_x(x), m_y(y) {
  std::cout << "Creating Point object and greeting John..." << std::endl;
  greet("John");
};