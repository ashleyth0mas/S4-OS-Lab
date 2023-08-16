#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>

struct dirent *entry;
int main()
{
    DIR *dir;
    FILE *source_fp, *dest_fp;
    char dirname[20], buffer[100], source_file[20], dest_file[20];
    size_t bytesread, byteswrite;
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
    printf("\nEnter the name of a source file and destination file from directory");
    scanf("%s%s", source_file, dest_file);
    if (source_fp = fopen(source_file, "r"))
    {
        printf("\nSourcefile exists");
    }

    if (dest_fp = fopen(dest_file, "w"))
    {
        printf("\nDestfile exists");
    }
    while ((bytesread = fread(buffer, 1, 100, source_fp)) > 0)
    {
        byteswrite = fwrite(buffer, 1, bytesread, dest_fp);
        if (bytesread != byteswrite)
        {
            printf("Error");
            fclose(source_fp);
            fclose(dest_fp);
            exit(1);
        }
    }
    printf("\nSuccessfully written from source to destination");
    fclose(source_fp);
    fclose(dest_fp);
}
