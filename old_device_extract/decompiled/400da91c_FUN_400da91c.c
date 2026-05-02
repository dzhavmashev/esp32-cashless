// Function : FUN_400da91c
// Address  : 0x400da91c
// Size     : 85 bytes


int FUN_400da91c(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iStack_28;
  int iStack_24;
  
  if (param_2 != 0) {
    iStack_28 = param_2;
    iStack_24 = param_3;
    iVar1 = FUN_40183b74(param_1,&iStack_28);
    if (iVar1 != 0) {
      return iVar1;
    }
    iVar1 = *(int *)(param_1 + 4);
    uVar3 = iVar1 + iStack_24 + 1;
    if (*(uint *)(param_1 + 8) < uVar3) {
      *(undefined1 *)(param_1 + 0x10) = 1;
      return 0;
    }
    *(uint *)(param_1 + 4) = uVar3;
    iVar2 = 0;
    if (iVar1 != 0) {
      for (; iStack_24 != iVar2; iVar2 = iVar2 + 1) {
        *(undefined1 *)(iVar1 + iVar2) = *(undefined1 *)(param_2 + iVar2);
      }
      *(undefined1 *)(iVar1 + iStack_24) = 0;
      return iVar1;
    }
  }
  return 0;
}

