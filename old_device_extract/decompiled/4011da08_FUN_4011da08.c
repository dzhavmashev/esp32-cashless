// Function : FUN_4011da08
// Address  : 0x4011da08
// Size     : 30 bytes


void FUN_4011da08(int *param_1)

{
  if (param_1 != (int *)0x0) {
    if (*param_1 != 0) {
      FUN_4010bb10();
      param_1[1] = 0;
      *param_1 = 0;
    }
    memw();
    FUN_4010b078(6,param_1);
  }
  return;
}

