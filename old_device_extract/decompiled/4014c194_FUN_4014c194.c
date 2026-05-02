// Function : FUN_4014c194
// Address  : 0x4014c194
// Size     : 110 bytes


undefined4 FUN_4014c194(uint *param_1,undefined1 *param_2)

{
  uint uVar1;
  undefined1 uVar2;
  
  uVar1 = *param_1;
  if (uVar1 == 0x2f25000) {
    return 1;
  }
  if (uVar1 < 0x2f25001) {
    if (uVar1 == 0xf25000) {
      return 0;
    }
    if (uVar1 == 0x1f25000) {
      if (param_2 == (undefined1 *)0x0) {
        return 6;
      }
      uVar2 = 5;
LAB_4014c1f2:
      *param_2 = uVar2;
      memw();
      memw();
      return 6;
    }
  }
  else {
    if (uVar1 == 0x4f25000) {
      return 3;
    }
    if (uVar1 == 0x5f25000) {
      if (param_2 == (undefined1 *)0x0) {
        return 6;
      }
      uVar2 = 0xd;
      goto LAB_4014c1f2;
    }
  }
  return 0x20;
}

