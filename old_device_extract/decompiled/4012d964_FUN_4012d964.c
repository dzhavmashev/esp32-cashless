// Function : FUN_4012d964
// Address  : 0x4012d964
// Size     : 6533 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 * FUN_4012d964(int *param_1)

{
  char cVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  short sVar6;
  undefined2 uVar7;
  ushort *puVar8;
  byte bVar9;
  undefined1 uVar10;
  undefined1 *puVar11;
  undefined1 *puVar12;
  uint uVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  uint uVar17;
  int iVar18;
  int *piVar19;
  undefined4 uVar20;
  ushort *puVar21;
  char *pcVar22;
  byte *pbVar23;
  undefined1 *puVar24;
  int iVar25;
  bool bVar26;
  int iVar27;
  uint uVar28;
  uint uVar29;
  short sVar30;
  undefined1 *puVar31;
  ushort uVar32;
  undefined1 *puVar33;
  undefined4 uVar34;
  undefined1 *puStack_7c;
  uint uStack_74;
  ushort *puStack_70;
  int iStack_6c;
  undefined4 uStack_68;
  undefined1 auStack_64 [16];
  undefined1 auStack_54 [48];
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  if ((param_1[1] == 0x10) || (param_1[0x11] == 0)) {
LAB_4012d97d:
    puVar11 = (undefined1 *)0xffff8f00;
    goto LAB_4012d980;
  }
  puStack_7c = (undefined1 *)FUN_40129bc8(param_1);
  if (puStack_7c != (undefined1 *)0x0) goto LAB_4012da49;
  if (((*(char *)(*param_1 + 5) == '\x01') && (*(char *)(param_1[0x11] + 7) == '\x01')) &&
     (puVar11 = (undefined1 *)FUN_40129fc8(param_1), puVar11 != (undefined1 *)0x0))
  goto LAB_4012da15;
  iVar18 = param_1[1];
  if (iVar18 == 0xc) {
    if (*(char *)(param_1[0x11] + 5) == '\0') {
      puVar11 = (undefined1 *)FUN_4012b260(param_1);
      goto LAB_4012da15;
    }
    param_1[1] = 0x11;
  }
  else {
    if (iVar18 == 7) {
      puVar11 = (undefined1 *)FUN_4012c394(param_1);
      goto LAB_4012da15;
    }
    if (iVar18 < 8) {
      if (iVar18 == 3) {
        puVar11 = (undefined1 *)FUN_4012d208(param_1);
        goto LAB_4012da15;
      }
      if (3 < iVar18) goto LAB_4012da68;
      if (iVar18 == 1) {
        pcVar22 = (char *)*param_1;
        if (*(int *)(pcVar22 + 0x4c) == 0) {
          puVar11 = (undefined1 *)0xffff8c00;
          goto LAB_4012e5d8;
        }
        bVar26 = param_1[2] == 0;
        if (bVar26) {
          param_1[4] = (uint)(byte)pcVar22[2];
          param_1[5] = (uint)(byte)pcVar22[3];
        }
        if (*pcVar22 == '\0') goto LAB_4012d97d;
        iVar27 = param_1[0x33];
        memw();
        FUN_401858e4(*pcVar22,pcVar22[1],pcVar22[5],iVar27 + 4);
        iVar18 = param_1[0x11];
        if ((*(char *)(*param_1 + 5) != '\x01') || (*(int *)(iVar18 + 0x240) == 0)) {
          uVar34 = (*(code *)&SUB_4008cd2c)(0);
          *(char *)(iVar18 + 0x470) = (char)((uint)uVar34 >> 0x18);
          *(char *)(iVar18 + 0x471) = (char)((uint)uVar34 >> 0x10);
          *(char *)(iVar18 + 0x472) = (char)((uint)uVar34 >> 8);
          *(char *)(iVar18 + 0x473) = (char)uVar34;
          memw();
          memw();
          puVar11 = (undefined1 *)
                    (**(code **)(*param_1 + 0x4c))
                              (*(undefined4 *)(*param_1 + 0x50),iVar18 + 0x474,0x1c);
          if (puVar11 != (undefined1 *)0x0) goto LAB_4012da15;
        }
        (*(code *)&SUB_4008b3d0)(iVar27 + 6,param_1[0x11] + 0x470,0x20);
        iVar14 = param_1[0x10];
        iVar18 = *(int *)(iVar14 + 0x10);
        if ((iVar18 - 0x10U < 0x11) && (param_1[2] == 0)) {
          if (*(char *)(param_1[0x11] + 2) == '\0') {
            iVar18 = 0;
          }
        }
        else {
          iVar18 = 0;
        }
        if (((bVar26) && (*(int *)(iVar14 + 0x6c) != 0)) && (*(int *)(iVar14 + 0x70) != 0)) {
          puVar11 = (undefined1 *)
                    (**(code **)(*param_1 + 0x4c))
                              (*(undefined4 *)(*param_1 + 0x50),iVar14 + 0x14,0x20);
          if (puVar11 != (undefined1 *)0x0) goto LAB_4012da15;
          iVar18 = 0x20;
          *(undefined4 *)(param_1[0x10] + 0x10) = 0x20;
        }
        *(char *)(iVar27 + 0x26) = (char)iVar18;
        memw();
        iVar14 = 0;
        while (iVar18 != iVar14) {
          iVar25 = param_1[0x10] + iVar14;
          iVar16 = iVar27 + iVar14;
          iVar14 = iVar14 + 1;
          *(undefined1 *)(iVar16 + 0x27) = *(undefined1 *)(iVar25 + 0x14);
          memw();
          memw();
        }
        puVar24 = (undefined1 *)(iVar27 + 0x27 + iVar18);
        puVar12 = (undefined1 *)(iVar27 + 0x4000);
        puVar11 = puVar24;
        if (*(char *)(*param_1 + 5) == '\x01') {
          if (puVar12 <= puVar24) goto LAB_4012dbf0;
          puVar11 = puVar24 + 1;
          if (*(int *)(param_1[0x11] + 0x240) == 0) {
            *puVar24 = 0;
            memw();
          }
          else {
            *puVar24 = *(undefined1 *)(param_1[0x11] + 0x244);
            memw();
            if ((puVar12 < puVar11) ||
               ((uint)((int)puVar12 - (int)puVar11) < (uint)*(byte *)(param_1[0x11] + 0x244)))
            goto LAB_4012dbf0;
            memw();
            (*(code *)&SUB_4008b3d0)(puVar11,*(undefined4 *)(param_1[0x11] + 0x240));
            puVar11 = puVar11 + *(byte *)(param_1[0x11] + 0x244);
          }
        }
        if ((puVar11 <= puVar12) && (1 < (uint)((int)puVar12 - (int)puVar11))) {
          puVar24 = puVar11 + 2;
          piVar19 = *(int **)(*param_1 + (param_1[5] + 0xc) * 4 + 4);
          uVar17 = 0;
          uStack_74 = 0;
          while (*piVar19 != 0) {
            memw();
            uVar34 = FUN_4012d7a8();
            memw();
            iVar18 = FUN_4012d910(uVar34,param_1,*(undefined1 *)(*param_1 + 3),
                                  *(undefined1 *)(*param_1 + 1));
            if (iVar18 == 0) {
              uVar28 = FUN_40185b6c(uVar34);
              if ((puVar12 < puVar24) || ((uint)((int)puVar12 - (int)puVar24) < 2))
              goto LAB_4012dbf0;
              uVar17 = uVar17 + 1;
              uStack_74 = uStack_74 | uVar28;
              *puVar24 = (char)((uint)*piVar19 >> 8);
              memw();
              puVar24[1] = (char)*piVar19;
              memw();
              puVar24 = puVar24 + 2;
            }
            piVar19 = piVar19 + 1;
            memw();
          }
          if (bVar26) {
            if ((puVar12 < puVar24) || ((uint)((int)puVar12 - (int)puVar24) < 2)) goto LAB_4012dbf0;
            *puVar24 = 0;
            uVar17 = uVar17 + 1;
            puVar24[1] = 0xff;
            memw();
            puVar24 = puVar24 + 2;
          }
          if (*(char *)(*param_1 + 0x10) == '\x01') {
            if ((puVar12 < puVar24) || ((uint)((int)puVar12 - (int)puVar24) < 2)) goto LAB_4012dbf0;
            *puVar24 = 0x56;
            uVar17 = uVar17 + 1;
            puVar24[1] = 0;
            puVar24 = puVar24 + 2;
          }
          *puVar11 = (char)(uVar17 >> 7);
          puVar11[1] = (char)(uVar17 << 1);
          memw();
          if ((puVar24 <= puVar12) && (1 < (uint)((int)puVar12 - (int)puVar24))) {
            *puVar24 = 1;
            puVar11 = puVar24 + 2;
            puVar24[1] = 0;
            memw();
            if ((puVar11 <= puVar12) && (1 < (uint)((int)puVar12 - (int)puVar11))) {
              if (param_1[0x3b] == 0) {
                uVar17 = 0;
              }
              else {
                if (puVar12 < puVar24 + 4) goto LAB_4012dbf0;
                memw();
                iVar18 = (*(code *)&SUB_4008c01c)();
                uVar17 = iVar18 + 9;
                if ((uint)((int)puVar12 - (int)(puVar24 + 4)) < uVar17) goto LAB_4012dbf0;
                cVar1 = (char)iVar18;
                puVar24[6] = (char)((uint)(iVar18 + 5) >> 8);
                puVar24[7] = cVar1 + '\x05';
                puVar24[4] = 0;
                puVar24[5] = 0;
                puVar24[8] = (char)((uint)(iVar18 + 3) >> 8);
                puVar24[10] = 0;
                puVar24[9] = cVar1 + '\x03';
                puVar24[0xb] = (char)((uint)iVar18 >> 8);
                puVar24[0xc] = cVar1;
                memw();
                memw();
                (*(code *)&SUB_4008b3d0)(puVar24 + 0xd,param_1[0x3b],iVar18);
              }
              if (param_1[2] == 1) {
                puVar31 = puVar11 + uVar17 + 2;
                if ((puVar12 < puVar31) ||
                   ((uint)((int)puVar12 - (int)puVar31) < param_1[0x81] + 5U)) goto LAB_4012dbf0;
                *puVar31 = 0xff;
                puVar31[1] = 1;
                puVar31[2] = 0;
                memw();
                puVar31[3] = (char)param_1[0x81] + '\x01';
                memw();
                puVar31[4] = (char)param_1[0x81];
                memw();
                memw();
                (*(code *)&SUB_4008b3d0)(puVar31 + 5,param_1 + 0x82,param_1[0x81]);
                iVar18 = param_1[0x81] + 5;
              }
              else {
                iVar18 = 0;
              }
              if (*(char *)(*param_1 + 1) == '\x03') {
                iVar14 = 0;
                iVar25 = *(int *)(*param_1 + 0xac);
                if (iVar25 != 0) {
LAB_4012deb6:
                  if (*(int *)(iVar25 + iVar14) != 0) goto LAB_4012deae;
                  if (iVar14 != 0) {
                    puVar31 = puVar11 + uVar17 + iVar18 + 2;
                    if ((puVar31 <= puVar12) && (iVar14 + 6U <= (uint)((int)puVar12 - (int)puVar31))
                       ) {
                      puVar33 = puVar31 + 6;
                      iVar14 = 0;
                      while( true ) {
                        piVar19 = (int *)(iVar25 + iVar14);
                        if (*piVar19 == 0) break;
                        iVar14 = iVar14 + 4;
                        memw();
                        uVar10 = FUN_40185aa8();
                        *puVar33 = uVar10;
                        puVar33[1] = 3;
                        memw();
                        memw();
                        uVar10 = FUN_40185aa8(*piVar19);
                        puVar33[2] = uVar10;
                        puVar33[3] = 1;
                        memw();
                        puVar33 = puVar33 + 4;
                        memw();
                      }
                      puVar31[1] = 0xd;
                      *puVar31 = 0;
                      puVar31[3] = (char)iVar14 + '\x02';
                      iVar25 = iVar14 + 6;
                      puVar31[2] = (char)((uint)(iVar14 + 2) >> 8);
                      puVar31[4] = (char)((uint)iVar14 >> 8);
                      puVar31[5] = (char)iVar14;
                      memw();
                      goto LAB_4012df04;
                    }
                    goto LAB_4012dbf0;
                  }
                }
              }
              else {
                iVar25 = 0;
LAB_4012df04:
                iVar25 = uVar17 + iVar18 + iVar25;
                if (uStack_74 == 0) {
LAB_4012dfa0:
                  iVar18 = 0;
                  if (*(char *)(*param_1 + 8) != '\0') {
                    puVar31 = puVar11 + iVar25 + 2;
                    if ((puVar12 < puVar31) || ((uint)((int)puVar12 - (int)puVar31) < 5))
                    goto LAB_4012dbf0;
                    *puVar31 = 0;
                    iVar18 = 5;
                    puVar31[1] = 1;
                    puVar31[2] = 0;
                    puVar31[3] = 1;
                    memw();
                    puVar31[4] = *(undefined1 *)(*param_1 + 8);
                    memw();
                  }
                  iVar14 = 0;
                  if (*(char *)(*param_1 + 0xe) != '\0') {
                    puVar31 = puVar11 + iVar25 + iVar18 + 2;
                    if ((puVar12 < puVar31) || ((uint)((int)puVar12 - (int)puVar31) < 4))
                    goto LAB_4012dbf0;
                    *puVar31 = 0;
                    puVar31[1] = 4;
                    puVar31[2] = 0;
                    puVar31[3] = 0;
                    memw();
                    iVar14 = 4;
                  }
                  iVar14 = iVar25 + iVar18 + iVar14;
                  iVar18 = 0;
                  if ((*(char *)(*param_1 + 9) != '\0') &&
                     (iVar18 = 0, *(char *)(*param_1 + 1) != '\0')) {
                    puVar31 = puVar11 + iVar14 + 2;
                    if ((puVar12 < puVar31) || ((uint)((int)puVar12 - (int)puVar31) < 4))
                    goto LAB_4012dbf0;
                    *puVar31 = 0;
                    iVar18 = 4;
                    puVar31[1] = 0x16;
                    puVar31[2] = 0;
                    puVar31[3] = 0;
                    memw();
                  }
                  iVar14 = iVar14 + iVar18;
                  iVar18 = 0;
                  if ((*(char *)(*param_1 + 10) != '\0') &&
                     (iVar18 = 0, *(char *)(*param_1 + 1) != '\0')) {
                    puVar31 = puVar11 + iVar14 + 2;
                    if ((puVar12 < puVar31) || ((uint)((int)puVar12 - (int)puVar31) < 4))
                    goto LAB_4012dbf0;
                    *puVar31 = 0;
                    puVar31[1] = 0x17;
                    puVar31[2] = 0;
                    puVar31[3] = 0;
                    memw();
                    iVar18 = 4;
                  }
                  iVar14 = iVar14 + iVar18;
                  iVar25 = 0;
                  piVar19 = *(int **)(*param_1 + 0xdc);
                  puVar31 = puVar11 + iVar14 + 2;
                  iVar18 = 0;
                  if (piVar19 != (int *)0x0) {
                    for (; *piVar19 != 0; piVar19 = piVar19 + 1) {
                      memw();
                      iVar18 = (*(code *)&SUB_4008c01c)();
                      iVar25 = iVar25 + iVar18 + 1;
                    }
                    if ((puVar12 < puVar31) || ((uint)((int)puVar12 - (int)puVar31) < iVar25 + 6U))
                    goto LAB_4012dbf0;
                    puVar31[1] = 0x10;
                    pbVar23 = puVar31 + 6;
                    *puVar31 = 0;
                    memw();
                    for (piVar19 = *(int **)(*param_1 + 0xdc); *piVar19 != 0; piVar19 = piVar19 + 1)
                    {
                      memw();
                      bVar9 = (*(code *)&SUB_4008c01c)();
                      *pbVar23 = bVar9;
                      memw();
                      memw();
                      (*(code *)&SUB_4008b3d0)(pbVar23 + 1,*piVar19,(uint)bVar9);
                      pbVar23 = pbVar23 + bVar9 + 1;
                    }
                    iVar18 = (int)pbVar23 - (int)puVar31;
                    puVar31[4] = (char)((uint)(iVar18 + -6) >> 8);
                    puVar31[5] = (char)iVar18 + -6;
                    puVar31[2] = (char)((uint)(iVar18 + -4) >> 8);
                    puVar31[3] = (char)iVar18 + -4;
                    memw();
                    memw();
                  }
                  iVar14 = iVar14 + iVar18;
                  iVar18 = *param_1;
                  if (*(char *)(iVar18 + 5) == '\x01') {
                    iVar25 = 0;
                    if (*(int *)(iVar18 + 0xe0) != 0) {
                      iVar25 = 0;
                      if (*(int *)(iVar18 + 0xe4) != 0) {
                        uVar17 = 0;
                        if (*(char *)(iVar18 + 0x12) == '\x01') {
                          uVar17 = (uint)*(ushort *)((int)param_1 + 0xf6);
                        }
                        puVar31 = puVar11 + iVar14 + 2;
                        if ((puVar12 < puVar31) ||
                           (iVar18 = (*(int *)(iVar18 + 0xe4) + 1) * 2 + uVar17,
                           (uint)((int)puVar12 - (int)puVar31) < iVar18 + 5U)) goto LAB_4012dbf0;
                        iVar18 = iVar18 + 1;
                        puVar31[1] = 0xe;
                        puVar31[3] = (char)iVar18;
                        puVar33 = puVar31 + 6;
                        *puVar31 = 0;
                        puVar31[2] = (char)((uint)iVar18 >> 8);
                        puVar31[4] = 0;
                        memw();
                        puVar31[5] = (char)(*(int *)(*param_1 + 0xe4) << 1);
                        memw();
                        uVar28 = 0;
                        while (uVar28 < *(uint *)(*param_1 + 0xe4)) {
                          uVar32 = *(ushort *)(*(int *)(*param_1 + 0xe0) + uVar28 * 2);
                          if (uVar32 == 0) {
                            puStack_7c = (undefined1 *)0xffffff92;
                            goto LAB_4012e3aa;
                          }
                          if ((2 < uVar32) && (1 < (ushort)(uVar32 - 5))) {
                            puStack_7c = (undefined1 *)0xffffff92;
                            goto LAB_4012e3bf;
                          }
                          *puVar33 = 0;
                          uVar28 = uVar28 + 1;
                          puVar33[1] = (char)uVar32;
                          memw();
                          puVar33 = puVar33 + 2;
                          memw();
                        }
                        *puVar33 = (char)uVar17;
                        memw();
                        puVar33 = puVar33 + 1;
                        if (uVar17 != 0) {
                          memw();
                          (*(code *)&SUB_4008b3d0)(puVar33,param_1 + 0x3e,uVar17);
                          puVar33 = puVar33 + uVar17;
                        }
                        iVar25 = (int)puVar33 - (int)puVar31;
                      }
                    }
                  }
                  else {
                    iVar25 = 0;
                  }
                  iVar14 = iVar14 + iVar25;
                  uVar17 = 0;
                  if (*(char *)(*param_1 + 0xf) != '\0') {
                    puVar31 = puVar11 + iVar14 + 2;
                    if (puVar12 < puVar31) goto LAB_4012dbf0;
                    iVar18 = *(int *)(param_1[0x10] + 0x70);
                    uVar17 = iVar18 + 4;
                    if ((uint)((int)puVar12 - (int)puVar31) < uVar17) goto LAB_4012dbf0;
                    *puVar31 = 0;
                    puVar31[1] = 0x23;
                    puVar31[2] = (char)((uint)iVar18 >> 8);
                    puVar31[3] = (char)iVar18;
                    memw();
                    if ((*(int *)(param_1[0x10] + 0x6c) == 0) || (iVar18 == 0)) {
                      uVar17 = 4;
                    }
                    else {
                      memw();
                      (*(code *)&SUB_4008b3d0)(puVar31 + 4);
                    }
                  }
                  iVar14 = iVar14 + uVar17;
                  if (iVar14 != 0) {
                    puVar24[3] = (char)iVar14;
                    puVar11 = puVar11 + iVar14 + 2;
                    puVar24[2] = (char)((uint)iVar14 >> 8);
                    memw();
                  }
                  param_1[0x34] = 0x16;
                  param_1[0x35] = (int)puVar11 - iVar27;
                  *(undefined1 *)param_1[0x33] = 1;
                  memw();
                  param_1[1] = param_1[1] + 1;
                  if (*(char *)(*param_1 + 5) == '\x01') {
                    memw();
                    FUN_401299a8(param_1);
                  }
                  puVar11 = (undefined1 *)FUN_4012a534(param_1);
                  if (puVar11 != (undefined1 *)0x0) goto LAB_4012da15;
                  if (*(char *)(*param_1 + 5) == '\x01') {
                    puVar11 = (undefined1 *)FUN_40129fc8(param_1);
                    goto LAB_4012da15;
                  }
                  goto LAB_4012da49;
                }
                iVar18 = *(int *)(*param_1 + 0xb0);
                if (iVar18 != 0) {
                  iVar14 = 0;
LAB_4012df15:
                  iVar16 = *(int *)(iVar18 + iVar14 * 2);
                  if (iVar16 != 0) goto LAB_4012e23e;
                  if (iVar14 != 0) {
                    puVar31 = puVar11 + iVar25 + 2;
                    if ((puVar31 <= puVar12) && (iVar14 + 6U <= (uint)((int)puVar12 - (int)puVar31))
                       ) {
                      puVar33 = puVar31 + 6;
                      iVar14 = *(int *)(*param_1 + 0xb0);
                      iVar18 = 0;
                      while (*(int *)(iVar14 + iVar18 * 2) != 0) {
                        memw();
                        iVar16 = FUN_401355f8();
                        *puVar33 = (char)((ushort)*(undefined2 *)(iVar16 + 4) >> 8);
                        memw();
                        puVar33[1] = (char)*(undefined2 *)(iVar16 + 4);
                        memw();
                        puVar33 = puVar33 + 2;
                        memw();
                        iVar18 = iVar18 + 2;
                      }
                      puVar31[2] = (char)((uint)(iVar18 + 2) >> 8);
                      iVar25 = iVar25 + 6 + iVar18;
                      puVar31[1] = 10;
                      puVar31[3] = (char)iVar18 + '\x02';
                      puVar31[5] = (char)iVar18;
                      puVar33 = puVar11 + iVar25 + 2;
                      *puVar31 = 0;
                      puVar31[4] = (char)((uint)iVar18 >> 8);
                      memw();
                      if ((puVar12 < puVar33) || ((uint)((int)puVar12 - (int)puVar33) < 6))
                      goto LAB_4012dbf0;
                      puVar33[1] = 0xb;
                      iVar25 = iVar25 + 6;
                      puVar33[3] = 2;
                      *puVar33 = 0;
                      puVar33[2] = 0;
                      puVar33[4] = 1;
                      puVar33[5] = 0;
                      memw();
                      goto LAB_4012dfa0;
                    }
                    goto LAB_4012dbf0;
                  }
                }
              }
LAB_4012ddf4:
              puStack_7c = (undefined1 *)0xffffa180;
              goto LAB_4012ddf7;
            }
          }
        }
LAB_4012dbf0:
        puVar11 = (undefined1 *)0xffff9600;
        memw();
        goto LAB_4012d980;
      }
      if (iVar18 < 2) {
        if (iVar18 == 0) {
          param_1[1] = 1;
          memw();
          puStack_7c = (undefined1 *)0x0;
        }
        else {
          puStack_7c = (undefined1 *)0xffff8f00;
        }
        goto LAB_4012da49;
      }
      puVar11 = (undefined1 *)FUN_4012a960(param_1,1);
      if (puVar11 != (undefined1 *)0x0) goto LAB_4012e3f8;
      if (param_1[0x20] != 0x16) {
        if (param_1[2] != 1) goto LAB_4012e3b2;
        iVar18 = param_1[3];
        iVar27 = *(int *)(*param_1 + 0x20);
        param_1[3] = iVar18 + 1;
        if ((iVar27 < 0) || (puStack_7c = &DAT_ffff8900, iVar18 + 1 <= iVar27)) {
          puStack_7c = (undefined1 *)0xffff9500;
          param_1[0x2c] = 1;
          goto LAB_4012e3aa;
        }
        goto LAB_4012da49;
      }
      pcVar22 = (char *)param_1[0x1e];
      if (*(char *)(*param_1 + 5) == '\x01') {
        if (*pcVar22 == '\x03') {
          if ((uint)param_1[0x21] < 0xf) {
LAB_4012e3e9:
            FUN_4012a73c(param_1,2,0x32);
            puVar11 = (undefined1 *)0xffff8680;
          }
          else {
            FUN_40185918(&puStack_70,&iStack_6c,1,pcVar22 + 0xc);
            if (((((int)puStack_70 < 3) || (iStack_6c < 2)) ||
                ((int)(uint)*(byte *)*param_1 < (int)puStack_70)) ||
               ((int)(uint)((byte *)*param_1)[1] < iStack_6c)) {
              FUN_4012a73c(param_1,2,0x46);
              puVar11 = (undefined1 *)0xffff9180;
            }
            else {
              bVar9 = pcVar22[0xe];
              uVar17 = (uint)bVar9;
              if ((param_1[0x1e] + param_1[0x21]) - (int)(pcVar22 + 0xf) < (int)uVar17)
              goto LAB_4012e3e9;
              FUN_4013ae44(*(undefined4 *)(param_1[0x11] + 0x240));
              iVar18 = param_1[0x11];
              uVar34 = FUN_4013ae30(1,uVar17);
              *(undefined4 *)(iVar18 + 0x240) = uVar34;
              if (*(int *)(param_1[0x11] + 0x240) == 0) {
                puVar11 = (undefined1 *)0xffff8100;
              }
              else {
                memw();
                (*(code *)&SUB_4008b3d0)(*(int *)(param_1[0x11] + 0x240),pcVar22 + 0xf,uVar17);
                *(byte *)(param_1[0x11] + 0x244) = bVar9;
                memw();
                param_1[1] = 1;
                memw();
                FUN_4012c4dc(param_1);
                FUN_40129dc0(param_1);
              }
            }
          }
LAB_4012e3f8:
          memw();
          puStack_7c = puVar11;
          goto LAB_4012da49;
        }
        FUN_4013ae44(*(undefined4 *)(param_1[0x11] + 0x240));
        iVar18 = param_1[0x11];
        *(undefined4 *)(iVar18 + 0x240) = 0;
        *(undefined1 *)(iVar18 + 0x244) = 0;
        memw();
      }
      iVar18 = 0xc;
      if (*(char *)(*param_1 + 5) != '\x01') {
        iVar18 = 4;
      }
      if (((uint)param_1[0x2a] < iVar18 + 0x26U) || (*pcVar22 != '\x02')) goto LAB_4012e4d9;
      pcVar22 = pcVar22 + iVar18;
      FUN_40185918(param_1 + 4,param_1 + 5,*(char *)(*param_1 + 5),pcVar22);
      pbVar23 = (byte *)*param_1;
      if (((param_1[4] < (int)(uint)pbVar23[2]) ||
          ((param_1[5] < (int)(uint)pbVar23[3] || ((int)(uint)*pbVar23 < param_1[4])))) ||
         ((int)(uint)pbVar23[1] < param_1[5])) {
        FUN_4012a73c(param_1,2,0x46);
        puStack_7c = (undefined1 *)0xffff9180;
        goto LAB_4012da49;
      }
      (*(code *)&SUB_4008b3d0)(param_1[0x11] + 0x490,pcVar22 + 2,0x20);
      iVar18 = 0xc;
      uVar17 = (uint)(byte)pcVar22[0x22];
      if (uVar17 < 0x21) {
        if (*(char *)(*param_1 + 5) != '\x01') {
          iVar18 = 4;
        }
        iVar18 = uVar17 + iVar18;
        uVar28 = param_1[0x2a];
        if (iVar18 + 0x27U < uVar28) {
          uVar29 = (uint)CONCAT11(pcVar22[uVar17 + 0x26],pcVar22[uVar17 + 0x27]);
          if ((2 < uVar29 - 1) && (uVar28 == uVar29 + 0x28 + iVar18)) goto LAB_4012e582;
        }
        else if (uVar28 == iVar18 + 0x26U) {
          uVar29 = 0;
LAB_4012e582:
          if (pcVar22[uVar17 + 0x25] != '\0') {
            FUN_4012a73c(param_1,2,0x2f);
            puVar11 = (undefined1 *)0xffff8f80;
            goto LAB_4012e5d8;
          }
          uVar28 = (uint)CONCAT11(pcVar22[uVar17 + 0x23],pcVar22[uVar17 + 0x24]);
          iVar18 = param_1[0x11];
          memw();
          uVar34 = FUN_4012d7a8(uVar28);
          *(undefined4 *)(iVar18 + 0x14) = uVar34;
          if (*(int *)(param_1[0x11] + 0x14) == 0) {
            memw();
            FUN_4012a73c(param_1,2,0x50);
LAB_4012db17:
            puStack_7c = (undefined1 *)0xffff8f00;
            goto LAB_4012e3aa;
          }
          FUN_4012c4b4(param_1);
          iVar18 = param_1[0x11];
          if ((((*(char *)(iVar18 + 2) == '\0') || (uVar17 == 0)) || (param_1[2] != 0)) ||
             (((iVar27 = param_1[0x10], uVar28 != *(uint *)(iVar27 + 8) ||
               (*(int *)(iVar27 + 0xc) != 0)) || (uVar17 != *(uint *)(iVar27 + 0x10))))) {
LAB_4012e629:
            param_1[1] = param_1[1] + 1;
            *(undefined1 *)(iVar18 + 2) = 0;
            memw();
            iVar18 = param_1[0x10];
            memw();
            uVar34 = (*(code *)&SUB_4008cd2c)(0);
            *(undefined4 *)(iVar18 + 4) = uVar34;
            iVar18 = param_1[0x10];
            *(undefined4 *)(iVar18 + 0xc) = 0;
            *(uint *)(iVar18 + 8) = uVar28;
            *(uint *)(iVar18 + 0x10) = uVar17;
            memw();
            (*(code *)&SUB_4008b3d0)(iVar18 + 0x14,pcVar22 + 0x23,uVar17);
          }
          else {
            memw();
            iVar27 = (*(code *)&SUB_4008b33c)(iVar27 + 0x14,pcVar22 + 0x23,uVar17);
            if (iVar27 != 0) goto LAB_4012e629;
            param_1[1] = 0xc;
            memw();
          }
          piVar19 = *(int **)(*param_1 + (param_1[5] + 0xc) * 4 + 4);
          do {
            iVar18 = *piVar19;
            if (iVar18 == 0) goto LAB_4012e675;
            piVar19 = piVar19 + 1;
          } while (iVar18 != *(int *)(param_1[0x10] + 8));
          uVar34 = FUN_4012d7a8();
          iVar18 = FUN_4012d910(uVar34,param_1,param_1[5],param_1[5]);
          if (iVar18 == 0) {
            puVar21 = (ushort *)(pcVar22 + uVar17 + 0x28);
            *(undefined4 *)(param_1[0x10] + 0xc) = 0;
            bVar26 = false;
            do {
              if (uVar29 == 0) {
                if (*(char *)(param_1[0x11] + 2) != '\0') {
                  memw();
                  puVar11 = (undefined1 *)FUN_4012bd8c(param_1);
                  uVar34 = 0x50;
                  if (puVar11 != (undefined1 *)0x0) goto LAB_4012ed52;
                }
                iVar18 = param_1[0x80];
                if (((iVar18 == 0) && (*(char *)(*param_1 + 7) == '\x02')) ||
                   ((param_1[2] == 1 &&
                    (((iVar18 == 1 && (!bVar26)) ||
                     ((iVar18 == 0 && ((*(char *)(*param_1 + 7) == '\0' || (bVar26))))))))))
                goto LAB_4012e920;
                goto LAB_4012da49;
              }
              uVar32 = *puVar21 << 8 | *puVar21 >> 8;
              uVar17 = (puVar21[1] & 0xff) << 8 | (uint)(puVar21[1] >> 8);
              if (uVar29 < uVar17 + 4) goto LAB_4012e4d9;
              if (uVar32 == 0x10) {
                piVar19 = *(int **)(*param_1 + 0xdc);
                if (piVar19 == (int *)0x0) {
LAB_4012e7e4:
                  FUN_4012a73c(param_1,2,0x6e);
                  puStack_7c = (undefined1 *)0xffff8680;
                  goto LAB_4012da49;
                }
                if (((uVar17 < 4) ||
                    (((puVar21[2] & 0xff) << 8 | (uint)(puVar21[2] >> 8)) != uVar17 - 2)) ||
                   (uVar28 = (uint)(byte)puVar21[3], uVar28 != uVar17 - 3)) goto LAB_4012e4d9;
                while( true ) {
                  iVar18 = *piVar19;
                  if (iVar18 == 0) goto LAB_4012e920;
                  memw();
                  uVar13 = (*(code *)&SUB_4008c01c)(iVar18);
                  if ((uVar28 == uVar13) &&
                     (iVar27 = (*(code *)&SUB_4008b33c)((char *)((int)puVar21 + 7),iVar18,uVar28),
                     iVar27 == 0)) break;
                  piVar19 = piVar19 + 1;
                }
                param_1[0x3c] = iVar18;
                memw();
              }
              else {
                if (uVar32 < 0x11) {
                  if (uVar32 == 4) {
                    if ((*(char *)(*param_1 + 0xe) == '\0') || (uVar17 != 0)) goto LAB_4012e920;
                    *(undefined4 *)(param_1[0x10] + 0x78) = 1;
                    memw();
                  }
                  else if (uVar32 < 5) {
                    if ((uVar32 == 1) &&
                       (((uVar17 != 1 || (*(char *)(*param_1 + 8) == '\0')) ||
                        ((char)puVar21[2] != *(char *)(*param_1 + 8))))) break;
                  }
                  else if (uVar32 == 0xb) {
                    if ((uVar17 == 0) || (uVar28 = (uint)(byte)puVar21[2], uVar17 != uVar28 + 1))
                    goto LAB_4012e4d9;
                    pbVar23 = (byte *)((int)puVar21 + 5);
                    while( true ) {
                      if (uVar28 == 0) goto LAB_4012e920;
                      if (*pbVar23 < 2) break;
                      uVar28 = uVar28 - 1;
                      pbVar23 = pbVar23 + 1;
                    }
                    *(uint *)(param_1[0x11] + 0x180) = (uint)*pbVar23;
                    memw();
                  }
                  else if ((((uVar32 == 0xe) && (iVar18 = *param_1, *(char *)(iVar18 + 5) == '\x01')
                            ) && (iVar27 = *(int *)(iVar18 + 0xe0), iVar27 != 0)) &&
                          (iVar14 = *(int *)(iVar18 + 0xe4), iVar14 != 0)) {
                    uVar32 = 0;
                    if (*(char *)(iVar18 + 0x12) == '\x01') {
                      uVar32 = *(ushort *)((int)param_1 + 0xf6);
                    }
                    if (((uVar17 < 5) || (uVar17 != (byte)puVar21[4] + 5)) ||
                       (((char)puVar21[2] != '\0' || (*(char *)((int)puVar21 + 5) != '\x02'))))
                    goto LAB_4012e7b3;
                    sVar6 = CONCAT11((char)puVar21[3],*(char *)((int)puVar21 + 7));
                    iVar18 = (int)sVar6;
                    sVar30 = 0;
                    if ((0 < iVar18) && ((iVar18 < 3 || ((iVar18 - 5U & 0xffff) < 2)))) {
                      sVar30 = sVar6;
                    }
                    *(undefined2 *)(param_1 + 0x3d) = 0;
                    memw();
                    iVar18 = 0;
                    while (*(short *)(iVar27 + iVar18 * 2) != sVar30) {
                      iVar18 = iVar18 + 1;
                      iVar14 = iVar14 + -1;
                      if (iVar14 == 0) goto LAB_4012e920;
                    }
                    *(short *)(param_1 + 0x3d) = sVar30;
                    memw();
                    if (sVar30 == 0) goto LAB_4012e920;
                    if (uVar17 == 5) {
                      *(undefined2 *)((int)param_1 + 0xf6) = 0;
                      memw();
                      memw();
                    }
                    else if (((byte)puVar21[4] != uVar32) ||
                            (iVar18 = (*(code *)&SUB_4008b33c)
                                                (param_1 + 0x3e,(char *)((int)puVar21 + 9)),
                            iVar18 != 0)) break;
                  }
                  goto LAB_4012e768;
                }
                if (uVar32 == 0x17) {
                  if (((*(char *)(*param_1 + 10) == '\0') || (param_1[5] == 0)) || (uVar17 != 0))
                  goto LAB_4012e7e4;
                  *(undefined1 *)(param_1[0x11] + 6) = 1;
                  memw();
                  memw();
                }
                else if (uVar32 < 0x18) {
                  if (uVar32 == 0x16) {
                    if (((*(char *)(*param_1 + 9) == '\0') || (param_1[5] == 0)) || (uVar17 != 0))
                    goto LAB_4012e7e4;
                    *(undefined4 *)(param_1[0x10] + 0x7c) = 1;
                    memw();
                  }
                }
                else if (uVar32 == 0x23) {
                  if ((*(char *)(*param_1 + 0xf) == '\0') || (uVar17 != 0)) goto LAB_4012e7e4;
                  *(undefined1 *)(param_1[0x11] + 5) = 1;
                  memw();
                  memw();
                }
                else if (uVar32 == 0xff01) {
                  if (param_1[2] == 0) {
                    if ((uVar17 != 1) || ((char)puVar21[2] != '\0')) goto LAB_4012e920;
                    bVar26 = true;
                    param_1[0x80] = 1;
                    memw();
                  }
                  else {
                    if ((((uVar17 != param_1[0x81] * 2 + 1U) ||
                         (param_1[0x81] * 2 != (uint)(byte)puVar21[2])) ||
                        (iVar18 = FUN_401862dc((char *)((int)puVar21 + 5),param_1 + 0x82),
                        iVar18 != 0)) ||
                       (iVar18 = FUN_401862dc((char *)((int)puVar21 + param_1[0x81] + 5),
                                              param_1 + 0x85), iVar18 != 0)) {
LAB_4012e920:
                      uVar34 = 0x28;
                      goto LAB_4012e4dc;
                    }
                    bVar26 = true;
                  }
                }
              }
LAB_4012e768:
              iVar18 = uVar29 - uVar17;
              uVar29 = iVar18 - 4;
              puVar21 = (ushort *)((int)puVar21 + uVar17 + 4);
              if (iVar18 - 5U < 3) {
                memw();
LAB_4012e7b3:
                puStack_7c = (undefined1 *)0xffff8680;
                goto LAB_4012ddf7;
              }
            } while( true );
          }
LAB_4012e675:
          uVar34 = 0x2f;
          goto LAB_4012e4dc;
        }
      }
LAB_4012e4d9:
      uVar34 = 0x32;
LAB_4012e4dc:
      memw();
      FUN_4012a73c(param_1,2,uVar34);
      puVar11 = (undefined1 *)0xffff8680;
      goto LAB_4012d980;
    }
    if (iVar18 == 0xb) {
      puVar11 = (undefined1 *)FUN_4012c514(param_1);
      goto LAB_4012da15;
    }
    if (iVar18 < 0xc) {
      if (iVar18 == 9) {
        iVar18 = *(int *)(param_1[0x11] + 0x14);
        puStack_70 = (ushort *)0x0;
        memw();
        puStack_7c = (undefined1 *)FUN_4012bd8c(param_1);
        if (puStack_7c == (undefined1 *)0x0) {
          uVar17 = *(uint *)(iVar18 + 0x10);
          if (uVar17 == 0) goto LAB_4012eab8;
          if ((4 < uVar17) && (1 < uVar17 - 9)) goto LAB_4012eab8;
          if (param_1[0x3a] == 0) goto LAB_4012eab8;
          iVar18 = param_1[0x11];
          if (((iVar18 == 0) || (piVar19 = *(int **)(iVar18 + 0x1e4), piVar19 == (int *)0x0)) &&
             (piVar19 = *(int **)(*param_1 + 0xa0), piVar19 == (int *)0x0)) goto LAB_4012eab8;
          if (*piVar19 == 0) goto LAB_4012eab8;
          memw();
          iVar27 = FUN_40185b9c(param_1);
          puStack_7c = (undefined1 *)0xffff8a00;
          if (iVar27 == 0) goto LAB_4012da49;
          memw();
          (**(code **)(iVar18 + 0x1c))(param_1,auStack_64,&iStack_6c);
          if (param_1[5] == 3) {
            if (*(int *)(*(int *)(param_1[0x11] + 0x14) + 0xc) == 7) {
              *(undefined1 *)(param_1[0x33] + 4) = 5;
              memw();
              uVar34 = 7;
            }
            else {
              *(undefined1 *)(param_1[0x33] + 4) = 4;
              memw();
              uVar34 = 6;
              memw();
            }
            memw();
            FUN_40185b9c(param_1);
            puVar11 = auStack_64;
            iVar27 = param_1[0x33];
            iVar18 = 2;
            uVar10 = FUN_4012d170();
            *(undefined1 *)(iVar27 + 5) = uVar10;
            memw();
            iStack_6c = 0;
            memw();
          }
          else {
            uVar34 = FUN_40185b9c(param_1);
            iVar18 = FUN_401864ec(uVar34,4);
            if (iVar18 == 0) {
              puVar11 = auStack_64;
              iVar18 = 0;
              uVar34 = 0;
            }
            else {
              uVar34 = 4;
              iStack_6c = iStack_6c + -0x10;
              puVar11 = auStack_54;
              iVar18 = 0;
            }
          }
          memw();
          uVar20 = FUN_40185b9c(param_1);
          memw();
          puStack_7c = (undefined1 *)
                       FUN_40139c0c(uVar20,uVar34,puVar11,iStack_6c,param_1[0x33] + iVar18 + 6,
                                    &puStack_70,*(undefined4 *)(*param_1 + 0x4c),
                                    *(undefined4 *)(*param_1 + 0x50),0);
          if (puStack_7c != (undefined1 *)0x0) goto LAB_4012da49;
          *(char *)(param_1[0x33] + iVar18 + 4) = (char)((uint)puStack_70 >> 8);
          memw();
          *(char *)(param_1[0x33] + iVar18 + 5) = (char)puStack_70;
          memw();
          uVar10 = 0xf;
          param_1[0x35] = (int)((int)puStack_70 + iVar18 + 6);
          param_1[0x34] = 0x16;
          puVar11 = (undefined1 *)param_1[0x33];
          memw();
          goto LAB_4012eee4;
        }
        goto LAB_4012da49;
      }
      if (9 < iVar18) {
        puVar11 = (undefined1 *)FUN_4012a714(param_1);
        goto LAB_4012da15;
      }
      iVar14 = param_1[0x11];
      iVar18 = *(int *)(iVar14 + 0x14);
      iVar27 = *(int *)(iVar18 + 0x10);
      if (iVar27 == 2) {
        iStack_6c = *(int *)(iVar14 + 0x28);
        *(char *)(param_1[0x33] + 4) = (char)((uint)iStack_6c >> 8);
        memw();
        *(char *)(param_1[0x33] + 5) = (char)iStack_6c;
        memw();
        iVar18 = param_1[0x11];
        memw();
        uVar34 = FUN_401317d8(iVar18 + 0x2c);
        puStack_7c = (undefined1 *)
                     FUN_4013427c(iVar18 + 0x28,uVar34,param_1[0x33] + 6,iStack_6c,
                                  *(undefined4 *)(*param_1 + 0x4c),*(undefined4 *)(*param_1 + 0x50))
        ;
        if (puStack_7c != (undefined1 *)0x0) goto LAB_4012da49;
        iVar18 = param_1[0x11];
        memw();
        puStack_7c = (undefined1 *)
                     FUN_401342c4(iVar18 + 0x28,iVar18 + 0x4b0,0x424,iVar18 + 0x10,
                                  *(undefined4 *)(*param_1 + 0x4c),*(undefined4 *)(*param_1 + 0x50))
        ;
        iVar27 = 6;
        if (puStack_7c != (undefined1 *)0x0) goto LAB_4012da49;
      }
      else {
        if ((1 < iVar27 - 3U) && (1 < iVar27 - 9U)) {
          iVar27 = FUN_40185b88(iVar18);
          if (iVar27 == 0) {
            if (*(int *)(iVar18 + 0x10) == 1) {
              puStack_7c = (undefined1 *)FUN_4012d840(param_1,4,&iStack_6c,0);
              goto LAB_4012ef64;
            }
          }
          else {
            iVar27 = *param_1;
            if ((((*(int *)(iVar27 + 0xd4) != 0) && (iVar14 = *(int *)(iVar27 + 0xd8), iVar14 != 0))
                && (*(int *)(iVar27 + 0xcc) != 0)) && (*(int *)(iVar27 + 0xd0) != 0)) {
              iStack_6c = iVar14;
              if (0x4000 < iVar14 + 6U) {
LAB_4012ef8d:
                puStack_7c = (undefined1 *)0xffff9600;
                memw();
                goto LAB_4012e3bf;
              }
              *(char *)(param_1[0x33] + 4) = (char)((uint)iVar14 >> 8);
              memw();
              *(char *)(param_1[0x33] + 5) = (char)iVar14;
              memw();
              memw();
              (*(code *)&SUB_4008b3d0)
                        (param_1[0x33] + 6,*(undefined4 *)(*param_1 + 0xd4),
                         *(undefined4 *)(*param_1 + 0xd8));
              iVar25 = *param_1;
              iVar14 = *(int *)(iVar18 + 0x10);
              iVar16 = *(int *)(iVar25 + 0xd8);
              iVar27 = iVar16 + 6;
              if (iVar14 == 5) {
                iStack_6c = 0;
              }
              else {
                if (iVar14 == 7) {
                  puStack_7c = (undefined1 *)FUN_4012d840(param_1,iVar27,&iStack_6c,2);
                }
                else if (iVar14 == 6) {
                  iStack_6c = *(int *)(param_1[0x11] + 0x28);
                  if (0x4000 < (uint)(iStack_6c + 2 + iVar27)) goto LAB_4012ef8d;
                  *(char *)(param_1[0x33] + iVar27) = (char)((uint)iStack_6c >> 8);
                  memw();
                  iVar27 = iVar16 + 8;
                  *(char *)(param_1[0x33] + iVar16 + 7) = (char)iStack_6c;
                  memw();
                  iVar14 = param_1[0x11];
                  memw();
                  uVar34 = FUN_401317d8(iVar14 + 0x2c);
                  puStack_7c = (undefined1 *)
                               FUN_4013427c(iVar14 + 0x28,uVar34,param_1[0x33] + iVar27,iStack_6c,
                                            *(undefined4 *)(*param_1 + 0x4c),
                                            *(undefined4 *)(*param_1 + 0x50));
                }
                else {
                  if (iVar14 != 8) goto LAB_4012ef19;
                  puStack_7c = (undefined1 *)
                               FUN_401346b4(param_1[0x11] + 0xa4,&iStack_6c,param_1[0x33] + iVar27,
                                            0x4000 - iVar27,*(undefined4 *)(iVar25 + 0x4c),
                                            *(undefined4 *)(iVar25 + 0x50));
                }
                if (puStack_7c != (undefined1 *)0x0) {
                  memw();
                  goto LAB_4012da49;
                }
              }
              memw();
              puStack_7c = (undefined1 *)FUN_4012c1f8(param_1,*(undefined4 *)(iVar18 + 0x10));
              if (puStack_7c != (undefined1 *)0x0) {
                memw();
                goto LAB_4012da49;
              }
              goto LAB_4012eed0;
            }
          }
LAB_4012ef19:
          puStack_7c = (undefined1 *)0xffff9400;
          goto LAB_4012da49;
        }
        puStack_7c = (undefined1 *)
                     FUN_401346b4(iVar14 + 0xa4,&iStack_6c,param_1[0x33] + 4,1000,
                                  *(undefined4 *)(*param_1 + 0x4c),*(undefined4 *)(*param_1 + 0x50))
        ;
        if (puStack_7c != (undefined1 *)0x0) goto LAB_4012da49;
        iVar18 = param_1[0x11];
        memw();
        puStack_7c = (undefined1 *)
                     FUN_40134718(iVar18 + 0xa4,iVar18 + 0x10,iVar18 + 0x4b0,0x400,
                                  *(undefined4 *)(*param_1 + 0x4c),*(undefined4 *)(*param_1 + 0x50))
        ;
LAB_4012ef64:
        iVar27 = 4;
        if (puStack_7c != (undefined1 *)0x0) {
          memw();
          goto LAB_4012da49;
        }
      }
LAB_4012eed0:
      uVar10 = 0x10;
      param_1[0x34] = 0x16;
      puVar11 = (undefined1 *)param_1[0x33];
      param_1[0x35] = iStack_6c + iVar27;
LAB_4012eee4:
      *puVar11 = uVar10;
      memw();
      param_1[1] = param_1[1] + 1;
      memw();
      puVar11 = (undefined1 *)FUN_4012a534(param_1);
      goto LAB_4012da15;
    }
    if (iVar18 == 0xe) {
      iVar18 = 0xf;
      goto LAB_4012ea55;
    }
    if (iVar18 < 0xf) {
      puVar11 = (undefined1 *)0xffff8f00;
      if (iVar18 != 0xd) goto LAB_4012e5d8;
      puVar11 = (undefined1 *)FUN_4012c630(param_1);
      goto LAB_4012da15;
    }
    if (iVar18 == 0xf) {
      FUN_4012cae8(param_1);
      goto LAB_4012da49;
    }
    if (iVar18 != 0x11) goto LAB_4012db17;
  }
  memw();
  puVar11 = (undefined1 *)FUN_4012a960(param_1,1);
  if (puVar11 != (undefined1 *)0x0) goto LAB_4012d980;
  if (param_1[0x20] != 0x16) goto LAB_4012e3b2;
  if (*(char *)param_1[0x1e] == '\x04') {
    iVar18 = 4;
    if (*(char *)(*param_1 + 5) == '\x01') {
      iVar18 = 0xc;
    }
    if (iVar18 + 6U <= (uint)param_1[0x2a]) {
      pbVar23 = (byte *)((char *)param_1[0x1e] + iVar18);
      bVar9 = *pbVar23;
      bVar2 = pbVar23[5];
      uVar7 = *(undefined2 *)(pbVar23 + 4);
      bVar3 = pbVar23[2];
      uVar17 = CONCAT21(uVar7,bVar2) & 0xffff;
      bVar4 = pbVar23[1];
      bVar5 = pbVar23[3];
      if (param_1[0x2a] == iVar18 + 6U + uVar17) {
        *(undefined1 *)(param_1[0x11] + 5) = 0;
        memw();
        param_1[1] = 0xc;
        if ((CONCAT21(uVar7,bVar2) & 0xffff) != 0) {
          iVar18 = param_1[0xf];
          if ((iVar18 != 0) && (*(int *)(iVar18 + 0x6c) != 0)) {
            memw();
            FUN_4013ae54(*(int *)(iVar18 + 0x6c),*(undefined4 *)(iVar18 + 0x70));
            FUN_4013ae44(*(undefined4 *)(param_1[0xf] + 0x6c));
            iVar18 = param_1[0xf];
            *(undefined4 *)(iVar18 + 0x6c) = 0;
            *(undefined4 *)(iVar18 + 0x70) = 0;
          }
          memw();
          FUN_4013ae54(*(undefined4 *)(param_1[0x10] + 0x6c),*(undefined4 *)(param_1[0x10] + 0x70));
          FUN_4013ae44(*(undefined4 *)(param_1[0x10] + 0x6c));
          iVar18 = param_1[0x10];
          *(undefined4 *)(iVar18 + 0x6c) = 0;
          *(undefined4 *)(iVar18 + 0x70) = 0;
          memw();
          iVar18 = FUN_4013ae30(1,uVar17);
          if (iVar18 != 0) {
            memw();
            uVar34 = (*(code *)&SUB_4008b3d0)(iVar18,pbVar23 + 6,uVar17);
            iVar18 = param_1[0x10];
            *(uint *)(iVar18 + 0x70) = uVar17;
            param_1 = (int *)((uint)bVar9 << 0x18 | (uint)bVar5 | (uint)bVar4 << 0x10 |
                             (uint)bVar3 << 8);
            *(undefined4 *)(iVar18 + 0x6c) = uVar34;
            *(int **)(iVar18 + 0x74) = param_1;
            *(undefined4 *)(iVar18 + 0x10) = 0;
            memw();
            goto LAB_4012d980;
          }
          FUN_4012a73c(param_1,2,0x50);
          puStack_7c = (undefined1 *)0xffff8100;
          goto LAB_4012ddf7;
        }
        goto LAB_4012da49;
      }
    }
  }
  FUN_4012a73c(param_1,2,0x32);
  puStack_7c = (undefined1 *)0xffff9200;
LAB_4012da49:
  do {
    iVar18 = _DAT_3ffc5708;
    memw();
    memw();
    if (iStack_24 == _DAT_3ffc5708) {
      return puStack_7c;
    }
    memw();
    (*(code *)&SUB_40082ec4)();
LAB_4012da68:
    if (iVar18 == 5) {
      uVar17 = *(uint *)(*(int *)(param_1[0x11] + 0x14) + 0x10);
      if ((uVar17 == 0) || ((4 < uVar17 && (1 < uVar17 - 9)))) {
        iVar18 = 6;
LAB_4012ea55:
        param_1[1] = iVar18;
        memw();
      }
      else {
        puVar11 = (undefined1 *)FUN_4012a960(param_1,1);
        if (puVar11 == (undefined1 *)0x0) {
          if (param_1[0x20] != 0x16) {
LAB_4012e3b2:
            FUN_4012a73c(param_1,2,10);
            puStack_7c = &DAT_ffff8900;
LAB_4012e3bf:
            memw();
            goto LAB_4012da49;
          }
          pcVar22 = (char *)param_1[0x1e];
          param_1[1] = param_1[1] + 1;
          cVar1 = *pcVar22;
          param_1[0x3a] = (uint)(cVar1 == '\r');
          if (cVar1 == '\r') {
            uVar17 = 0xc;
            if (*(char *)(*param_1 + 5) != '\x01') {
              uVar17 = 4;
            }
            uVar28 = param_1[0x2a];
            if (uVar17 < uVar28) {
              uVar29 = (uint)(byte)pcVar22[uVar17];
              iVar18 = uVar17 + uVar29;
              if (iVar18 + 2U < uVar28) {
                if (param_1[5] == 3) {
                  if (uVar28 <= iVar18 + 3 +
                                (uint)CONCAT11(pcVar22[iVar18 + 1],pcVar22[iVar18 + 2U]))
                  goto LAB_4012edd4;
                  uVar29 = uVar29 + 2 + (uint)CONCAT11(pcVar22[iVar18 + 1],pcVar22[iVar18 + 2U]);
                }
                if (uVar28 == (uint)CONCAT11(pcVar22[uVar17 + uVar29 + 1],
                                             pcVar22[uVar17 + uVar29 + 2]) + uVar17 + 3 + uVar29)
                goto LAB_4012da49;
              }
            }
LAB_4012edd4:
            FUN_4012a73c(param_1,2,0x32);
            puStack_7c = (undefined1 *)0xffff8580;
LAB_4012ddf7:
            memw();
            goto LAB_4012da49;
          }
          param_1[0x2c] = 1;
          memw();
        }
LAB_4012da15:
        memw();
        puStack_7c = puVar11;
      }
      goto LAB_4012da49;
    }
    if (5 < iVar18) {
      puVar11 = (undefined1 *)FUN_4012a960(param_1,1);
      if (puVar11 == (undefined1 *)0x0) {
        if (param_1[0x20] != 0x16) {
          puStack_7c = &DAT_ffff8900;
          goto LAB_4012ddf7;
        }
        iVar18 = 0xc;
        cVar1 = *(char *)(*param_1 + 5);
        if (cVar1 != '\x01') {
          iVar18 = 4;
        }
        if ((param_1[0x2a] != iVar18) || (*(char *)param_1[0x1e] != '\x0e')) {
          FUN_4012a73c(param_1,2,0x32);
          puVar11 = (undefined1 *)0xffff8480;
          goto LAB_4012d980;
        }
        param_1[1] = param_1[1] + 1;
        if (cVar1 != '\x01') goto LAB_4012da49;
        memw();
        FUN_40129dc0(param_1);
      }
LAB_4012e5d8:
      memw();
      puStack_7c = puVar11;
      goto LAB_4012da49;
    }
    iVar18 = *(int *)(param_1[0x11] + 0x14);
    puStack_70 = (ushort *)0x0;
    if (*(int *)(iVar18 + 0x10) == 1) {
      iVar18 = 5;
      goto LAB_4012ea55;
    }
    if (1 < *(int *)(iVar18 + 0x10) - 9U) {
      puStack_7c = (undefined1 *)FUN_4012a960(param_1,1);
      if (puStack_7c == (undefined1 *)0x0) {
        if (param_1[0x20] == 0x16) {
          pcVar22 = (char *)param_1[0x1e];
          uVar17 = *(uint *)(iVar18 + 0x10);
          uVar28 = uVar17 & 0xfffffffd;
          if (*pcVar22 == '\f') {
            iVar27 = 0xc;
            if (*(char *)(*param_1 + 5) != '\x01') {
              iVar27 = 4;
            }
            puStack_70 = (ushort *)(pcVar22 + iVar27);
            puVar21 = (ushort *)(pcVar22 + param_1[0x2a]);
            if (((uVar17 - 6 & 0xfffffffd) == 0) || (uVar28 == 5)) {
              if (1 < param_1[0x2a] - iVar27) {
                uVar29 = (uint)CONCAT11((char)*puStack_70,*(char *)((int)puStack_70 + 1));
                puStack_70 = puStack_70 + 1;
                if ((int)uVar29 <= (int)puVar21 - (int)puStack_70) {
                  puStack_70 = (ushort *)((int)puStack_70 + uVar29);
                  if (uVar28 != 5) goto LAB_4012ebaa;
                  goto LAB_4012ebdc;
                }
              }
            }
            else {
LAB_4012ebaa:
              if ((uVar17 & 0xfffffffb) == 2) {
                memw();
                iVar27 = FUN_40134100(param_1[0x11] + 0x28,&puStack_70,puVar21);
                if ((iVar27 == 0) &&
                   (uVar17 = FUN_40131798(param_1[0x11] + 0x2c),
                   *(uint *)(*param_1 + 0x30) <= uVar17)) {
LAB_4012ebdc:
                  puVar8 = puStack_70;
                  if (2 < *(int *)(iVar18 + 0x10) - 2U) goto LAB_4012eab8;
                  iVar27 = 0xc;
                  if (*(char *)(*param_1 + 5) != '\x01') {
                    iVar27 = 4;
                  }
                  iVar14 = param_1[0x1e];
                  if (param_1[5] == 3) {
                    if (puStack_70 + 1 <= puVar21) {
                      memw();
                      iVar25 = FUN_40185a74((char)*puStack_70);
                      if (((iVar25 != 0) &&
                          (iVar16 = FUN_40185a10(*(char *)((int)puStack_70 + 1)), iVar16 != 0)) &&
                         (iVar15 = FUN_40185b00(param_1,iVar25), iVar15 == 0)) {
                        puStack_70 = puStack_70 + 1;
                        memw();
                        iVar18 = FUN_40185b28(iVar18);
                        if (iVar18 == iVar16) goto LAB_4012ec9a;
                      }
                    }
                    uVar34 = 0x2f;
LAB_4012ec43:
                    FUN_4012a73c(param_1,2,uVar34);
                    puVar11 = (undefined1 *)0xffff8500;
                  }
                  else {
                    if (param_1[5] < 3) {
                      iVar16 = FUN_40185b28(iVar18);
                      iVar25 = 4;
                      if (iVar16 != 4) {
                        iVar25 = 0;
                      }
LAB_4012ec9a:
                      if (puStack_70 <= puVar21 + -1) {
                        uVar17 = (*puStack_70 & 0xff) << 8 | (uint)(*puStack_70 >> 8);
                        puStack_70 = puStack_70 + 1;
                        if (puStack_70 == (ushort *)((int)puVar21 - uVar17)) {
                          if (iVar25 == 0) {
                            iStack_6c = 0x24;
                            memw();
                            puVar11 = (undefined1 *)FUN_4012d5ac(param_1,auStack_64);
                          }
                          else {
                            puVar11 = (undefined1 *)
                                      FUN_4012d674(param_1,auStack_64,&iStack_6c,iVar14 + iVar27,
                                                   (int)puVar8 - (iVar14 + iVar27),iVar25);
                          }
                          if (puVar11 == (undefined1 *)0x0) {
                            if (*(int *)(param_1[0x10] + 100) == 0) goto LAB_4012ecf4;
                            iVar18 = *(int *)(param_1[0x10] + 100) + 0xcc;
                            iVar27 = FUN_401864ec(iVar18,iVar16);
                            if (iVar27 == 0) {
                              FUN_4012a73c(param_1,2,0x28);
                              puVar11 = (undefined1 *)0xffff9300;
                            }
                            else {
                              memw();
                              puVar11 = (undefined1 *)
                                        FUN_40139bb0(iVar18,iVar25,auStack_64,iStack_6c,puStack_70,
                                                     uVar17,0);
                              if (puVar11 == (undefined1 *)0x0) goto LAB_4012eab8;
                              uVar34 = 0x33;
LAB_4012ed52:
                              FUN_4012a73c(param_1,2,uVar34);
                            }
                          }
                          goto LAB_4012d980;
                        }
                      }
                      uVar34 = 0x32;
                      goto LAB_4012ec43;
                    }
LAB_4012ecf4:
                    puVar11 = (undefined1 *)0xffff9400;
                  }
LAB_4012d980:
                  memw();
                  puStack_7c = puVar11;
                  goto LAB_4012da49;
                }
              }
              else {
                if ((1 < uVar17 - 3) && (uVar17 != 8)) {
                  puStack_7c = (undefined1 *)0xffff9400;
                  goto LAB_4012ddf7;
                }
                iVar27 = FUN_40134624(param_1[0x11] + 0xa4,&puStack_70,puVar21);
                if ((iVar27 == 0) && (iVar27 = FUN_4012d814(param_1), iVar27 == 0))
                goto LAB_4012ebdc;
              }
            }
            memw();
            FUN_4012a73c(param_1,2,0x2f);
            puStack_7c = (undefined1 *)0xffff8500;
            goto LAB_4012ddf7;
          }
          if (uVar28 == 5) {
            param_1[0x2c] = 1;
            memw();
LAB_4012eab8:
            iVar18 = param_1[1] + 1;
            memw();
            goto LAB_4012ea55;
          }
        }
        memw();
        FUN_4012a73c(param_1,2,10);
        puStack_7c = &DAT_ffff8900;
LAB_4012e3aa:
        memw();
      }
      goto LAB_4012da49;
    }
    iVar18 = *(int *)(param_1[0x10] + 100);
    if (iVar18 == 0) {
      puStack_7c = (undefined1 *)0xffff9400;
    }
    else {
      iVar27 = FUN_401864ec((int *)(iVar18 + 0xcc),2);
      if (iVar27 == 0) {
        puStack_7c = (undefined1 *)0xffff9300;
        memw();
      }
      else {
        iStack_6c = *(int *)(iVar18 + 0xcc);
        uStack_68 = *(undefined4 *)(iVar18 + 0xd0);
        memw();
        iVar18 = FUN_40186520(&iStack_6c);
        uVar34 = 0;
        if (iVar18 - 2U < 3) {
          uVar34 = uStack_68;
        }
        puStack_7c = (undefined1 *)FUN_4013465c(param_1[0x11] + 0xa4,uVar34,1);
        if (puStack_7c == (undefined1 *)0x0) {
          memw();
          puStack_7c = (undefined1 *)FUN_4012d814(param_1);
          if (puStack_7c == (undefined1 *)0x0) goto LAB_4012eab8;
          puStack_7c = (undefined1 *)0xffff8600;
          memw();
        }
      }
    }
    memw();
    FUN_4012a73c(param_1,2,0x28);
  } while( true );
LAB_4012deae:
  iVar14 = iVar14 + 4;
  if (iVar14 == 0x10000) goto LAB_4012ddf4;
  goto LAB_4012deb6;
LAB_4012e23e:
  memw();
  iVar16 = FUN_401355f8(iVar16);
  if ((iVar16 == 0) || (iVar14 = iVar14 + 2, iVar14 == 0x10000)) goto LAB_4012ddf4;
  goto LAB_4012df15;
}

