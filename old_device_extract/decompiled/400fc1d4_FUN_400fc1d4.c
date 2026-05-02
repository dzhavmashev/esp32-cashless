// Function : FUN_400fc1d4
// Address  : 0x400fc1d4
// Size     : 790 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400fc1d4(int *param_1,int param_2,int param_3,uint param_4)

{
  uint *puVar1;
  int *piVar2;
  int *piVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint *puVar7;
  int iVar8;
  undefined4 *puVar9;
  int iVar10;
  int iVar11;
  int *piStack_5c;
  uint uStack_58;
  uint uStack_4c;
  uint uStack_48;
  undefined1 uStack_44;
  char cStack_43;
  byte bStack_42;
  undefined1 uStack_41;
  undefined1 auStack_3c [24];
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  if (param_2 == 0) {
    piVar2 = (int *)0x102;
  }
  else {
    piStack_5c = param_1 + 3;
    param_1[7] = param_3;
    param_1[8] = param_4;
    memw();
    FUN_400fc0c0(param_1);
    memw();
    FUN_400fc0c0(piStack_5c);
    iVar11 = -1;
    if (param_4 < 0x1861862) {
      iVar11 = param_4 * 0x54 + 4;
    }
    puVar1 = (uint *)(*(code *)&LAB_4016ffdf_1)(iVar11,&DAT_3f424b88);
    puVar7 = puVar1;
    if (puVar1 != (uint *)0x0) {
      puVar7 = puVar1 + 1;
      *puVar1 = param_4;
      puVar1 = puVar7;
      uStack_58 = param_4;
      while (uStack_58 = uStack_58 - 1, -1 < (int)uStack_58) {
        memw();
        FUN_400fb0ac(puVar1);
        puVar1 = puVar1 + 0x15;
        memw();
      }
    }
    iVar11 = param_1[6];
    param_1[6] = (int)puVar7;
    if (iVar11 != 0) {
      iVar8 = iVar11 + *(int *)(iVar11 + -4) * 0x54;
      iVar6 = iVar8;
      while (iVar11 != iVar6) {
        memw();
        FUN_400fafec(iVar6 + -0x10);
        iVar6 = iVar6 + -0x54;
      }
      FUN_4016fffc(iVar8 + (((uint)(iVar8 - iVar11) >> 2) * 0x3cf3cf3d & 0x3fffffff) * -0x54 + -4);
    }
    if (param_1[6] == 0) {
      piVar2 = (int *)&DAT_00000101;
    }
    else {
      iVar6 = param_3 + param_4;
      iVar11 = 0;
      while (param_3 != iVar6) {
        piVar2 = (int *)FUN_400fbe78(param_1[6] + iVar11,param_2,param_3);
        if (piVar2 != (int *)0x0) goto LAB_400fc361;
        iVar8 = FUN_400fb430(param_1[6] + iVar11,&uStack_4c);
        uVar4 = uStack_4c;
        if (iVar8 == 0) {
          for (piVar2 = (int *)*param_1; piVar2 != (int *)0x0; piVar2 = (int *)piVar2[1]) {
            iVar8 = FUN_400fb430(piVar2,&uStack_48);
            if ((iVar8 == 0) && (uVar4 < uStack_48)) {
              piVar3 = (int *)(param_1[6] + iVar11);
              iVar8 = param_1[2];
              iVar10 = *piVar2;
              if (iVar10 == 0) {
                puVar9 = (undefined4 *)*param_1;
                *piVar3 = 0;
                piVar3[1] = (int)puVar9;
                if (puVar9 != (undefined4 *)0x0) {
                  *puVar9 = piVar3;
                }
                *param_1 = (int)piVar3;
                if (param_1[1] == 0) {
                  param_1[1] = (int)piVar3;
                }
              }
              else {
                *(int **)(iVar10 + 4) = piVar3;
                *piVar2 = (int)piVar3;
                piVar3[1] = (int)piVar2;
                *piVar3 = iVar10;
                memw();
              }
              param_1[2] = iVar8 + 1;
              goto LAB_400fc332;
            }
          }
          iVar8 = param_1[6];
          piVar2 = param_1;
        }
        else {
          iVar8 = param_1[6];
          piVar2 = piStack_5c;
        }
        FUN_40184bac(piVar2,iVar8 + iVar11);
LAB_400fc332:
        iVar11 = iVar11 + 0x54;
        param_3 = param_3 + 1;
        memw();
      }
      if (param_1[2] != 0) goto LAB_400fc37d;
      param_1[9] = 0;
      memw();
      piVar2 = (int *)FUN_400fc0d8(param_1);
    }
  }
LAB_400fc361:
  do {
    param_1 = piVar2;
    memw();
    memw();
    if (iStack_24 == _DAT_3ffc5708) {
      return;
    }
    (*(code *)&SUB_40082ec4)();
LAB_400fc37d:
    piVar3 = (int *)FUN_400fb430(param_1[1],&uStack_48);
    uVar4 = 0;
    if (piVar3 != (int *)0x0) {
      uVar4 = (*(code *)&SUB_4008effc)(piVar3,"tSeqNo)",0x32,"ger.cpp",&DAT_3f40d3e0);
    }
    iVar11 = param_1[1];
    param_1[9] = uStack_48 + 1;
    uVar5 = 0xffffffff;
    uStack_48 = uVar4;
    while( true ) {
      memw();
      iVar6 = FUN_400fb6ac(iVar11,0xff,0xff,0,&uStack_48,&uStack_44,0xff,0xff);
      if (iVar6 != 0) break;
      uVar5 = bStack_42 + uStack_48;
      memw();
      uStack_48 = uVar5;
    }
    if (uVar5 != 0xffffffff) {
      for (iVar6 = *param_1; iVar11 != iVar6; iVar6 = *(int *)(iVar6 + 4)) {
        if ((*(int *)(iVar6 + 0xc) != -8) &&
           (iVar8 = FUN_400fbaa4(iVar6,uStack_44,cStack_43,auStack_3c,uStack_41,0xff), iVar8 == 0))
        goto LAB_400fc409;
      }
      if (cStack_43 == 'H') {
        iVar11 = *param_1;
        while ((iVar11 != iVar6 &&
               ((*(int *)(iVar11 + 0xc) == -8 ||
                (iVar8 = FUN_400fbaa4(iVar11,uStack_44,0x41,auStack_3c,uStack_41,0xff), iVar8 != 0))
               ))) {
          iVar11 = *(int *)(iVar11 + 4);
        }
      }
    }
LAB_400fc409:
    for (iVar11 = *param_1; iVar11 != 0; iVar11 = *(int *)(iVar11 + 4)) {
      if (*(int *)(iVar11 + 0xc) == -8) {
        iVar6 = param_1[1];
        if (*(int *)(iVar6 + 0xc) == -2) {
          piVar2 = (int *)FUN_400fb46c(iVar6);
          if (piVar2 != (int *)0x0) goto LAB_400fc361;
          FUN_40184bd0(param_1,iVar6);
          FUN_40184bac(piStack_5c,iVar6);
        }
        piVar2 = (int *)FUN_400fc0d8(param_1);
        if ((piVar2 != (int *)0x0) ||
           (((piVar2 = (int *)FUN_400fbff8(iVar11,param_1[1]), piVar2 != (int *)0x0 &&
             (piVar2 != (int *)0x1102)) ||
            (piVar2 = (int *)FUN_400fb46c(iVar11), piVar2 != (int *)0x0)))) goto LAB_400fc361;
        FUN_40184bd0(param_1,iVar11);
        FUN_40184bac(piStack_5c,iVar11);
        break;
      }
    }
    piVar2 = piVar3;
    if (param_1[5] == 0) {
      piVar2 = (int *)0x110d;
    }
  } while( true );
}

