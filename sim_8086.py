import sys

filename = sys.argv[1]

file = open(filename, "rb")

bin_data = file.read()
int_bin_data = int.from_bytes(bin_data, "big")

hi_byte = int_bin_data >> 8
lo_byte = int_bin_data & 255

opcode = hi_byte >> 2

# 1: the reg field identifies the destination of op
# 0: the reg field identifies the source of op
d_field = hi_byte & 2

# 1: use word size
# 0: use byte size
w_field = hi_byte & 1

# 
mode = lo_byte >> 6


reg_field = (lo_byte >> 3) & 7
rm_field = lo_byte & 7

register_lookup_w1 = {
    0: "AX",
    1: "CX",
    2: "DX",
    3: "BX",
    4: "SP",
    5: "BP",
    6: "SI", 
    7: "DI"
}

register_lookup_w0 = {
    0: "AL",
    1: "CL",
    2: "DL",
    3: "BL",
    4: "AH",
    5: "CH",
    6: "DH", 
    7: "BH"
}



if opcode == 34:
    asm_op = "mov"
else:
    raise Exception("opcode not found!")

asm_reg = register_lookup_w1[reg_field]
asm_rm = register_lookup_w1[rm_field]


if d_field:
    if w_field:
        raise Exception("not implemented yet")
    else:
        raise Exception("not implemented yet")
else:
    if w_field:
        asm_instruction = f"{asm_op} {register_lookup_w1[rm_field]}, {register_lookup_w1[reg_field]}"
    else: 
        asm_instruction = f"{asm_op} {asm_rm}, {asm_reg}"

with open("py_output_asm.asm", "w") as out_file:
    out_file.write(asm_instruction)



file.close()