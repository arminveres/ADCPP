#include <iostream>

using namespace std;

class parentMember {
public:
    parentMember() {
        cout << "Construct parent member class" << endl;
    }

    ~parentMember() {
        cout << "Destruct parent member class" << endl;
    }
};

class childMember {
public:
    childMember() {
        cout << "Construct child member class" << endl;
    }

    ~childMember() {
        cout << "Destruct child member class" << endl;
    }
};


class father {
    parentMember parentmember;
public:
    father() {
        cout << "Construct father class" << endl;
    }

    ~father() {
        cout << "Destruct father class" << endl;
    }
};

class mother {
    parentMember parentmember;
public:
    mother() {
        cout << "Construct mother class" << endl;
    }

    ~mother() {
        cout << "Destruct mother class" << endl;
    }
};

class child : public father, public mother {
    childMember childmember;
public:
    child() {
        cout << "Construct child class" << endl;
    }

    ~child() {
        cout << "Destruct child class" << endl;
    }
};

int main() {
    child c;
    cout << "-----------" << endl;
    return 0;
}
