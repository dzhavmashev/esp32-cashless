// Function : FUN_4010be0c
// Address  : 0x4010be0c
// Size     : 54 bytes


void FUN_4010be0c(int param_1)

{
  if (param_1 != 0) {
    FUN_4011b020();
    *(char *)(param_1 + 0xe) = *(char *)(param_1 + 0xe) + '\x01';
    memw();
    memw();
    FUN_4011b040();
    if (*(char *)(param_1 + 0xe) == '\0') {
      (*(code *)&SUB_40094c54)("if_init",0x34b,"buf_cat","== NULL");
    }
  }
  return;
}

