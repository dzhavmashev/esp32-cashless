// Function : FUN_40185408
// Address  : 0x40185408
// Size     : 17 bytes


void FUN_40185408(int param_1,undefined4 param_2,undefined4 param_3)

{
  if (param_1 != 0) {
    *(undefined4 *)(param_1 + 0x48) = param_2;
    *(undefined4 *)(param_1 + 0x4c) = param_3;
  }
  memw();
  return;
}

