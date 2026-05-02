// Function : FUN_40165458
// Address  : 0x40165458
// Size     : 112 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_40165458(char param_1)

{
  if (((param_1 == '\0') || (DAT_3ffc072c == '\0')) || ((_DAT_3ffc0730 & 8) == 0)) {
    FUN_401676f4(0,0);
    if ((_DAT_3ffc0730 & 0x40) != 0) {
      memw();
      _DAT_3ff730f4 = _DAT_3ff730f4 & 0xffff00ff;
      memw();
    }
  }
  else {
    FUN_401676f4(0,1);
    if ((_DAT_3ffc0730 & 0x40) != 0) {
      memw();
      _DAT_3ff730f4 = _DAT_3ff730f4 & 0xffff00ff | 0x4100;
      memw();
      memw();
    }
  }
  memw();
  return 0;
}

