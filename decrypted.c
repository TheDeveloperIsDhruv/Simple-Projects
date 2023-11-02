#include<stdio.h>
void decrypted(char *c){
    char *ptr=c;
    while(*ptr!='\0'){
        *ptr-=1;
        ptr++;
    }

}
int main(){
    char c[]="Ijj-!ipx!bsf!zpv@";
    decrypted(c);
    printf("The decrpyted message is %s",c);
    return 0;

}
