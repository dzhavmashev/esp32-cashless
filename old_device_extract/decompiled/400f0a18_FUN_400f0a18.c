// Function : FUN_400f0a18
// Address  : 0x400f0a18
// Size     : 30 bytes


void FUN_400f0a18(undefined4 *param_1)

{
  *(byte *)((int)param_1 + 0xf) = *(byte *)((int)param_1 + 0xf) & 0x7f;
  *param_1 = 0;
  param_1[1] = 0;
  FUN_40184790(param_1,0);
  return;
}

