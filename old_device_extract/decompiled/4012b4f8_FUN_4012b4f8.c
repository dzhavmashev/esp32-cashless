// Function : FUN_4012b4f8
// Address  : 0x4012b4f8
// Size     : 40 bytes


undefined4 FUN_4012b4f8(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0x400;
  if (param_1 != 2) {
    if (param_1 < 3) {
      if (param_1 == 1) {
        return 0x200;
      }
    }
    else {
      if (param_1 == 3) {
        return 0x800;
      }
      if (param_1 == 4) {
        return 0x1000;
      }
    }
    uVar1 = 0x4000;
  }
  return uVar1;
}

