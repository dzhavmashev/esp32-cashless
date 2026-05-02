// Function : FUN_401858e4
// Address  : 0x401858e4
// Size     : 51 bytes


void FUN_401858e4(byte param_1,int param_2,int param_3,byte *param_4)

{
  if (param_3 == 1) {
    if (param_2 == 2) {
      param_2 = 1;
    }
    *param_4 = param_1 - 2 ^ 0xff;
    param_2 = -param_2;
  }
  else {
    *param_4 = param_1;
    memw();
    memw();
  }
  param_4[1] = (byte)param_2;
  memw();
  memw();
  return;
}

