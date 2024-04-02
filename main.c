#include <stdio.h>
#include "mask.h"
#include "falses.h"
#include "uauth.h"
#include "configread.h"

int numUsers;

void main (){
	char tempChar[6];
	
	FILE *logs = fopen("config.txt", "a");
	fclose(logs);
	
	FILE *logfile = fopen("config.txt", "r");
	fscanf(logfile, "firstLogin = %s", tempChar);
	
	if(strcmp(tempChar, "false") == 0 || strcmp(tempChar, "true") == 0){
		
		if(strcmp(tempChar, "true") == 0){
		firstlogin();
	}
	if(strcmp(tempChar, "false") == 0){
		int choice;
		
		printf("\n\n\n\n\t\t\t\t\t\t Welcome Back! \n\n\t\t\t\t\t1. Continue with old account.\n\t\t\t\t\t2. Create a new account.\n\n\t\t\t\t\tEnter your choice number -> ");
		scanf("%d", &choice);
		
		if(choice == 1){
		login();
		}else if(choice == 2){
			firstlogin();
		}else{
			printf("\n\n\t\t\t\t\tInvalid choice try again.");
		}
	}
	}else{		
	FILE* firstlogin = fopen("config.txt", "w");
	fprintf(firstlogin, "firstLogin = true numUsers = 1");
	fclose(firstlogin);
	main();	
	}
	fclose(logfile);		
}

firstlogin(){
	
		char username[25], password[25];
		int nulls, numUsers = configread();
		++numUsers;
		
		printf("\n\n\n\n\n\n\t\t\t\t Welcome! Please create a new account to proceed.\n\n\t\t1) Create a Username.            \t(spaces, \\, / and - are not allowed. Maximum 25: Characters)\n\n\n\t\t\t\t\tUsername: ");
		scanf("%s", &username);
	
		nulls = falses(username);
		if(nulls == 0){
			
		printf("\n\n\t\t2) Create a secure Password.          \t(spaces, \\, / and - are not allowed. Maximum 25: Characters)\n\n\t\t\t\t\t");
		mask(password);
		
		nulls = falses(password);
		
		   if(nulls == 0){
			
			   FILE *passfile0 = fopen("user_data.txt", "a");
			   fprintf(passfile0, "\n%s %s",username, password);
			   fclose(passfile0);
			
			  printf("\n\n\n\t\t\t\t\t(!) Succesfully Logged In!");
		
		       FILE *logfile = fopen("config.txt", "w");
		       fprintf(logfile, "firstLogin = false numUsers = %d", numUsers);
		       fclose(logfile);
		       
		   }else{		
		       printf("\n\t(!) Please follow the given input algorithm. Try again later.");
			   return 0;
		        }		
		}else{	
			printf("\n\t(!) Please follow the given input algorithm. Try again later.");
			return 0;
	}		
}

login(){
	int numUsers = configread();
	struct User user[numUsers];
	char username[25], password[25];
	
	printf("\n\n\n\n\n\n\t\t\t Welcome back returning user! Please enter your details!\n\n\t\t\t\t\tUsername: ");
	scanf("%s", &username);
	
	mask(password);
	
	if(uauth(user, numUsers, username, password)){
		printf("\nsuccess!");
	}else{
		printf("\nfailed");
	}
}	
