#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *img;  // declare variable
    if (argc != 2)
    {
        printf("Usage: ./recover image");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");  // open the file to read
    if (file == NULL)
    {
        return 1;
    }
    // char *buffer = malloc(512);
    unsigned char *buffer = malloc(512);
    int file_number = 0;
    char filename[10];

    while (fread(buffer, 512, 1, file))  // read the file to search for jpegs files
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            sprintf(filename, "%03d.jpg", file_number);
            img = fopen(filename, "w");

            if (img == NULL)
            {
                fclose(file);
                free(buffer);
                return 1;
            }
            file_number ++;
        }
        if (file_number > 0)
        {
            fwrite(buffer, 512, 1, img);    // write the data
        }
    }
    fclose(img);
    fclose(file);
    return 0;

}
