// Function : FUN_40117650
// Address  : 0x40117650
// Size     : 1442 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_40117650(int param_1,undefined4 *param_2)

{
  byte bVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  short sVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  undefined4 *puVar12;
  uint3 uVar13;
  undefined4 *puVar14;
  byte *pbVar15;
  uint uVar16;
  uint3 uVar17;
  uint uVar18;
  byte *pbVar19;
  
  puVar12 = *(undefined4 **)(param_1 + 4);
  memw();
  uVar9 = FUN_40109eec(*puVar12);
  if (uVar9 >> 0x1c != 6) {
LAB_40117682:
    FUN_4010bb10(param_1);
    return 0;
  }
  if ((*(ushort *)(param_1 + 10) < 0x28) ||
     (uVar2 = *(ushort *)(param_1 + 8), iVar10 = FUN_40185290(*(undefined2 *)(puVar12 + 1)),
     (int)(uVar2 - 0x27) <= iVar10)) {
    FUN_40185290(*(undefined2 *)(puVar12 + 1));
    goto LAB_40117682;
  }
  sVar8 = FUN_40185290(*(undefined2 *)(puVar12 + 1));
  FUN_4010bd2c(param_1,sVar8 + 0x28);
  uVar13 = (uint3)puVar12[6];
  uVar16 = puVar12[6];
  iVar10 = puVar12[7];
  iVar3 = puVar12[8];
  iVar4 = puVar12[9];
  DAT_3ffc83f4 = 0;
  DAT_3ffc83e0 = (byte)(uVar9 >> 0x1c);
  memw();
  uVar9 = puVar12[2];
  iVar5 = puVar12[3];
  iVar6 = puVar12[4];
  iVar7 = puVar12[5];
  DAT_3ffc83dc = 0;
  memw();
  _DAT_3ffc83cc = uVar9;
  _DAT_3ffc83d0 = iVar5;
  _DAT_3ffc83d4 = iVar6;
  _DAT_3ffc83d8 = iVar7;
  _DAT_3ffc83e4 = uVar16;
  _DAT_3ffc83e8 = iVar10;
  _DAT_3ffc83ec = iVar3;
  _DAT_3ffc83f0 = iVar4;
  DAT_3ffc83f8 = DAT_3ffc83e0;
  if ((((uVar16 == 0 && iVar10 == 0) && (iVar3 == -0x10000)) ||
      ((uVar9 == 0 && iVar5 == 0 && (iVar6 == -0x10000)))) || ((uVar9 & 0xff) == 0xff))
  goto LAB_40117682;
  uVar17 = uVar13 & 0xc0ff;
  if ((uVar17 == 0x80fe) || (DAT_3ffc83f4 = '\0', ((uVar13 & 0x8fff) - 0x1ff & 0xfffffeff) == 0)) {
    DAT_3ffc83f4 = *(char *)((int)param_2 + 0xee) + '\x01';
  }
  memw();
  uVar13 = (uint3)puVar12[2] & 0xc0ff;
  DAT_3ffc83dc = '\0';
  if (uVar13 == 0x80fe) {
    DAT_3ffc83dc = *(char *)((int)param_2 + 0xee) + '\x01';
  }
  memw();
  puVar14 = param_2;
  _DAT_3ffc83b8 = param_2;
  _DAT_3ffc83bc = param_2;
  _DAT_3ffc83c4 = puVar12;
  if ((uVar16 & 0xff) == 0xff) {
    if (((uVar16 - 0x1ff & 0xfffffeff) != 0 || (iVar10 != 0 || iVar3 != 0)) || (iVar4 != 0x1000000))
    {
      memw();
      iVar10 = FUN_401854d8(param_2,&DAT_3ffc83e4);
      if (iVar10 == 0) goto LAB_401178b5;
    }
  }
  else {
    memw();
    iVar11 = FUN_40117278(param_2);
    if (iVar11 == 0) {
      if ((((uVar13 == 0x80fe) || (uVar17 == 0x80fe)) ||
          ((iVar3 == 0 && (uVar16 == 0 && iVar10 == 0) && (iVar4 == 0x1000000)))) ||
         ((iVar6 == 0 && (uVar9 == 0 && iVar5 == 0) && (iVar7 == 0x1000000)))) {
LAB_401178b5:
        puVar14 = (undefined4 *)0x0;
      }
      else {
        puVar14 = (undefined4 *)&DAT_3ffc83fc;
        do {
          puVar14 = (undefined4 *)*puVar14;
          if (puVar14 == (undefined4 *)0x0) goto LAB_401178b5;
        } while ((puVar14 == param_2) || (iVar10 = FUN_40117278(puVar14), iVar10 == 0));
      }
    }
  }
  if (((((_DAT_3ffc83cc != 0 || _DAT_3ffc83d0 != 0) || _DAT_3ffc83d4 != 0) || _DAT_3ffc83d8 != 0) ||
      (((_DAT_3ffc83e4 == 0x2ff && (_DAT_3ffc83ec == 0x1000000)) && (DAT_3ffc83f0 == -1)))) &&
     (puVar14 != (undefined4 *)0x0)) {
    pbVar15 = (byte *)((int)puVar12 + 6);
    memw();
    _DAT_3ffc83b8 = puVar14;
    FUN_4010ba9c(param_1,0x28);
    uVar9 = 0x28;
LAB_401179ae:
    bVar1 = *pbVar15;
    if (bVar1 != 0x3b) {
      if (bVar1 == 0x2b) {
        pbVar15 = *(byte **)(param_1 + 4);
        bVar1 = pbVar15[1];
        uVar16 = (bVar1 + 1) * 8;
        if ((*(ushort *)(param_1 + 10) < uVar16) || (*(ushort *)(param_1 + 10) < 8))
        goto LAB_401178ea;
        uVar9 = uVar9 + uVar16 & 0xffff;
        if (pbVar15[3] != 0) {
          uVar18 = bVar1 & 1;
          if ((bVar1 & 1) == 0) {
            if (pbVar15[2] - 2 < 2) goto LAB_40117ac3;
            pbVar19 = pbVar15 + 2;
          }
          else {
            pbVar19 = pbVar15 + 1;
LAB_40117b60:
            uVar18 = 0;
          }
          goto LAB_40117b26;
        }
LAB_40117ac3:
        FUN_4010ba9c(param_1,uVar16);
        if (*pbVar15 == 0) goto LAB_40117ace;
        goto LAB_401179ae;
      }
      if (bVar1 < 0x2c) {
        if (bVar1 != 0) goto LAB_401179c5;
        pbVar15 = *(byte **)(param_1 + 4);
        uVar16 = (pbVar15[1] + 1) * 8;
        if ((*(ushort *)(param_1 + 10) < 8) || (*(ushort *)(param_1 + 10) < uVar16))
        goto LAB_401178ea;
        iVar10 = 2;
LAB_40117ab9:
        if ((int)uVar16 <= iVar10) goto LAB_40117abc;
        pbVar19 = pbVar15 + iVar10;
        bVar1 = *pbVar19;
        if (bVar1 != 1) {
          uVar18 = 0xffffffff;
          if (bVar1 == 0) goto LAB_40117ae8;
          if ((bVar1 != 5) && (bVar1 != 0xc2)) {
            bVar1 = bVar1 >> 6;
            if (bVar1 == 2) goto LAB_40117b24;
            if (bVar1 != 3) {
              if (bVar1 != 1) goto LAB_40117ae5;
              goto LAB_401178ea;
            }
LAB_40117b18:
            if (DAT_3ffc83e4 == -1) goto LAB_401178ea;
LAB_40117b24:
            uVar18 = 2;
            goto LAB_40117b26;
          }
        }
LAB_40117ae5:
        uVar18 = (uint)pbVar19[1];
LAB_40117ae8:
        iVar10 = iVar10 + 2 + uVar18;
        goto LAB_40117ab9;
      }
      if (bVar1 == 0x2c) {
        pbVar15 = *(byte **)(param_1 + 4);
        if (7 < *(ushort *)(param_1 + 10)) {
          uVar9 = uVar9 + 8 & 0xffff;
          uVar16 = FUN_40185290(*(undefined2 *)(pbVar15 + 2));
          if (((uVar16 & 1) != 0) &&
             (uVar16 = FUN_40185290(*(undefined2 *)(puVar12 + 1)), (uVar16 & 7) != 0)) {
            pbVar19 = (byte *)(puVar12 + 1);
            goto LAB_40117b60;
          }
          if ((*(ushort *)(pbVar15 + 2) & 63999) == 0) {
            uVar16 = 8;
            goto LAB_40117ac3;
          }
        }
        goto LAB_401178ea;
      }
      if (bVar1 == 0x3c) {
        pbVar15 = *(byte **)(param_1 + 4);
        uVar16 = (pbVar15[1] + 1) * 8;
        if ((7 < *(ushort *)(param_1 + 10)) && (uVar16 <= *(ushort *)(param_1 + 10))) {
          iVar10 = 2;
LAB_40117a66:
          if ((int)uVar16 <= iVar10) goto LAB_40117abc;
          pbVar19 = pbVar15 + iVar10;
          bVar1 = *pbVar19;
          if (bVar1 != 5) {
            if (bVar1 < 6) {
              uVar18 = 0xffffffff;
              if (bVar1 != 0) {
                if (bVar1 != 1) goto LAB_40117a84;
                goto LAB_40117b0d;
              }
              goto LAB_40117b10;
            }
            if ((bVar1 != 0xc2) && (bVar1 != 0xc9)) {
LAB_40117a84:
              bVar1 = bVar1 >> 6;
              if (bVar1 != 2) {
                if (bVar1 != 3) {
                  if (bVar1 != 1) goto LAB_40117b0d;
                  goto LAB_401178ea;
                }
                goto LAB_40117b18;
              }
              goto LAB_40117b24;
            }
          }
LAB_40117b0d:
          uVar18 = (uint)pbVar19[1];
LAB_40117b10:
          iVar10 = iVar10 + 2 + uVar18;
          goto LAB_40117a66;
        }
        goto LAB_401178ea;
      }
    }
LAB_401179c5:
    _DAT_3ffc83c8 = (undefined2)uVar9;
    memw();
    memw();
    FUN_4010ba8c(param_1,uVar9);
    iVar10 = FUN_4010c1b0(param_1,param_2);
    if (iVar10 == 1) goto LAB_401178f2;
    memw();
    FUN_4010ba9c(param_1,uVar9);
    bVar1 = *pbVar15;
    if (bVar1 == 0x11) {
      FUN_40113498(param_1,param_2);
      goto LAB_401178f2;
    }
    if (bVar1 < 0x12) {
      if (bVar1 == 6) {
        FUN_4010efac(param_1,param_2);
        goto LAB_401178f2;
      }
    }
    else {
      if (bVar1 == 0x3a) {
        FUN_4011715c(param_1,param_2);
        goto LAB_401178f2;
      }
      if (bVar1 == 0x3b) goto LAB_401178ea;
    }
    if (iVar10 == 2) goto LAB_401178ea;
    FUN_4010ba8c(param_1,uVar9);
    if ((DAT_3ffc83e4 == -1) || (*(char *)((int)puVar12 + 6) == ':')) goto LAB_401178ea;
    goto LAB_40117ace;
  }
LAB_401178ea:
  FUN_4010bb10(param_1);
LAB_401178f2:
  memw();
  memw();
  DAT_3ffc83f4 = 0;
  _DAT_3ffc83f0 = 0;
  _DAT_3ffc83ec = 0;
  _DAT_3ffc83e8 = 0;
  _DAT_3ffc83e4 = 0;
  DAT_3ffc83dc = 0;
  _DAT_3ffc83d8 = 0;
  _DAT_3ffc83d4 = 0;
  _DAT_3ffc83d0 = 0;
  _DAT_3ffc83cc = 0;
  _DAT_3ffc83c8 = 0;
  _DAT_3ffc83c4 = (undefined4 *)0x0;
  _DAT_3ffc83bc = (undefined4 *)0x0;
  _DAT_3ffc83b8 = (undefined4 *)0x0;
  return 0;
LAB_40117abc:
  uVar9 = uVar9 + uVar16 & 0xffff;
  goto LAB_40117ac3;
LAB_40117ace:
  uVar18 = 1;
  pbVar19 = pbVar15;
LAB_40117b26:
  FUN_4011725c(param_1,uVar18,pbVar19);
  goto LAB_401178ea;
}

