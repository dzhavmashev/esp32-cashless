// Function : FUN_40137fb0
// Address  : 0x40137fb0
// Size     : 41 bytes


void FUN_40137fb0(int *param_1)

{
  if (*param_1 != -1) {
    FUN_401409a0(param_1 + 2);
    param_1[0x38] = 0;
    memw();
    FUN_4013ae54(param_1 + 0x39,400);
    *param_1 = -1;
  }
  memw();
  return;
}

