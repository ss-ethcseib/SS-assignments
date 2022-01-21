#include <iostream>
#include <math.h>
#include <thread>
#include <fstream>
#include <queue>
#include <mutex>

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

  int index;
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
	
	bodies[i] = {i, initial_mass,
		     {static_cast<float>(rand() % 10 * change * -1),
		      static_cast<float>(rand() % 10 * change)},
		     {0.f, 0.f}, {0.0, 0.0}, {0.f, 0.f}};
	change *= -1;
      }
    };

  auto CalcForceExerted =
    [&bodies, G](int index, body& bod) mutable noexcept(true) -> void
    {
      
      //The two bodies being looked at exert the same amount of force on
      //each other due to their masses being equal. With this said some
      //optimization can be done to achieve O(nlogn) time complexity.

      body::Point vector;
      std::mutex m;

      for(int x = bod.index + 1; x < numBodies[index]; x++){

	  //calculate the numerator of the fraction
	std::lock_guard<std::mutex> lock(m);
	{
	  vector = (bodies[x].position - bod.position) * G * bodies[x].mass * bod.mass;
	  
	  //calculate the denominator of the fraction.
	  vector = vector /abs(
	     pow(
		 sqrt(
		      pow(bodies[x].position.x - bod.position.x, 2) +
		      pow(bodies[x].position.y - bod.position.y, 2))
		 , 3));
	  
	  bod.totalForce = bod.totalForce + vector;
	  bodies[x].totalForce = bodies[x].totalForce - vector;
	}
      }
    };


  //std::mutex m;
  auto UpdateBody =
    [&CalcForceExerted, &m, timestep](body&& bod) mutable noexcept(true) -> void {

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

      //  std::lock_guard<std::mutex> lock(m);      
      CalcForceExerted(2, bod);
      
      UpdateAcceleration(bod);
      UpdateVelocity(bod);
      UpdatePosition(bod);
      
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
    
  fillArr(2);
  
  float start = 0.0f;
  long double dur = timestep * 60 * 60 * 24 * 30;
  std::queue<std::thread> qt;

  //Where the threading begins  
  while(start < dur){
    
    for(int i = 0; i < numBodies[2]; i++)
      qt.push(std::thread(UpdateBody, std::move(bodies[i])));
    
    //i'm undecided if I should move this outside the while loop.
    for(int i = 0; i < numBodies[2]; i++){
      qt.front().join();
      qt.pop();
    }

    start += timestep * 60 * 60 * 24;
  }
  
  delete[] bodies;
  
  return 0;
}
