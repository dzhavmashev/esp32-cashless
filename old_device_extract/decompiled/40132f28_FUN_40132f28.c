// Function : FUN_40132f28
// Address  : 0x40132f28
// Size     : 190 bytes


int FUN_40132f28(int *param_1,undefined4 param_2,undefined4 *param_3)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  
  piVar2 = (int *)*param_1;
  if (piVar2 == (int *)0x0) {
    return -0x6100;
  }
  iVar3 = piVar2[1];
  *param_3 = 0;
  if ((iVar3 - 3U < 5) || (iVar3 == 9)) {
    return 0;
  }
  iVar4 = 0;
  if (*piVar2 - 0x48U < 2) {
    return 0;
  }
  if (iVar3 == 1) {
    uVar1 = param_1[9];
  }
  else {
    if (iVar3 != 2) {
      return -0x6080;
    }
    uVar1 = param_1[9];
    if (param_1[2] == 1) {
      if ((code *)param_1[3] != (code *)0x0) {
        iVar3 = param_1[0xe];
        if (iVar3 == 0) {
          iVar3 = piVar2[4];
        }
        (*(code *)param_1[3])(param_1 + 5,iVar3);
LAB_40132f8c:
        iVar3 = (**(code **)(*(int *)(*param_1 + 0x1c) + 8))
                          (param_1[0xf],param_1[2],*(undefined4 *)(*param_1 + 0x18),param_1 + 10,
                           param_1 + 5,param_2);
        if (iVar3 != 0) {
          return iVar3;
        }
        iVar3 = *param_1;
        if (param_1[2] == 0) {
          uVar5 = 0;
          if (iVar3 != 0) {
            uVar5 = *(undefined4 *)(iVar3 + 0x18);
          }
          iVar3 = (*(code *)param_1[4])(param_2,uVar5,param_3);
          return iVar3;
        }
        uVar5 = 0;
        if (iVar3 != 0) {
          uVar5 = *(undefined4 *)(iVar3 + 0x18);
        }
        *param_3 = uVar5;
        memw();
        return 0;
      }
    }
    else {
      if (piVar2[6] == uVar1) goto LAB_40132f8c;
      uVar1 = param_1[3] | uVar1;
    }
  }
  if (uVar1 != 0) {
    iVar4 = -0x6280;
    memw();
  }
  return iVar4;
}

