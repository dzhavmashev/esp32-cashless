// Function : FUN_401391c4
// Address  : 0x401391c4
// Size     : 72 bytes


undefined4 FUN_401391c4(int *param_1,undefined4 param_2)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar2 = 0xffffaf00;
  if ((param_1 != (int *)0x0) && (*param_1 != 0)) {
    uVar1 = *(uint *)(*param_1 + 4);
    if (uVar1 < 7) {
      if (uVar1 < 5) {
        if (uVar1 == 3) {
          uVar2 = FUN_401416a0(param_1[1]);
        }
        else if (uVar1 == 4) {
          uVar2 = FUN_4013ed0c(param_1[1]);
        }
      }
      else {
        uVar2 = FUN_4013f8a4(param_1[1]);
      }
    }
    else {
      uVar2 = 0xffffaf00;
      if (uVar1 < 9) {
        uVar2 = FUN_40140b04(param_1[1],param_2);
      }
    }
  }
  return uVar2;
}

