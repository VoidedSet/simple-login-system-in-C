/*
header file - uauth.h
author - Kshayik
uses data structurs in arrays to read user_dat.txt and store them in the structure. the loop goes until 
either the limit for the number of users is reached or the user details matches with the ones entered
by the user.
*/

#include <stdio.h>
#include <string.h>

struct User{
	char username[25];
	char password[25];
};

int uauth(struct User user[], int numUsers, char *username, char *password){
	int i;
	FILE *datFile = fopen("user_data.txt", "r");
	for(i=0; i<numUsers; i++){
		fscanf(datFile, "%s %s", user[i].username, user[i].password);
		
	//	printf("\n%s %s\n", user[i].username, user[i].password);	//
		
		if(strcmp(user[i].username, username) == 0 && strcmp(user[i].password, password) == 0){
			return 1;
		}
	}
	fclose(datFile);
}
