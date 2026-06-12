#include "main.h"

extern "C" void kernel_main() {
    video[0] = "h";
    video[1] = "i";
    video[2] = "!";
    video[3] = "\0";
    while(true);
}
