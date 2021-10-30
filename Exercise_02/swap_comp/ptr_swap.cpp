void c_swap(int *a, int *b) { 
    int c=*a; *a=*b; *b=c; 
}
int main() {
    int a = 5;
    int b = 6;
    c_swap(&a, &b);
}
