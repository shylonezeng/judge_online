#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main(void){
        char s[]="123456789";
        char d[]="123";
        cout<<"address of s:"<<(void*)s<<",address of d:"<<(void*)d<<endl;
        strcpy(d,s);
        printf("%s,%s\n",d,s);

}
