#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getOcurrenceNumber(char passwd[100], char letter[2]){
    int nr = 0;
    // printf("%ld\n", strlen(passwd));
    while(strlen(passwd) > 1){
        // printf("%c   \n", passwd[0]);
        if(passwd[0] == letter[0]){
            nr++;
        }
        passwd++;
    }
    if(passwd[0] == letter[0]){
        nr++;
    }
    return nr;
}

int main(void){


    char input[] = "input2.txt";
    FILE *in = fopen(input, "rt");
    if(in == NULL){
        printf("Failed to open file.\n");
        exit(EXIT_FAILURE);
    }
    int low, high;
    char passwd[100], letter[2], line[100], *p;
    int nr1 = 0, nr2 = 0;
    while(fgets(line, 100, in) != NULL){
        p = strtok(line, "-");
        low = atoi(p);
        p = strtok(NULL, " ");
        high = atoi(p);
        p = strtok(NULL, ":");
        strcpy(letter, p);
        p = strtok(NULL, "\n");
        strcpy(passwd, p + 1);
        /* task 1 */
        int app = getOcurrenceNumber(passwd, letter);
        if(app >= low && app <= high)
            nr1++;

        /* task 2 */
        if((passwd[low-1] == letter[0] && passwd[high - 1] != letter[0]) ||
            (passwd[low-1] != letter[0] && passwd[high - 1] == letter[0]))
            nr2++;
        
    }

    printf("%d    %d\n", nr1, nr2);

    return 0;
}