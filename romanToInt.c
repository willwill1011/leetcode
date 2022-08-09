#include <stdio.h>

/*
Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
IV            4
IX            9
XL            40
XC            90
CD            400
CM            900  
*/
int romanCharToInt(char c)
{
    switch (c)
    {
    case 'I':
        return 1;
    case 'V':
        return 5;
    case 'X':
        return 10;
    case 'L':
        return 50;
    case 'C':
        return 100;
    case 'D':
        return 500;
    case 'M':
        return 1000;
    default:
        return 0;
    }
}
int main(){
    int i = 0;
    int value = 0;
    int temp = 0;
    char* s="LVIII";
    //for(int i=0;i<sizeof(s)-1;i++){
    while( i < sizeof(s)-1 ){
        temp=(romanCharToInt(s[i+1]) - romanCharToInt(s[i]));
        printf("\n-----i=%d temp=%d Ivalue=%d\t", i, temp, romanCharToInt(s[i]));
        switch(temp){
            case 4:
            case 40:
            case 400:
            case 9:
            case 90:
            case 900:
                value+=temp;
                printf("\n value=%d", value);
                i+=2;
                break;
            default :
                value+=romanCharToInt(s[i]);
                printf("\n value=%d", value);
                i++;
                break;
        }
    }
    printf("\n value=%d", value);
}