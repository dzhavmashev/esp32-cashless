// Function : FUN_401481f0
// Address  : 0x401481f0
// Size     : 42 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_401481f0(int param_1)

{
  int iVar1;
  
  if ((_DAT_3ffc8804 != 0) && (param_1 != 0)) {
    iVar1 = *(int *)(*(int *)(param_1 + 4) + 4);
    if ((**(uint **)(param_1 + 0x2c) & 0x40000) != 0) {
      iVar1 = iVar1 + 4;
    }
    iVar1 = FUN_40187c28(iVar1 + 4);
    if (iVar1 != 0) {
      FUN_40154b74(iVar1,param_1);
    }
  }
  return;
}

