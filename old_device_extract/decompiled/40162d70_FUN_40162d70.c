// Function : FUN_40162d70
// Address  : 0x40162d70
// Size     : 53 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_40162d70(uint param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar1 = _DAT_3ffc0034;
  iVar2 = 0;
  if ((param_1 & 0xff) < 0x10) {
    iVar3 = (param_1 & 0xff) * 0x30;
    iVar4 = _DAT_3ffc0034 + iVar3;
    iVar2 = *(int *)(iVar4 + 0x20);
    if (iVar2 != 0) {
      iVar5 = *(int *)(iVar2 + 0x28);
      *(int *)(iVar4 + 0x20) = iVar5;
      if (iVar5 == 0) {
        *(int *)(iVar4 + 0x24) = iVar1 + iVar3 + 0x20;
      }
      *(undefined4 *)(iVar2 + 0x28) = 0;
    }
  }
  memw();
  return iVar2;
}

