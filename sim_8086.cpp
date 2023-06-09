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

    unsigned char input_buffer[2]; // 2 bytes of data
    fread(input_buffer, 1, 2, file_input);

    unsigned char hi_byte = input_buffer[0];
    unsigned char lo_byte = input_buffer[1];

    printf("the value of the lo_byte: %d\n", lo_byte);
    printf("the value of the hi_byte: %d\n", hi_byte);

    unsigned char opcode = hi_byte >> 2;

    printf("the value of the opcode is %d\n", opcode);

    unsigned char d_field = hi_byte & 2;
    unsigned char w_field = hi_byte & 1;

    printf("the value of the d_field is %d\n", d_field);
    printf("the value of the w_field is %d\n", w_field);

    unsigned char mode = lo_byte >> 6;
    unsigned char reg_field = (lo_byte >> 3) & 7;
    unsigned char rm_field = lo_byte & 7;

    unsigned char asm_op;
    unsigned char asm_d;
    unsigned char asm_w;
    unsigned char asm_reg;
    unsigned char asm_rm;


    if (opcode == "34") 
    {
        asm_op = "mov"
    }
    else 
    {
        asm_op = NULL;
    }


    fclose(file_input);
    return(0);

}