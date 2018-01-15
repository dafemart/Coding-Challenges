#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define QUEENS 8
#define COLUMNS 8
#define ROWS 8

typedef struct stack{
    int queens_pos[QUEENS];
    int size;
}queen_stack;

void initialize_stack(queen_stack* stk){
    stk->size = 0;
    int i;
    for(i = 0; i < QUEENS; i++){
        stk->queens_pos[i] = -1;
    }
}

int insert(int element, queen_stack* stk){
    if(stk->size == 8)
       return 0;
    stk->queens_pos[stk->size] = element;
    stk->size++;
    return 1;
}

int pop(queen_stack* stk){
    if(stk->size == 0)
       return 0;
    int top = stk->queens_pos[stk->size];
    stk->size--;
    return 1;
}

void print_stack(queen_stack* stk){
    int i;
    for(i = 0; i < stk->size; i++){
        int x_pos = stk->queens_pos[i]/8;
        int y_pos = stk->queens_pos[i]%8;
         printf("%d-%d_",x_pos,y_pos);
    }
    printf("\n");
}


int is_pos_valid(int pos, queen_stack* stk){
    int x_pos = pos / 8;
    int y_pos = pos % 8;
    int i;
    for(i = 0; i < stk->size; i++){
        int current_x = stk->queens_pos[i]/8;
        int current_y = stk->queens_pos[i]%8;
        if(y_pos == current_y){
            return 0;
        }

        int x_dist = x_pos - current_x;
        int y_dist = abs(y_pos - current_y);
        if(x_dist == y_dist){
          return 0;
        }
    }
    return 1;
}

void print_all_ways(int row, queen_stack* queens_pos){
   if(row == ROWS){
       print_stack(queens_pos);
       return;
   }
   else{
       int i;
       for(i = 0; i < COLUMNS; i++){
           int pos = 8*row + i;
           int valid = is_pos_valid(pos, queens_pos);
           if(valid > 0){
               if(insert(pos,queens_pos) > 0){
                  print_all_ways(row + 1, queens_pos);
               }
               else{
                   printf("ERROR: stack overflow");
                   return;
               }

               if(pop(queens_pos) == 0){
                 printf("ERROR: reducing empty stack");
                return;
              }
           }
       }
   }
}

int main(){
    queen_stack new_stack;
    initialize_stack(&new_stack);
    print_all_ways(0, &new_stack);
}