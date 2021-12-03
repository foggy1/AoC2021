#include <stdio.h>

int main () {
    int current_depth, last_depth;
    int depth_increases = 0;
    FILE * fp;

    fp = fopen ("input.txt", "r");
    while (fscanf(fp, "%d", &current_depth)==1)
    {
      if (current_depth > last_depth && last_depth != 1) {
          depth_increases = depth_increases + 1;
      }
      last_depth = current_depth;
    }

    fclose(fp);

    printf("Number of Depth Increases |%d|\n", depth_increases );

    return(0);
}
