// Function : FUN_40141738
// Address  : 0x40141738
// Size     : 46 bytes


undefined4 FUN_40141738(undefined4 *param_1,int param_2,undefined4 param_3,uint param_4)

{
  undefined4 uVar1;
  byte *pbVar2;
  
  pbVar2 = (byte *)*param_1;
  uVar1 = 0xffffffa0;
  if (0 < param_2 - (int)pbVar2) {
    uVar1 = 0xffffff9e;
    if (*pbVar2 == param_4) {
      *param_1 = pbVar2 + 1;
      memw();
      uVar1 = FUN_40186734(param_1,param_2,param_3);
    }
  }
  return uVar1;
}

