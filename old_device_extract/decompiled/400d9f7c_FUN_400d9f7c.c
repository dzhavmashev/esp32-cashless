// Function : FUN_400d9f7c
// Address  : 0x400d9f7c
// Size     : 69 bytes


void FUN_400d9f7c(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  *param_1 = param_2;
  param_1[1] = param_3;
  param_1[2] = param_4;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  *(undefined2 *)(param_1 + 7) = 0;
  FUN_400f0be8(param_1 + 8,&DAT_3f42161d);
  param_1[0xc] = 0;
  param_1[0xf] = param_1[0x11];
  param_1[0xd] = 0;
  param_1[0x10] = 10000;
  param_1[0xe] = 0;
  param_1[0x11] = 5000;
  param_1[0x15] = 0;
  param_1[0x12] = 300000;
  param_1[0x19] = 0;
  return;
}

