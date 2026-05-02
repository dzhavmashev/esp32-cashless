// Function : FUN_400fac70
// Address  : 0x400fac70
// Size     : 30 bytes


void FUN_400fac70(undefined4 *param_1,int param_2)

{
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = param_2;
  *param_1 = &DAT_3f40d3a8;
  if (param_2 == 0) {
    memw();
    (*(code *)&SUB_40094bc8)();
  }
  return;
}

