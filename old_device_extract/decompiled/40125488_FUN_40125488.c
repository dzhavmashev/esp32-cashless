// Function : FUN_40125488
// Address  : 0x40125488
// Size     : 28 bytes


void FUN_40125488(undefined4 param_1,int param_2)

{
  if (param_2 != 0) {
    *(undefined4 *)(param_2 + 0x188) = 1;
    *(undefined4 *)(param_2 + 0x114) = 0;
  }
  memw();
  FUN_40125058(param_2);
  return;
}

