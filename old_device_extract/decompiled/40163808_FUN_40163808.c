// Function : FUN_40163808
// Address  : 0x40163808
// Size     : 141 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40163808(uint param_1)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  param_1 = param_1 & 0xff;
  bVar1 = *(byte *)(_DAT_3ffc0034 + param_1 + 0x18);
  uVar2 = (uint)bVar1;
  if (((*(uint *)(_DAT_3ffc0034 + param_1 * 4 + 4) & 1 << (bVar1 & 0x1f)) != 0) &&
     (iVar3 = _DAT_3ffc0034 + uVar2 * 0x30, *(char *)(iVar3 + 0x31) != '\0')) {
    *(undefined1 *)(iVar3 + 0x31) = 0;
    memw();
    if ((*(int *)(iVar3 + 0x20) == 0) && (*(int *)(iVar3 + 0x34) == 0)) {
      memw();
      FUN_40163728(uVar2,param_1);
    }
    uVar4 = *(uint *)(_DAT_3ffc0034 + param_1 * 4 + 4);
    if (uVar4 != 0) {
      uVar2 = 1 << 0x20 - (0x20 - (uVar2 & 0x1f));
      uVar5 = uVar2 - 1 & uVar4;
      uVar2 = (uVar2 ^ 0xffffffff) & (uVar4 ^ uVar5);
      if (uVar2 == 0) {
        if (uVar5 == 0) goto LAB_40163890;
        uVar2 = -uVar5 & uVar5;
      }
      else {
        uVar2 = -uVar2 & uVar2;
      }
      *(char *)(_DAT_3ffc0034 + param_1 + 0x18) = '\x1f' - (char)LZCOUNT(uVar2);
      memw();
    }
  }
LAB_40163890:
  memw();
  return;
}

