boolean infinite_loop() {
    int i;
    while (true) {
        i = 0;
    }
    return false;
}

main() {
    int i;
    if(true || infinite_loop() )  {
        i = 1;
    }
}