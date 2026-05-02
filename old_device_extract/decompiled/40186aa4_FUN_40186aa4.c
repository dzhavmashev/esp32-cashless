// Function : FUN_40186aa4
// Address  : 0x40186aa4
// Size     : 26 bytes


void FUN_40186aa4(int param_1,char param_2,int param_3)

{
  if (param_3 != 0) {
    if (param_3 != 1) goto LAB_40186aba;
    param_2 = param_2 + *(char *)(param_1 + 0xa9);
  }
  *(char *)(param_1 + 0xa9) = param_2;
  memw();
LAB_40186aba:
  memw();
  return;
}

