// Function : FUN_4011da74
// Address  : 0x4011da74
// Size     : 25 bytes


void FUN_4011da74(int *param_1)

{
  if (param_1 != (int *)0x0) {
    if (*param_1 != 0) {
      FUN_4010bb10();
    }
    param_1[1] = 0;
    *param_1 = 0;
  }
  memw();
  return;
}

