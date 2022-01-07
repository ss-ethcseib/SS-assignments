#include <gtest/gtest.h>
#include "includes.h"
#include <math.h>

Triangle tri = Triangle(new Point(0.0f, 0.0f), new Point(1.0f, 2.0f), new Point(2.0f, 0.0f), 2.0f);

TwoDShape* shape = &tri;
float DistanceCalc(float x1, float x2, float y1, float y2){

  return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

TEST(Point_Tests, GetX_Y){
  
  float p1 = 3.f, p2 = 4.f;
  Point p(p1, p2);
  
  if(p.getX() == p1 && p.getY() == p2){
    SUCCEED(); 
  }
  else
    FAIL();  
}

TEST(Line_Tests, Distance_Test){   
  float x1 = 1.f, x2 = 1.f;
  float y1 = 2.f, y2 = 2.f;

  Line l(new Point(x1, y1), new Point(x2, y2));

  ASSERT_EQ(sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2)), l.Distance());
}

TEST(Line_Tests, EqualTo_Operator_Test){
  float x1 = 1.f, x2 = 1.f;
  float y1 = 2.f, y2 = 2.f;

  Line l1(new Point(x1, y1), new Point(x2, y2));
  Line l2(new Point(x1, y1), new Point(x2, y2));

  if(l1 == l2){
    SUCCEED();
    
  }
  else{
    FAIL();
    return;
  }

  Line l3(new Point(y2, y2), new Point(y1, y1));

  if(l3 == l1){
    FAIL();
    return;
  }
  else
    SUCCEED();
}

TEST(Multi_Line_Tests, Functor_Test){
  Multi_Line lines;
  lines(new Line(new Point(1.3f, 1.2f), new Point(1.2f, 1.2f)));
  Line l(new Point(1.3f, 1.2f), new Point(1.2f, 1.2f));

  if(l == *lines[0]){
    SUCCEED();
  }
  else
    FAIL();
}

TEST(Multi_Line_Tests, Square_Bracket_Overload_Test){
  Multi_Line lines;

  float x1 = 0, x2 = 2;
  float y1 = 1, y2 = 2;

  lines(new Line(new Point(x1, y1), new Point(x2, y2)));

  Line l(new Point(x1, y1), new Point(x2, y2));

  if(l == *lines[0])
    SUCCEED();
  else
    FAIL();
}

TEST(Triangle_Tests, Area_Test){
  ASSERT_EQ(0.5 * 2.0f * 2.0f, shape->Area());
}

TEST(Triangele_Tests, Perimeter_Test){
  float perimeter = DistanceCalc(0.0f, 1.0f, 0.0f, 2.0f) +
    DistanceCalc(1.0f, 2.0f, 2.0f, 0.0f) + DistanceCalc(2.0f, 0.0f, 0.0f, 0.0f);
  ASSERT_EQ(perimeter, shape->Perimeter());
}

TEST(Quadrilateral_Tests, Area_Test){
  
  Triangle** tr = new Triangle*[3];

  tr[0] = new Triangle(new Point(0.0f, 0.0f), new Point(1.0f, 1.5f), new Point(2.5f, 0.0f), 2.0f);

  tr[1] = new Triangle(new Point(0.0f, 0.0f), new Point(2.5f, -1.0f), new Point(2.5f, 0.0f), 2.0f);
  
  tr[2] = nullptr;
  
  Quadrilateral q(tr);
  shape = &q;

  if(tr[0]->Area() + tr[1]->Area() == shape->Area()){
    delete[] tr;
    SUCCEED();
  }
  else{
    delete[] tr;
    FAIL();
  }
}

TEST(Quadrilateral_Tests, Perimeter_Test){

  Triangle** tr = new Triangle*[3];
  
  tr[0] = new Triangle(new Point(0.0f, 0.0f), new Point(1.0f, 1.5f), new Point(2.5f, 0.0f), 2.0f);
  
  tr[1] = new Triangle(new Point(0.0f, 0.0f), new Point(2.5f, -1.0f), new Point(2.5f, 0.0f), 2.0f);
  
  tr[2] = nullptr;
  
  Quadrilateral q(tr);

  shape = &q;
  
  if(tr[0]->Perimeter() + tr[1]->Perimeter() - (2 * tr[0]->compareTrianglePoints(*tr[1]).Distance()) == shape->Perimeter()){
    delete[] tr;
    SUCCEED();
  }
  else{
    delete[] tr;
    FAIL();
  }
}

