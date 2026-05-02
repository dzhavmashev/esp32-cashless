// Function : FUN_4016a6c8
// Address  : 0x4016a6c8
// Size     : 214 bytes


/* WARNING: Removing unreachable block (ram,0x4016a709) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4016a6c8(void)

{
  int iVar1;
  int iVar2;
  short sVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  undefined1 auStack_40 [16];
  uint uStack_30;
  
  if ((_DAT_3ffca4c8 & 0x4000) == 0) {
    uStack_30 = (uint)(-1 < DAT_3ffca53c + 0x2b) * (DAT_3ffca53c + 0x2b) & 0xffff;
    iVar2 = 0;
    do {
      uVar5 = 0x20;
      iVar1 = 4;
      if (iVar2 != 0) {
        uVar5 = 0x30;
        iVar1 = 0x10;
      }
      sVar3 = 0;
      if ((_DAT_3ffc073e & 1) != 0) {
        sVar3 = 6;
      }
      sVar3 = ((_DAT_3ffc073e >> 6 & 0xff) + sVar3 & 0xff) * -4 + (short)uStack_30;
      iVar4 = (int)sVar3;
      if (iVar4 < 0) {
        iVar4 = 0;
        sVar3 = 0;
      }
      else if (0x78 < iVar4) {
        sVar3 = 0x78;
        iVar4 = 0x78;
      }
      iVar6 = iVar2 + 0x1a;
      iVar2 = iVar2 + 1;
      FUN_4016bffc(uVar5,iVar1 * 2 + 0x3ffca4d4,&DAT_3ffca4c8 + iVar6 * 2,0x80,iVar4,0);
    } while (iVar2 != 2);
    FUN_4016bffc(uVar5,auStack_40,&DAT_3ffca514,0x80,
                 (uint)(-1 < (short)(sVar3 + -0x28)) * (int)(short)(sVar3 + -0x28),2);
    _DAT_3ffca4c8 = _DAT_3ffca4c8 | 0x4000;
  }
  return;
}

