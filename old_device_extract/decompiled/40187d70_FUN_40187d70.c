// Function : FUN_40187d70
// Address  : 0x40187d70
// Size     : 71 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40187d70(int param_1)

{
  int iVar1;
  int iVar2;
  uint *puVar3;
  
  if (DAT_3ffc1a44 == '\0') {
    puVar3 = *(uint **)(param_1 + 0x2c);
    memw();
    iVar1 = _DAT_3ffbffec;
    iVar2 = _DAT_3ffbffe8;
    if ((*puVar3 & 0x400000) != 0) {
      iVar1 = _DAT_3ffbffe4;
      iVar2 = _DAT_3ffbffe0;
    }
    if ((uint)((iVar2 - iVar1) * 0x400) < (_DAT_3ff73c00 + _DAT_3ffc1a30) - puVar3[6]) {
      puVar3[6] = _DAT_3ff73c00 + _DAT_3ffc1a30 + (iVar2 - iVar1) * -0x400;
    }
  }
  memw();
  return;
}

