// Function : FUN_4012ccb4
// Address  : 0x4012ccb4
// Size     : 149 bytes


int FUN_4012ccb4(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  
  *param_1 = param_2;
  param_1[0x2e] = 0;
  memw();
  iVar1 = FUN_4013ae30(1,0x414d);
  param_1[0x19] = iVar1;
  if (iVar1 != 0) {
    iVar1 = FUN_4013ae30(1,0x414d);
    param_1[0x2e] = iVar1;
    if (iVar1 != 0) {
      memw();
      FUN_40129ca8(param_1);
      (*(code *)&SUB_4008b530)(param_1 + 0x3d,0,0x104);
      iVar1 = FUN_4012cb68(param_1);
      if (iVar1 == 0) {
        return 0;
      }
      goto LAB_4012ccd5;
    }
  }
  iVar1 = -0x7f00;
LAB_4012ccd5:
  memw();
  FUN_4013ae44(param_1[0x19]);
  FUN_4013ae44(param_1[0x2e]);
  *param_1 = 0;
  param_1[0x19] = 0;
  param_1[0x2e] = 0;
  param_1[0x1b] = 0;
  param_1[0x1a] = 0;
  param_1[0x1c] = 0;
  param_1[0x1d] = 0;
  param_1[0x1e] = 0;
  param_1[0x30] = 0;
  param_1[0x2f] = 0;
  param_1[0x31] = 0;
  param_1[0x32] = 0;
  param_1[0x33] = 0;
  memw();
  return iVar1;
}

