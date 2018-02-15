#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"

/*======== void add_point() ==========
Inputs:   struct matrix * points
         int x
         int y
         int z 
Returns: 
adds point (x, y, z) to points and increment points.lastcol
if points is full, should call grow on points
====================*/
void add_point( struct matrix * points, double x, double y, double z) {
  int lastcol = points->lastcol++;
  points->m[0][lastcol] = x;
  points->m[1][lastcol] = y;
  points->m[2][lastcol] = z;

  if(lastcol >= points->cols) grow_matrix(points, points->cols * 2);
  //points->lastcol++;
}

/*======== void add_edge() ==========
Inputs:   struct matrix * points
          int x0, int y0, int z0, int x1, int y1, int z1
Returns: 
add the line connecting (x0, y0, z0) to (x1, y1, z1) to points
should use add_point
====================*/
void add_edge( struct matrix * points, 
	       double x0, double y0, double z0, 
	       double x1, double y1, double z1) {
  add_point(points, x0, y0, z0);
  add_point(points, x1, y1, z1);
}

/*======== void draw_lines() ==========
Inputs:   struct matrix * points
         screen s
         color c 
Returns: 
Go through points 2 at a time and call draw_line to add that line
to the screen
====================*/
void draw_lines( struct matrix * points, screen s, color c) {
  int i = 0;
  for(; i < points->lastcol; i += 2){
    draw_line(points->m[0][i], points->m[1][i], 
	      points->m[0][i + 1], points->m[1][i + 1], 
	      s, c);
  }
}





void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {

  int a = y1 - y0;
  int b = x1 - x0;

  if(a * b > 0){
    if(b > a){
      int d = 2 * a - b;
      while(x0 < x1){
	plot(s, c, x0, y0);
	if(d > 0) {
	  y0++;
	  d -= 2 * b;
	}
	x0++;
	d += 2 * a;
      }
    }else if(a > b){
      int d = a - (2 * b);
      while(x0 < x1){
	plot(s, c, x0, y0);
	if(d < 0) {
	  x0++;
	  d += 2 * a;
	}
	y0++;
	d -= 2 * b;
      }
    }
  }else{
    int d = b - (2 * a);
    while(x0 < x1){
      plot(s, c, x0, y0);
      if(d < 0) {
	y0--;
	d -= 2 * b;
      }
      x0++;
      d += 2 * a;
      printf("%d ", d);
    }
  }
}
