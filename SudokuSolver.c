//Sudoku solver
#include<stdio.h>
#include<stdlib.h>
int A[9][9] = {{3, 0, 6, 5, 0, 8, 4, 0, 0}, 
         {5, 2, 0, 0, 0, 0, 0, 0, 0}, 
         {0, 8, 7, 0, 0, 0, 0, 3, 1}, 
         {0, 0, 3, 0, 1, 0, 0, 8, 0}, 
         {9, 0, 0, 8, 6, 3, 0, 0, 5}, 
         {0, 5, 0, 0, 9, 0, 6, 0, 0}, 
         {1, 3, 0, 0, 0, 0, 2, 5, 0}, 
         {0, 0, 0, 0, 0, 0, 0, 7, 4}, 
         {0, 0, 5, 2, 0, 6, 3, 0, 0} };

int DisplayBoard(){
    int i, j;
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
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
int ifEmptyField( int i, int j){
    if(A[i][j] == 0) return 1;
    else return 0;
}
int EmptyFieldCounter(){
    int emptyCounter = 0;
    int i,j;
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            if(ifEmptyField(i,j)) {
                emptyCounter++;
            }
    }
    }
    return emptyCounter;
}

int inRow( int i, int j, int num){
    //to check if the number is valid in the row
    //if valid then returns 1
    //else returns 0
    int k;
    for (k=0;k<9;k++){
        if(A[i][k]==num) return 0;
    }
    return 1;
}

int inColumn( int i, int j, int num){
    //to check if the number is valid in the column
    //if valid then returns 1
    //else returns 0
    int k;
    for(k=0;k<9;k++){
        if(A[k][j]==num) return 0;
    }
    return 1;
}

int inBlock( int i, int j, int num){
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
 
 void sudoku_solver(int empty[EmptyFieldCounter()][2], int index){
    int i;
    for(i=1;i<=9;i++){
        if(inRow(empty[index][0],empty[index][1],i) && 
           inColumn(empty[index][0],empty[index][1],i) && 
           inBlock(empty[index][0],empty[index][1],i)){
            A[empty[index][0]][empty[index][1]] = i;
            DisplayBoard();
            index++;
            sudoku_solver(empty, index);
        } 
     }
     index--;
     sudoku_solver(empty, index);
 }

int main(){
    int i,j,k;
        
    //print sudoku board
    DisplayBoard();
    
    //checks 
    //empty field
    // printf("%d\n", ifEmptyField(0,1)); // op = 1
    // printf("%d\n", ifEmptyField(1,1)); // op = 0

    // //in row check
    // printf("%d\n", inRow(0,1,2)); // op = 1

    // //in column check
    // printf("%d\n", inColumn(2,0,5)); // op = 0

    // //in block check
    // printf("%d\n", inBlock(8,7,2)); // op = 0
    // printf("%d\n", inBlock(8,7,5)); // op = 0
    // printf("%d\n", inBlock(8,7,7)); // op = 0
    // printf("%d\n", inBlock(8,7,4)); // op = 0
    // printf("%d\n", inBlock(8,7,3)); // op = 0

    // printf("%d\n", inBlock(8,7,1)); // op = 1
    // printf("%d\n", inBlock(8,7,6)); // op = 1
    // printf("%d\n", inBlock(8,7,8)); // op = 1
    // printf("%d\n", inBlock(8,7,9)); // op = 1

    
   //printf("Total missing places: %d",EmptyFieldCounter());

    // create an array to store all empty indices
    int EmptyPlIndices[EmptyFieldCounter()][2]; 
    //this array will store all empty field to be filled
    
    k=0;
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            if(ifEmptyField(i,j)) {
                EmptyPlIndices[k][0]=i;
                EmptyPlIndices[k++][1]=j;
            }
        }
    }
    //Display the list of empty places
    // for(i=0;i<EmptyFieldCounter();i++){
    //    printf("(%d,%d) ",EmptyPlIndices[i][0],EmptyPlIndices[i][1]);
    // }
   //sudoku_solver(EmptyPlIndices,0);


    return 0;
}