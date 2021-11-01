//
// Created by arminveres on 10/31/21.
//
#include <iostream>
#include <list>

#include "dumb_pointer.h"
#include "smart_pointer.h"

using namespace std;

class Object {
    int x;
public:
    explicit Object(int val): x(val) {}

    int method1() const {
        return x + 1;
    }

    int method2() const {
        return x + 2;
    }

    int method3() const {
        return x + 3;
    }

    friend ostream &operator<<(ostream &os, const Object &o) {
        os << "value: " << o.x;
        return os;
    }
};

void dumb_test() {
    cout << "Dumb Pointer Test:" << endl;

    Object *o = new Object(1);
    dumb_pointer<Object> p = o;

    cout << *p << ": " << p << endl;
}


void print(smart_pointer<Object> p) {
    cout << p.counter() << ": " <<  *p << endl;
}

void smart_test() {
    cout << "Smart Pointer Test:" << endl;

    Object *o1 = new Object(1);
    Object *o2 = new Object(2);

    smart_pointer<Object> p(o1);
    cout << p.counter() << endl;

    smart_pointer<Object> q(p);
    cout << p.counter() << endl;
    cout << q.counter() << endl;

    smart_pointer<Object> r(o2);
    cout << r.counter() << endl;

    cout << "---" << endl;

    q = r;
    cout << p.counter() << endl;
    cout << q.counter() << endl;
    cout << r.counter() << endl;

    cout << "---" << endl;

    print(p);
    print(q);
    print(r);

    cout << "---" << endl;

    cout << *p << " " << *r << endl;
    cout << p->method1() << " " << q->method2() << " " << r->method3() << endl;
}

int main() {
    dumb_test();

    cout << "----------------------------------" << endl << endl;

    smart_test();
}