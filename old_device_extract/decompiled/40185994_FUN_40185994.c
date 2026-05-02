// Function : FUN_40185994
// Address  : 0x40185994
// Size     : 13 bytes


void FUN_40185994(int param_1,undefined4 param_2,undefined4 param_3)

{
  *(undefined4 *)(param_1 + 0xa4) = param_2;
  *(undefined4 *)(param_1 + 0xa8) = param_3;
  memw();
  return;
}

