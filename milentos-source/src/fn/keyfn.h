#define VIDEO_MEM 0xB8000
#define WIGTH 80
#define HEIGHT 25
#define MAX_BUFFER 128


#ifdef __cplusplus
extern "C" {
#endif

extern volatile char* video;
extern int cursor_x;
extern int cursor_y;
extern char input_buffer[MAX_BUFFER];
extern int index_buffer;
extern char keyboard_map[];


char keyboard_gc();
void print_char(char c);
void add_char(char C);
void write(const char* str);
void clear_scr();


#ifdef __cplusplus
}
#endif