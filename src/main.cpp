// Copyright 2026 Астафьева Анастасия an-astafyeva

#include <iostream>
#include "../include/fun.h"

int main() {
    const char *str = "Hello world test123 ABC def GhI";

    std::cout << "faStr1: " << faStr1(str) << std::endl;
    std::cout << "faStr2: " << faStr2(str) << std::endl;
    std::cout << "faStr3: " << faStr3(str) << std::endl;

    return 0;
}
