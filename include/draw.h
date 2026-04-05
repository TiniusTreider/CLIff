#ifndef DRAW_H
#define DRAW_H

struct position;
struct color;

void put_char(char, struct position, struct color);
void put_string(char*, struct position, struct color);

#endif

