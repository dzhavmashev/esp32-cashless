// Function : FUN_401102b4
// Address  : 0x401102b4
// Size     : 42 bytes


bool FUN_401102b4(int param_1)

{
  if (param_1 == 0) {
    (*(code *)&SUB_40094c54)("lid pcb",0x59a,"prepare","id pbuf");
  }
  return *(char *)(*(int *)(param_1 + 4) + 0xe) != '\x01';
}

