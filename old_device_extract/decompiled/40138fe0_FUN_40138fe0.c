// Function : FUN_40138fe0
// Address  : 0x40138fe0
// Size     : 119 bytes


undefined4 FUN_40138fe0(int *param_1,int *param_2)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  
  if (param_1 == (int *)0x0) {
    return 0xffffaf00;
  }
  if ((((*param_1 == 0) || (param_2 == (int *)0x0)) || (iVar3 = *param_2, *param_1 != iVar3)) ||
     (iVar3 == 0)) {
LAB_40139018:
    uVar1 = 0xffffaf00;
  }
  else {
    uVar2 = *(uint *)(iVar3 + 4);
    if (uVar2 < 7) {
      if (uVar2 < 5) {
        if (uVar2 == 3) {
          FUN_401416f8(param_1[1],param_2[1]);
        }
        else {
          if (uVar2 != 4) goto LAB_40139018;
          FUN_4013ec7c(param_1[1],param_2[1]);
        }
      }
      else {
        FUN_4013f7c4(param_1[1],param_2[1]);
      }
    }
    else {
      if (8 < uVar2) {
        return 0xffffaf00;
      }
      FUN_401409dc(param_1[1],param_2[1]);
    }
    uVar1 = 0;
  }
  return uVar1;
}

