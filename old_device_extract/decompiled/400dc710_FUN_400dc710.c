// Function : FUN_400dc710
// Address  : 0x400dc710
// Size     : 39 bytes


int FUN_400dc710(int param_1,int param_2,int param_3)

{
  for (; param_1 != param_2; param_1 = param_1 + 0x14) {
    FUN_400f0d4c(param_3,param_1);
    *(undefined4 *)(param_3 + 0x10) = *(undefined4 *)(param_1 + 0x10);
    param_3 = param_3 + 0x14;
  }
  return param_3;
}

