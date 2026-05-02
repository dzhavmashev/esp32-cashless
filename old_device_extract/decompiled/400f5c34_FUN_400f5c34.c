// Function : FUN_400f5c34
// Address  : 0x400f5c34
// Size     : 63 bytes


undefined4 FUN_400f5c34(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  iVar2 = *(int *)(param_1 * 4 + 0x3ffc5588);
  iVar1 = *(int *)(iVar2 + 0xa8);
  while (*(int *)(iVar2 + 0xa4) != iVar1) {
    piVar4 = (int *)(*(int *)(iVar2 + 0xb0) + iVar1 * 4);
    iVar1 = iVar1 + 1;
    iVar3 = *piVar4 - param_2;
    *piVar4 = iVar3;
    if (*(int *)(iVar2 + 0xac) <= iVar1) {
      iVar1 = 0;
    }
    if (iVar3 < 0) {
      *(int *)(iVar2 + 0xa8) = iVar1;
      memw();
    }
  }
  return 0;
}

