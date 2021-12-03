#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main () {
    char binary[20];
    char head[20];
    long common[20] = { 0 };
    FILE * fp;
    int i;

    fp = fopen ("input.txt", "r");

    fscanf(fp, "%s", head);
    int len = strlen(head);
    char gamma[len];
    char epsilon[len];

    while (fscanf(fp, "%s", binary)!=EOF)
    {
        for (i = 0; i < len; i++) {
            if (binary[i] == '0')
            {
                common[i] = common[i] - 1;
            }
            else
            {
                common[i] = common[i] + 1;
            }
        }
    }

    for (i = 0; i < len; i++)
    {
        if (common[i] > 0)
        {
            gamma[i] = '1';
            epsilon[i] = '0';
        }
        else {
            gamma[i] = '0';
            epsilon[i] = '1';
        }
    }

    printf("Power Consumption Rate: %ld\n", strtol(gamma, 0, 2) * strtol(epsilon, 0, 2));

    fclose(fp);

    return(0);
}
