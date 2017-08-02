#include <dirent.h> 
#include <stdio.h> 

int main(void)
{
	system("clear");
  DIR           *d;
  struct dirent *dir;
  char  path[400];
  puts("Enter full path name of directory you want to view:");
  scanf("%s",&path);
  
  d = opendir(path);
  if (d)
  {
	  printf("The Directory Contents are .\n/******************************/ \n");
    while ((dir = readdir(d)) != NULL)
    {
      printf("%s\n", dir->d_name);
    }
    

    closedir(d);
  }
  else 
  printf("Directory doesnt exist");

  return(0);
}
