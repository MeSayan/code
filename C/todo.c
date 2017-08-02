#include <ctype.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#define FILE_NAME "todo"
#define TEMP_FILE "todo_temp"

void addToFile(const char *text) {
    FILE *fp = fopen(FILE_NAME,"a");
    if( fp != NULL)
        fprintf(fp,"%s\n",text);
    fclose(fp);
}

void removeFromFile(const char *text) {
    FILE *fp = fopen(FILE_NAME,"r");
    FILE *wp = fopen(TEMP_FILE,"w");

    char buffer[100];

    while( fgets(buffer, sizeof(buffer)/sizeof(char), fp) != NULL ) {
        if(strstr(buffer,text))
            printf("%s removed from file\n",buffer);
        else
            fprintf(wp,"%s",buffer);
    }
    fclose(fp);
    fclose(wp);

}



int main(int argc, char **argv) {
    int list, add, remove;
    char c;
    add = remove = 0;
    optind = 0;

    while( ( c = getopt(argc,argv,"la:r:")) != -1) {
        switch(c) {
            case 'l': list = 1;
                      system("sort todo");
                      break;
            case 'a': if(!remove) { 
                          add = 1;
                          addToFile(optarg);
                      }
                      break;
            case 'r': if(!add) {
                        remove = 1;
                        removeFromFile(optarg);
                      }
                      break;
            case '?': if( optopt == 'a')
                          fprintf(stderr,"Option a requiers parameter \n");
                      else if( optopt == 'b')
                          fprintf(stderr,"Option b requires parameter \n");
                      break;
            }
    }

    return 0;
}
