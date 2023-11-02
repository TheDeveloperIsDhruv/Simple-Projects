#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main(){
	int h,m,s;
	scanf("%d%d%d",&h,&m,&s);
	if(h>12 || m>60 || s>60){
		printf("Error");
		
	}
        printf("CLOCK");
	while(1){
	s++;
	if(s>59){
	  m++;
	  s=0;
	}
	if(m>59){
		h++;
		m=0;
	}
	if(h>12){
		h=1;
	}
	printf("\n%2d:%2d:%2d",h,m,s);
	usleep(1000000);
	}
}
	
