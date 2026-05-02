// Function : FUN_4013427c
// Address  : 0x4013427c
// Size     : 68 bytes


int FUN_4013427c(uint *param_1,undefined4 param_2,undefined4 param_3,uint param_4,undefined4 param_5
                ,undefined4 param_6)

{
  int iVar1;
  
  iVar1 = -0x3080;
  if ((param_4 != 0) && (param_4 <= *param_1)) {
    iVar1 = FUN_40134030(param_1,param_2,param_5,param_6);
    if (iVar1 == -0x3180) {
      iVar1 = -0x3280;
    }
    else {
      if (iVar1 == 0) {
        iVar1 = FUN_40131900(param_1 + 10,param_3,param_4);
      }
      if ((iVar1 != 0) && (-0x80 < iVar1)) {
        iVar1 = iVar1 + -0x3280;
      }
    }
  }
  return iVar1;
}

