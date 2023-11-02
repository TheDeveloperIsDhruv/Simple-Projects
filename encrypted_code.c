#include<stdio.h>
void encrypted(char *c){
    char *ptr=c;
    while(*ptr!='\0'){
        *ptr+=1;
        ptr++;
    }

}
int main(){
    char c[]="Hii, how are you?";
    encrypted(c);
    printf("The encrpyted message is %s",c);
    return 0;

}
