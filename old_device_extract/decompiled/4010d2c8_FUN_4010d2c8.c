// Function : FUN_4010d2c8
// Address  : 0x4010d2c8
// Size     : 21 bytes


void FUN_4010d2c8(int param_1)

{
  if (*(int *)(param_1 + 0xa0) != 0) {
    FUN_4010ce5c();
    *(undefined4 *)(param_1 + 0xa0) = 0;
  }
  memw();
  return;
}

