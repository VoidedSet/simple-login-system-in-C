#include <stdio.h>

int configread() {
    FILE *config;
    char loginVal[6];
    int numUsers;

    config = fopen("config.txt", "r");
    fscanf(config, "firstLogin = %s numUsers = %d", loginVal, &numUsers);

    //numUsers++;
    fclose(config);
    
    /*
    FILE *configW;
    configW = fopen("config.txt", "w");
    
    fprintf(config, "firstLogin = %s numUsers = %d", loginVal, numUsers);
    fclose(configW);
    */
    
    return numUsers;
}

