// Function : FUN_400e995c
// Address  : 0x400e995c
// Size     : 22 bytes


int FUN_400e995c(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x34);
  if (iVar1 < 0) {
    iVar1 = FUN_400f0834(param_1);
    *(int *)(param_1 + 0x34) = iVar1;
  }
  return iVar1;
}

