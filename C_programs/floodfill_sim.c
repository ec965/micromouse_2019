#include<stdio.h>
#include "arrayprint.h"
#include "cell.h"
#define X 16
#define Y 16
//X is columns Y is rows
int main(){
  int i,j,k;
  int mazeX = X*2+1;
  int mazeY = Y*4+1;
  char maze[mazeX][mazeY];//print maze
  struct cell num_maze[X][Y];
  char*pointer_char = &maze[0][0];//pointer for printing maze

  int mousestart=1;//intialize while loop
  int mousemove = 0; //refresh the maze when the mouse moves

//initialize maze
  for (i=0;i<mazeX;i++){
    for(j=0;j<mazeY;j++){
      if(i%2==0){
        if(j%4==0){
          maze[i][j] = '+';
        }//if
        if(j%4!=0){
          if(i==0 || i==mazeX-1){
            maze[i][j] = '-';
          }//if
          else{
            maze[i][j] = ' ';
          }//else
        }//if
      }//if
      if(i%2!=0){
        if(j==0 || j==mazeY-1){
          maze[i][j] = '|';
        }//if
        else{
          maze[i][j] = ' ';
        }//else
      }//if
    }//for
  }//for
//  generate the number array
  num_maze[0][0].distance = 14;
  for(i=0; i<16; i++) {
     k=14;
     for(j=0;j<16;j++) {
       if (i<=7){
          num_maze[i][j].distance = k-i;
          if (j < 7){
            k--;
          }
          if (j>7){
            k++;
          }
        }
        if(i>=8){
          num_maze[i][j].distance = k+i-8-7;
          if (j < 7){
            k--;
          }
          if (j>7){
            k++;
          }
        }
      }
   }

  while(mousestart!=0){
    printf("Mouse start:\n1 - top left\n2 - top right\n3 - bottom right\n4 - bottom left\n");
    scanf("%d", &mousestart);
    if (mousestart == 1){
      maze[1][1] = 'v';
    }
    else if(mousestart == 2){
      maze[1][mazeY-2] = 'v';
    }
    else if(mousestart == 3){
      maze[mazeX-2][1] = '^';
    }
    else if(mousestart == 4){
      maze[mazeX-2][mazeY-2] = '^';
    }
    printmaze_char(mazeX,mazeY,pointer_char);
    mousestart = 0;
  }
  return 0;
}//main

void printmaze_char(int mazeX,int mazeY,char*maze){
  int i,j;
  for(i=0; i<mazeX; i++) {
    for(j=0; j<mazeY; j++) {
      printf("%c",*maze);
      if(j==mazeY-1){
        printf("\n");
      }
      maze++;
    }
  }
}

void printmaze_int(int mazeX,int mazeY,int*maze){
  int i,j;
  for(i=0; i<mazeX; i++) {
    for(j=0; j<mazeY; j++) {
      printf("%4d",*maze);
      if(j==mazeY-1){
        printf("\n");
      }
      maze++;
    }
  }
}
