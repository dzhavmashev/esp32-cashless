// Function : FUN_401043e0
// Address  : 0x401043e0
// Size     : 44 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_401043e0(int param_1)

{
  _DAT_3ffc810c = param_1 + 2;
  _DAT_3ffc8110 = 0x2e;
  if (_DAT_3ffc8130 != 1) {
    _DAT_3ffc8110 = 0x2c;
  }
  memw();
  (*_DAT_3ffc81e8)(_DAT_3ffc8130 & 0xff,param_1,_DAT_3ffc8110);
  return;
}

