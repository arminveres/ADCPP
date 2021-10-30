void swap(int &a, int &b) { 
    int c=a; a=b; b=c; 
}

int main() {
    int a = 5;
    int b = 6;
    swap(a, b);
}
