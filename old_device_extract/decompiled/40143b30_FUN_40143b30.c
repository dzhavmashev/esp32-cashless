// Function : FUN_40143b30
// Address  : 0x40143b30
// Size     : 426 bytes


int FUN_40143b30(undefined4 *param_1,int param_2,uint *param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  char *pcVar4;
  uint uVar5;
  uint auStack_24 [9];
  
  pcVar4 = (char *)*param_1;
  if (param_2 - (int)pcVar4 < 1) {
    return -0x2460;
  }
  if (*pcVar4 == '\x17') {
    iVar3 = 2;
  }
  else {
    if (*pcVar4 != '\x18') {
      return -0x2462;
    }
    iVar3 = 4;
  }
  *param_1 = pcVar4 + 1;
  memw();
  iVar1 = FUN_40186734(param_1,param_2,auStack_24);
  if (iVar1 != 0) {
    return iVar1 + -0x2400;
  }
  if (auStack_24[0] < iVar3 + 8U) {
    return -0x2400;
  }
  iVar1 = FUN_40143738(param_1,iVar3,param_3);
  if (iVar1 != 0) {
    return iVar1;
  }
  if (iVar3 == 2) {
    if ((int)*param_3 < 0x32) {
      *param_3 = *param_3 + 100;
    }
    *param_3 = *param_3 + 0x76c;
  }
  memw();
  iVar1 = FUN_40143738(param_1,2,param_3 + 1);
  if (iVar1 != 0) {
    return iVar1;
  }
  iVar1 = FUN_40143738(param_1,2,param_3 + 2);
  if (iVar1 != 0) {
    return iVar1;
  }
  iVar1 = FUN_40143738(param_1,2,param_3 + 3);
  if (iVar1 != 0) {
    return iVar1;
  }
  iVar1 = FUN_40143738(param_1,2,param_3 + 4);
  if (iVar1 != 0) {
    return iVar1;
  }
  iVar3 = auStack_24[0] - iVar3;
  if (iVar3 - 8U < 2) {
    return -0x2400;
  }
  iVar1 = FUN_40143738(param_1,2,param_3 + 5);
  if (iVar1 != 0) {
    return iVar1;
  }
  if (iVar3 == 0xb) {
    if (*(char *)*param_1 != 'Z') {
      return -0x2400;
    }
    *param_1 = (char *)*param_1 + 1;
  }
  else if (iVar3 != 10) {
    return -0x2400;
  }
  uVar2 = *param_3;
  if (9999 < uVar2) {
    return -0x2400;
  }
  if (0x17 < param_3[3]) {
    return -0x2400;
  }
  if (0x3b < param_3[4]) {
    return -0x2400;
  }
  if (0x3b < param_3[5]) {
    return -0x2400;
  }
  uVar5 = param_3[1];
  if (uVar5 == 6) {
LAB_40143cdc:
    iVar3 = 0x1e;
  }
  else {
    if ((int)uVar5 < 7) {
      if (uVar5 != 3) {
        if ((int)uVar5 < 4) {
          if (uVar5 != 1) {
            if (uVar5 != 2) {
              return -0x2400;
            }
            if ((((uVar2 & 3) != 0) || (iVar3 = 0x1d, uVar2 == ((int)uVar2 / 100) * 100)) &&
               (iVar3 = 0x1d, (int)uVar2 % 400 != 0)) {
              iVar3 = 0x1c;
            }
            goto LAB_40143c94;
          }
        }
        else {
          if (uVar5 == 4) goto LAB_40143cdc;
          if (uVar5 != 5) {
            return -0x2400;
          }
        }
      }
    }
    else {
      if (uVar5 == 9) goto LAB_40143cdc;
      if (8 < (int)uVar5) {
        if (uVar5 == 0xb) goto LAB_40143cdc;
        if ((10 < (int)uVar5) && (uVar5 != 0xc)) {
          return -0x2400;
        }
      }
    }
    iVar3 = 0x1f;
  }
LAB_40143c94:
  uVar2 = param_3[2];
  if ((int)uVar2 <= iVar3) {
    if (-1 < (int)(uVar2 | uVar2 - 1)) {
      return 0;
    }
    memw();
  }
  return -0x2400;
}

