#include "fn/keyfn.h"
#include "fn/vga.h"
#include "fn/string.h"

__attribute__((section(".multiboot")))
const int multiboot_header[] = {
    0x1BADB002,
    0x0,
    -(0x1BADB002)
};




extern "C" void kernel_main() {
    clear_scr();
    write("LeniteKernel started!\n\n> ");
    
    
    while(true) {
        char ckey = keyboard_gc();
        if (!ckey) continue;

        if (ckey == '\n') {
            enter_command();
            write("> ");

        }
        else {
            print_char(ckey);
            add_char(ckey);
        }
    }    
    
}
