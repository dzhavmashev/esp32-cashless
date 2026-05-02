// Function : FUN_400fe63c
// Address  : 0x400fe63c
// Size     : 185 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400fe63c(byte *param_1)

{
  memw();
  memw();
  memw();
  memw();
  memw();
  memw();
  memw();
  memw();
  memw();
  memw();
  memw();
  memw();
  memw();
  memw();
  memw();
  _DAT_3ff480d4 =
       (param_1[3] & 1) << 0xe | (param_1[4] & 1) << 0xf | 0x3ff0000 | (param_1[2] & 1) << 0x1a |
       (*param_1 & 7) << 0x1b | (param_1[1] & 1) << 0x1e;
  memw();
  return;
}

