// Function : FUN_401866cc
// Address  : 0x401866cc
// Size     : 32 bytes


int FUN_401866cc(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 4);
  while ((iVar1 != 0 && (*(int *)(*(int *)(param_1 + 8) + iVar1 * 4 + -4) == 0))) {
    iVar1 = iVar1 + -1;
  }
  return iVar1;
}

