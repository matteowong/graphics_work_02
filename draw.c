#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

//Insert your line algorithm here
void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {
  //swap x0,y0 and x1,y1 if necessary
  if (x0>x1) {
    printf("swap\n");
    int temp=x0;
    x0=x1;
    x1=temp;
    temp=y0;
    y0=y1;
    y1=temp;
  }else if (x0==x1 && y0>y1) {
    int temp=y0;
    y0=y1;
    y1=temp;
  }
  //octant 1
  int oct=which_oct(x0,y0,x1,y1);
  printf("which_oct: %d\n",oct);

  int x,y,A,B,d;
  x=x0;
  y=y0;
  A=y1-y0;
  B=-(x1-x0);

  if (oct==1) {
    d=2*A+B;
    while (x<=x1) {
      plot(s,c,x,y);
      if (d>0) {
	y++;
	d+=2*B;
      }
      x++;
      d+=2*A;
    }
  }

  else if (oct==2) {
    d=A+2*B;
    while(y<=y1) {
      plot(s,c,x,y);
      if (d<0) {
	x++;
	d+=2*A;
      }
      y++;
      d+=2*B;
    }
  }
  else if (oct==8) {
    //octant 8, -1<m<0
  
    d=2*A-B;
    while (x<=x1) {
      plot(s,c,x,y);
      if (d<0) {
	y--;
	d-=2*B;
      }
      x++;
      d+=2*A;
    }
  }
  else if (oct==7) {
    //octant 7, m<-1
    d=A-2*B;
    while (y>=y1) {
      plot(s,c,x,y);
      if (d>0) {
	x++;
	d+=2*A;
      }
      y--;
      d-=2*B;
    }
  }
  /*else if (oct==-1) {
    if (y>y1) {
      y0=y1;
      y1=y;
      y=y0;
    }
    while (y<=y1) {
      plot(s,c,x,y);
      y++;
    }
    }*/
}


//assume x0<x1
int which_oct(int x0, int y0, int x1, int y1) {
  if (x0==x1)
    return 2;
  double slope=((double)y1-y0)/(x1-x0);
  printf("slope: %f\n",slope);
  if (slope>=1)
    return 2;
  else if (slope>=0)
    return 1;
  else if (slope>=-1)
    return 8;
  else if (slope<-1)
    return 7;
  return -1;

}


