module;
module math; // lack of "export" marks this file as Module-Implementation-File

// Implementations
double add(double a, double b) {
  return a + b;
}

// Pointer constructor
Point::Point(double x, double y)
    : m_x(x), m_y(y){};