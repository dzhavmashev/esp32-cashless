// Function : FUN_4016fbc4
// Address  : 0x4016fbc4
// Size     : 81 bytes


undefined4 FUN_4016fbc4(uint param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  if (param_1 != 0xff) {
    param_1 = param_1 & 0x70;
    if (param_1 == 0x20) {
      uVar1 = FUN_40170f4c(param_2);
      return uVar1;
    }
    if (param_1 < 0x21) {
      if (param_1 == 0) {
        return 0;
      }
      if (param_1 == 0x10) {
        return 0;
      }
    }
    else {
      if (param_1 == 0x40) {
        uVar1 = FUN_40170f24();
        return uVar1;
      }
      if (param_1 == 0x50) {
        return 0;
      }
      if (param_1 == 0x30) {
        uVar1 = FUN_40170f44();
        return uVar1;
      }
    }
    (*(code *)&SUB_40094bc8)();
  }
  return 0;
}

