// Copyright 2026 Астафьева Анастасия an-astafyeva

#include "fun.h"
#include <cctype>
#include <cmath>

unsigned int faStr1(const char *str) {
    unsigned int count = 0;
    bool hasDigit = false;
    bool inWord = false;

    for (int i = 0; str[i] != '\0'; i++) {
        if (!isspace(static_cast<unsigned char>(str[i]))) {
            inWord = true;
            if (isdigit(static_cast<unsigned char>(str[i]))) {
                hasDigit = true;
            }
        } else {
            if (inWord && !hasDigit) {
                count++;
            }
            inWord = false;
            hasDigit = false;
        }
    }

    if (inWord && !hasDigit) {
        count++;
    }

    return count;
}

unsigned int faStr2(const char *str) {
    unsigned int count = 0;
    bool inWord = false;
    bool valid = true;
    int pos = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (!isspace(static_cast<unsigned char>(str[i]))) {
            char ch = str[i];

            if (!inWord) {
                inWord = true;
                valid = true;
                pos = 0;
            }

            if (pos == 0) {
                if (!(ch >= 'A' && ch <= 'Z')) {
                    valid = false;
                }
            } else {
                if (!(ch >= 'a' && ch <= 'z')) {
                    valid = false;
                }
            }

            pos++;
        } else {
            if (inWord && valid) {
                count++;
            }
            inWord = false;
            valid = true;
            pos = 0;
        }
    }

    if (inWord && valid) {
        count++;
    }

    return count;
}

unsigned int faStr3(const char *str) {
    unsigned int words = 0;
    unsigned int totalLength = 0;
    unsigned int currentLength = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (!isspace(static_cast<unsigned char>(str[i]))) {
            currentLength++;
        } else {
            if (currentLength > 0) {
                totalLength += currentLength;
                words++;
                currentLength = 0;
            }
        }
    }

    if (currentLength > 0) {
        totalLength += currentLength;
        words++;
    }

    if (words == 0) {
        return 0;
    }

    return static_cast<unsigned int>(
        round(static_cast<double>(totalLength) / words));
}
