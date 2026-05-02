// Function : FUN_401063cc
// Address  : 0x401063cc
// Size     : 34 bytes


void FUN_401063cc(int param_1,undefined4 param_2,undefined4 param_3)

{
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + -1;
  memw();
  (**(code **)(param_1 + 0x10))(param_2,*(undefined4 *)(param_1 + 0x14),param_3);
  FUN_4010528c(param_2,0x74);
  return;
}

