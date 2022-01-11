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
```cpp
fraction(int cntr = 0, int denom = 1);
```
* defintion of members outside class def.: `classname::`
* just using member functions adds no overhead

#### Sidebar: inline
* replaces function call with function's body
* goes into the header
* useful for smaller functions
* only a hint for the compiler, may decide against it
* Compiler can only inline function if its implementation is visible, which is why inline func. go into header

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

#### C/C++ const (vs. Java final)
* C/C++ const specifies that given variable/object the pointing variable is **constant**
* in Java final only specifies that value cannot be changed
* C/C++ distinguished wheter **pointer** is const or the **structure** pointed to
```cpp
int size() const; // promises not to change variables from inside out
const int vector<string> v2; // object cannot be modified
const int vector<string> *vp = &v2; // pointer is not constant, only the object type pointed to
vector<string> *const vq = &v2; // pointer is a constant, object it's pointing to isn't
```

#### Namespaces
* Modular Programming, avoid name collisions and for user defines data-types
```cpp
namespace { ... } // may be anonymous
/* anonymous or unnamed namespaces can be used to make variables
 * and functions usable in the same file, avoiding collisions and
 * making them global static
 */
namespace utils {
  namespace fractions { ... }
} // nested namespaces
namespace utils::fractions { ... } // C++17 supports nested ns w/ ::
using NAMESPACE::VAR; // to import single statements
using namespace NAMESPACE; // to import whole namespace
```
* operators can be defined in multiple ways and scopes
```cpp
fraction fraction::operator+(complex b); // member function
fraction operator+(fraction a, complex b); // stand-alone
```
* which one will be used by the compiler?
  * use member operator, if multiple member operators, use overloading rules
  * is there operator+(a,b,) defined in their namespaces of classes of objects a and b? if yes, use it, if multiple use standard overloading rules

### Standard Library - Basics
#### Input and Output
```cpp
cout // standard output
operator<< // write output to a stream
cin // standard input
operator>> // read input from a stream
fstream // file stream
sstream // string stream
```
* Stream states
  * good: all is fine
  * fail: last operation failed
  * bad: characters may have been lost
  * eof: reached end-of-file
* operator>> by default skips whitespaces, use istream::get() to read each character
#### Container
* different data structures
* abstraction of a memory area
* user-defined allocator
* can be accessed using iterators

* Sequence Containers
  * `vector<T>, list<T>, forward_list<T>, deque<T>`
* Asscociative Containers
  * `map<K,V>, multimap<K,V>` using trees
  * `set<K>, multiset<K>` using trees
  * `unordered_map<K,V>, unordered_multimap<K,V>` using hash
  * `unordered_set<K>, unordered_multiset<K>` using hash
* Sequence Container Adapters
  * `stack<T,C>`
  * `queue<T,C>, priority_queue<T,C>`

##### Complexity Guarantees

![Complexity Guarantees](./images/compguar.jpg)

##### Iterators
```cpp
vector<string>::iterator fst = playlist.begin();
// since C++11 also:
auto fst = being();
```
![Iterator Types](./images/itertypes.jpg)

## Lecture 2
### Templates
Types of polymorphism
* "Ad-hoc"
  * overloading
  * statically resolved by compiler
* Dynamic
  * using `virtual` member functions
  * Method to be invoked identified durin run-time (suing virtual method table)
* Static or Parametric
  * using templates
  * Function to be invoked can be identified statically
  * Concrete Functions/Classes are generated for the individual parameter types
Declaration and Definition
```cpp
template<typename /* or class */ T>
T min(T a, T b) {
  return a < b ? a : b;
}
void f() { // specifying type of parameter
  min<double>(2.718282, 1.0);
  min<char>('a', 'z');
  min<int>(1, 26);
  min<double>(pi, 2.718282);
  min<int>('a', 26);
  min<double>(2.718282, 1);
}
void f2() { // deduction: type of parameter
  min(2.718282, 1.0);
  min('a', 'z');
  min(1, 26);
  min(pi, 2.718282);
  // min('a', 26); ambiguous
  // min(2.718282, 1); ambiguous
}
// resolving ambiguities
// explicit and necessary
min<int>('a', 26);
// or even if unnecessary
min<const double>(pi, 2.718282);
```
* types used with this template have to provide the routines used by the template -> in this case comparison operator and copy constructor
* checked and resolved statically (during compile-time)
* definition must be available to compiler
* when invoking templates the parameter of the type can be specified, but the compiler is also able to deduce unambiguous cases
* Templates and non-templates can be mixen (with care)
* e.g. min function template and non-template based -> non-template will be preferred if no type conversion is needed

#### Templates: Specialization

* e.g. for C-style strings

```cpp
template<typename T>
T min(T a, T b) {
  return a<b ? a : b;
}

template<>
char *min<char *>(char *a, char *b) {
  return strcmp(a, b)<0 ? a : b; 
}

template<>
const char *min<const char *>(const char *a, const char *b) {
  return strcmp(a, b)<0 ? a : b;
}
-------------------------------------------------------------
#include "min.h"
void foo(char *x, char *y, const char *z) {
cout << min(x, y) << endl;  // yes
cout << min(x, z) << endl;  // compiler error; there is no implicit parameter
                            // conversions for templates.
cout << min<const char*>(x, z) << endl; // yes
```
* before C++17 no template parameter deduction for constructors
```cpp
pair<int, bool>(1, false);
// helper function s.a.
make_pair(1, false);
// since C++17
pair(1, false);
```

### Separate Compilation

Why?
* one source file is unrealistic
* break up code into logical structure
* reduction of compile time (only changed parts recompiled)

How?
* multiple source files
* compiler needs to know about
  * Functions and variables provided by other compilation units
  * their signatures and types

