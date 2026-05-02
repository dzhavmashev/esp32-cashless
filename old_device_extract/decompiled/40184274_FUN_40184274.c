// Function : FUN_40184274
// Address  : 0x40184274
// Size     : 19 bytes


void FUN_40184274(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  *param_1 = param_2;
  param_1[1] = param_3;
  param_1[2] = 0;
  *(undefined1 *)(param_1 + 3) = 1;
  param_1[6] = 0;
  return;
}

