// Function : FUN_40185918
// Address  : 0x40185918
// Size     : 56 bytes


void FUN_40185918(uint *param_1,uint *param_2,int param_3,byte *param_4)

{
  uint uVar1;
  
  if (param_3 == 1) {
    *param_1 = 0x101 - *param_4;
    if (0x100 - param_4[1] != 1) {
      *param_2 = 0x100 - param_4[1];
      goto LAB_40185937;
    }
    uVar1 = 2;
  }
  else {
    *param_1 = (uint)*param_4;
    uVar1 = (uint)param_4[1];
    memw();
  }
  *param_2 = uVar1;
  memw();
LAB_40185937:
  memw();
  return;
}

