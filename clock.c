#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

/*void clock(int h, int m,int s){
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
		printf("%2d:%2d:%2d\n",h,m,s);
		usleep(1000000);
	}
}*/
void cadclock(int h,int m,int s){
	int a,b;
	if(h>10){
		 a=h-10;
	}
	if(m>30){
	 b=m-30;
	}
	if(h<10){
		a=h;
	}	
	if(m<30){
		b=m+30;
	}
	printf("Canadian Clock\n");
        while(1){
                s++;
                if(s>59){
                        b++;
                        s=0;
                }
                if(b>59){
                        a++;
                        b=0;
                }
                if(a>23){
                        a=0;
                }
                printf("%2d:%2d:%2d\n",a,b,s);
                usleep(1000000);
        }
}

int main(){
	int h,m,s;
	scanf("%d%d%d",&h,&m,&s);
	if(h>23 || m>59 || s>59){
		printf("Wrong Time");
		exit(0);
	}
        cadclock(h,m,s);
	//cadclock(h,m,s);
	return 0;
}
