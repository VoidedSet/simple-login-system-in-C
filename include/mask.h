/*
header file - mask.h
author - Kshayik
basically runs a loop where it constantly accepts characters without displaying them and converting them to "*"
until pressed enter which is when it breaks the loop. For backspace it wont display "*"
*/

#include <stdio.h>
#include <conio.h>

void mask(char password[26]) {
    char ch;
    int i = 0;

    printf("\n\n\t\t\t\t\tPassword: ");
    
    while (1) {
        ch = getch(); // Get a character from the user without echoing it
        if (ch == 13) // 13 is the ASCII code for Enter
            {break;}
			else if (ch == 8) // 8 is the ASCII code for Backspace
			{
				--i;
				password[i] = ch;
			}else{
        printf("*"); 
        password[i] = ch; // Store the character in the password array
        i++;
			}
    }
    password[i] = '\0'; // Null-terminate the password string    
}
