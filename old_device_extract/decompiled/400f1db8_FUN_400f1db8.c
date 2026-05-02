// Function : FUN_400f1db8
// Address  : 0x400f1db8
// Size     : 59 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400f1db8(uint param_1)

{
  do {
    memw();
    memw();
    memw();
  } while ((_DAT_3ff6e01c >> 0x10 & 0xff) == 0x80);
  memw();
  _DAT_6002e000 = param_1 & 0xff;
  return;
}

