// Function : FUN_40186044
// Address  : 0x40186044
// Size     : 50 bytes


int FUN_40186044(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  iVar1 = 0;
  while( true ) {
    if (*(int *)(param_1 + 4) == iVar1) {
      return 0;
    }
    if ((*(uint *)(*(int *)(param_1 + 8) + iVar1 * 4) & 1) != 0) break;
    iVar2 = iVar2 + 1;
    iVar1 = iVar1 + 1;
  }
  return iVar2;
}

