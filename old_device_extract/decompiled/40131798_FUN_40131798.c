// Function : FUN_40131798
// Address  : 0x40131798
// Size     : 64 bytes


int FUN_40131798(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  if (*(int *)(param_1 + 4) != 0) {
    iVar1 = *(int *)(param_1 + 4);
    do {
      iVar2 = iVar1;
      iVar1 = iVar2 + -1;
      if (iVar1 == 0) break;
    } while (*(int *)(*(int *)(param_1 + 8) + iVar1 * 4) == 0);
    iVar1 = iVar2 * 0x20 - (uint)((*(uint *)(*(int *)(param_1 + 8) + iVar1 * 4) & 0x80000000) == 0);
  }
  return iVar1;
}

