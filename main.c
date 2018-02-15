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

  edges = new_matrix(4, 4);
  
  add_edge(edges, 1, 2, 3, 300, 500, 3);
  print_matrix(edges);
  
  draw_lines(edges, s, c);
  display(s);
  free_matrix( edges );
}