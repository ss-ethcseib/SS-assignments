#include <gtest/gtest.h>
#include "includes.h"
#include <math.h>

TwoDShape* shape = new Triangle(new Point(0.0f, 0.0f), new Point(1.0f, 2.0f), new Point(2.0f, 0.0f), 2.0f);
float DistanceCalc(float x1, float x2, float y1, float y2){

  return sqrt(pow(x1 + x2, 2) - pow(y1 + y2, 2));
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
  //delete shape;
  
  Triangle** tr = new Triangle*[3];

  tr[0] = new Triangle(new Point(0.0f, 0.0f), new Point(1.0f, 1.5f), new Point(2.5f, 0.0f), 2.0f);

  tr[1] = new Triangle(new Point(0.0f, 0.0f), new Point(2.5f, -1.0f), new Point(2.5f, 0.0f), 2.0f);
  
  tr[2] = nullptr;
  //shape = new Quadrilateral(tr, );
  
  //ASSERT_EQ(0.5f * 2.5f * (2.0f + 2.5f), quad.Area());
  delete[] tr;
}

TEST(Quadrilateral_Tests, Perimeter_Test){

  ASSERT_EQ(2.0f * 2 + 2.5f * 2, shape->Perimeter());
}

TEST(Trapezoid_Test, Area_Test){
  //delete shape;
  //shape = new Trapezoid();
  
  //ASSERT_EQ();
}

int main(int argc, char **argv){
  ::testing::InitGoogleTest(&argc, argv);
  delete shape;
  return RUN_ALL_TESTS();
}
