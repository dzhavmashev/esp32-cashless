// Function : FUN_400f1d5c
// Address  : 0x400f1d5c
// Size     : 40 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400f1d5c(uint param_1)

{
  do {
    memw();
    memw();
    memw();
  } while ((_DAT_3ff4001c >> 0x10 & 0xff) == 0x80);
  memw();
  _DAT_60000000 = param_1 & 0xff;
  return;
}

