#include <cassert>
#include <type_traits>

//Copy assignable because the copy
//assignment operator can be
//implicitly defined
struct A{};

//Copy assignable because the copy
//assignment operator is user defined.
struct B{ B& operator=(const B& b){ return *this; } };

//copy assignment operator is deleted
//so it is not copy assignable.
struct C{ C& operator=(C&) = delete; };

//copy constructor is deleted but the
//copy assignment operator can still
//be implicitly defined. Making this
//copy assignable.
struct D{ D(D&) = delete; };

//Copy assignment operator not implicitly created
//because a move constructor makes the compiler
//implicitly create a move assignment operator.
//Thus, this is not copy assignable.
struct E{ E(E&& e){} };

//Copy assignment operator not implicitly created
//due to the move assignment operator. Making this
//not copy assignable.
struct F{ F& operator=(F&& f){return *this;}};

//Copy assignment operator not implicitly created
//due to the const int j. Thus, this struct is not
//copy assignable.
struct G{ const int j; };

//Not copy assignable because copy assignment operator
//not implicitly created due to the int& j
struct H{ int& j; };

//Not copy assignable because H is not copy assignable.
struct I: public H{ };

//Not copy assignable because of the anonymous union.
struct J{ union{ int i; struct B b; }; };
  
int main(){

  assert(std::is_copy_assignable<A>::value);
  assert(std::is_copy_assignable<B>::value);
  assert(!std::is_copy_assignable<C>::value);
  assert(std::is_copy_assignable<D>::value);
  assert(!std::is_copy_assignable<E>::value);
  assert(!std::is_copy_assignable<F>::value);
  assert(!std::is_copy_assignable<G>::value);
  assert(!std::is_copy_assignable<H>::value);
  assert(!std::is_copy_assignable<I>::value);
  assert(!std::is_copy_assignable<J>::value);
  
  return 0;
}
