// Function : FUN_400e7730
// Address  : 0x400e7730
// Size     : 90 bytes


void FUN_400e7730(undefined1 *param_1,int param_2)

{
  undefined4 uVar1;
  
  *(int *)(param_1 + 4) = param_2;
  uVar1 = FUN_400f1a9c();
  *(undefined4 *)(param_1 + 8) = uVar1;
  if (param_2 == 2) {
    uVar1 = 2000;
  }
  else {
    if (param_2 < 3) {
      if ((param_2 != 0) && (param_2 != 1)) {
        return;
      }
      FUN_400f1a40(*param_1,param_2);
      param_1[0xc] = (char)param_2;
      return;
    }
    if (param_2 == 4) {
      uVar1 = 0xfa;
    }
    else {
      if (3 < param_2) {
        if (param_2 != 5) {
          return;
        }
        goto LAB_400e7752;
      }
      uVar1 = 1000;
    }
  }
  *(undefined4 *)(param_1 + 0x10) = uVar1;
LAB_400e7752:
  FUN_400f1a40(*param_1,1);
  param_1[0xc] = 1;
  uVar1 = FUN_400f1a9c();
  *(undefined4 *)(param_1 + 8) = uVar1;
  return;
}

