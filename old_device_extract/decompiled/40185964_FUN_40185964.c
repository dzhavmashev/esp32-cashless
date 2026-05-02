// Function : FUN_40185964
// Address  : 0x40185964
// Size     : 13 bytes


void FUN_40185964(int param_1,undefined4 param_2,undefined4 param_3)

{
  *(undefined4 *)(param_1 + 0x68) = param_2;
  *(undefined4 *)(param_1 + 0x6c) = param_3;
  memw();
  return;
}

