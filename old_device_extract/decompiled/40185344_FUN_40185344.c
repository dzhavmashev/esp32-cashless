// Function : FUN_40185344
// Address  : 0x40185344
// Size     : 28 bytes


void FUN_40185344(int *param_1,uint param_2,undefined2 *param_3)

{
  for (; (param_1 != (int *)0x0 && (*(ushort *)((int)param_1 + 10) <= param_2));
      param_1 = (int *)*param_1) {
    param_2 = param_2 - *(ushort *)((int)param_1 + 10) & 0xffff;
  }
  if (param_3 != (undefined2 *)0x0) {
    *param_3 = (short)param_2;
    memw();
  }
  memw();
  return;
}

