#include <stdio.h>
int solvemaze(int r,int c);
void printmaze();
void printsolution();
// Enter 0 to Make a Way 
// Enter 1 to Build a Wall 
int maze[3][3]={
	{0,1,1},
	{0,0,1},
	{1,0,0} 
};
int solution[3][3];
int r,c,i,j;char ch;
void printmaze()
{
   int i,j;
   for(i=0;i<3;i++)
   {
   		for(j=0;j<3;j++)
		{
			if(maze[i][j]==1)
         		printf("||\t");
         	else
         		printf("  \t");
      	}
      	printf("\n");
   }
}
void printsolution()
{
   int i,j;
   for(i=0;i<3;i++)
   {
   		for(j=0;j<3;j++)
		{
			if(solution[i][j]==1 && maze[i][j]==0)
         		printf("~>\t");
         	else if(solution[i][j]==0 && maze[i][j]==1)
         		printf("||\t");
         	else
         		printf("  \t");
      	}
      	printf("\n");
   }
}
int solvemaze(int r,int c)
{
   	if((r==3-1) && (c==3-1))
   	{
      solution[r][c]=1;
      return 1;
  	}
   	if(r>=0 && c>=0 && r<3 && c<3 && solution[r][c]==0 && maze[r][c]==0)
	{
     	solution[r][c]=1; // if safe to visit then visit the cell
      	if(solvemaze(r+1,c)) // going down
        	return 1;
      	if(solvemaze(r-1,c)) // going up
        	return 1;
      	if(solvemaze(r,c+1)) // going right
        	return 1;
      	if(solvemaze(r,c-1)) // going left
        	return 1;
      	solution[r][c]=0; // backtracking (Repeat)
    		return 0;
   	}
   return 0;
}
void main()
{
	printf("\n\n ..... RAT MAZE GAME .....");
	printf("\n\n\t  START \n\n\n");
	printmaze();
	printf("\n\n");
	for(i=0;i<3;i++)
	{
      	for(j=0;j<3;j++)
		{
        	solution[i][j]=0;
    	}
   	}
	if(solvemaze(0,0))
     	printsolution();
   	else
    	printf("No solution !!");
}

