// Function : FUN_4018e3a8
// Address  : 0x4018e3a8
// Size     : 75 bytes


void FUN_4018e3a8(undefined4 param_1,uint *param_2)

{
  uint uVar1;
  
  FUN_4018e2e4(param_1,param_2);
  param_2[1] = param_2[1] + param_2[4] * -0xc;
  uVar1 = 0;
  if (0xc < param_2[2]) {
    uVar1 = param_2[2] - 0xc;
  }
  param_2[2] = uVar1;
  uVar1 = 0;
  if (0xc < *param_2) {
    uVar1 = *param_2 - 0xc;
  }
  *param_2 = uVar1;
  uVar1 = 0;
  if (0xc < param_2[3]) {
    uVar1 = param_2[3] - 0xc;
  }
  param_2[3] = uVar1;
  memw();
  return;
}

