#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;
int main(void){
    int i;
    const char a[47]="A7B9X5E0F1G8Y4Z1JKLOP5M0Q3C3R9S2H8TU2I6V6W4N7D";
    char str[17]="";
    srand((unsigned)time(NULL));
    for(i=0;i<16;str[i++]=a[rand()%46]);
    time_t lt=time(NULL);
    struct tm *ptr=localtime(&lt);cout << ptr->tm_year << endl;
    itoa(ptr->tm_year+1900,str+4,10);
    if((i=ptr->tm_mon+1)<10){
        *(str+8)='0';
        *(str+9)=i+'0';
    }
    else itoa(i,str+8,10);
    if((i=ptr->tm_mday)<10){
        *(str+10)='0';
        *(str+11)=i+'0';
    }
    else{;
        *(str+10)=ptr->tm_mday/10+'0';
        *(str+11)=ptr->tm_mday%10+'0';
    }
    cout << "The string is \'" << str << "\'\n";
    return 0;
    return 0;
}