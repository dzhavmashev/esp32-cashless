// Function : FUN_40185a40
// Address  : 0x40185a40
// Size     : 37 bytes


void FUN_40185a40(int *param_1,int param_2,int param_3)

{
  if (param_2 == 1) {
    if (*param_1 == 0) {
      *param_1 = param_3;
      memw();
    }
  }
  else if ((param_2 == 4) && (param_1[1] == 0)) {
    param_1[1] = param_3;
    memw();
  }
  return;
}

