// Function : FUN_4010d2e0
// Address  : 0x4010d2e0
// Size     : 89 bytes


void FUN_4010d2e0(int param_1)

{
  if (((param_1 != 0) && (*(uint *)(param_1 + 0x3c) != 10)) && (1 < *(uint *)(param_1 + 0x3c))) {
    FUN_4010caa8(param_1);
    if (*(int *)(param_1 + 0xa4) != 0) {
      FUN_4010bb10();
      *(undefined4 *)(param_1 + 0xa4) = 0;
    }
    if (*(int *)(param_1 + 0xa0) != 0) {
      memw();
      FUN_4010d2c8(param_1);
    }
    *(undefined2 *)(param_1 + 0x5c) = 0xffff;
    memw();
    memw();
    FUN_4010ce5c(*(undefined4 *)(param_1 + 0x98));
    FUN_4010ce5c(*(undefined4 *)(param_1 + 0x9c));
    *(undefined4 *)(param_1 + 0x98) = 0;
    *(undefined4 *)(param_1 + 0x9c) = 0;
    *(undefined2 *)(param_1 + 0x94) = 0;
    memw();
  }
  memw();
  return;
}

