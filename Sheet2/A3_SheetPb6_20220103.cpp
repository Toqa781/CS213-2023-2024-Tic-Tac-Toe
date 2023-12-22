// File name:A3_SheetPb6_20220103.cpp
// Purpose:in the comments
// Author(s):Habiba Ayman Hamed
// ID(s):20220103
// Section:S7,8
// Date:8/12/2023
#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;
class Universe{
private:
    int rows,columns;
    vector<vector<int>>grid;
public:
    //constructor
    Universe(int r,int c):rows(r),columns(c),grid(rows,vector<int>(columns,0)){}

    //generates a starting layout(random)
    void initialize(){
        //srand(time(0));
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                grid[i][j] = rand() % 2 ;
            }
        }
    }
    //sets all the cells as dead.
    void reset(){
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                grid[i][j] = 0;
            }
        }
    }
    //returns the number of alive neighbors.
    int count_neighbors(int row,int col){
        int cnt = 0;
        for (int i = -1; i <= 1; ++i) {
            for (int j = -1; j <= 1; ++j) {
                if (i==0 && j==0)continue;//skip current cell
                int newrow = row + i;
                int newcol = col + j;
                if (newrow >= 0 && newcol >= 0 && newrow < rows && newcol < columns) {
                    if (grid[newrow][newcol] == 1)
                        cnt++;
                }
            }
        }
        return cnt;
    }
   //produces a new state of the game based on the transition rules.
   void next_generation(){
        vector<vector<int>>newgrid = grid;
       for (int i = 0; i < rows; ++i) {
           for (int j = 0; j < columns; ++j) {
               int neighbors = count_neighbors(i,j);
               //Any live cell with fewer than two live neighbors dies, as if caused by underpopulation
               if(grid[i][j]==1){
                   if(neighbors<2)
                       newgrid[i][j]=0;
                   //Any live cell with two or three live neighbors lives on to the next generation
                   else if(neighbors==2 || neighbors==3)
                       newgrid[i][j] = 1;
                   //Any live cell with more than three live neighbors dies, as if by overpopulation
                   else if(neighbors>3)
                       newgrid[i][j] =0;
               }
               //Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction
               else{
                   if(neighbors==3)
                       newgrid[i][j]=1;
               }
           }
       }
       grid = newgrid;
   }
   //shows the game status on the console (It is better to erase screen and rewrite)
   void display(){
       for (int i = 0; i < rows; ++i) {
           for (int j = 0; j < columns; ++j) {
               cout<<(grid[i][j] ? "1 ":"0 ")<<" ";
           }
           cout<<endl;
       }
    }
    //to start the game for a certain number of runs.
    void run(int generation){
        for (int i = 0; i < generation; ++i) {
            cout<<"Generation "<<i+1<<":"<<endl;
            display();
            next_generation();
        }
    }
};
int main(){
    Universe universe(10, 10);  // Adjust rows and cols as needed
    universe.initialize();
    universe.run(3);
    return 0;
}
