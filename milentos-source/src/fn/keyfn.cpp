#include "keyfn.h"
#include "vga.h"



volatile char* video = (char*) VIDEO_MEM;
int cursor_x = 0;
int cursor_y = 0;
char input_buffer[MAX_BUFFER];
int index_buffer = 0;
char keyboard_map[128] = {
    0,
    27,
    '1', '2', '3', '4', '5', '6',
    '7', '8', '9', '0', '-', '=',
    '\b',
    '\t',
    'q', 'w', 'e', 'r', 't', 'y',
    'u', 'i', 'o', 'p', '[', ']',
    '\n',
    0,
    'a', 's', 'd', 'f', 'g', 'h',
    'j', 'k', 'l', ';', '\'',
    '`',
    0,
    '\\',
    'z', 'x', 'c', 'v', 'b', 'n',
    'm', ',', '.', '/',
    0,
    '*',
    0,
    ' ',
};



char keyboard_gc() {
    static unsigned char last = 0;
    unsigned char scancode;

    scancode = inb(0x60);

    if (scancode == 0 || scancode == last) {
        return 0;
    }

    last = scancode;

    if (scancode & 0x80) return 0;

    if (scancode > 0 && scancode < 128) {
        return keyboard_map[scancode];
    }

    return 0;

}

void print_char(char c) {
    if (c == '\n') {
        cursor_x = 0;
        cursor_y++;
        return;
    } 

    int index = (cursor_y * WIGTH + cursor_x) * 2;

    video[index] = c;
    video[index + 1] = 0x07;

    cursor_x++;

    if (cursor_x >= WIGTH) {
        cursor_x = 0;
        cursor_y++;
    }
    
}

void add_char(char C) {
    if(index_buffer < MAX_BUFFER - 1) {
        input_buffer[index_buffer++] = C;
    }
}

void write(const char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
	    print_char(str[i]);
    }
}

void clear_scr() {
    for (int i = 0; i < WIGTH * HEIGHT * 2; i += 2) {
	    video[i] = ' ';
 	    video[i + 1] = 0x07;

        cursor_x = 0;
        cursor_y = 0;
        write("> ");
    }
}