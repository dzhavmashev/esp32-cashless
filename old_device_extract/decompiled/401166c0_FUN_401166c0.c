// Function : FUN_401166c0
// Address  : 0x401166c0
// Size     : 39 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_401166c0(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = 0;
  if (((*(byte *)(param_1 + 0xeb) & 1) != 0) && (*(int *)(param_1 + 4) != 0)) {
    uVar1 = 1;
    if (*(int *)(param_1 + 4) != _DAT_3ffc83e4) {
      iVar2 = FUN_4018549c();
      uVar1 = 1;
      if (iVar2 == 0) {
        uVar1 = 0;
      }
    }
  }
  return uVar1;
}

