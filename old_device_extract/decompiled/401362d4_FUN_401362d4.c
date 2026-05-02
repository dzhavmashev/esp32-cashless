// Function : FUN_401362d4
// Address  : 0x401362d4
// Size     : 103 bytes


undefined4 FUN_401362d4(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = FUN_401863d8(param_1);
  if (iVar1 == 2) {
    iVar1 = FUN_4018601c(param_2,0);
    if ((iVar1 == 0) && (iVar1 = FUN_4018601c(param_2,1), iVar1 == 0)) {
      iVar1 = FUN_40131798(param_2);
      if (iVar1 + -1 == *(int *)(param_1 + 0x5c)) {
        if (iVar1 + -1 != 0xfe) {
          return 0;
        }
        iVar1 = FUN_4018601c(param_2,2);
        if (iVar1 == 0) {
          return 0;
        }
      }
    }
  }
  else {
    if (iVar1 != 1) {
      return 0xffffb080;
    }
    iVar1 = FUN_40131ad8(param_2,1);
    if ((-1 < iVar1) && (iVar1 = FUN_401860ec(param_2,param_1 + 0x4c), iVar1 < 0)) {
      return 0;
    }
  }
  return 0xffffb380;
}

