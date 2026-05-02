// Function : FUN_4016413c
// Address  : 0x4016413c
// Size     : 56 bytes


undefined4 FUN_4016413c(byte param_1)

{
  undefined4 uVar1;
  
  uVar1 = 2;
  if (param_1 != 4) {
    if (param_1 < 5) {
      if (param_1 == 2) {
        return 3;
      }
    }
    else {
      if (param_1 == 0xb) {
        return 1;
      }
      if (param_1 == 0x16) {
        return 0;
      }
    }
    FUN_40147fe4(6,0x200,1," %s %u\n");
    uVar1 = 0;
  }
  return uVar1;
}

