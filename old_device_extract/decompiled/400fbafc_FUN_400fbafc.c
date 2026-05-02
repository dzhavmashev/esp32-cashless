// Function : FUN_400fbafc
// Address  : 0x400fbafc
// Size     : 883 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_400fbafc(int param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  ulonglong uVar10;
  ulonglong uVar11;
  undefined8 uVar12;
  uint uStack_70;
  int iStack_6c;
  uint uStack_68;
  undefined1 uStack_64;
  undefined1 uStack_63;
  byte bStack_62;
  int iStack_60;
  undefined1 auStack_5c [24];
  undefined1 uStack_44;
  undefined1 uStack_43;
  byte bStack_42;
  int iStack_40;
  int iStack_24;
  
  memw();
  iVar4 = param_1 + 0x18;
  memw();
  iStack_24 = _DAT_3ffc5708;
  if (((*(uint *)(param_1 + 0xc) & 0xfffffffb) == 0xfffffff8) ||
     (*(uint *)(param_1 + 0xc) == 0xfffffffe)) {
    memw();
    uVar10 = (**(code **)(**(int **)(param_1 + 0x50) + 0xc))
                       (*(int **)(param_1 + 0x50),*(int *)(param_1 + 8) + 0x20,iVar4);
    iVar5 = (int)uVar10;
    if (iVar5 != 0) {
      *(undefined4 *)(param_1 + 0xc) = 0;
      goto LAB_400fbb51;
    }
  }
