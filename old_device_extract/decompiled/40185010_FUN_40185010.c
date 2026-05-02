// Function : FUN_40185010
// Address  : 0x40185010
// Size     : 51 bytes


uint FUN_40185010(int param_1)

{
  uint uVar1;
  
  uVar1 = param_1 - 0x30;
  if (9 < (uVar1 & 0xff)) {
    if ((param_1 - 0x61U & 0xff) < 6) {
      uVar1 = param_1 - 0x57;
    }
    else {
      uVar1 = 0xffffffff;
      if ((param_1 - 0x41U & 0xff) < 6) {
        uVar1 = param_1 - 0x37;
      }
    }
  }
  return uVar1;
}

