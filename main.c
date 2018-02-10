#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

int main() {

  screen s;
  color c;

  c.red = 0;
  c.green = MAX_COLOR;
  c.blue = 0;
  
  
  

  clear_screen(s);
  draw_line(375,375,250,300,s,c);//octant 1
  draw_line(375,375,300,250,s,c);//octant 2
  draw_line(375,125,300,250,s,c);//octant 7
  draw_line(375,125,250,200,s,c);//octant 8
  draw_line(125,125,250,200,s,c);
  draw_line(125,125,200,250,s,c);
  draw_line(125,375,200,250,s,c);
  draw_line(125,375,250,300,s,c);
  
  draw_line(500,250,0,250,s,c);//horizontal
  draw_line(125,125,375,375,s,c);//m=1
  draw_line(375,125,125,375,s,c);//m=-1
  draw_line(250,500,250,0,s,c);//vertical

  display(s);
  save_extension(s, "lines.png");
}
