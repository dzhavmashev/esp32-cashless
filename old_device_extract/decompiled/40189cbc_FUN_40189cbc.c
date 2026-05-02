// Function : FUN_40189cbc
// Address  : 0x40189cbc
// Size     : 30 bytes


void FUN_40189cbc(undefined4 *param_1,int param_2,int param_3)

{
  param_2 = param_2 - (int)param_1;
  while( true ) {
    param_3 = param_3 + -1;
    if (param_3 == -1) break;
    memw();
    *param_1 = *(undefined4 *)((int)param_1 + param_2);
    param_1 = param_1 + 1;
  }
  memw();
  return;
}