LAB_400fbb6e:
  iVar2 = 0;
  *(undefined4 *)(param_1 + 0x40) = 0;
  do {
    memw();
    uVar10 = (*(code *)&LAB_40184b76_2)(iVar4,iVar2,&uStack_70);
    iVar5 = (int)uVar10;
    if (iVar5 != 0) goto LAB_400fbb51;
    if (uStack_70 == 2) {
      if (*(int *)(param_1 + 0x3c) == -1) {
        *(int *)(param_1 + 0x3c) = iVar2;
      }
      *(short *)(param_1 + 0x40) = *(short *)(param_1 + 0x40) + 1;
      memw();
    }
    else if (uStack_70 == 0) {
      *(short *)(param_1 + 0x42) = *(short *)(param_1 + 0x42) + 1;
      memw();
      memw();
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 != 0x7e);
  if (*(uint *)(param_1 + 0xc) == 0xfffffffe) {
    iVar5 = 0;
    do {
      memw();
      uVar11 = (*(code *)&LAB_40184b76_2)(iVar4,iVar5,&uStack_70);
      if ((int)uVar11 != 0) goto LAB_400fbda5;
      if (uStack_70 == 3) {
        *(int *)(param_1 + 0x38) = iVar5;
        break;
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 != 0x7e);
    do {
      if (0x7d < *(uint *)(param_1 + 0x38)) goto LAB_400fbc76;
      memw();
      uVar11 = (**(code **)(**(int **)(param_1 + 0x50) + 0xc))
                         (*(int **)(param_1 + 0x50),
                          *(int *)(param_1 + 8) + 0x40 + *(uint *)(param_1 + 0x38) * 0x20,&iStack_6c
                          ,4);
      if ((int)uVar11 != 0) goto LAB_400fbbfc;
      uVar11 = (ulonglong)*(uint *)(param_1 + 0x38) << 0x20;
      if (iStack_6c == -1) goto LAB_400fbc76;
      uStack_68 = uStack_70;
      memw();
      uVar11 = (*(code *)&LAB_40184b76_2)(iVar4,*(uint *)(param_1 + 0x38),&uStack_68);
      if ((int)uVar11 != 0) goto LAB_400fbda5;
      uVar11 = FUN_40184a44(param_1,*(undefined4 *)(param_1 + 0x38),0);
      if ((int)uVar11 != 0) goto LAB_400fbbfc;
      *(int *)(param_1 + 0x38) = *(int *)(param_1 + 0x38) + 1;
      if (uStack_68 == 2) {
        *(short *)(param_1 + 0x40) = *(short *)(param_1 + 0x40) + -1;
        memw();
      }
      *(short *)(param_1 + 0x42) = *(short *)(param_1 + 0x42) + 1;
      memw();
      memw();
    } while( true );
  }
  if ((*(uint *)(param_1 + 0xc) & 0xfffffffb) == 0xfffffff8) {
    uVar3 = *(uint *)(param_1 + 0x3c);
    while( true ) {
      iVar5 = (int)uVar10;
      uVar10 = uVar10 & 0xffffffff00000000;
      if (0x7d < uVar3) break;
      uVar11 = (*(code *)&LAB_40184b76_2)(iVar4,uVar3,&uStack_70);
      if ((int)uVar11 != 0) goto LAB_400fbda5;
      uVar10 = uVar11;
      if (uStack_70 == 2) {
        uVar11 = FUN_40184b50(param_1,uVar3,&uStack_44);
        iVar5 = iStack_40;
        if ((int)uVar11 != 0) goto LAB_400fbbfc;
        uVar12 = FUN_400fc574(&uStack_44);
        if (iVar5 == (int)uVar12) {
          if (bStack_42 == 0) {
            uVar11 = CONCAT44((int)((ulonglong)uVar12 >> 0x20),0xffffffff);
            goto LAB_400fbda5;
          }
          uVar11 = FUN_400faef8(param_1 + 0x44,&uStack_44,uVar3);
          if ((int)uVar11 != 0) goto LAB_400fbbfc;
          uVar7 = (uint)bStack_42;
          uVar10 = FUN_40184a1c(uStack_43);
          if ((int)uVar10 != 0) {
            uVar9 = uVar3;
            do {
              uVar9 = uVar9 + 1;
              if (uVar3 + uVar7 <= uVar9) goto LAB_400fbe58;
              memw();
              uVar11 = (*(code *)&LAB_40184b76_2)(iVar4,uVar9,&uStack_70);
              uVar10 = CONCAT44((int)(uVar11 >> 0x20),uStack_70);
              if ((int)uVar11 != 0) goto LAB_400fbda5;
            } while (uStack_70 == 2);
            uVar10 = FUN_400fb554(param_1,uVar3);
          }
LAB_400fbe58:
          uVar3 = uVar3 + (uVar7 - 1);
        }
        else {
          uVar11 = FUN_400fb554(param_1,uVar3);
          uVar10 = uVar11;
          if ((int)uVar11 != 0) goto LAB_400fbbfc;
        }
      }
      uVar3 = uVar3 + 1;
    }
  }
  goto LAB_400fbb51;
LAB_400fbc76:
  uVar9 = *(uint *)(param_1 + 0x38);
  uVar3 = 0xffffffff;
  uVar7 = 0;
  while( true ) {
    iVar5 = (int)uVar11;
    if ((uVar9 < 0x7e) * uVar9 + (uint)(uVar9 >= 0x7e) * 0x7e <= uVar7) break;
    memw();
    uVar11 = (*(code *)&LAB_40184b76_2)(iVar4,uVar7,&uStack_70);
    if ((int)uVar11 != 0) goto LAB_400fbda5;
    if (uStack_70 == 0) {
LAB_400fbca3:
      uVar6 = 1;
LAB_400fbca5:
      uVar3 = 0xffffffff;
    }
    else {
      if (uStack_70 == 1) {
        uVar11 = FUN_400fb554(param_1,uVar7);
        if ((int)uVar11 == 0) goto LAB_400fbca3;
        goto LAB_400fbbfc;
      }
      uVar11 = FUN_40184b50(param_1,uVar7,&uStack_64);
      iVar5 = iStack_60;
      if ((int)uVar11 != 0) goto LAB_400fbbfc;
      iVar2 = FUN_400fc574(&uStack_64);
      uVar3 = uVar7;
      if (iVar5 == iVar2) {
        uVar11 = FUN_400faef8(param_1 + 0x44,&uStack_64,uVar7);
        if ((int)uVar11 != 0) goto LAB_400fbbfc;
        uVar1 = FUN_400faf84(param_1 + 0x44,0,&uStack_64);
        uVar10 = FUN_40184a1c(uStack_63);
        uVar6 = 1;
        uVar11 = uVar10;
        if ((int)uVar10 != 0) {
          uVar6 = (uint)bStack_62;
          for (uVar8 = uVar7; uVar11 = uVar10, uVar8 < uVar7 + uVar6; uVar8 = uVar8 + 1) {
            memw();
            uVar11 = (*(code *)&LAB_40184b76_2)(iVar4,uVar8,&uStack_70);
            uVar10 = CONCAT44((int)(uVar11 >> 0x20),uStack_70);
            if ((int)uVar11 != 0) goto LAB_400fbda5;
            if (uStack_70 != 2) {
              uVar11 = FUN_400fb554(param_1,uVar7);
              goto LAB_400fbca5;
            }
          }
        }
        if (uVar1 < uVar7) {
          uVar11 = FUN_400fb554(param_1,uVar1);
        }
      }
      else {
        uVar11 = FUN_400fb554(param_1,uVar7);
        if ((int)uVar11 != 0) goto LAB_400fbbfc;
        uVar6 = 1;
      }
    }
    uVar7 = uVar7 + uVar6;
  }
  uVar10 = uVar11 & 0xffffffff00000000;
  if (uVar3 == 0xffffffff) goto LAB_400fbb51;
  uStack_68 = 0;
  memw();
  uVar10 = FUN_400fb6ac(param_1,uStack_64,uStack_63,auStack_5c,&uStack_68,&uStack_44,0xff,0xff);
  iVar5 = (int)uVar10;
  uVar10 = uVar10 & 0xffffffff00000000;
  if ((iVar5 != 0) || (uVar10 = (ulonglong)uStack_68 << 0x20, uVar3 <= uStack_68))
  goto LAB_400fbb51;
  uVar11 = FUN_400fb554(param_1);
  iVar5 = 0;
  uVar10 = uVar11 & 0xffffffff00000000;
  if ((int)uVar11 == 0) goto LAB_400fbb51;
  *(undefined4 *)(param_1 + 0xc) = 0;
LAB_400fbda5:
  iVar5 = (int)uVar11;
  memw();
  uVar10 = uVar11;
LAB_400fbb51:
  iVar4 = iStack_24;
  memw();
  memw();
  if (iStack_24 == _DAT_3ffc5708) {
    return (int)uVar10;
  }
  memw();
  (*(code *)&SUB_40082ec4)(iVar5,(int)(uVar10 >> 0x20));
  goto LAB_400fbb6e;
LAB_400fbbfc:
  *(undefined4 *)(param_1 + 0xc) = 0;
  memw();
  goto LAB_400fbda5;
}

