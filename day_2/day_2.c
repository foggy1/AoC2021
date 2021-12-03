#include <stdio.h>
#include <string.h>

int main () {
    int value;
    char command[10];
    FILE * fp;
    int x = 0, y = 0;

    fp = fopen ("input.txt", "r");
    while (fscanf(fp, "%s %d", command, &value)!=EOF)
    {
        if (strcmp(command, "forward") == 0)
        {
            x = x + value;
        }
        else if (strcmp(command, "down") == 0) {
            y = y + value;
        }
        else if (strcmp(command, "up") == 0) {
            y = y - value;
        }
    }

    fclose(fp);

    printf("Distance |%d|\n", x );
    printf("Depth |%d|\n", y );

    printf("Depth times distance is |%d|\n", x * y );

    return(0);
}
