#include "../include/fun.h"
#include <cctype>
#include <cmath>

unsigned int faStr1(const char *str)
{
    unsigned int count = 0;
    bool hasDigit = false;
    bool inWord = false;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (!isspace(str[i]))
        {
            inWord = true;
            if (isdigit(str[i]))
                hasDigit = true;
        }
        else
        {
            if (inWord && !hasDigit)
                count++;

            inWord = false;
            hasDigit = false;
        }
    }

    if (inWord && !hasDigit)
        count++;

    return count;
}

unsigned int faStr2(const char *str)
{
    unsigned int count = 0;
    bool inWord = false;
    bool valid = true;
    bool firstChecked = false;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (!isspace(str[i]))
        {
            if (!inWord)
            {
                inWord = true;
                valid = true;
                firstChecked = false;
            }

            if (!firstChecked)
            {
                if (!isupper(str[i]))
                    valid = false;
                firstChecked = true;
            }
            else
            {
                if (!islower(str[i]))
                    valid = false;
            }
        }
        else
        {
            if (inWord && valid)
                count++;

            inWord = false;
        }
    }

    if (inWord && valid)
        count++;

    return count;
}

unsigned int faStr3(const char *str)
{
    unsigned int words = 0;
    unsigned int totalLength = 0;
    unsigned int currentLength = 0;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (!isspace(str[i]))
        {
            currentLength++;
        }
        else
        {
            if (currentLength > 0)
            {
                totalLength += currentLength;
                words++;
                currentLength = 0;
            }
        }
    }

    if (currentLength > 0)
    {
        totalLength += currentLength;
        words++;
    }

    if (words == 0)
        return 0;

    return (unsigned int)round((double)totalLength / words);
}
add solution
