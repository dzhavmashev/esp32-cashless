// Function : FUN_4018c75c
// Address  : 0x4018c75c
// Size     : 640 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4018c75c(char param_1,char param_2,uint *param_3,uint param_4,undefined4 param_5)

{
  undefined1 uVar1;
  undefined1 uVar2;
  bool bVar3;
  uint uVar4;
  uint uVar5;
  int *piVar6;
  undefined1 *puVar7;
  int iVar8;
  uint *puVar9;
  int iVar10;
  int iVar11;
  int local_40;
  
  param_4 = param_4 & 0xffff;
  if (param_1 == '\0') {
    iVar11 = param_4 * *(int *)(_DAT_3ffc0034 + 0x3b8);
LAB_4018c7e8:
    iVar11 = FUN_4018b928(0,7,iVar11);
    if (iVar11 == 0) {
      FUN_4018b770(param_3,param_4);
      return;
    }
  }
  else {
    if (param_4 != 1) {
      memw();
      FUN_4018b770(param_3,param_4);
      FUN_40147fe4(6,0x20,2,0x3f437153,param_4);
      return;
    }
    memw();
    if (500 < (*_DAT_3ffc06fc >> 0xc & 0xfff)) {
      iVar11 = *(int *)(_DAT_3ffc0034 + 0x3b8);
      goto LAB_4018c7e8;
    }
    memw();
    iVar11 = FUN_4018b928(0,8,*_DAT_3ffc06fc >> 0xc & 0xfff);
    if (iVar11 == 0) {
      iVar11 = *(int *)(_DAT_3ffc0034 + 0x3b8);
      goto LAB_4018c7e8;
    }
  }
  puVar9 = _DAT_3ffc06fc;
  piVar6 = (int *)_DAT_3ffc06fc[1];
  uVar4 = FUN_4018b754(piVar6);
  uVar5 = uVar4 & 0xffff;
  local_40 = 0;
  if (uVar5 != 0) {
    puVar7 = (undefined1 *)((int)piVar6 + (uVar4 & 0xffff) + 0x18);
    memw();
    local_40 = FUN_40165300(piVar6 + 6,puVar7);
    if (local_40 == 1) {
      uVar1 = *(undefined1 *)((int)piVar6 + 0x19);
      *puVar7 = (char)piVar6[6];
      memw();
      uVar2 = *(undefined1 *)((int)piVar6 + 0x1a);
      puVar7[1] = uVar1;
      memw();
      uVar1 = *(undefined1 *)((int)piVar6 + 0x1b);
      puVar7[2] = uVar2;
      puVar7[3] = uVar1;
      memw();
      memw();
    }
    else if (local_40 == 2) {
      uVar5 = 0;
    }
  }
  bVar3 = true;
  iVar8 = *(int *)(*(int *)(iVar11 + 4) + 4);
  if (param_3 == puVar9) {
    iVar8 = (*(code *)&SUB_4008b3d0)(iVar8,param_3[1],0x18);
    memw();
    (*(code *)&SUB_4008b3d0)
              (iVar8 + 0x18,param_3[1] + uVar5 + 0x18,((*param_3 >> 0xc & 0xfff) - 0x18) - uVar5);
    memw();
    memw();
    uVar4 = *param_3 >> 0xc & 0xfff;
    puVar9 = *(uint **)(iVar11 + 4);
  }
  else {
    do {
      if (bVar3) {
        iVar8 = (*(code *)&SUB_4008b3d0)(iVar8,puVar9[1],0x18);
        iVar10 = _DAT_3ffc0034;
        memw();
        iVar8 = (*(code *)&SUB_4008b3d0)
                          (iVar8 + 0x18,puVar9[1] + uVar5 + 0x18,
                           (*(int *)(_DAT_3ffc0034 + 0x3b8) + -0x18) - uVar5);
        iVar10 = (*(int *)(iVar10 + 0x3b8) + -0x18) - uVar5;
      }
      else {
        memw();
        iVar8 = (*(code *)&SUB_4008b3d0)(iVar8,puVar9[1],*(undefined4 *)(_DAT_3ffc0034 + 0x3b8));
        iVar10 = *(int *)(_DAT_3ffc0034 + 0x3b8);
      }
      iVar8 = iVar8 + iVar10;
      bVar3 = false;
      puVar9 = (uint *)puVar9[2];
    } while (param_3 != puVar9);
    memw();
    (*(code *)&SUB_4008b3d0)(iVar8,param_3[1],*param_3 >> 0xc & 0xfff);
    memw();
    uVar4 = (*param_3 >> 0xc & 0xfff) +
            (*(uint *)(_DAT_3ffc0034 + 0x3b8) & 0xffff) * (param_4 - 1 & 0xffff);
    puVar9 = *(uint **)(iVar11 + 4);
  }
  memw();
  memw();
  *puVar9 = *puVar9 & 0xff000fff | (uVar4 - uVar5 & 0xfff) << 0xc;
  if (DAT_3ffc072c == '\x01') {
    if (*piVar6 < 0) goto LAB_4018c98a;
    memw();
  }
  if (uVar5 != 0) {
    iVar8 = *(int *)(iVar11 + 0x10);
    FUN_40165378(_DAT_3ffc06fc[1] + 0x18,uVar5,iVar8,iVar8 + 0x1c,*(uint *)(iVar8 + 0x18) & 0xfff,
                 local_40);
  }
LAB_4018c98a:
  FUN_4018b770(param_3,param_4);
  *(undefined4 *)(*(int *)(iVar11 + 0x2c) + 4) = param_5;
  *(undefined1 *)(*(int *)(iVar11 + 0x2c) + 8) = DAT_3ffc0728;
  memw();
  *(undefined1 *)(*(int *)(iVar11 + 0x2c) + 9) = DAT_3ffc0729;
  memw();
  uVar4 = 0x100;
  if (param_4 != 1) {
    uVar4 = 0x80;
  }
  **(uint **)(iVar11 + 0x2c) = **(uint **)(iVar11 + 0x2c) | uVar4;
  if (param_2 != '\0') {
    **(uint **)(iVar11 + 0x2c) = **(uint **)(iVar11 + 0x2c) | 0x10;
  }
  memw();
  FUN_40160f8c(iVar11);
  return;
}

