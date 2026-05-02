// Function : FUN_401673e4
// Address  : 0x401673e4
// Size     : 57 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_401673e4(int param_1)

{
  if (param_1 == 1) {
    memw();
    return _DAT_3ff73cc0 >> 0x10 & 0x7ff;
  }
  if (param_1 != 0) {
    if (param_1 != 2) {
      return 0;
    }
    memw();
    return _DAT_3ff73cc8 & 0xf;
  }
  memw();
  return _DAT_3ff73cc0 & 0x7ff;
}

