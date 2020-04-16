main() {
    int i;
    int j;
    int fib;
    int num;
    fib = 1;
    i = 1;
    j = 1;
    num = getchar();
    num = num - 48;
    while(num > 0) {
        fib = i + j;
        j = i;
        i = fib;
        printi(fib);
        prints("\n");
        num = num - 1;
    }
}