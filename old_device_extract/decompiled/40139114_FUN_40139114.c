// Function : FUN_40139114
// Address  : 0x40139114
// Size     : 88 bytes


undefined4 FUN_40139114(int *param_1)

{
  undefined4 uVar1;
  uint uVar2;
  
  if (param_1 == (int *)0x0) {
    return 0xffffaf00;
  }
  if (*param_1 == 0) {
    return 0xffffaf00;
  }
  uVar2 = *(uint *)(*param_1 + 4);
  if (uVar2 == 5) {
    uVar1 = 1;
LAB_4013915c:
    uVar1 = FUN_4013f7ec(param_1[1],uVar1);
  }
  else {
    if (uVar2 < 6) {
      if (uVar2 == 3) {
        uVar1 = FUN_401416c8(param_1[1]);
        return uVar1;
      }
      if (uVar2 != 4) {
        return 0xffffaf00;
      }
      uVar1 = FUN_4013eca8(param_1[1]);
      return uVar1;
    }
    if (uVar2 == 7) {
      uVar1 = 1;
    }
    else {
      if (uVar2 < 7) {
        uVar1 = 0;
        goto LAB_4013915c;
      }
      if (uVar2 != 8) {
        return 0xffffaf00;
      }
      uVar1 = 0;
    }
    uVar1 = FUN_40140a08(param_1[1],uVar1);
  }
  return uVar1;
}

