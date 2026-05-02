// Function : FUN_40150358
// Address  : 0x40150358
// Size     : 121 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_40150358(int param_1)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  iVar2 = _DAT_3ffc8804;
  iVar4 = 0x102;
  if ((param_1 != 0) && (_DAT_3ffc8804 != 0)) {
    iVar4 = *(int *)(param_1 + 0xc);
    _DAT_3ffc7998 = (uint)*(byte *)(param_1 + 8);
    if (iVar4 == 0) {
      uVar3 = FUN_401463ac(0);
      iVar4 = -((uVar3 ^ 1) & 0xff);
    }
    else {
      bVar1 = *(byte *)(_DAT_3ffbfc54 + 0x3f6);
      uVar3 = 1;
      memw();
      for (; uVar3 <= bVar1; uVar3 = uVar3 + 1 & 0xff) {
        iVar5 = *(int *)(uVar3 * 4 + iVar2 + 0xec);
        if ((iVar5 != 0) && (iVar5 = (*(code *)&SUB_4008b33c)(iVar4,iVar5 + 4,6), iVar5 == 0)) {
          iVar4 = FUN_40146aac(uVar3);
          goto LAB_401503c6;
        }
      }
      iVar4 = -1;
LAB_401503c6:
      _DAT_3ffc7998 = 0;
    }
  }
  memw();
  return iVar4;
}

