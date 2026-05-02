// Function : FUN_4016677c
// Address  : 0x4016677c
// Size     : 35 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_4016677c(int param_1)

{
  memw();
  memw();
  _DAT_3ff73c58 = _DAT_3ff73c58 & 0x3fffffff | param_1 << 0x1e;
  memw();
  return 0;
}

