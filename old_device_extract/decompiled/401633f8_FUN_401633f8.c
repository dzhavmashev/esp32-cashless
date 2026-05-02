// Function : FUN_401633f8
// Address  : 0x401633f8
// Size     : 132 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_401633f8(uint param_1)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  
  param_1 = param_1 & 0xff;
  uVar6 = 4;
  bVar1 = *(byte *)(_DAT_3ffc0034 + param_1 * 0x30 + 0x2c);
  if (bVar1 < 8) {
    if ((bVar1 == 0) || (bVar1 == 3)) {
      uVar6 = 2;
    }
    else {
      uVar6 = 3;
      if ((2 < bVar1) && (uVar6 = 1, 5 < bVar1)) {
        uVar6 = 0;
      }
    }
  }
  FUN_40187ce0(uVar6);
  iVar2 = _DAT_3ffc0034;
  iVar5 = _DAT_3ffc0034 + param_1 * 0x30;
  iVar3 = 0;
  if (((*(char *)(iVar5 + 0x29) == '\0') &&
      (iVar3 = *(int *)(_DAT_3ffc0034 + (param_1 + 1) * 0x30 + 4), iVar3 == 0)) &&
     (iVar4 = *(int *)(iVar5 + 0x20), iVar4 != 0)) {
    iVar3 = *(int *)(iVar4 + 0x28);
    *(int *)(iVar5 + 0x20) = iVar3;
    if (iVar3 == 0) {
      *(uint *)(iVar5 + 0x24) = iVar2 + param_1 * 0x30 + 0x20;
    }
    *(undefined4 *)(iVar4 + 0x28) = 0;
    memw();
    FUN_40187d70(iVar4);
    return iVar4;
  }
  return iVar3;
}

