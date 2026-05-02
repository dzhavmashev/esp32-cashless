// Function : FUN_4015560c
// Address  : 0x4015560c
// Size     : 45 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4015560c(uint param_1)

{
  int iVar1;
  
  iVar1 = _DAT_3ffbfd50;
  param_1 = param_1 & 0xff;
  if (param_1 < 3) {
    *(undefined1 *)(_DAT_3ffbfd50 + param_1 + 0x98) = 0;
    memw();
    *(undefined4 *)(param_1 * 0x24 + iVar1 + 0x50) = 0;
  }
  memw();
  return;
}

