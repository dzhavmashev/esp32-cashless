// Function : FUN_400fe6f8
// Address  : 0x400fe6f8
// Size     : 36 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400fe6f8(uint param_1)

{
  memw();
  memw();
  _DAT_3ff4803c = _DAT_3ff4803c & 0xffffff7f | (param_1 & 1) << 7;
  memw();
  return;
}

