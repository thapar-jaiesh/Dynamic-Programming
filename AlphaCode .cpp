#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll m=1000000000+7;

ll alphaCode(ll input[],ll size,ll output[]){
    
    if(size==0||size==1){
        return 1;
    }
    if(output[size]!=-1){
        return output[size];
    }
    ll numCodes=0;
    if(input[size-1] == 0)
    {
        if(input[size-2] == 1 || input[size-2] == 2)
            numCodes = numCodes%m + alphaCode(input,size-2,output)%m;
        else
            numCodes = 0;
    }
    else 
    {
        numCodes = numCodes%m + alphaCode(input,size-1,output)%m;
    	numCodes %= m;
    	if(input[size-2]*10+input[size-1]>= 10 && input[size-2]*10+input[size-1]<=26){
        	numCodes = numCodes%m + alphaCode(input,size-2,output)%m;
        	numCodes%=m;
    	}
    }
    output[size]=numCodes;
    return numCodes;
}

int main()
{
    while(true){
    	string s;
        cin>>s;
        if(s == "0")
            break;
        //ek input string lia jisme number hi daalenge
        ll input[s.size()];
        for(int i=0;i<s.size();i++){
            input[i]=s[i]-'0';
        }
         ll output[s.size()+1];
    	memset(output,-1,sizeof(output));
        cout<<alphaCode(input,s.size(),output)<<endl;
       
    }
    
    return 0;
}
