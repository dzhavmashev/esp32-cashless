// Function : FUN_40185b28
// Address  : 0x40185b28
// Size     : 41 bytes


uint FUN_40185b28(int param_1)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_1 + 0x10);
  if (uVar1 != 4) {
    if (uVar1 < 5) {
      if (uVar1 == 0) {
        return 0;
      }
    }
    else if (uVar1 != 7) {
      if (uVar1 < 7) {
        return 0;
      }
      if (1 < uVar1 - 9) {
        return 0;
      }
      return 2;
    }
    uVar1 = 1;
  }
  return uVar1;
}

