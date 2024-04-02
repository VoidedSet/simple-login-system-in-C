/*
header file - falses.h
author - Kshayik
basically accepts the input finds and stores it string length, goes thru a loop where it constantly checks 
for unwanted characters like \, -, /, and space if such a thing is found, the number of nulls increases.
*/

#include <stdio.h>
#include <string.h>

int falses(char input[26]) {
	
	int i, nulls = 0, slen;
		
	slen = strlen(input);
	
for(i = 0; i <= slen; ++i){
	if(input[i] == ' ' || input[i] == '-' || input[i] == '/' || input[i] == '\\'){
				++nulls;
			}
			}
			
return nulls;

	}
