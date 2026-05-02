// Function : FUN_4018419c
// Address  : 0x4018419c
// Size     : 20 bytes


void FUN_4018419c(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  *param_1 = param_2;
  param_1[1] = param_3;
  param_1[2] = param_4;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = param_1 + 4;
  param_1[7] = param_1 + 4;
  param_1[8] = 0;
  return;
}

