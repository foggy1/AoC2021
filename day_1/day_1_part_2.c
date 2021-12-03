#include <stdio.h>

int main () {
    int current_depth;
    int depth_increases = 0;
    int window_buffer[4];
    int i = 0;
    FILE * fp;

    fp = fopen ("input.txt", "r");
    while (fscanf(fp, "%d", &current_depth)==1)
    {
        if (i < 4)
        {
            window_buffer[i] = current_depth;
        }
        else
        {
            window_buffer[0] = window_buffer[1];
            window_buffer[1] = window_buffer[2];
            window_buffer[2] = window_buffer[3];
            window_buffer[3] = current_depth;
        }
        if (window_buffer[3] > window_buffer[0]) {
            depth_increases = depth_increases + 1;
        }
        i = i + 1;
    }

    fclose(fp);

    printf("Number of Depth Increases |%d|\n", depth_increases );

    return(0);
}
