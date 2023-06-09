#include <stdio.h>
#include <stdint.h>

int main()
{
    FILE *file_input;
    file_input = fopen("listing_0037_single_register_mov", "rb");

    if (file_input == NULL) 
    {
        printf("file not found\n");
    }

    printf("file found\n");

    uint8_t input_buffer[2]; // 2 bytes of data
    fread(input_buffer, 1, 2, file_input);

    uint8_t hi_byte = input_buffer[0];
    uint8_t lo_byte = input_buffer[1];

    printf("the value of the lo_byte: %d\n", lo_byte);
    printf("the value of the hi_byte: %d\n", hi_byte);

    uint8_t opcode = hi_byte >> 2;

    printf("the value of the opcode is %d\n", opcode);

    uint8_t d_field = hi_byte & 2;
    uint8_t w_field = hi_byte & 1;

    printf("the value of the d_field is %d\n", d_field);
    printf("the value of the w_field is %d\n", w_field);

    uint8_t mode = lo_byte >> 6;
    uint8_t reg_field = (lo_byte >> 3) & 7;
    uint8_t rm_field = lo_byte & 7;

    char *asm_op;
    // int8_t asm_d;
    // int8_t asm_w;
    // int8_t asm_reg;
    // int8_t asm_rm;

    switch (opcode) {
        case 34: {
            asm_op = "mon";
        } break;
        default: {
            asm_op = NULL
        }
    }

    if (asm_op == NULL) 
    {
        printf("opcode not implemented or does not exist\n");
        exit(1);
    }





    fclose(file_input);
    return(0);

}