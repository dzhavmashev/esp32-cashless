// Function : FUN_40139210
// Address  : 0x40139210
// Size     : 85 bytes


undefined4 FUN_40139210(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  uint uVar2;
  
  if (param_1 == 0) {
    return 0xffffaf00;
  }
  uVar2 = *(uint *)(param_1 + 4);
  if (uVar2 == 5) {
    uVar1 = 1;
LAB_4013925b:
    uVar1 = FUN_4013cb80(param_2,param_3,param_4,uVar1);
  }
  else {
    if (uVar2 < 6) {
      if (uVar2 == 3) {
        uVar1 = FUN_4013941c();
        return uVar1;
      }
      if (uVar2 != 4) {
        return 0xffffaf00;
      }
      uVar1 = FUN_4013cb28();
      return uVar1;
    }
    if (uVar2 != 7) {
      if (uVar2 < 7) {
        uVar1 = 0;
        goto LAB_4013925b;
      }
      if (uVar2 != 8) {
        return 0xffffaf00;
      }
    }
    uVar1 = FUN_4013cbd8();
  }
  return uVar1;
}

