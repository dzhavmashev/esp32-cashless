// Function : FUN_40106368
// Address  : 0x40106368
// Size     : 93 bytes


undefined4 FUN_40106368(int param_1,uint param_2)

{
  undefined4 uVar1;
  
  if ((param_2 & 8) == 0) {
    if ((param_2 & 2) == 0) {
      if ((param_2 & 0x100) == 0) {
        if ((param_2 & 0x80) == 0) {
          if ((param_2 & 1) == 0) {
            uVar1 = 0;
            if ((param_2 & 0x20) != 0) {
              uVar1 = 0xfac06;
            }
          }
          else {
            uVar1 = 0xfac00;
            if (param_1 != 2) {
              uVar1 = 0x50f200;
            }
          }
        }
        else {
          uVar1 = 0xfac01;
          if (param_1 != 2) {
            uVar1 = 0x50f201;
          }
        }
      }
      else {
        uVar1 = 0xfac05;
        if (param_1 != 2) {
          uVar1 = 0x50f205;
        }
      }
    }
    else {
      uVar1 = 0xfac02;
      if (param_1 != 2) {
        uVar1 = 0x50f202;
      }
    }
  }
  else {
    uVar1 = 0xfac04;
    if (param_1 != 2) {
      uVar1 = 0x50f204;
    }
  }
  return uVar1;
}

