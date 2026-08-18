#include <iostream>

int add_(int a, int b)
{
    return a + b;
}

int main()
{
    int x = 2;
    int y = 3;

    return add_(x, y);
}