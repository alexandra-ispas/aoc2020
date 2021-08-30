#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>

int binarySearch(long int arr[], int l, int r, int x)
{
    while (l <= r) {
        int m = l + (r - l) / 2;
  
        // Check if x is present at mid
        if (arr[m] == x)
            return m;
  
        // If x greater, ignore left half
        if (arr[m] < x)
            l = m + 1;
  
        // If x is smaller, ignore right half
        else
            r = m - 1;
    }
  
    // if we reach here, then element was
    // not present
    return -1;
}

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int scan (char str[], int lwr, int uppr) {
    // printf("%s, %d, %d\n", str, lwr, uppr);
    if(strlen(str) == 1) {
        if(str[0] == 'F' || str[0] == 'L'){
            return lwr;
        } else {
            return uppr;
        }
    }

    float m = (float)(uppr + lwr) / 2;
    if(str[0] == 'F' || str[0] == 'L'){
        scan(str + 1, lwr, (int)floor(m));
    } else {
        scan(str + 1, (int)round(m), uppr);
    }
}


int main(void) {
    long ids[1000];
    int idx = 0;
    long maxId = INT_MIN;
    char filename[] = "input.txt";
    FILE *in = fopen(filename, "rt");
    if(in == NULL){
        fprintf(stderr, "Failed to open file.\n");
        exit(EXIT_FAILURE);
    }

    char *line = (char*)malloc(11 * sizeof(char));
    if(line == NULL){
        fprintf(stderr, "Allocation failure.\n");
        exit(EXIT_FAILURE);
    }

    long min = INT_MAX;

    long unsigned int size = 11;
    while(getline(&line, &size, in) != -1){
        if(line[strlen(line) - 1] == '\n'){
            line[strlen(line) - 1] = 0;
        }
        char rowStr[10], colStr[4];
        strncpy(rowStr, line, 7);
        strcpy(colStr, line);
        strcpy(colStr, colStr + 7);
        int row = scan(line, 0, 127);
        int col = scan(colStr, 0, 7);
        long id = row * 8 + col;
        ids[idx++] = id;
        if(id > maxId)
            maxId = id;
    }
    fclose(in);
    qsort(ids, sizeof(ids) / sizeof(ids[0]), sizeof(long int), cmpfunc);
    long int i;
    for(i = 7; i < maxId; i++){
        if(binarySearch(ids, 0, sizeof(ids) / sizeof(ids[0]) - 1, i) == -1){
            printf("%ld\n", i);
            break;
        }
    }
    printf("%ld\n", maxId);
    return 0;
}
