#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"

int main() {

  screen s;
  color c;
  struct matrix *edges;
  struct matrix *idented;
  struct matrix *edges2;
  struct matrix *to_draw;

  c.red = 0;
  c.green = MAX_COLOR;
  c.blue = 0;

  clear_screen(s);
  edges = new_matrix(4, 4);
  edges2 = new_matrix(4, 4);
  to_draw = new_matrix(4, 4);
  
  add_edge(to_draw, 0, 0, 0, 150, 150, 0);
  add_edge(to_draw, 100, 200, 0, 450, 450, 0);
  add_edge(edges, 2, 2, 2, 3, 3, 3);
  printf("matrix below will be multiplied by itself\n");
  print_matrix(edges);
  edges2 = new_matrix(4, 4);
  
  //add_edge(edges2, 1, 2, 3, 300, 400, 3);
  //add_edge(edges2, 100, 200, 3, 300, 400, 3);
  add_edge(edges2, 2, 2, 2, 3, 3, 3);
  matrix_mult(edges, edges2);

  printf("\nreturns:\n");
  print_matrix(edges2);

  idented = new_matrix(4, 4);
  ident(idented);
  printf("\n4x4 identity matrix:\n");
  print_matrix(idented);
  //draw_line(0, 0, 100, 100, s, c);
  
  
  draw_lines(to_draw, s, c);
  //save_ppm(s, "the_ppm");
  display(s);
  //free_matrix( edges );
}
