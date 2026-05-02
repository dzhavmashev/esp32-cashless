// Function : FUN_400fe05c
// Address  : 0x400fe05c
// Size     : 230 bytes


void FUN_400fe05c(int *param_1,uint param_2)

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
  memw();
  memw();
  memw();
  memw();
  memw();
  *(uint *)(*param_1 + 0x20) =
       *(uint *)(*param_1 + 0x20) & 0xfe07cfff | (param_2 & 1) << 0xc | (param_2 >> 1 & 1) << 0xd |
       (param_2 >> 2 & 1) << 0x13 | (param_2 >> 3 & 1) << 0x14 | (param_2 >> 4 & 1) << 0x15 |
       (param_2 >> 5 & 1) << 0x16 | (param_2 >> 6 & 1) << 0x17 | (param_2 >> 7 & 1) << 0x18;
  memw();
  return;
}

