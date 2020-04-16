int fact(int i) {
    if (i < 1) {
        return 1;
    }
    return (i * (fact (i - 1)));
}

main() {
    int i;
    i = fact(4);
}