# Advanced Programming in C++
## Generalities
* C++ allows use of different Programming paradigms:
  * Procedural programming
  * Object-based programming (templates, static polymorphism)
  * Object-oriented programming (inheritance, dynamic polymorphism)
* Features of special interest
  * strong vs weak typing
  * static vs dynamic typing
  * templates
  * Standard Library (STL)
  * Exception Handling

## Lecture 1
### Classes
* Encapsulation
* Abstract data types
* User defined types

_"Decide which Types you want; provide a full set of operations for each type"_ - Bjarne Stroustrup

* OO can be simulated in C, by e.g. passing the struct or record to the function call as the first argument
* C++ can use default parameters in instantiations
` fraction(int cntr = 0, int denom = 1); `
* defintion of members outside class def.: `classname::`
* just using member functions adds no overhead

#### Constructor & Destructor
* executed after memory allocation for object
* ':' section initializes members by skipping default construction
* since C++11 other constructors from the same class
* executed before memory get's deallocated
* allows you to free additional resources (later)
```cpp
class C { //a C11 class with a target constructor
  int s;
  T t;  //has a conversion operator to double
 
 public:
  //the target constructor
  C(int i, T& t1): s(i), t(t1) {/*more common init code*/}
 
  //three delegating ctors that call the target ctor
  C(): C(12, 4.5) {/*specific post-init code*/}
  C(int i): C(i, 4.5) {/*specific post-init code*/}
  C(T& t1): C(12, t1) {/*specific post-init code*/}
  //destructor
  ~C(void) {//some code}
}; 
```
#### Access Control
* `public:` may be used by anybody
* `private:` may only be used by the class
* `protected:` may be used by class and subclass
* `friend ...` allow artifact acces to internals of class (compared to package in Java)
```cpp
class fraction {
  friend int read(fraction &f);
  ...
};
//or close relationship classes
class matric {
  friend class vector
  ...
};
```
* members of `struct` public by default
* members of `class` private by default
#### User-defined Operators
* basically all operators may be overloaded
* must adhere to mathematical properties though
* Reflexivity `foo==foo`
* Symmetry `foo==bar <=> bar==foo`
* Transitivity `foo==bar & bar==foobar ==> foo==foobar`
* Associativity and Commutativity
* `foo+=bar <=> foo=foo+bar` & `foo!=bar <=> !(foo==bar)`

#### Default Artifacts (classes)
* created by compiler if not defined
* Default constructor `T(void)`
* Copy constructor `T(const T&)`
* Assigment operator `operator=(T)`
* Destructor does nothing
##### Disable Default Artifacts
* for access of other classes, hide the def. constructor
* if it shouldn't be created at all:
  * since C++11 mark with `= delete`
  * prior: declare but don't implement
**Rule of Three**
* if either implemented (copy con. assignment. op or destructor), implement all 3 (even if not needed, just use same code the compiler would have created)

#### User-defined Conversion Operations
* allows users to define implicit conversion functions
* Stylewyse one should use `static_cast<T>(x)` instead of `(T) x`
* operator can be declared e.g. in class as 
```cpp
operator double() { return (double a/b) //return something}
```

#### Sidebar: inline
* replaces function call with function's body
* goes into the header
* useful for smaller functions
* only a hint for the compiler, may decide against it
