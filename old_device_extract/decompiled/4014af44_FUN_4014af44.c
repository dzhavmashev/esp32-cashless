// Function : FUN_4014af44
// Address  : 0x4014af44
// Size     : 89 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4014af44(uint param_1)

{
  int iVar1;
  
  if ((param_1 == 0xffffffff) || (0x87 < param_1)) goto LAB_4014af98;
  if ((int)param_1 < 8) {
    if ((_DAT_3ffc8800 == 0) || (*(int *)(_DAT_3ffc8800 + 0xe4) == 0)) goto LAB_4014af98;
    iVar1 = param_1 * 4 + *(int *)(_DAT_3ffc8800 + 0xe4);
  }
  else {
    if (_DAT_3ffc8804 == 0) goto LAB_4014af98;
    iVar1 = *(int *)(((int)(param_1 - 8) >> 3) * 4 + _DAT_3ffc8804 + 0xec);
    if (iVar1 == 0) goto LAB_4014af98;
    iVar1 = (param_1 - 8 & 7) * 4 + iVar1;
  }
  iVar1 = *(int *)(iVar1 + 0x244);
  if (iVar1 != 0) {
    *(char *)(iVar1 + 0x4c) = *(char *)(iVar1 + 0x4c) + '\x01';
    *(ushort *)(iVar1 + 0x2c) = *(ushort *)(iVar1 + 0x2c) & 0xfffd;
    memw();
  }
LAB_4014af98:
  memw();
  return;
}

