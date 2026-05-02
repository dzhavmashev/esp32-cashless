// Function : FUN_40188f54
// Address  : 0x40188f54
// Size     : 939 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_40188f54(uint param_1)

{
  uint uVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  undefined4 uVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  undefined1 auStack_c0 [8];
  undefined1 *puStack_b8;
  int iStack_98;
  undefined1 auStack_90 [5];
  char cStack_8b;
  char cStack_8a;
  char cStack_89;
  undefined1 uStack_83;
  undefined1 uStack_7d;
  undefined1 auStack_70 [8];
  undefined4 uStack_68;
  undefined1 *puStack_60;
  uint uStack_5c;
  int iStack_58;
  uint uStack_54;
  undefined4 uStack_50;
  uint uStack_4c;
  uint uStack_48;
  uint uStack_44;
  uint uStack_40;
  uint uStack_3c;
  uint uStack_38;
  int iStack_34;
  int *piStack_30;
  int iStack_2c;
  
  param_1 = param_1 & 0xff;
  uVar9 = 4;
  uVar1 = (uint)*(byte *)(_DAT_3ffc0034 + param_1 * 0x30 + 0x2c);
  if (uVar1 < 8) {
    if ((uVar1 == 0) || (uVar1 == 3)) {
      uVar9 = 2;
    }
    else {
      uVar9 = 3;
      if ((2 < uVar1) && (uVar9 = 1, 5 < uVar1)) {
        uVar9 = 0;
      }
    }
  }
  uStack_50 = FUN_40187ce0(uVar9);
  iVar3 = _DAT_3ffc0034 + param_1 * 0x30;
  iVar6 = *(int *)(iVar3 + 0x34);
  if (iVar6 != 0) {
    iVar5 = _DAT_3ffc0034 + param_1 * 0x30;
    if (*(char *)(iVar5 + 0x29) == '\0') {
      memw();
      FUN_40147fe4(6,0x800,1,"","s_func_app.c",0xa93);
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
    piStack_30 = *(int **)(iVar6 + 0x2c);
    iStack_2c = _DAT_3ffc0034;
    memw();
    (*(code *)&SUB_4008b3d0)(auStack_90,piStack_30,0x20);
    uStack_7d = 5;
    cStack_8a = '\0';
    cStack_89 = '\0';
    memw();
    puStack_b8 = auStack_70;
    uStack_68 = *(undefined4 *)(iVar6 + 4);
    if ((*(char *)(iVar5 + 0x4d) == '\0') && (*(char *)(iVar5 + 0x41) == '\x02')) {
      uStack_54 = *(uint *)(iVar5 + 0x44);
      memw();
    }
    else {
      uStack_54 = (uint)*(ushort *)(iVar6 + 0x16) + (uint)*(ushort *)(iVar6 + 0x14);
    }
    iVar5 = iStack_2c + param_1 * 0x30;
    uStack_48 = (uint)*(ushort *)(iVar5 + 0x2a);
    uStack_3c = (uint)*(byte *)(iVar5 + 0x28);
    uStack_5c = 1 << 0x20 - (0x20 - (uVar1 & 0x1f));
    uStack_44 = *(uint *)(iVar3 + 0x3c);
    uStack_40 = *(uint *)(iVar3 + 0x38);
    uStack_38 = (uStack_5c ^ 0xffffffff) & 0xff;
    uStack_4c = (uint)*(byte *)((int)piStack_30 + 5);
    iStack_34 = param_1 * 0x30;
    iVar3 = 0;
    cVar2 = '\0';
    iVar5 = *(int *)(iVar6 + 0x24);
    iStack_58 = 0;
    memw();
    iStack_98 = iVar6;
    puStack_60 = auStack_c0;
    while (iVar7 = *(int *)(puStack_60 + 0x28), iVar7 != 0) {
      if ((*(char *)(_DAT_3ffc0034 + iStack_34 + 0x4d) == '\0') &&
         (*(char *)(_DAT_3ffc0034 + iStack_34 + 0x41) == '\x02')) {
        if (cVar2 == '\0') {
          cStack_89 = cStack_89 + '\x01';
          memw();
        }
        memw();
        if ((**(uint **)(iVar7 + 8) & 0x40000000) != 0) {
          cVar2 = cVar2 + '\x01';
          memw();
        }
      }
      else {
        cStack_89 = cStack_89 + '\x01';
        memw();
      }
      uVar10 = *(byte *)(*(int *)(*(int *)(iVar7 + 4) + 4) + 3) - uStack_48;
      uVar11 = uVar10 & 0xff;
      iStack_2c = iVar7;
      if (uVar11 < 0x40) {
        uVar8 = uStack_44;
        if (0x1f < uVar11) {
          uVar8 = uStack_40;
        }
        if ((uVar8 & 1 << ((byte)uVar10 & 0x1f)) == 0) goto LAB_401890ee;
        piStack_30 = (int *)0x1;
        cStack_8a = cStack_8a + '\x01';
        memw();
        memw();
LAB_4018913b:
        memw();
        (*(code *)&SUB_4000ab7c)(**(uint **)(*(int *)(iStack_2c + 4) + 4) & 0xfff,4);
        FUN_40189c74(puStack_60,iStack_2c);
        **(uint **)(iStack_2c + 0x2c) = **(uint **)(iStack_2c + 0x2c) | 0x400000;
        if (piStack_30 == (int *)0x0) {
          iVar3 = *(int *)(*(int *)(iStack_2c + 4) + 4);
          if ((**(uint **)(iStack_2c + 0x2c) & 0x40000) != 0) {
            iVar3 = iVar3 + 4;
          }
          FUN_401604bc(uStack_50,iStack_2c,0);
        }
        else {
          if (uStack_5c == (*(byte *)(iVar5 + 0x26) & uStack_5c)) {
            iVar3 = *(int *)(*(int *)(iStack_2c + 4) + 4);
            if ((**(uint **)(iStack_2c + 0x2c) & 0x40000) != 0) {
              iVar3 = iVar3 + 4;
            }
            *(byte *)(iVar5 + 0x26) = *(byte *)(iVar5 + 0x26) & (byte)uStack_38;
            memw();
          }
          memw();
          FUN_40188010(uStack_50,iStack_2c,0);
        }
      }
      else {
LAB_401890ee:
        memw();
        iVar7 = FUN_40187d04(iVar7);
        if (iVar7 != 0) {
          piStack_30 = (int *)0x0;
          goto LAB_4018913b;
        }
        if ((cVar2 == '\0') ||
           ((cVar2 == '\x01' && (memw(), (**(uint **)(iStack_2c + 8) & 0x40000000) != 0)))) {
          iVar7 = *(int *)(*(int *)(iStack_2c + 4) + 4);
          if ((**(uint **)(iStack_2c + 0x2c) & 0x40000) != 0) {
            iVar7 = iVar7 + 4;
          }
          *(byte *)(iVar7 + 1) = *(byte *)(iVar7 + 1) | 8;
          memw();
        }
        puStack_60 = *(undefined1 **)(puStack_60 + 0x28);
        iStack_58 = iStack_2c;
        memw();
      }
    }
    cStack_8b = (char)uStack_4c;
    if (uStack_3c == 0) {
      uStack_7d = 1;
      memw();
      uStack_83 = *(undefined1 *)(*(int *)(iVar6 + 0x2c) + 0xd);
      memw();
      memw();
    }
    else {
      cStack_8b = cStack_8b + '\x01';
      memw();
    }
    iVar4 = param_1 + 1;
    piStack_30 = (int *)&DAT_3ffc0034;
    memw();
    FUN_40189534(iVar5,auStack_90,uStack_54 & 0xffff);
    iVar6 = iStack_98;
    iVar7 = FUN_40189c90(iVar5);
    if ((iVar7 == 0) || (iVar5 = FUN_40189ca4(iVar5,uVar1), iVar5 == 0)) {
      if (iVar6 != 0) {
        iVar5 = iVar6;
        if (iVar6 == *(int *)(*piStack_30 + iVar4 * 0x30 + 4)) {
          memw();
          FUN_40163ab4(iVar6);
        }
        for (; iVar5 != iStack_58; iVar5 = *(int *)(iVar5 + 0x28)) {
          *(undefined4 *)(*(int *)(iVar5 + 8) + 8) = 0;
        }
        iVar12 = *piStack_30;
        iVar7 = iVar12 + param_1 * 0x30;
        iVar13 = *(int *)(iVar7 + 0x20);
        *(int *)(iVar5 + 0x28) = iVar13;
        if (iVar13 == 0) {
          *(int *)(iVar7 + 0x24) = iVar5 + 0x28;
        }
        *(int *)(iVar12 + param_1 * 0x30 + 0x20) = iVar6;
      }
      *(undefined4 *)(*piStack_30 + iVar4 * 0x30 + 4) = 0;
    }
    else {
      *(int *)(*piStack_30 + iVar4 * 0x30 + 4) = iVar6;
      if (iVar6 != 0) {
        **(uint **)(iVar6 + 0x2c) = **(uint **)(iVar6 + 0x2c) | 0x480000;
        memw();
      }
    }
    if (iVar3 != 0) {
      memw();
      FUN_40162dac(uVar1,iVar3 + 4,iVar3 + 10,(*(ushort *)(iVar3 + 0x16) >> 4) + 1 & 0xfff);
      FUN_40162f2c(uVar1,param_1);
      return 0;
    }
  }
  FUN_40188470(param_1);
  uVar9 = 4;
  if (uVar1 < 8) {
    if ((uVar1 == 0) || (uVar1 == 3)) {
      uVar9 = 2;
    }
    else {
      uVar9 = 3;
      if ((2 < uVar1) && (uVar9 = 1, 5 < uVar1)) {
        uVar9 = 0;
      }
    }
  }
  uVar9 = FUN_40188e54(uVar9);
  return uVar9;
}

