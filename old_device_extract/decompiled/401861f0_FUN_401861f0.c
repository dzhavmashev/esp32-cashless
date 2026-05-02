// Function : FUN_401861f0
// Address  : 0x401861f0
// Size     : 40 bytes


int FUN_401861f0(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *param_1;
  iVar1 = ((iVar3 + 2) * 2 & 8U) + iVar3;
  iVar2 = 3;
  do {
    iVar2 = iVar2 + -1;
    iVar1 = iVar1 * (2 - iVar3 * iVar1);
  } while (iVar2 != 0);
  return -iVar1;
}

