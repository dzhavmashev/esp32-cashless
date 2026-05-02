// Function : FUN_400f1d84
// Address  : 0x400f1d84
// Size     : 51 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400f1d84(uint param_1)

{
  do {
    memw();
    memw();
    memw();
  } while ((_DAT_3ff5001c >> 0x10 & 0xff) == 0x80);
  memw();
  _DAT_60010000 = param_1 & 0xff;
  return;
}

