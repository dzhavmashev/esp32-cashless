// Function : FUN_4018511c
// Address  : 0x4018511c
// Size     : 40 bytes


undefined4 FUN_4018511c(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0x10;
  if (param_1 != 0x20) {
    if (param_1 < 0x21) {
      if (param_1 == 2) {
        return 0x20;
      }
      param_1 = param_1 + -8;
      uVar1 = 0x10;
    }
    else {
      if (param_1 == 0x80) {
        return 5;
      }
      param_1 = param_1 + -0x100;
      uVar1 = 0xd;
    }
    if (param_1 != 0) {
      uVar1 = 0;
    }
  }
  return uVar1;
}

