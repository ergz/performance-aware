#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{

    if (argc == 1) 
    {
        printf("no assembled file was provided to program\n");
        exit(1);
    }
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

    // 1: the reg field identifies the destination of op
    // 0: the reg field identifies the source of op
    uint8_t d_field = hi_byte & 2;
    
    // 1: use word size
    // 0: use byte size
    uint8_t w_field = hi_byte & 1;

    printf("the value of the d_field is %d\n", d_field);
    printf("the value of the w_field is %d\n", w_field);

    uint8_t mode = lo_byte >> 6;
    uint8_t reg_field = (lo_byte >> 3) & 7;
    uint8_t rm_field = lo_byte & 7;

    char *asm_op;
    // int8_t asm_d;
    // int8_t asm_w;
    char *asm_reg;
    // int8_t asm_rm;

    switch (opcode) {
        case 34: {
            asm_op = "mov";
        } break;
        default: {
            asm_op = NULL;
        } break;
    }

    char *asm_rm;
    switch (reg_field)
    {
        case 0: {
            asm_reg = "ax";
        } break;
        case 1: {
            asm_reg = "cx";
          } break;
        case 2: {
            asm_reg = "dx";
          } break;
        case 3: {
            asm_reg = "bx";
          } break;
        case 4: {
            asm_reg = "sp";
          } break;
        case 5: {
            asm_reg = "bp";
          } break;
        case 6: {
            asm_reg = "si";
        } break;
        case 7: {
            asm_reg = "di";
        } break; 
    }

    switch (rm_field)
    {
        case 0: {
            asm_rm = "ax";
        } break;
        case 1: {
            asm_rm = "cx";
          } break;
        case 2: {
            asm_rm = "dx";
          } break;
        case 3: {
            asm_rm = "bx";
          } break;
        case 4: {
            asm_rm = "sp";
          } break;
        case 5: {
            asm_rm = "bp";
          } break;
        case 6: {
            asm_rm = "si";
        } break;
        case 7: {
            asm_rm = "di";
        } break; 
    }

    if (asm_op == NULL) 
    {
        printf("opcode not implemented or does not exist\n");
        exit(1);
    }

    char asm_str[20];


    if (d_field)  
    {
        // case when the reg field identifies the destination
        if (w_field) 
        {
            // use word size 
            printf("not implemented yet\n");
            exit(1);            
        }
        else 
        {
            // use byte size
            printf("not implemented yet\n");
            exit(1);    
        }
    }
    else
    {  
        // case when the reg field identifies the source
        if (w_field) 
        {
            // use word size 
            sprintf(asm_str, "%s %s, %s", asm_op, asm_rm, asm_reg);
        }
        else 
        {
            // use byte size
            printf("not implemented yet\n");
            exit(1);
        }

    }

    fclose(file_input);

    FILE *f_out;
    f_out = fopen("c_asm.asm", "w");
    fprintf(f_out, asm_str);
    fclose(f_out);



    return(0);

}