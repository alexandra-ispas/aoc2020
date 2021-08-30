#include <stdio.h>
#include <stdlib.h>

#define L 323
#define C 31


char **read_input(char filename[100]){
    char **matrix = (char**)calloc(L, sizeof(char*));
    if(matrix == NULL){
        printf("Allocation error.\n");
        exit(EXIT_FAILURE);
    }
    for(int i = 0; i < L; i++){
        matrix[i] = (char*)calloc(C, sizeof(char));
        if(matrix[i] == NULL){
            printf("Allocation error.\n");
            for(int j = 0; j < i; j++){
                free(matrix[j]);
            }
            free(matrix);
            exit(EXIT_FAILURE);
        }
    }

    FILE *in = fopen(filename, "rt");
    if(in == NULL){
        printf("Allocation error.\n");
        for(int i = 0; i < L; i++){
            free(matrix[i]);
        }
        free(matrix);
        exit(EXIT_FAILURE);
    }
    int i = 0, j = 0;
    char c;
    while((c = getc(in)) > 0){
        if(j < C){
            matrix[i][j++] = c;
        } else {
            if(j == C){
                i++;
                j = 0;
            } else {
                i++;
                j = 0;
                matrix[i][j++] = c;
            }
        }
    }
    /*
    for(i = 0; i < L; i++){
        for(j = 0; j < C; j++){
            printf("%c  ", matrix[i][j]);
        }
        printf("\n");
    }
    */
    return matrix;
}

long go(int right, int down, char **matrix){
    int nr = 0;
    int x = down, y = right;
    while(x < L){
        if(matrix[x][y] == '#'){
            nr++;
        }
        x += down;
        y = (y + right) % (C);
    }
    return nr;
}

int main(void){
    char **matrix = read_input("input.txt");
    printf("%ld\n", go(1, 1, matrix) *
                    go(3, 1, matrix) * 
                    go(5, 1, matrix) * 
                    go(7, 1, matrix) *
                    go(1, 2, matrix));
    return 0;
}