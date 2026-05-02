// Function : FUN_400e4a64
// Address  : 0x400e4a64
// Size     : 36 bytes


void FUN_400e4a64(int param_1,undefined4 param_2,int *param_3)

{
  *(undefined4 *)(param_1 + 8) = param_2;
  FUN_400f0d18(param_1 + 0xc,param_3);
  if ((*(byte *)((int)param_3 + 0xf) & 0x80) == 0) {
    param_3 = (int *)*param_3;
  }
  FUN_400f06a4(0x3ffc5490,"ackend.",param_2,param_3);
  return;
}

