// Function : FUN_40131bcc
// Address  : 0x40131bcc
// Size     : 239 bytes


int FUN_40131bcc(undefined4 *param_1,undefined4 *param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  
  uVar1 = *(uint *)(param_3 + 4);
  while ((uVar1 != 0 && (*(int *)(*(int *)(param_3 + 8) + uVar1 * 4 + -4) == 0))) {
    uVar1 = uVar1 - 1;
  }
  if ((uint)param_2[1] < uVar1) {
LAB_40131bda:
    iVar2 = -10;
  }
  else {
    iVar2 = FUN_40131574(param_1);
    if (iVar2 != 0) {
      return iVar2;
    }
    iVar2 = uVar1 * 4;
    if ((uVar1 < (uint)param_2[1]) && (param_2 != param_1)) {
      (*(code *)&SUB_4008b3d0)(param_1[2] + iVar2,param_2[2] + iVar2,(param_2[1] - uVar1) * 4);
    }
    uVar5 = param_2[1];
    if (uVar5 < (uint)param_1[1]) {
      (*(code *)&SUB_4008b530)(param_1[2] + uVar5 * 4,0,(param_1[1] - uVar5) * 4);
    }
    iVar3 = 0;
    iVar7 = param_1[2];
    uVar5 = 0;
    iVar8 = param_2[2];
    iVar9 = *(int *)(param_3 + 8);
    while (iVar3 != iVar2) {
      uVar6 = *(uint *)(iVar8 + iVar3) - uVar5;
      uVar10 = *(uint *)(iVar9 + iVar3);
      uVar5 = (uint)(uVar6 < uVar10) + (uint)(*(uint *)(iVar8 + iVar3) < uVar5);
      *(uint *)(iVar7 + iVar3) = uVar6 - uVar10;
      iVar3 = iVar3 + 4;
      memw();
    }
    if (uVar5 != 0) {
      piVar4 = (int *)(iVar7 + iVar3);
      while (uVar1 < (uint)param_1[1]) {
        if (*piVar4 != 0) goto LAB_40131c68;
        *piVar4 = -1;
        uVar1 = uVar1 + 1;
        piVar4 = piVar4 + 1;
        memw();
      }
      if (param_1[1] == uVar1) goto LAB_40131bda;
LAB_40131c68:
      piVar4 = (int *)(iVar7 + uVar1 * 4);
      *piVar4 = *piVar4 + -1;
    }
    *param_1 = 1;
    memw();
    iVar2 = 0;
  }
  return iVar2;
}

