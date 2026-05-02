// Function : FUN_401860ec
// Address  : 0x401860ec
// Size     : 142 bytes


int FUN_401860ec(int *param_1,int *param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  
  uVar1 = param_1[1];
  while ((uVar1 != 0 && (*(int *)(param_1[2] + uVar1 * 4 + -4) == 0))) {
    uVar1 = uVar1 - 1;
  }
  for (uVar3 = param_2[1]; uVar3 != 0; uVar3 = uVar3 - 1) {
    if (*(int *)(param_2[2] + uVar3 * 4 + -4) != 0) goto LAB_401860fc;
  }
  iVar2 = 0;
  if (uVar1 != 0) {
LAB_401860fc:
    if (uVar3 < uVar1) {
      iVar2 = *param_1;
    }
    else {
      iVar4 = *param_2;
      iVar2 = -iVar4;
      if (uVar3 <= uVar1) {
        iVar2 = *param_1;
        if (iVar2 < 1) {
          if ((iVar2 < 0) && ((iVar4 >> 0x1f) - iVar4 < 0)) {
            return -1;
          }
        }
        else if (iVar4 < 0) {
          return 1;
        }
        do {
          uVar1 = uVar1 - 1;
          if (uVar1 == 0xffffffff) {
            return 0;
          }
          uVar5 = *(uint *)(param_1[2] + uVar1 * 4);
          uVar3 = *(uint *)(param_2[2] + uVar1 * 4);
          if (uVar3 < uVar5) {
            return iVar2;
          }
        } while (uVar3 <= uVar5);
        iVar2 = -iVar2;
      }
    }
  }
  return iVar2;
}

