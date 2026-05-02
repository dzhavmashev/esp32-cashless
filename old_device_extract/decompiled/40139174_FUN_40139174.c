// Function : FUN_40139174
// Address  : 0x40139174
// Size     : 74 bytes


undefined4 FUN_40139174(int *param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar2 = 0xffffaf00;
  if ((param_1 != (int *)0x0) && (*param_1 != 0)) {
    uVar1 = *(uint *)(*param_1 + 4);
    if (uVar1 < 7) {
      if (uVar1 < 5) {
        if (uVar1 == 3) {
          uVar2 = FUN_401416b4(param_1[1]);
        }
        else if (uVar1 == 4) {
          uVar2 = FUN_4013ecf4(param_1[1]);
        }
      }
      else {
        uVar2 = FUN_4013f87c(param_1[1]);
      }
    }
    else {
      uVar2 = 0xffffaf00;
      if (uVar1 < 9) {
        uVar2 = FUN_40140aec(param_1[1],param_2,param_3);
      }
    }
  }
  return uVar2;
}

