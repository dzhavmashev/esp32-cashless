// Function : FUN_400d9a08
// Address  : 0x400d9a08
// Size     : 33 bytes


uint FUN_400d9a08(int param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = (*(code *)&LAB_40183a7b_1)(param_1 + 0x3c);
  uVar2 = 0;
  if (iVar1 != 0) {
    uVar2 = (uint)((*(int *)(param_1 + 0x4c) >> 0x1f) - *(int *)(param_1 + 0x4c)) >> 0x1f;
  }
  return uVar2;
}

