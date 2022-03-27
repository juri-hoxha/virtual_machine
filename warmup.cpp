#include <vector>
using std::vector;
#include <iostream>
using std::cout;
#include <stdlib.h>

vector<vector<bool> > world = {
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};

int main(int argc, char *argv[])
{

	vector<vector<bool>> future(world); /* make future a copy of world. */

	int r = world.size(); // # of rows
  vector<bool> Columns = world[0]; //first vector
  int c = Columns.size(); // # of columns in first vector

	int n; //number of iterations
  char* N = argv[1]; // read from command line
  n = atoi(N); // convert char to int

for (int k=0; k<n; k++){
  for (int i=0; i<r; i++){
   for (int j=0; j<c; j++){
    size_t nb = 0;
    // Check for neighbors in world
    if (world[(((i-1)+r)%r)][(((j-1)+c)%c)]==1){
     nb++;
    }
    if (world[(((i-1)+r)%r)][(((j)+c)%c)]==1){
     nb++;
    }
    if (world[(((i-1)+r)%r)][(((j+1)+c)%c)]==1){
     nb++;
    }
    if (world[(((i)+r)%r)][(((j+1)+c)%c)]==1){
     nb++;
    }
    if (world[(((i+1)+r)%r)][(((j+1)+c)%c)]==1){
     nb++;
    }
    if (world[(((i+1)+r)%r)][(((j)+c)%c)]==1){
     nb++;
    }
    if (world[(((i+1)+r)%r)][(((j-1)+c)%c)]==1){
     nb++;
    }
    if (world[(((i)+r)%r)][(((j-1)+c)%c)]==1){
     nb++;
    }
    // Apply rules
    if (nb<2){
     future[i][j]=0;
    }
    if (nb>3) {
     future[i][j]=0;
    }
    if (nb==3){
     future[i][j]=1;
    }
   }
  }

		world = future; //update current world to next generation future
}

  // Print new world after n iteration loop is finished
  for (int i=0; i<r; i++){
   for (int j=0; j<c; j++) {
    if (future[i][j]==0){
     cout << ".";
    } else {
     cout << "O";
    }
   }
   cout << "\n" ;
  }
	return 0;
}
