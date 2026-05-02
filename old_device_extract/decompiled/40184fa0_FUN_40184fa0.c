// Function : FUN_40184fa0
// Address  : 0x40184fa0
// Size     : 55 bytes


undefined4 FUN_40184fa0(uint param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 8;
  if (param_1 != 4) {
    if (param_1 < 5) {
      if (param_1 == 2) {
        return 0x100;
      }
      if (2 < param_1) {
        return 2;
      }
      iVar1 = param_1 - 1;
      uVar2 = 0x80;
    }
    else {
      if (param_1 == 6) {
        return 0x20;
      }
      if (param_1 < 6) {
        return 10;
      }
      iVar1 = param_1 - 7;
      uVar2 = 0x400;
    }
    if (iVar1 != 0) {
      uVar2 = 1;
    }
  }
  return uVar2;
}

