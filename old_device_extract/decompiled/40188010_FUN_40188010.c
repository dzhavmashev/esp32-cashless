// Function : FUN_40188010
// Address  : 0x40188010
// Size     : 35 bytes


void FUN_40188010(int param_1,int param_2,undefined1 param_3)

{
  *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 1;
  *(undefined1 *)(*(int *)(param_2 + 0x2c) + 0x13) = 1;
  memw();
  memw();
  FUN_40187fa0(param_2,param_3);
  return;
}

