#include "Utils.h"
#include <iostream>

using namespace std;

template <typename T>
void print(T message)
{
    cout << message << endl;
    // Makes it so things work properly. Might only need one
    cout.clear();
    cout.flush();
}
