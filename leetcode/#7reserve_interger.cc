#include <climits>
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;
class Solution {
public:
    int reverse(int x) {
        bool sign=false;
        if(x<0)
        {
            sign=true;
            x*=-1;
        }
    
        char ax[16];
        snprintf(ax,16,"%d",x);
        int len=strlen(ax);
       
        long result=0; //bug existed still: long int overflow can not be checked
        int wValue=1;
        
        for(int i=0;i<len;++i){
            result+=(ax[i]-'0')*(long)wValue;
           // std::cout<<"temp result:"<<result<<std::endl;
            wValue*=10;
        }
        
       // std::cout<<"INT_MAX:"<<LONG_MAX<<"\nstring number:"<<ax<<std::endl;
        //cout<<"result:"<<result<<endl;
        if(result>INT_MAX)
            result=0;
        
        if(sign)
            result*=-1;
        return (int)result;
            
    }
};

int main() {
    Solution slt;
    std::cout << "reversed result:" << slt.reverse(1534236469)<<std::endl;
}
