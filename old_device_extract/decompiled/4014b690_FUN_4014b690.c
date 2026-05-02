// Function : FUN_4014b690
// Address  : 0x4014b690
// Size     : 833 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4014b690(byte *param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  byte bVar5;
  undefined1 uVar6;
  char *pcVar7;
  int iVar8;
  char cVar9;
  undefined1 uVar10;
  byte bVar11;
  undefined1 uVar12;
  uint uVar13;
  int *piVar14;
  undefined1 uVar15;
  int iVar16;
  int iVar17;
  char cStack_40;
  byte bStack_3f;
  uint uStack_30;
  byte *pbStack_2c;
  uint uStack_28;
  
  pcVar7 = (char *)FUN_4015b1d4();
  iVar4 = _DAT_3ffc8804;
  iVar3 = _DAT_3ffc8800;
  if (((param_1 != (byte *)0x0) && (param_1[1] != 0)) &&
     (iVar8 = FUN_40154d88(*param_1), iVar8 == 0)) {
    FUN_40147fe4(1,4,2,0x3f4365ef);
    param_1[1] = 0;
    memw();
  }
  iVar8 = _DAT_3ffc8804;
  if (((_DAT_3ffc8804 != 0) && (_DAT_3ffc8800 != 0)) &&
     ((pbStack_2c = param_1, param_1 != (byte *)0x0 ||
      ((*(int *)(_DAT_3ffc8800 + 0xe4) != 0 &&
       (pbStack_2c = (byte *)(*(int *)(_DAT_3ffc8800 + 0xe4) + 0xab),
       *(int *)(_DAT_3ffc8800 + 0x98) != 0)))))) {
    bVar11 = *pbStack_2c;
    if (0xd < (bVar11 - 1 & 0xff)) {
      memw();
      FUN_40147fe4(1,0x800,1,"",&DAT_3f423a5e,0x6b9);
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
    uStack_30 = (uint)*(byte *)(_DAT_3ffbfc54 + 0x3fa);
    uVar13 = (uint)*(byte *)(_DAT_3ffc8804 + 0x156);
    bVar5 = *(byte *)(_DAT_3ffc8804 + 0x157);
    if (bVar11 == uVar13) {
      bVar1 = false;
      if (bVar5 == 0) goto LAB_4014b6dc;
LAB_4014b758:
      bVar11 = pbStack_2c[1];
      if (bVar11 == 0) {
        if (!bVar1) goto LAB_4014b6dc;
        if (*(byte *)(iVar8 + 0x156) < 5) {
          uVar15 = 1;
        }
        else {
          uVar15 = 2;
        }
        *(undefined1 *)(iVar8 + 0x157) = uVar15;
        memw();
        memw();
      }
      else if (bVar5 == bVar11) {
        if (!bVar1) goto LAB_4014b6dc;
      }
      else {
        *(byte *)(iVar8 + 0x157) = bVar11;
        memw();
        memw();
      }
    }
    else {
      *(byte *)(_DAT_3ffc8804 + 0x156) = bVar11;
      memw();
      if (bVar5 != 0) {
        bVar1 = true;
        goto LAB_4014b758;
      }
    }
    memw();
    uStack_28 = uVar13;
    FUN_40147fe4(1,0x4000,3,0x3f434db0,uVar13,bVar5,*(undefined1 *)(iVar8 + 0x156),
                 *(undefined1 *)(iVar8 + 0x157));
    if (*(char *)(iVar8 + 0x156) == '\x0e') {
      *(undefined1 *)(iVar8 + 0x157) = 0;
      *(undefined1 *)(iVar8 + 0x168) = 1;
      memw();
      memw();
      FUN_4015469c(iVar8,1);
      FUN_4014aea0(iVar8);
      FUN_4014de24(1);
    }
    if ((uStack_30 != 1) && (uStack_28 == 0xe)) {
      *(char *)(iVar8 + 0x168) = (char)uStack_30;
      memw();
      memw();
      FUN_4015469c(iVar8,uStack_30);
      if (uStack_30 == 3) {
        FUN_4014a9bc(iVar8);
      }
      if (pbStack_2c[1] != 0) {
        *(byte *)(iVar8 + 0x157) = pbStack_2c[1];
        memw();
        memw();
        FUN_4014de24(1,2);
      }
    }
    iVar2 = _DAT_3ffbfc54;
    piVar14 = (int *)(iVar8 + 0xf0);
    for (iVar17 = 1; iVar17 <= (int)(uint)*(byte *)(iVar2 + 0x3f6); iVar17 = iVar17 + 1) {
      iVar16 = *piVar14;
      if ((iVar16 != 0) && (*(short *)(iVar16 + 0x26) != 0)) {
        cVar9 = *(char *)(iVar8 + 0x156);
        *(char *)(iVar16 + 0xab) = cVar9;
        memw();
        if (*(char *)(iVar16 + 0xac) == '\x01') {
          if ((byte)(cVar9 - 1U) < 9) {
LAB_4014b842:
            *(undefined1 *)(iVar16 + 0xac) = *(undefined1 *)(iVar8 + 0x157);
            memw();
          }
          else {
            memw();
          }
        }
        else if (((byte)(cVar9 - 5U) < 9) && (*(char *)(iVar16 + 0xac) == '\x02'))
        goto LAB_4014b842;
      }
      piVar14 = piVar14 + 1;
    }
    memw();
  }
LAB_4014b6dc:
  bStack_3f = 0;
  memw();
  if (iVar4 == 0) {
    memw();
    if (iVar3 == 0) {
      return;
    }
    cStack_40 = *(char *)(iVar3 + 0x156);
    memw();
    cVar9 = cStack_40;
    if (param_1 == (byte *)0x0) {
      cVar9 = '\0';
    }
  }
  else {
    cStack_40 = *(char *)(iVar4 + 0x156);
    memw();
    memw();
    cVar9 = cStack_40;
  }
  memw();
  iVar8 = FUN_4014b5d0();
  if (iVar8 == 0) {
    if (param_1 == (byte *)0x0) goto LAB_4014b8f9;
    bVar11 = param_1[1];
    if (bVar11 == 1) {
      bVar5 = *param_1 - 1;
    }
    else {
      if (bVar11 != 2) goto LAB_4014b8f9;
      bVar5 = *param_1 - 5;
    }
    if (8 < bVar5) goto LAB_4014b8f9;
LAB_4014b8f3:
    memw();
    bStack_3f = bVar11;
  }
  else {
    if (iVar4 != 0) {
      bVar11 = *(byte *)(iVar4 + 0x157);
      if (bVar11 == 1) {
        bVar5 = *(char *)(iVar4 + 0x156) - 1;
      }
      else {
        if (bVar11 != 2) goto LAB_4014b8b8;
        bVar5 = *(char *)(iVar4 + 0x156) - 5;
      }
      if (bVar5 < 9) goto LAB_4014b8f3;
    }
LAB_4014b8b8:
    if ((iVar3 != 0) && (*(int *)(iVar3 + 0xe4) != 0)) {
      bStack_3f = *(byte *)(*(int *)(iVar3 + 0xe4) + 0xac);
      memw();
      memw();
    }
  }
LAB_4014b8f9:
  bVar11 = 0;
  if (cVar9 != '\0') {
    bVar11 = bStack_3f;
  }
  memw();
  (**(code **)(_DAT_3ffc1a34 + 0x1a4))(cVar9,bVar11);
  uVar15 = 0xff;
  uVar12 = 0xff;
  if (iVar4 != 0) {
    uVar15 = *(undefined1 *)(iVar4 + 0x156);
    uVar12 = *(undefined1 *)(iVar4 + 0x157);
  }
  uVar6 = 0xff;
  uVar10 = 0xff;
  if (iVar3 != 0) {
    uVar6 = *(undefined1 *)(iVar3 + 0x156);
    uVar10 = *(undefined1 *)(iVar3 + 0x157);
  }
  memw();
  FUN_40147fe4(1,4,3,0x3f434d75,cStack_40,bStack_3f,*pcVar7,pcVar7[1],uVar15,uVar12,uVar6,uVar10,
               *(undefined1 *)(_DAT_3ffbfc54 + 0x3f3));
  if ((cStack_40 == *pcVar7) && (bStack_3f == pcVar7[1])) {
    return;
  }
  FUN_4015b1ec(&cStack_40);
  if ((DAT_3ffc9022 & 1) == 0) {
    FUN_4015b284(&cStack_40);
    return;
  }
  FUN_40147fe4(1,8,3,0x3f434d49);
  return;
}

