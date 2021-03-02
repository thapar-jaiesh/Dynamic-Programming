/*Given an integer N, find and return the count of minimum numbers required to represent N as a sum of squares.
That is, if N is 4, then we can represent it as : {1^2 + 1^2 + 1^2 + 1^2} and {2^2}. The output will be 1, as 1 is the minimum count of numbers required to represent N as sum of squares.
Input format :
The first and the only line of input contains an integer value, 'N'.
 Output format :
Print the minimum count of numbers required.
Constraints :
0 <= n <= 10 ^ 4

Time Limit: 1 sec
Sample Input 1 :
12
Sample Output 1 :
3
Explanation of Sample Output 1 :
12 can be represented as : 
A) (1^1) + (1^1) + (1^1) + (1^1) + (1^1) + (1^1) + (1^1) + (1^1) + (1^1) + (1^1) + (1^1) + (1^1)

B) (1^1) + (1^1) + (1^1) + (1^1) + (1^1) + (1^1) + (1^1) + (1^1)  + (2 ^ 2)

C) (1^1) + (1^1) + (1^1) + (1^1) + (2 ^ 2) + (2 ^ 2)

D) (2 ^ 2) + (2 ^ 2) + (2 ^ 2)

As we can see, the output should be 3.
Sample Input 2 :
9
Sample Output 2 :
1
*/
    
#include<bits/stdc++.h>

bool perfect_square(int n){
    int i=1;
    for(int i=0;i<=n;i++){
        if(i*i==n){
            return true;
        }
    }
    return false;
}

int mincount(int n,int t[])
{
	//Write your code here
    
    //simple recursive solution
    //base case
    //seedhi si baat hai negative to hoga nai number
    
    if(n<0){
        return 0;
    }
    if(n<=3){
        return n;
    }
    if(perfect_square(n)){
        return 1;
    }
    if(t[n]!=-1){
        return t[n];
    }
    //zyada se zyada kitna hi bura hoga? ki 1*1+1*1.....+1*1=n hoga? matlab n 
    int count=n;
    for(int i=1;i<=n;i++){
        int temp=i*i;
        if(temp>n){
            break;
        }
        else{
            count=min(count,mincount(n-temp,t)+1);
        }
        
    }
     t[n]=count;
    return t[n];
}
int minCount(int n){
    int t[10001];
    memset(t,-1,sizeof(t));
    return mincount(n,t);
    
}
