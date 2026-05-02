// Function : FUN_40187d04
// Address  : 0x40187d04
// Size     : 102 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool FUN_40187d04(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (((DAT_3ffc1a44 == '\0') || (memw(), DAT_3ffc1a3c != '\0')) || (_DAT_3ffc1a40 == 0)) {
    memw();
    iVar1 = _DAT_3ff73c00 + _DAT_3ffc1a30;
  }
  else {
    iVar1 = (**(code **)(_DAT_3ffc1a34 + 0x110))();
  }
  iVar2 = _DAT_3ffbffe8;
  if ((**(uint **)(param_1 + 0x2c) & 0x400000) != 0) {
    iVar2 = _DAT_3ffbffe0;
  }
  return (uint)((iVar2 + -5) * 0x400) < iVar1 - (*(uint **)(param_1 + 0x2c))[6];
}

