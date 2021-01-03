//Sudoku solver
#include<stdio.h>
#include<stdlib.h>
const int m = 9;
const int n = 9;

int DisplayBoard(int A[m][n]){
    int i, j;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            printf("%d ",A[i][j]);
            if((j+1)%3==0 & (j+1)!=9) printf("| ");
        }        
         if((i+1)%3==0 & (i+1)!=9) {
             printf("\n");
             printf("- - - - - - - - - - -");
         }
         printf("\n");
    }
    printf("\n");
    return 1;
}

int ifEmptyField(int A[m][n], int i, int j){
    if(A[i][j] == 0) return 1;
    else return 0;
}

int inRow(int A[m][n], int i, int j, int num){
    //to check if the number is valid in the row
    //if valid then returns 1
    //else returns 0
    int k;
    for (k=0;k<n;k++){
        if(A[i][k]==num) return 0;
    }
    return 1;
}

int inColumn(int A[m][n], int i, int j, int num){
    //to check if the number is valid in the column
    //if valid then returns 1
    //else returns 0
    int k;
    for(k=0;k<m;k++){
        if(A[k][j]==num) return 0;
    }
    return 1;
}

int inBlock(int A[m][n], int i, int j, int num){
    int a, b;
    a = (i/3)*3;
    b = (j/3)*3;
    int k,l;
    for(k=a;k<a+3;k++){
        for(l=b;l<b+3;l++){
            if(A[k][l]==num ) return 0;
        }
    }
    return 1;
}

int main(){
    int A[9][9]={ {3, 0, 6, 5, 0, 8, 4, 0, 0}, 
         {5, 2, 0, 0, 0, 0, 0, 0, 0}, 
         {0, 8, 7, 0, 0, 0, 0, 3, 1}, 
         {0, 0, 3, 0, 1, 0, 0, 8, 0}, 
         {9, 0, 0, 8, 6, 3, 0, 0, 5}, 
         {0, 5, 0, 0, 9, 0, 6, 0, 0}, 
         {1, 3, 0, 0, 0, 0, 2, 5, 0}, 
         {0, 0, 0, 0, 0, 0, 0, 7, 4}, 
         {0, 0, 5, 2, 0, 6, 3, 0, 0} };
    //print sudoku board
    DisplayBoard(A);
    
    //checks 
    //empty field
    printf("%d\n", ifEmptyField(A,0,1)); // op = 1
    printf("%d\n", ifEmptyField(A,1,1)); // op = 0

    //in row check
    printf("%d\n", inRow(A,0,1,2)); // op = 1

    //in column check
    printf("%d\n", inColumn(A,2,0,5)); // op = 0

    //in block check
    printf("%d\n", inBlock(A,8,7,2)); // op = 0
    printf("%d\n", inBlock(A,8,7,5)); // op = 0
    printf("%d\n", inBlock(A,8,7,7)); // op = 0
    printf("%d\n", inBlock(A,8,7,4)); // op = 0
    printf("%d\n", inBlock(A,8,7,3)); // op = 0

    printf("%d\n", inBlock(A,8,7,1)); // op = 1
    printf("%d\n", inBlock(A,8,7,6)); // op = 1
    printf("%d\n", inBlock(A,8,7,8)); // op = 1
    printf("%d\n", inBlock(A,8,7,9)); // op = 1

    return 0;
}