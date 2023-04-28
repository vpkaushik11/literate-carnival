#include<stdio.h>
#include<string.h>

int main() {
    int a = 20;
    int x=1;
    int y=2;
    int z=3;
    while(a<z){
        a++;
        if(a > 0){
            x--;
        }
        else{
            y--;
        }
    }
    a = 0;
    return 1;
}