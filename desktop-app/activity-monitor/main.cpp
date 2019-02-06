#include <iostream>
#include <stdint.h>
#include "win32/WinSocketHandler.h"

using namespace std;

int main(int argc, char** argv) {
    cout << "Hello";
    WinSocketHandler *h = new WinSocketHandler(3000);
    return 0;
}