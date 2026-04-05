#ifndef DRAW_H
#define DRAW_H

struct position {
        unsigned int x;
        unsigned int y;
};
struct color {
        unsigned char foreground;
        unsigned char background;
};

void put_char(char, struct position, struct color);
void put_string(char*, struct position, struct color);

#endif

