/*You are given a magic grid A with R rows and C columns. In the cells of the grid, you will either get magic juice, which increases your strength by |A[i][j]| points, or poison, which takes away |A[i][j]| strength points. If at any point of the journey, the strength points become less than or equal to zero, then you will die.
You have to start from the top-left corner cell (1,1) and reach at the bottom-right corner cell (R,C). From a cell (i,j), you can only move either one cell down or right i.e., to cell (i+1,j) or cell (i,j+1) and you can not move outside the magic grid. You have to find the minimum number of strength points with which you will be able to reach the destination cell.
Input format:
The first line contains the number of test cases T. T cases follow. Each test case consists of R C in the first line followed by the description of the grid in R lines, each containing C integers. Rows are numbered 1 to R from top to bottom and columns are numbered 1 to C from left to right. Cells with A[i][j] < 0 contain poison, others contain magic juice.
Output format:
Output T lines, one for each case containing the minimum strength you should start with from the cell (1,1) to have a positive strength through out his journey to the cell (R,C).
Constraints:
1 ≤ T ≤ 5
2 ≤ R, C ≤ 500
-10^3 ≤ A[i][j] ≤ 10^3
A[1][1] = A[R][C] = 0
Time Limit: 1 second
Sample Input 1:
3
2 3
0 1 -3
1 -2 0
2 2
0 1
2 0
3 4
0 -2 -3 1
-1 4 0 -2
1 -2 -3 0
Sample Output 1:
2
1
2

*/


#include<bits/stdc++.h>
int getMinimumStrength(int** grid, int r, int c) {
	// Write your code here
    int t[r][c];
    memset(t,-1,sizeof(t));
    //initialization
    t[r-1][c-1]=1;
    t[r-2][c-1]=1;
    t[r-1][c-2]=1;
    for(int j=c-3;j>=0;j--){
        if(grid[r-1][j+1]<0){
            t[r-1][j]=t[r-1][j+1]-grid[r-1][j+1];
        }
        else{
            t[r-1][j]=max(1,t[r-1][j+1]-grid[r-1][j+1]);
        }
    }
    for(int i=r-3;i>=0;i--){
        if(grid[i+1][c-1]<0){
            t[i][c-1]=t[i+1][c-1]=grid[i+1][c-1];
        }
        else{
            t[i][c-1]=max(1,t[i+1][c-1]-grid[i+1][c-1]);
        }
    }
   
    //filling rest of the array
    //we have to find minimum amount of health
    //basically we are filling from bottom to top
    //the warrior can go either down or right
    //he will chose the path where its health decreases minimum or simply increases
    //each box will tell the minimum power required to reach the end from that prticular box
    //that is we willl chose maximum of two
    //and add in with the current box weight
 	for(int i=r-2;i>=0;i--){
        for(int j=c-2;j>=0;j--){
            int down;
            int right;
            if(grid[i+1][j]<0){
                down=t[i+1][j]-grid[i+1][j];
            }
            else{
                down=max(1,t[i+1][j]-grid[i+1][j]);
            }
            if(grid[i][j+1]<0){
                right=t[i][j+1]-grid[i][j+1];
            }
            else{
                right=max(1,t[i][j+1]-grid[i][j+1]);
            }
            t[i][j]=min(down,right);
        }
    }
    int ans=t[0][0];
    
    return ans;
}
