// Function : FUN_401844c8
// Address  : 0x401844c8
// Size     : 25 bytes


int FUN_401844c8(int param_1,uint param_2)

{
  if (*(uint *)(param_1 + 0xc) <= param_2) {
    param_2 = (*(uint *)(param_1 + 0xc) + param_2) - *(int *)(param_1 + 0x10);
  }
  return *(int *)(param_1 + 4) + param_2;
}

