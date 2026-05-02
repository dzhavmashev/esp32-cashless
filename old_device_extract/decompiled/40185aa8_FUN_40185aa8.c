// Function : FUN_40185aa8
// Address  : 0x40185aa8
// Size     : 48 bytes


undefined4 FUN_40185aa8(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 3;
  if (param_1 != 5) {
    if (param_1 < 6) {
      if (param_1 == 3) {
        return 1;
      }
      param_1 = param_1 + -4;
      uVar1 = 2;
    }
    else {
      if (param_1 == 7) {
        return 5;
      }
      if (param_1 < 7) {
        return 4;
      }
      param_1 = param_1 + -8;
      uVar1 = 6;
    }
    if (param_1 != 0) {
      uVar1 = 0;
    }
  }
  return uVar1;
}