TEST(Trapezoid_Test, Area_Test){
  float base1 = 1.0f;
  float base2 = 2.0f;
  float side1 = 3.0f;
  float side2 = 1.0f;
  float height = 5.0f;
  
  Trapezoid trap(base1, base2, side1, side2, height);
  
  shape = &trap;
  
  ASSERT_EQ(0.5f * (base1 + base2) * height, shape->Area());
}

TEST(Trapezoid_Test, Perimeter_Test){

  float base1 = 1.0f;
  float base2 = 2.0f;
  float side1 = 3.0f;
  float side2 = 1.0f;
  float height = 5.0f;
  
  Trapezoid trap(base1, base2, side1, side2, height);
  
  shape = &trap;

  ASSERT_EQ(base1 + base2 + side1 + side2, shape->Perimeter());
}

TEST(Parallelogram_Tests, Area_Test){
  float b = 2.0f;
  float h = 2.0f;
  
  Parallelogram par(b, h);
  shape = &par;

  ASSERT_EQ(b * h, shape->Area());
}

TEST(Parallelogram_Tests, Perimeter_Test){
  float b = 1.f;
  float h = 2.f;

  Parallelogram par(b, h);
  shape = &par;
  
  ASSERT_EQ(2 * b + 2 * h, shape->Perimeter());
}

TEST(Rectangle_Tests, Area_Test){
  float l = 2.f;
  float w = 2.f;

  Rectangle rec(l, w);
  shape = &rec;

  ASSERT_EQ(l * w, shape->Area());
}

TEST(Rectangle_Tests, Perimeter_Test){

  float l = 2.f;
  float w = 2.f;

  Rectangle rec(l, w);
  shape = &rec;

  ASSERT_EQ(l * 2 + w * 2, shape->Perimeter());
}

TEST(Rhombus_Tests, Area_Test){

  float d1 = 2.f;
  float d2 = 2.f;
  float side = 8.f;
  
  Rhombus rh(d1, d2, side);
  shape = &rh;

  ASSERT_EQ(0.5 * d1 * d2, shape->Area());
}

TEST(Rhombus_Tests, Perimeter_Test){

  float d1 = 2.f;
  float d2 = 2.f;
  float side = 2.f;
  
  Rhombus rh(d1, d2, side);
  shape = &rh;

  ASSERT_EQ(4 * side, shape->Perimeter());
}

TEST(Square_Tests, Area_Test){
  float side = 4.f;

  Square sq(side);
  shape = &sq;

  ASSERT_EQ(side * side, shape->Area());
}

TEST(Square_Tests, Perimeter_Test){
  float side = 4.f;

  Square sq(side);
  shape = &sq;

  ASSERT_EQ(4 * side, shape->Perimeter());
}

TEST(Ellipse_Tests, Area_Test){

  float a = 2.f;
  float b = 2.f;
  
  Ellipse e(a, b);
  shape = &e;
  float area = 3.14159 * a * b;
  
  ASSERT_EQ(area, shape->Area());
}

TEST(Ellipse_Tests, Circumference_Test){
  float a = 2.f;
  float b = 2.f;

  Ellipse e(a, b);
  shape = &e;

  float cir = 3.14159 * (3 * (a + b) - sqrt((3 * a + b) * (a + 3 * b)));
  
  ASSERT_EQ(cir, shape->Circumference());
}

TEST(Ellipse_Tests, Diameter_Test){
  float a = 2.f;
  float b = 2.f;

  Ellipse e(a, b);
  shape = &e;

  ASSERT_EQ(2 * a, shape->Diameter());
}

TEST(Circle_Tests, Area_Test){
  float r = 4.f;

  Circle c(r);
  shape = &c;

  float area = 3.14159 * r * r;
  
  ASSERT_EQ(area, shape->Area());
}

TEST(Circle_Tests, Circumference_Test){
  float r = 3.f;

  Circle c(r);
  shape = &c;

  float area = 3.14159 * 2 * r;
  
  ASSERT_EQ(area, shape->Circumference());
}

TEST(Circle_Tests, Diameter_Test){
  float r = 2.f;

  Circle c(r);
  shape = &c;

  ASSERT_EQ(r * 2, shape->Diameter());
}

int main(int argc, char **argv){
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