In C++
* each source file into an object .o
* object files provide 'minimum' to execute code
* not enough info for the compiler to identify
  * functions provided by other compilation unit
  * Layout of user-defined type
* uses header files to store interfaces

#### Header Files
* another encapsulation mechanism
  * describe interface provided by object files
  * and what should be exported to other compilation units

##### What goes into header files?
* "everything" to be exported and or used in other files
  * **Variables**:
    * Declaration into header, **mark as `extern`**
    * Defintion into implementation file
  * **Constant Variables**
    * Declaration into header, if needed to be used elsewhere
    * Definition either into header (may be allocated multiple times, beware!) or into implementation file

```cpp
// vars.h
#ifndef VARS_H_
#define VARS_H_

extern int my_dumb_global_variable; // no memory allocated
const double pi = 3.141596;
extern const int[] primes;

#endif

// vars.cc
#include "vars.h"

int my_dumb_global_variable=17;
const int primes[]={2, 3, 5, ..., 1234567891};
```

  * **Functions**
    * Decleration into header, definition into impl. file
  * **Inline Functions**
    * If to be inlined in impl. file only, treat like functions
    * If to be inlined globally (typically), decl. and def. into header
    * compiler has to know the impl. to be used instead of func. call

```cpp
// util.h
#ifndef UTIL_H_
#define UTIL_H_

inline void swap(int &a, int &b) { // inline functions decl. in the header
  int c=a; a=b; b=c;
}
extern int gcf(int a, int b); // extern decl. for functions is optional.
inline int lcm(int a, int b) {
  return (a/gcf(a,b))*b;
}
#endif

// util.cc
#include "util.h"

int gcf(int a, int b) {
  if (a<b) swap(a,b);
  while (b!=0) {
    a=a-b;
    if (a<b) swap(a,b);
  }
  return a;
}
```

  * **Types**
    * Type declaration and definitions into header, layout needs to be known
    * for member functions same rules as for functions

```cpp
// fraction.h
class fraction {
  int c; int d;
 public:
  fraction(int cntr=0, int denom=1) : c(cntr), d(denom) { /*void*/ }
  fraction operator*(const fraction &b);
  fraction operator/(fraction b) { // small implicit inline function
    swap(b.c, b.d);
    return (*this)*b;
  }
};

// fraction.cc
#include "fraction.h"
#include "util.h"
fraction::fraction operator*(const fraction &b) {
  fraction r;
  int f1=gcf(this->c,b.d), f2=gcf(b.c,this->d);
  r.c=(this->c/f1)*(b.c/f2);
  r.d=(this->d/f2)*(b.d/f1);
  return r;
}
```

  * **Templates**
    * Decl. and Def. into header
    * code is only generated when parametrized -> may look like  code but they are only definitions, from which code can be generated
    * if template is only parametrized with small set of types:
      * can treat template functions and template classes like normal functions and classes
      * need to instantiate the class in an impl. file that has access to full templ. def. `template class pvector<string>;`
* "nothing" that causes compiler to immediately generate code
* except for small number of things
* to prevent multiple inclusions:
```cpp
// either use 
#ifndef VARS_H_
#define VARS_H_
#endif

// or use, although non-standard, still widely used
#pragma once
/* code */
```

### Memory management
* Built-in types and objects can be stored on stack and heap
* Stack memory managed automatically
* Heap memory needs to be allocated and freed explicitly
* in C++ all parameters can be passed by value, pointer or reference

#### Typical Memory Layout

![a typical memory layout](./images/memlayout.jpg)

#### The Stack
* stores local variables, return addresses etc.

#### Pointers (TYPE*)
* should be used sparsely and carefully
* since it can point to different types use -> TYPE*
##### Pointer Operations
* &-Operator:
  * obtains address where value is tored (lvalue)
  * returns a pointer to the type of lvale
  * `&(lvalue)`
* *-Operator:
  * Dereference a pointer
  * return the type of the value the pointer points to
  * `*(expr)`

```cpp
void c_swap(int *x, int *y) {
  int z = *x;
  *x = *y;
  *y = z;
}

int a=3, b=5;
c_swap(&a, &b);
```

#### References (TYPE&)
* refers to a value or object stored in memory, another name i.e. alias for a given value or object
* it cannot be changed to refer to a different location
* functions may also return References
* allows the function to be used as lvalue:

```cpp
class fraction {
 public:
  // other functions
  // conversion fraction to double
  operator double() { return (double)c/d; }
  // references as return value
  int &counter() { return c; }
  int &denominator() { return d; }
};

void normalize(fraction &a) {
  int f = gcf(a.counter(), a.denominator());
  a.counter() = a.counter() / f;
  a.denominator() /= f;
  // counter() and denominator() are now used as lvalues
}
```

* same charactereristics as a pointer
  * variable a reference points to should exist as long the reference itself
  * never return a reference to a local variable, unless static
  (but avoid static local variables, they are like global variables)
* References are taken implicitly
  * makes the code nicer to read but easy to overlook
* Google Coding Style suggests avoiding references as return values
and instead stick to pointers

#### Commonly Used (Safe) Patterns
* Function references elements passed by caller
  * `swap(int &a, int &b)`
    * if a and b are valid in caller scope, they 'must be' valid in callee's scope
    * make sure it is obvious to caller that a and b might be changed
  * `print_vector(const vector<string> &v)`
    * with const we promise not to change v
    * avoids duplication of v
* Function return reference to element passed to it
  * `ostream &operator<<(ostream &os, const T &element)`
    * same arg. as above, we return to caller a reference to an object
* Member function return reference to elem. of its class
  * `int &fraction::counter()`
  * ` T &vector::operator[](size_t index)`
    * this is implicitly passed to member function

