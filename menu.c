#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct user{
	char name[10],pswd[10];
	int id;
	int amount;
	int pnum;
};
void add(){
	struct user usr;
	printf("Enter the name:\t");
	scanf("%s",usr.name);
	printf("Enter the id:\t");
	scanf("%d",&usr.id);
	printf("Enter the amount:\t");
	scanf("%d",&usr.amount);
	printf("Enter the phone number:\t");
	scanf("%d",&usr.pnum);
	printf("Enter the password:\t");
	scanf("%s",usr.pswd);
	FILE *f;
	char filename[50];
	strcpy(filename,usr.name);
	f=fopen(strcat(filename,".dat"),"w");
	fwrite(&usr,sizeof(struct user),1,f);
	if(&fwrite!=0){
		printf("Account successfully registered");
	}
	else{
		printf("Please try again later");
	}
	fclose(f);
}

void login(){
	struct user usr;
	FILE *f,*f1;
        int r=1,ch,amt;
        char passwd[10],uname[1],fname[10];
	printf("Enter the name:\t");
	scanf("%s",uname);
	printf("Enter the password:\t");
	scanf("%s",passwd);
	strcpy(fname,uname);
	f=fopen(strcat(fname,".dat"),"r");
	if(f==NULL){
		printf("Account not registered");
	}
	else{
	fread(&usr,sizeof(struct user),1,f);
	fclose(f);
	if(strcmp(passwd,usr.pswd)==0){
			printf("Password Matched\n");
			printf("1 means YES\n");
			printf("0 means NO\n");
			printf("Do you want to continue further?\t");
			scanf("%d",&r);
			while(r!=0){
			printf("1.Current Balance Check\n");
			printf("2.Do you want to deposit amount?\n");
			printf("3.Do you want to withdraw?\n");
			printf("4.Do you want to change password?\n"); 
			printf("Enter your choice:\t");
			scanf("%d",&ch);	
			switch(ch){
				case 1:
					printf("Your current balance is %d",usr.amount);
				break;
				case 2:
					printf("How much amount needs to be deposited?\t");
					scanf("%d",&amt);
					usr.amount+=amt;
					f1=fopen(fname,"w");
					fwrite(&usr,sizeof(struct user),1,f1);
					if(&fwrite!=NULL){
					printf("Amount successfully deposited!");
					fclose(f1);
					}
					break;
				case 3:
					printf("How much amount needs to be withdrawn?\t");
					scanf("%d",&amt);
					if(amt<usr.amount){
					usr.amount-=amt;
					f=fopen(fname,"w");
					fwrite(&usr,sizeof(struct user),1,f);
					if(&fwrite!=0){
						printf("Amount successfully withdrawn!\n");
					}
					}
					else{
						printf("Amount cannot be withdrawn!\n");
					}
					break;
				case 4:
					printf("Please enter new password:\t");
					scanf("%s",passwd);
					strcpy(usr.pswd,passwd);
					f=fopen(fname,"w");
					fwrite(&usr,sizeof(struct user),1,f);
					if(&fwrite!=0){	
						printf("Password Successfully Changed!\n");
					}
					break;
			}
			printf("Continue Further?\t");
			scanf("%d",&r);
			
	     }
	}
	else{
		printf("Incorrect Password");
	}
      }
		
}
	
	

	
int main(){
	printf("1.Open New Account\n");
	printf("2.Login into an existing account\n");
	printf("3.Exit\n");
        printf("Enter your choice:\t");
        int c;
	scanf("%d",&c);
	if(c==1){
		add();
	}
        if(c==2){
		login();
	}
        if(c==3){
		exit(0);
        }
return 0;
}

       
