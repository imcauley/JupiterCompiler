int fact(int i) {
    return (i * (fact (i - 1)));
}

main() {
    fact(4);
}