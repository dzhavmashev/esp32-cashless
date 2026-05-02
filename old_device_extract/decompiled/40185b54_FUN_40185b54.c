// Function : FUN_40185b54
// Address  : 0x40185b54
// Size     : 23 bytes


uint FUN_40185b54(int param_1)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_1 + 0x10);
  if (uVar1 != 0) {
    if (uVar1 < 4) {
      uVar1 = 1;
    }
    else if (uVar1 != 4) {
      uVar1 = 0;
    }
  }
  return uVar1;
}

