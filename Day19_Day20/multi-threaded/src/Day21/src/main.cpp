#include <iostream>
#include <math.h>
#include <thread>
#include <json/writer.h>
#include <fstream>
#include <queue>

typedef struct body body;
struct body{

  struct Point{
    long double x, y;

    struct Point& operator=(const struct Point& p){

      if(this == &p)
	return *this;
      
      this->x = p.x;
      this->y = p.y;

      return *this;
    }

    template<class T>
    struct Point& operator*(const T& val){
      if(std::is_arithmetic<T>::value){
	this->x *= val;
	this->y *= val;
      }
      return *this;
    }

    template<class T>
    struct Point& operator/(const T& val){
      if(std::is_arithmetic<T>::value){
        this->x /= val;
        this->y /= val;
      }                                                                      
      return *this;                                                          
    }

    struct Point& operator+(const struct Point& p){
      this->x += p.x;
      this->y += p.y;

      return *this;
    }

    struct Point& operator-(const struct Point& p){
      this->x -= p.x;
      this->y -= p.y;

      return *this;
    }

    long double norm(){
      return this->x + this->y;
    }

    long double magnitude(){
      return sqrt(pow(this->x, 2) + pow(this->y, 2));
    }
  };
  
  float mass;
  struct Point position;
  struct Point velocity;
  struct Point totalForce; // computed
  struct Point acceleration;  // computed from f = ma
};

int main(){

  /* Number of N bodies */
  constexpr int numBodies[] = {2, 10, 20, 50, 100, 200, 500, 1000, 2000};
  /* Gravitational constant */
  constexpr double G = 6.673e-11;

  /* timestep */
  constexpr double timestep = 1;//0.001;  // experiment with this!

  /* small mass */
  constexpr double initial_mass = 100.0; // experiment with this!

  /* num timesteps */
  constexpr double k = 1; // you can experiment with this! it can be fairly large.
  body* bodies = nullptr;
  auto fillArr =
    [&bodies](int index) mutable noexcept(false) -> void
    {
      int change = 1;
      bodies = new body[numBodies[index]];
      
      for(int i = 0; i < numBodies[index]; i++){
	
	bodies[i] = {initial_mass,
		     {static_cast<float>(rand() % 10 * change * -1),
		      static_cast<float>(rand() % 10 * change)},
		     {0.f, 0.f}, {0.0, 0.0}, {0.f, 0.f}};
	change *= -1;
      }
    };

  auto CalcForceExerted =
    [&bodies, G](int index) mutable noexcept(true) -> void
    {
      
      //The two bodies being looked at exert the same amount of force on
      //each other due to their masses being equal. With this said some
      //optimization can be done to achieve O(nlogn) time complexity.

      body::Point vector;
      for(int y = 0; y < numBodies[index] - 1; y++){
	for(int x = y + 1; x < numBodies[index]; x++){

	  //calculate the numerator of the fraction
	  vector = (bodies[x].position - bodies[y].position) * G * bodies[x].mass * bodies[y].mass;

	  //calculate the denominator of the fraction.
	  vector = vector /abs(
	    pow(
	      sqrt(
		   pow(bodies[y].position.x - bodies[x].position.x, 2) +
		   pow(bodies[y].position.y - bodies[x].position.y, 2))
	      , 3));
	  
	  bodies[y].totalForce = bodies[y].totalForce + vector;
	  bodies[x].totalForce = bodies[x].totalForce - vector;
	}
      }
    };


  auto UpdateBodies =
    [&bodies, timestep](int index) mutable noexcept(true) -> void {

      auto UpdateAcceleration =
	[](body& bod) mutable noexcept(true) -> void {
	  bod.acceleration = bod.totalForce / bod.mass;
	};
      
      auto UpdateVelocity =
	[timestep](body& bod) mutable noexcept(true) -> void {
	  bod.velocity = bod.velocity + bod.acceleration * timestep;
	};

      auto UpdatePosition =
	[timestep](body& bod) mutable noexcept(true) -> void {
	  bod.position = bod.position + bod.velocity * timestep;
	};
	
      for(int i = 0; i < numBodies[index]; i++){
	UpdateAcceleration(bodies[i]);
	UpdateVelocity(bodies[i]);
	UpdatePosition(bodies[i]);
      }
    };

  auto ComputeDistance =
    [](const body& bod1, const body& bod2) noexcept(true) -> float {
      return sqrt(pow(bod1.position.x - bod2.position.x, 2) + pow(bod1.position.y - bod2.position.y, 2));
    };

  auto TotalForceSummation =
    [&bodies](int index) noexcept(true) -> float{

      float ret = 0.f;
      for(int i = 0; i < numBodies[index]; i++)
	ret += bodies[i].totalForce.norm();
      return ret;
    };

  auto InteractionsPerSec =
    [](int count, float D) noexcept(true) -> float {
      return k * count * count / D;
    };

  auto threadFunc =
    [=](float& ret) mutable noexcept(false) -> void {

      fillArr(2);
      
      float start = 0.0f;
      long double dur = timestep * 60 * 60 * 24 * 30;
      
      while(start < dur){
	CalcForceExerted(2);
	UpdateBodies(2);
	
	start += timestep * 60 * 60 * 24;
	ret += InteractionsPerSec(numBodies[2], dur);
      }
      
      delete[] bodies;
    };
  std::queue<std::thread> ts;
  std::queue<float*> rets;
  float* ret;
  Json::Value event;
  
  for(int x = 0; x < 8; x++){
    for(int y = 0; y <= x; y++){
      ret = new float;
      *ret = 0.f;
      
      ts.push(std::thread(threadFunc, std::ref(*ret)));
      rets.push(ret);
    }

    float aggregate = 0.f;
    for(int y = 0; y <= x; y++){
      ts.front().join();
      ts.pop();
      
      aggregate += *rets.front();
      delete rets.front();
      rets.pop();
    }
    event[x]["interactions per second"] = aggregate;
    event[x]["thread count"] = x + 1;
  }
  
  std::ofstream out("json", std::ios::out);
 
  std::cout << event << std::endl;
  out << event <<std::endl;

  out.close();
  return 0;
}
