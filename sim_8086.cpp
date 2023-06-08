#include <stdio.h>

int main()
{
    FILE *file_input;
    file_input = fopen("listing_0037_single_register_mov", "rb");

    if (file_input == NULL) 
    {
        printf("file not found\n");
    }

    printf("file found\n");

    char input_buffer[2]; // 2 bytes of data
    fread(input_buffer, 1, 2, file_input);





    fclose(file_input);
    return(0);

}