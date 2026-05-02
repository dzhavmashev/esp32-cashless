// Function : FUN_400fb4e4
// Address  : 0x400fb4e4
// Size     : 40 bytes


int FUN_400fb4e4(int param_1)

{
  int iVar1;
  
  iVar1 = 4000;
  if (((*(int *)(param_1 + 0xc) != -1) && (iVar1 = 0, *(int *)(param_1 + 0xc) != -4)) &&
     (*(uint *)(param_1 + 0x38) < 0x7d)) {
    iVar1 = *(uint *)(param_1 + 0x38) * -0x20 + 4000;
  }
  return iVar1;
}

