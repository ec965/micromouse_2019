#include<stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#define NORTH 1
#define SOUTH 2
#define EAST 3
#define WEST 4
#define X 16
#define Y 16

struct cell{
  int n_wall;
  int s_wall;
  int e_wall;
  int w_wall;
  int distance;
};

struct coord{
  int x;
  int y;
};

//FUNCTION DEFINITIONS

int get_distance(int, int, int, int);

//calculates the distance from the center of the maze
//diemension is the dimensions of the maze i.e. 16x16 would give a dimension of 16
int get_center(int, int, int);

//update mouse poisiton coordinate for given movement direction
struct coord move(struct coord, int);

//choose direction
int choose_direction(struct coord , struct cell , struct cell);
//are you at the goal?
bool at_goal(int, int, int);

//check boundaries: True if within bounds
bool check_bound(int);


int main(){
  struct cell maze[Y][X];
  int i,j;
  struct coord coord1 = {1,1};
  for (i=0; i<Y; i++){
    for (j=0;j<X;j++){
      maze[i][j].distance = get_center(i,j,X);
    }
  }

  for (i=0; i<Y; i++){
    for (j=0;j<X;j++){
      printf("%3d", maze[i][j].distance);
      if (j == X-1){
        printf("\n");
      }
    }
  }
  printf("\n%3d", maze[coord1.y][coord1.x].distance);
  return 0;
}

//FUNCTION DEFINITIONS

int get_distance(int current_x, int current_y, int final_x, int final_y){
  int distance = abs(final_y-current_y) + abs(final_x-current_x);
  return distance;
}

//calculates the distance from the center of the maze
//diemension is the dimensions of the maze i.e. 16x16 would give a dimension of 16
int get_center(int current_x, int current_y, int dimension){
  int center = dimension/2; //center of 16x16 is (8,8)
  //four center squares are (7,7), (8,7), (7,8), (8,8)
  int max_distance = 0;
  if (current_y<center){
    if(current_x<center){
      //top left quardarnt of maze
      max_distance = get_distance(current_x, current_y, center-1, center-1);
    }
    else{
      //top right quardrant of maze
      max_distance = get_distance(current_x, current_y, center, center-1);
    }
  }
  else{
    if(current_x<center){
      //bottom left quardrant
      max_distance = get_distance(current_x, current_y, center-1,center);
    }
    else{
      //bottom right quardarant
      max_distance = get_distance(current_x,current_y, center, center);
    }
  }
  return max_distance;
}

//update mouse poisiton coordinate for given movement direction
struct coord move(struct coord current_position, int direction){
  struct coord next_position = {0,0};
  if (direction == NORTH){
    next_position.x = current_position.x;
    next_position.y = current_position.y-1;
  }
  else if(direction == SOUTH){
    next_position.x = current_position.x;
    next_position.y = current_position.y+1;
  }
  else if(direction == EAST){
    next_position.x = current_position.x-1;
    next_position.y = current_position.y;
  }
  else if(direction == WEST){
    next_position.x = current_position.x+1;
    next_position.y = current_position.y;
  }
  return next_position;
}

//choose direction
int choose_direction(struct coord current_coord, struct cell current_cell,struct cell next_cell){
  int direction = 0;
  if (current_cell.n_wall == 0 && current_cell.distance > next_cell.distance){
    direction = NORTH;
  }
  else if (current_cell.s_wall == 0 && current_cell.distance > next_cell.distance){
    direction = SOUTH;
  }
  else if (current_cell.e_wall == 0 && current_cell.distance > next_cell.distance){
    direction = EAST;
  }
  else if (current_cell.w_wall == 0 && current_cell.distance > next_cell.distance){
    direction = WEST;
  }
  else{
    direction = 0;
  }
  return direction;
}

//are you at the goal?
bool at_goal(int current_x, int current_y, int dimension){
  bool check;
  if (get_center(current_x,current_y,dimension) == 0){
    check = true;
  }
  else{
    check = false;
  }
  return check;
}

//check boundaries: True if within bounds
bool check_bound(int x_or_y){
  bool check;
  if(x_or_y>X || x_or_y>Y || x_or_y<0 || x_or_y<0){
    check = 0;
  }
  else{
    check = 1;
  }
  return check;
}
