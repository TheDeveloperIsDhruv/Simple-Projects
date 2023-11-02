#include<stdio.h>
 int factorial(int c);
 int main(){
     int a;
     scanf("%d",&a);
     int z=factorial(a);
     printf("The factorial is %d",z);
     return 0;
 }
 int factorial(int c){
     if(c==0 || c==1){
         return 1;
     }
     else{
         return c*factorial(c-1);
     }
 }