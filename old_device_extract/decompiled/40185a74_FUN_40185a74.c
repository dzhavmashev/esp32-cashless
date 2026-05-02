// Function : FUN_40185a74
// Address  : 0x40185a74
// Size     : 49 bytes


undefined4 FUN_40185a74(uint param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  param_1 = param_1 & 0xff;
  uVar1 = 5;
  if (param_1 != 3) {
    if (param_1 < 4) {
      if (param_1 == 1) {
        return 3;
      }
      iVar2 = param_1 - 2;
      uVar1 = 4;
    }
    else {
      if (param_1 == 5) {
        return 7;
      }
      if (param_1 < 5) {
        return 6;
      }
      iVar2 = param_1 - 6;
      uVar1 = 8;
    }
    if (iVar2 != 0) {
      uVar1 = 0;
    }
  }
  return uVar1;
}

