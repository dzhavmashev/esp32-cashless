// Function : FUN_40131da0
// Address  : 0x40131da0
// Size     : 823 bytes


int FUN_40131da0(int *param_1,undefined4 *param_2,int *param_3,int *param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  uint *puVar7;
  int iVar8;
  uint *puVar9;
  undefined4 uVar10;
  uint uVar11;
  undefined8 uVar12;
  int iStack_84;
  int iStack_68;
  uint uStack_64;
  int iStack_60;
  undefined4 uStack_5c;
  int iStack_58;
  int iStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  int iStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 *puStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  uint *puStack_30;
  uint local_2c [11];
  
  memw();
  iVar1 = FUN_40131ad8(param_4,0);
  if (iVar1 == 0) {
    return -0xc;
  }
  uStack_34 = 3;
  puStack_30 = local_2c;
  iStack_68 = 1;
  uStack_64 = 0;
  iStack_60 = 0;
  uStack_5c = 1;
  iStack_58 = 0;
  iStack_54 = 0;
  uStack_50 = 1;
  uStack_4c = 0;
  iStack_48 = 0;
  uStack_44 = 1;
  uStack_40 = 0;
  puStack_3c = (undefined4 *)0x0;
  uStack_38 = 1;
  memw();
  iVar1 = FUN_40186078(param_3,param_4);
  if (iVar1 < 0) {
    if (((param_1 == (int *)0x0) || (iVar1 = FUN_40131700(param_1,0), iVar1 == 0)) &&
       ((param_2 == (undefined4 *)0x0 || (iVar1 = FUN_4013167c(param_2,param_3), iVar1 == 0)))) {
      return 0;
    }
  }
  else {
    iVar1 = FUN_4013167c(&iStack_68,param_3);
    if ((iVar1 == 0) && (iVar1 = FUN_4013167c(&uStack_5c,param_4), iVar1 == 0)) {
      uStack_5c = 1;
      iStack_68 = 1;
      memw();
      iVar1 = FUN_40131574(&uStack_50,param_3[1] + 2);
      if ((iVar1 == 0) &&
         ((iVar1 = FUN_40131700(&uStack_50,0), iVar1 == 0 &&
          (iVar1 = FUN_40131574(&uStack_44,param_3[1] + 2), iVar1 == 0)))) {
        uVar2 = FUN_40131798(&uStack_5c);
        if ((uVar2 & 0x1f) == 0x1f) {
          memw();
          iStack_84 = 0;
        }
        else {
          iStack_84 = 0x1f - (uVar2 & 0x1f);
          memw();
          iVar1 = FUN_40131980(&iStack_68,iStack_84);
          if ((iVar1 != 0) || (iVar1 = FUN_40131980(&uStack_5c,iStack_84), iVar1 != 0))
          goto LAB_40131e19;
        }
        iVar5 = iStack_58;
        uVar2 = uStack_64;
        iVar8 = uStack_64 - iStack_58;
        iVar3 = iVar8 * 0x20;
        iVar1 = FUN_40131980(&uStack_5c,iVar3);
        if (iVar1 == 0) {
          do {
            iVar1 = FUN_401860ec(&iStack_68,&uStack_5c);
            if (iVar1 < 0) {
              iVar1 = FUN_40131a34(&uStack_5c,iVar3);
              if (iVar1 == 0) {
                uVar4 = iVar5 - 1;
                iVar3 = ((uVar2 + 0x3fffffff) - iVar5) * 4;
                goto LAB_40131f20;
              }
              break;
            }
            piVar6 = (int *)(iStack_48 + iVar8 * 4);
            *piVar6 = *piVar6 + 1;
            memw();
            iVar1 = FUN_40131d30(&iStack_68,&iStack_68,&uStack_5c);
          } while (iVar1 == 0);
        }
      }
    }
  }
  goto LAB_40131e19;
LAB_40131f20:
  uVar2 = uVar2 - 1;
  if (uVar2 <= uVar4) goto LAB_40131f28;
  puVar9 = (uint *)(iStack_60 + uVar2 * 4);
  puVar7 = (uint *)(iStack_60 + uVar2 * 4 + -4);
  uVar11 = *(uint *)(iStack_54 + uVar4 * 4);
  iVar8 = -1;
  piVar6 = (int *)(iStack_48 + iVar3);
  if (*puVar9 < uVar11) {
    iVar8 = -1;
    if (uVar11 != 0) {
      memw();
      uVar12 = (*(code *)&SUB_4000cff8)(*puVar7,*puVar9,uVar11,0);
      iVar8 = (int)uVar12;
      if ((int)((ulonglong)uVar12 >> 0x20) != 0) {
        iVar8 = -1;
      }
    }
  }
  uVar11 = 0;
  *piVar6 = iVar8;
  if (uVar2 != 1) {
    uVar11 = puVar9[-2];
  }
  *puStack_30 = uVar11;
  puStack_30[1] = *puVar7;
  puStack_30[2] = *puVar9;
  *piVar6 = *piVar6 + 1;
  do {
    *(int *)(iStack_48 + iVar3) = *(int *)(iStack_48 + iVar3) + -1;
    memw();
    iVar8 = FUN_40131700(&uStack_44,0);
    if (iVar8 != 0) goto LAB_40131f7a;
    uVar10 = 0;
    if (uVar4 != 0) {
      uVar10 = *(undefined4 *)(iStack_54 + iVar5 * 4 + -8);
    }
    *puStack_3c = uVar10;
    puStack_3c[1] = *(undefined4 *)(iStack_54 + uVar4 * 4);
    memw();
    iVar8 = FUN_4013d778(&uStack_44,&uStack_44,*(undefined4 *)(iStack_48 + iVar3));
    if (iVar8 != 0) goto LAB_40131f7a;
    iVar8 = FUN_401860ec(&uStack_44,&uStack_38);
  } while (0 < iVar8);
  iVar8 = FUN_4013d778(&uStack_44,&uStack_5c,*(undefined4 *)(iStack_48 + iVar3));
  if (iVar8 != 0) goto LAB_40131f7a;
  iVar8 = FUN_40131980(&uStack_44,iVar3 << 3);
  if ((iVar8 != 0) || (iVar8 = FUN_40131d30(&iStack_68,&iStack_68,&uStack_44), iVar8 != 0))
  goto LAB_40131f7a;
  iVar8 = FUN_40131ad8(&iStack_68,0);
  if (iVar8 < 0) {
    iVar8 = FUN_4013167c(&uStack_44,&uStack_5c);
    if (((iVar8 != 0) || (iVar8 = FUN_40131980(&uStack_44,iVar3 << 3), iVar8 != 0)) ||
       (iVar8 = FUN_40131d18(&iStack_68,&iStack_68,&uStack_44), iVar8 != 0)) goto LAB_40131f7a;
    *(int *)(iStack_48 + iVar3) = *(int *)(iStack_48 + iVar3) + -1;
  }
  iVar3 = iVar3 + -4;
  memw();
  goto LAB_40131f20;
LAB_40131f28:
  if (param_1 == (int *)0x0) {
LAB_40131f46:
    if (param_2 == (undefined4 *)0x0) goto LAB_40131e19;
    memw();
    iVar8 = FUN_40131a34(&iStack_68,iStack_84);
    if (iVar8 == 0) {
      iStack_68 = *param_3;
      memw();
      iVar8 = FUN_4013167c(param_2,&iStack_68);
      if (iVar8 == 0) {
        iVar5 = FUN_40131ad8(param_2,0);
        if (iVar5 != 0) goto LAB_40131e19;
        *param_2 = 1;
        iVar8 = 0;
      }
    }
  }
  else {
    memw();
    iVar8 = FUN_4013167c(param_1,&uStack_50);
    if (iVar8 == 0) {
      *param_1 = *param_3 * *param_4;
      goto LAB_40131f46;
    }
  }
LAB_40131f7a:
  iVar1 = iVar8;
  memw();
LAB_40131e19:
  FUN_40131548(&iStack_68);
  FUN_40131548(&uStack_5c);
  FUN_40131548(&uStack_50);
  FUN_40131548(&uStack_44);
  FUN_4013ae54(local_2c,0xc);
  return iVar1;
}

