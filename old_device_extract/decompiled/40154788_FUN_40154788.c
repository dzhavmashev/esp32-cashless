// Function : FUN_40154788
// Address  : 0x40154788
// Size     : 51 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_40154788(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = 0;
  iVar1 = 0;
  for (iVar2 = _DAT_3ffc8804; (uint)*(byte *)(_DAT_3ffbfc54 + 0x3f6) * 4 + _DAT_3ffc8804 != iVar2;
      iVar2 = iVar2 + 4) {
    iVar4 = *(int *)(iVar2 + 0xf0);
    if ((iVar4 != 0) && (iVar3 < *(int *)(iVar4 + 0x108))) {
      iVar1 = iVar4;
      iVar3 = *(int *)(iVar4 + 0x108);
    }
  }
  return iVar1;
}

