#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>
struct dirent *entry;
int main()
{
  DIR *dir;
  FILE *source_fp;
  char dirname[20], buffer[100], key[20], source_file[20];
  char *newline;
  int count = 0;

  printf("Enter directory name:");
  scanf("%s", dirname);
  if ((dir = opendir(dirname)) != NULL)
  {
    printf("\nDirectory already exists");
    printf("\nDirectory entries:");
    while ((entry = readdir(dir)) != NULL)
    {
      printf("%s\n", entry->d_name);
    }
  }
  printf("\nEnter file name to search for the pattern:");
  scanf("%s", source_file);
  if (source_fp = fopen(source_file, "r"))
  {
    printf("\nFile exists");
  }
  else
  {
    printf("\nError");
    exit(1);
  }

  printf("\nEnter the word to search for:");
  scanf("%s", key);
  while ((fgets(buffer, 100, source_fp)) != NULL)
  {
    count++;
    newline = strchr(buffer, '\n');
    if (newline)
      *newline = '\0';
    if (strstr(buffer, key))
    {
      printf("Line no %d:\t%s", count, buffer);
    }
  }
}
