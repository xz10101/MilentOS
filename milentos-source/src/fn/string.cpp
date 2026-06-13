#include "string.h"
#include "keyfn.h"

int strcmp(const char* a, const char* b) {
    int i = 0;
    while (a[i] && b[i]) {
        if (b[i] == ' ') {
            i++;
        }
        if (a[i] != b[i]) return 0;
        i++;
        
    }
    return a[i] == b[i];
}

void enter_command() {
    input_buffer[index_buffer] = '\0';

    write("\n");
    if (strcmp(input_buffer, " ")) {
        write("\n");
    }
    
    else {
        write(input_buffer);
        write("\n");
    }


    index_buffer = 0;
}
