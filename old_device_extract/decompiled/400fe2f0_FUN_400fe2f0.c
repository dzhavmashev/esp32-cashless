// Function : FUN_400fe2f0
// Address  : 0x400fe2f0
// Size     : 49 bytes


void FUN_400fe2f0(undefined4 *param_1)

{
  if ((undefined1 *)*param_1 == &DAT_3ff40000) {
    memw();
    memw();
    memw();
    uRam3ff40020 = uRam3ff40020 & 0xfffbffff;
    memw();
  }
  memw();
  return;
}

