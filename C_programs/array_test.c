#include<stdio.h>
int main(){
  int X = 16;
  int Y = 16;
   /* 2D array declaration*/
  int wallmaze[X][Y];
  int distmaze[X][Y];
  int goal = distmaze[8][8];
  int start = distmaze[0][0];
   /*creates maze*/
   int i/*rows*/, j/*collumns*/;
   int k;
   for(i=0; i<16; i++) {
      k=14;
      for(j=0;j<16;j++) {
        if (i<=7){
           distmaze[i][j] = k-i;
           if (j < 7){
             k--;
           }
           if (j>7){
             k++;
           }
         }
         if(i>=8){
           distmaze[i][j] = k+i-8-7;
           if (j < 7){
             k--;
           }
           if (j>7){
             k++;
           }
         }
       }
    }

   //Displays maze
   printf("16x16 Maze\n");
   for(i=0; i<16; i++) {
      for(j=0;j<16;j++) {
         printf("%4d", distmaze[i][j]);
         if(j==15){
            printf("\n");
         }
      }
   }
   return 0;
}
