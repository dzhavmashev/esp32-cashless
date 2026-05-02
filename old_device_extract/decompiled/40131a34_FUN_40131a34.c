// Function : FUN_40131a34
// Address  : 0x40131a34
// Size     : 162 bytes


undefined4 FUN_40131a34(int param_1,uint param_2)

{
  undefined4 uVar1;
  int iVar2;
  uint *puVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined4 *puVar7;
  int iVar8;
  uint uVar9;
  
  uVar5 = param_2 >> 5;
  uVar4 = param_2 & 0x1f;
  if (*(uint *)(param_1 + 4) < uVar5) {
LAB_40131a4a:
    uVar1 = FUN_40131700(param_1,0);
  }
  else {
    if (*(uint *)(param_1 + 4) == uVar5) {
      if (uVar4 != 0) goto LAB_40131a4a;
      if (0x1f < param_2) {
        uVar6 = 0;
        goto LAB_40131a8f;
      }
    }
    else {
      if (0x1f < param_2) {
        iVar2 = uVar5 << 2;
        uVar6 = 0;
        while (uVar6 < *(int *)(param_1 + 4) - uVar5) {
          iVar8 = uVar6 * 4;
          puVar7 = (undefined4 *)(*(int *)(param_1 + 8) + iVar2);
          uVar6 = uVar6 + 1;
          iVar2 = iVar2 + 4;
          *(undefined4 *)(*(int *)(param_1 + 8) + iVar8) = *puVar7;
          memw();
        }
LAB_40131a8f:
        for (; uVar6 < *(uint *)(param_1 + 4); uVar6 = uVar6 + 1) {
          *(undefined4 *)(*(int *)(param_1 + 8) + uVar6 * 4) = 0;
        }
      }
      if (uVar4 != 0) {
        iVar2 = *(int *)(param_1 + 4);
        uVar5 = 0;
        while (iVar2 = iVar2 + -1, iVar2 != -1) {
          puVar3 = (uint *)(*(int *)(param_1 + 8) + iVar2 * 4);
          uVar9 = *puVar3;
          uVar6 = uVar9 >> (param_2 & 0x1f) | uVar5;
          uVar5 = uVar9 << 0x20 - (0x20 - (0x20 - uVar4 & 0x1f));
          *puVar3 = uVar6;
          memw();
        }
      }
    }
    uVar1 = 0;
    memw();
  }
  return uVar1;
}

