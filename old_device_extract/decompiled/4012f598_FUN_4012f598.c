// Function : FUN_4012f598
// Address  : 0x4012f598
// Size     : 7054 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code ******* FUN_4012f598(int *param_1,undefined4 param_2,undefined4 param_3,code *******param_4)

{
  bool bVar1;
  short sVar2;
  undefined1 uVar3;
  byte bVar4;
  char cVar5;
  int iVar6;
  byte *pbVar7;
  uint uVar8;
  byte *pbVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  undefined1 *puVar13;
  ushort uVar14;
  code *******pppppppcVar15;
  byte *pbVar16;
  code *******pppppppcVar17;
  int *piVar18;
  undefined4 *puVar19;
  code *pcVar20;
  code ******ppppppcVar21;
  ushort *puVar22;
  ushort *puVar23;
  code *******pppppppcVar24;
  char *pcVar25;
  int iVar26;
  code *****pppppcVar27;
  undefined4 uVar28;
  uint uVar29;
  ushort *puVar30;
  code *******in_a13;
  code *******pppppppcVar31;
  code *****apppppcStack_120 [4];
  undefined4 local_110;
  code ******ppppppcStack_10c;
  ushort *puStack_f8;
  code ******ppppppcStack_f4;
  byte *pbStack_f0;
  ushort *puStack_ec;
  code ******ppppppcStack_e8;
  code ******ppppppcStack_e4;
  code ******ppppppcStack_e0;
  code ******ppppppcStack_dc;
  code ******ppppppcStack_d8;
  code ******ppppppcStack_d4;
  code ******ppppppcStack_d0;
  code ******ppppppcStack_cc;
  code ******ppppppcStack_c8;
  code ******ppppppcStack_c4;
  int iStack_b8;
  undefined1 auStack_b4 [4];
  code *****pppppcStack_b0;
  code ******local_ac;
  code ****ppppcStack_a8;
  undefined4 auStack_a4 [2];
  code ******ppppppcStack_9c;
  code ******ppppppcStack_98;
  undefined4 uStack_94;
  undefined1 auStack_90 [108];
  uint uStack_24;
  code *****apppppcStack_20 [8];
  
  memw();
  memw();
  uStack_24 = _DAT_3ffc5708;
  if (param_1[1] == 0x10) {
LAB_4012f678:
    param_4 = (code *******)0xffff8f00;
    memw();
    goto LAB_4012fcd4;
  }
  if (param_1[0x11] == 0) {
LAB_4012f628:
    pppppppcVar15 = (code *******)0xffff8f00;
    goto LAB_4012f606;
  }
  memw();
  ppppppcStack_e8 = (code ******)FUN_40129bc8(param_1);
  pppppppcVar17 = (code *******)local_ac;
  if ((code *******)ppppppcStack_e8 != (code *******)0x0) goto LAB_4012f6cc;
  if (((*(char *)(*param_1 + 5) == '\x01') && (*(char *)(param_1[0x11] + 7) == '\x01')) &&
     (pppppppcVar17 = (code *******)FUN_40129fc8(param_1), pppppppcVar17 != (code *******)0x0))
  goto LAB_4012f695;
  pppppppcVar15 = (code *******)param_1[1];
  ppppppcStack_e4 = (code ******)pppppppcVar15;
  if (pppppppcVar15 == (code *******)&DAT_00000008) {
    iVar6 = *(int *)(param_1[0x11] + 0x14);
    ppppppcStack_e8 = (code ******)FUN_4012a960(param_1,1);
    pppppppcVar17 = (code *******)local_ac;
    if ((code *******)ppppppcStack_e8 != (code *******)0x0) goto LAB_4012f6cc;
    iVar26 = 0xc;
    if (*(char *)(*param_1 + 5) != '\x01') {
      iVar26 = 4;
    }
    pcVar25 = (char *)param_1[0x1e];
    local_ac = (code ******)(pcVar25 + iVar26);
    param_4 = (code *******)param_1[0x2a];
    pppppppcVar15 = (code *******)(pcVar25 + (int)param_4);
    if ((param_1[0x20] != 0x16) || (*pcVar25 != '\x10')) {
LAB_40130d88:
      ppppppcStack_e8 = (code ******)0xffff8400;
      memw();
      pppppppcVar17 = (code *******)local_ac;
      goto LAB_4012f6cc;
    }
    iVar10 = *(int *)(iVar6 + 0x10);
    if (iVar10 == 2) {
      ppppppcStack_e8 = (code ******)FUN_4012f348(param_1,&local_ac,pppppppcVar15);
      pppppppcVar17 = (code *******)local_ac;
      if ((code *******)ppppppcStack_e8 != (code *******)0x0) goto LAB_4012f6cc;
      if (pppppppcVar15 != (code *******)local_ac) goto LAB_40130d88;
      iVar6 = param_1[0x11];
      in_a13 = (code *******)(iVar6 + 0x10);
      memw();
      iVar6 = FUN_401342c4(iVar6 + 0x28,iVar6 + 0x4b0,0x424,in_a13,*(undefined4 *)(*param_1 + 0x4c),
                           *(undefined4 *)(*param_1 + 0x50));
LAB_40130ddc:
      if (iVar6 != 0) {
        pppppppcVar17 = (code *******)0xffff8300;
        goto LAB_4012f927;
      }
    }
    else {
      if ((iVar10 - 9U < 2) || (iVar10 - 3U < 2)) {
        iVar6 = FUN_401346ec(param_1[0x11] + 0xa4,local_ac,(int)param_4 - iVar26);
        ppppppcStack_e8 = (code ******)0xffff8380;
        pppppppcVar17 = (code *******)local_ac;
        if (iVar6 != 0) goto LAB_4012f6cc;
        in_a13 = (code *******)0x400;
        iVar6 = param_1[0x11];
        memw();
        iVar6 = FUN_40134718(iVar6 + 0xa4,iVar6 + 0x10,iVar6 + 0x4b0,0x400,
                             *(undefined4 *)(*param_1 + 0x4c),*(undefined4 *)(*param_1 + 0x50));
        goto LAB_40130ddc;
      }
      if (iVar10 == 5) {
        param_4 = (code *******)apppppcStack_20;
        ppppppcStack_e8 = (code ******)FUN_4012f3a4(param_1,&local_ac,pppppppcVar15);
LAB_40130e24:
        pppppppcVar17 = (code *******)local_ac;
        if ((code *******)ppppppcStack_e8 != (code *******)0x0) goto LAB_4012f6cc;
        ppppppcStack_e8 = (code ******)0x0;
        if (pppppppcVar15 != (code *******)local_ac) goto LAB_40130d88;
LAB_40130e34:
        memw();
        ppppppcStack_e8 = (code ******)FUN_4012c1f8(param_1,*(undefined4 *)(iVar6 + 0x10));
      }
      else {
        if (iVar10 == 7) {
          ppppppcStack_e8 = (code ******)FUN_4012f3a4(param_1,&local_ac,pppppppcVar15);
          pppppppcVar17 = (code *******)local_ac;
          if ((code *******)ppppppcStack_e8 != (code *******)0x0) goto LAB_4012f6cc;
          in_a13 = (code *******)0x2;
          memw();
          pppppppcVar17 = (code *******)FUN_4012f428(param_1,local_ac,pppppppcVar15,2);
          ppppppcStack_e8 = (code ******)pppppppcVar17;
LAB_40130eb7:
          if (pppppppcVar17 != (code *******)0x0) {
            memw();
            pppppppcVar17 = (code *******)local_ac;
            goto LAB_4012f6cc;
          }
          goto LAB_40130e34;
        }
        if (iVar10 == 6) {
          ppppppcStack_e8 = (code ******)FUN_4012f3a4(param_1,&local_ac,pppppppcVar15);
          pppppppcVar17 = (code *******)local_ac;
          if ((code *******)ppppppcStack_e8 != (code *******)0x0) goto LAB_4012f6cc;
          memw();
          ppppppcStack_e8 = (code ******)FUN_4012f348(param_1,&local_ac,pppppppcVar15);
          goto LAB_40130e24;
        }
        if (iVar10 == 8) {
          ppppppcStack_e8 = (code ******)FUN_4012f3a4(param_1,&local_ac,pppppppcVar15);
          pppppppcVar17 = (code *******)local_ac;
          if ((code *******)ppppppcStack_e8 != (code *******)0x0) goto LAB_4012f6cc;
          memw();
          pppppppcVar17 =
               (code *******)
               FUN_401346ec(param_1[0x11] + 0xa4,local_ac,(int)pppppppcVar15 - (int)local_ac);
          ppppppcStack_e8 = (code ******)0xffff8380;
          memw();
          goto LAB_40130eb7;
        }
        ppppppcStack_e8 = (code ******)0xffff9400;
        pppppppcVar17 = (code *******)local_ac;
        if (iVar10 != 1) goto LAB_4012f6cc;
        in_a13 = (code *******)0x0;
        memw();
        ppppppcStack_e8 = (code ******)FUN_4012f428(param_1,local_ac,pppppppcVar15,0);
      }
      if ((code *******)ppppppcStack_e8 != (code *******)0x0) {
        memw();
        pppppppcVar17 = (code *******)local_ac;
        goto LAB_4012f6cc;
      }
    }
    ppppppcStack_e8 = (code ******)FUN_4012bd8c(param_1);
    pppppppcVar17 = (code *******)local_ac;
    if ((code *******)ppppppcStack_e8 != (code *******)0x0) goto LAB_4012f6cc;
    iVar6 = param_1[1] + 1;
  }
  else {
    pppppppcVar17 = (code *******)local_ac;
    if ((int)pppppppcVar15 < 9) {
      if (pppppppcVar15 == (code *******)0x3) {
        pppppppcVar17 = (code *******)FUN_4012c394(param_1);
        goto LAB_4012f695;
      }
      if (3 < (int)pppppppcVar15) {
        if (pppppppcVar15 == (code *******)&DAT_00000005) {
          param_4 = (code *******)&DAT_00000006;
          iVar6 = *(int *)(param_1[0x11] + 0x14);
          param_1[1] = 6;
          cVar5 = *(char *)(param_1[0x11] + 4);
          iVar26 = param_1[0x33];
          if (cVar5 == '\x03') {
            cVar5 = *(char *)(*param_1 + 6);
          }
          uVar8 = *(uint *)(iVar6 + 0x10);
          if (((uVar8 != 0) && ((uVar8 < 5 || (uVar8 - 9 < 2)))) && (cVar5 != '\0')) {
            *(undefined1 *)(iVar26 + 6) = 0x40;
            puVar22 = (ushort *)(iVar26 + 7);
            iVar6 = 0;
            *(undefined1 *)(iVar26 + 5) = 1;
            *(undefined1 *)(iVar26 + 4) = 2;
            memw();
            if (param_1[5] == 3) {
              pbVar16 = *(byte **)(*param_1 + 0xac);
              iVar10 = 0;
              puVar30 = puVar22;
              while( true ) {
                iVar6 = iVar10 + 2;
                puVar22 = (ushort *)((int)puVar30 + iVar6);
                if (*(int *)pbVar16 == 0) break;
                memw();
                pbStack_f0 = pbVar16;
                puStack_ec = puVar30;
                iVar12 = FUN_40185aa8();
                iVar6 = iVar10;
                if ((iVar12 != 0) && (iVar11 = FUN_4012d570(param_1,iVar12), iVar11 == 0)) {
                  *(byte *)puVar22 = (byte)iVar12;
                  iVar6 = iVar10 + 4;
                  *(byte *)((int)puStack_ec + iVar10 + 3) = 1;
                  *(byte *)((int)puStack_ec + iVar6) = (byte)iVar12;
                  *(byte *)((int)puStack_ec + iVar10 + 5) = 3;
                  memw();
                }
                pbVar16 = pbStack_f0 + 4;
                memw();
                iVar10 = iVar6;
                puVar30 = puStack_ec;
              }
              *(char *)(iVar26 + 7) = (char)((uint)iVar10 >> 8);
              *(char *)(iVar26 + 8) = (char)iVar10;
              memw();
            }
            puVar22 = puVar22 + 1;
            param_4 = (code *******)0x0;
            if (*(char *)(*param_1 + 0x11) == '\x01') {
              iVar10 = *(int *)(param_1[0x11] + 0x1ec);
              if (iVar10 == 0) {
                iVar10 = *(int *)(*param_1 + 0xa4);
              }
              param_4 = (code *******)0x0;
              memw();
              puVar30 = (ushort *)(iVar26 + 0x4000);
              for (; (iVar10 != 0 && (*(int *)(iVar10 + 0x1c) != 0));
                  iVar10 = *(int *)(iVar10 + 0x154)) {
                uVar8 = *(uint *)(iVar10 + 0x48);
                if (puVar30 < puVar22) break;
                puVar23 = (ushort *)(uVar8 & 0xffff);
                in_a13 = (code *******)(puVar23 + 1);
                if ((code *******)((int)puVar30 - (int)puVar22) < in_a13) break;
                *(byte *)puVar22 = (byte)((uVar8 & 0xffff) >> 8);
                in_a13 = (code *******)(puVar22 + 1);
                *(byte *)((int)puVar22 + 1) = (byte)uVar8;
                memw();
                param_4 = (code *******)((uint)((int)param_4 + (uVar8 & 0xffff) + 2) & 0xffff);
                memw();
                puStack_f8 = puVar23;
                puStack_ec = puVar30;
                iVar12 = (*(code *)&SUB_4008b3d0)(in_a13,*(undefined4 *)(iVar10 + 0x4c),puVar23);
                puVar22 = (ushort *)((int)puStack_f8 + iVar12);
                puVar30 = puStack_ec;
              }
            }
            param_1[0x34] = 0x16;
            param_1[0x35] = (int)puVar22 - iVar26;
            *(undefined1 *)param_1[0x33] = 0xd;
            memw();
            *(char *)(param_1[0x33] + iVar6 + 7) = (char)((uint)param_4 >> 8);
            memw();
            *(char *)(param_1[0x33] + iVar6 + 8) = (char)param_4;
            memw();
            memw();
            goto LAB_401307a8;
          }
          goto LAB_4012f6cc;
        }
        param_4 = pppppppcVar15;
        if (4 < (int)pppppppcVar15) {
          if (pppppppcVar15 != (code *******)&DAT_00000006) {
            if (pppppppcVar15 == (code *******)&DAT_00000007) {
              pppppppcVar17 = (code *******)FUN_4012d208(param_1);
              goto LAB_4012f695;
            }
            goto LAB_4012f628;
          }
          param_1[0x35] = 4;
          param_1[0x34] = 0x16;
          *(undefined1 *)param_1[0x33] = 0xe;
          memw();
          param_1[1] = param_1[1] + 1;
          if (*(char *)(*param_1 + 5) == '\x01') {
            memw();
            FUN_401299a8(param_1);
          }
          pppppppcVar17 = (code *******)FUN_4012a534(param_1);
          if (pppppppcVar17 != (code *******)0x0) goto LAB_4012f695;
          goto LAB_4013036c;
        }
        pppppcStack_b0 = (code *****)0x0;
        iVar6 = *(int *)(param_1[0x11] + 0x14);
        uVar8 = *(uint *)(iVar6 + 0x10);
        if (uVar8 == 7) {
LAB_40130860:
          param_1[1] = param_1[1] + 1;
          memw();
          pppppppcVar17 = (code *******)ppppppcStack_e8;
          goto LAB_4012f927;
        }
        if (uVar8 < 8) {
          if ((uVar8 == 1) || (uVar8 == 5)) goto LAB_40130860;
        }
        else if (uVar8 - 9 < 2) {
          puVar19 = (undefined4 *)FUN_40185bb8(param_1);
          iVar6 = FUN_40186520();
          if (iVar6 != 2) {
            iVar6 = FUN_40186520(puVar19);
            pppppppcVar17 = (code *******)0xffff9300;
            if (iVar6 != 3) goto LAB_4012f927;
          }
          iVar6 = param_1[0x11];
          local_ac = (code ******)*puVar19;
          ppppcStack_a8 = (code ****)puVar19[1];
          memw();
          iVar26 = FUN_40186520(&local_ac);
          pppppcVar27 = (code *****)0x0;
          if (iVar26 - 2U < 3) {
            pppppcVar27 = (code *****)ppppcStack_a8;
          }
          pppppppcVar17 = (code *******)FUN_4013465c(iVar6 + 0xa4,pppppcVar27,0);
          if (pppppppcVar17 != (code *******)0x0) goto LAB_4012f927;
          goto LAB_40130860;
        }
        param_1[0x35] = 4;
        if ((uVar8 - 6 & 0xfffffffd) == 0) {
          param_1[0x35] = 5;
          *(undefined1 *)(param_1[0x33] + 4) = 0;
          memw();
          param_4 = (code *******)param_1[0x35];
          param_1[0x35] = (int)((int)param_4 + 1);
          *(byte *)((int)param_4 + param_1[0x33]) = 0;
          memw();
          memw();
        }
        if ((*(int *)(iVar6 + 0x10) == 2) ||
           (param_4 = (code *******)0x0, *(int *)(iVar6 + 0x10) == 6)) {
          local_ac = (code ******)0x0;
          iVar26 = *param_1;
          if ((*(int *)(iVar26 + 0xbc) == 0) || (*(int *)(iVar26 + 200) == 0)) {
            pppppppcVar17 = (code *******)0xffff8f00;
            goto LAB_40130a43;
          }
          memw();
          pppppppcVar17 =
               (code *******)FUN_40134220(param_1[0x11] + 0x28,iVar26 + 0xb4,iVar26 + 0xc0);
          if (pppppppcVar17 == (code *******)0x0) {
            iVar26 = param_1[0x11];
            uVar28 = FUN_401317d8(iVar26 + 0x2c);
            in_a13 = &local_ac;
            param_4 = (code *******)param_1[0x35];
            pppppppcVar17 =
                 (code *******)
                 FUN_4013414c(iVar26 + 0x28,uVar28,(byte *)((int)param_4 + param_1[0x33]),in_a13,
                              *(undefined4 *)(*param_1 + 0x4c),*(undefined4 *)(*param_1 + 0x50));
            if (pppppppcVar17 == (code *******)0x0) {
              param_4 = (code *******)(param_1[0x33] + param_1[0x35]);
              param_1[0x35] = (int)((int)local_ac + param_1[0x35]);
              goto LAB_40130901;
            }
          }
        }
        else {
LAB_40130901:
          uVar8 = *(uint *)(iVar6 + 0x10);
          if ((2 < uVar8) && ((uVar8 < 5 || (uVar8 == 8)))) {
            piVar18 = (int *)0x0;
            puVar19 = *(undefined4 **)(*param_1 + 0xb0);
            local_ac = (code ******)0x0;
            for (; param_4 = (code *******)*puVar19, param_4 != (code *******)0x0;
                puVar19 = puVar19 + 1) {
              for (piVar18 = *(int **)(param_1[0x11] + 0x1d8);
                  (undefined4 *)*piVar18 != (undefined4 *)0x0; piVar18 = piVar18 + 1) {
                if (*(code ********)*piVar18 == param_4) goto LAB_4013091e;
              }
            }
            if (piVar18 != (int *)0x0) {
LAB_4013091e:
              if ((undefined4 *)*piVar18 != (undefined4 *)0x0) {
                memw();
                pppppppcVar17 =
                     (code *******)FUN_4013456c(param_1[0x11] + 0xa4,*(undefined4 *)*piVar18);
                if (pppppppcVar17 == (code *******)0x0) {
                  param_4 = (code *******)*param_1;
                  in_a13 = (code *******)(0x4000 - param_1[0x35]);
                  pppppppcVar17 =
                       (code *******)
                       FUN_401345cc(param_1[0x11] + 0xa4,&local_ac,param_1[0x33] + param_1[0x35],
                                    in_a13,param_4[0x13],param_4[0x14]);
                  if (pppppppcVar17 == (code *******)0x0) {
                    param_4 = (code *******)(param_1[0x33] + param_1[0x35]);
                    param_1[0x35] = (int)((int)local_ac + param_1[0x35]);
                    goto LAB_40130976;
                  }
                }
                goto LAB_40130a9c;
              }
            }
            pppppppcVar17 = (code *******)0xffff8c80;
            goto LAB_40130a43;
          }
LAB_40130976:
          if (2 < *(int *)(iVar6 + 0x10) - 2U) goto LAB_40130b49;
          in_a13 = (code *******)param_1[0x35];
          pppppppcVar15 = (code *******)((int)in_a13 + (param_1[0x33] - (int)param_4));
          local_ac = (code ******)0x0;
          memw();
          iVar26 = FUN_40185b28(iVar6);
          if (param_1[5] == 3) {
            if ((iVar26 == 0) ||
               (pppppppcVar24 = (code *******)FUN_40185a28(param_1[0x11] + 8,iVar26),
               pppppppcVar24 == (code *******)0x0)) {
              pppppppcVar17 = (code *******)0xffff9400;
              goto LAB_40130a43;
            }
LAB_40130aa8:
            in_a13 = param_4;
            pppppppcVar17 =
                 (code *******)
                 FUN_4012d674(param_1,auStack_a4,&local_ac,param_4,pppppppcVar15,pppppppcVar24);
          }
          else {
            pppppppcVar24 = *(code ********)(iVar6 + 0x10);
            if (pppppppcVar24 == (code *******)&DAT_00000004) goto LAB_40130aa8;
            local_ac = (code ******)0x24;
            memw();
            pppppppcVar17 = (code *******)FUN_4012d5ac(param_1,auStack_a4,param_4,pppppppcVar15);
            pppppppcVar24 = pppppppcVar17;
            in_a13 = pppppppcVar15;
          }
          if (pppppppcVar17 == (code *******)0x0) {
            if (param_1[5] == 3) {
              iVar10 = param_1[0x35];
              iVar6 = param_1[0x33];
              param_1[0x35] = iVar10 + 1;
              memw();
              uVar3 = FUN_40185aa8(pppppppcVar24);
              *(undefined1 *)(iVar6 + iVar10) = uVar3;
              memw();
              param_4 = (code *******)param_1[0x35];
              iVar6 = param_1[0x33];
              param_1[0x35] = (int)((int)param_4 + 1);
              memw();
              bVar4 = FUN_401859f8(iVar26);
              *(byte *)((int)param_4 + iVar6) = bVar4;
              memw();
            }
            memw();
            iVar6 = FUN_40185bb8(param_1);
            if (iVar6 == 0) {
              pppppppcVar17 = (code *******)0xffff8a00;
              goto LAB_40130a43;
            }
            param_4 = *(code ********)(*param_1 + 0x50);
            local_110 = *(undefined4 *)(*param_1 + 0x4c);
            memw();
            in_a13 = (code *******)local_ac;
            ppppppcStack_10c = (code ******)param_4;
            pppppppcVar17 =
                 (code *******)
                 FUN_40139c58(iVar6,pppppppcVar24,auStack_a4,local_ac,
                              param_1[0x33] + param_1[0x35] + 2,&pppppcStack_b0);
            if (pppppppcVar17 == (code *******)0x0) {
LAB_40130b49:
              if ((code ******)pppppcStack_b0 != (code ******)0x0) {
                iVar6 = param_1[0x35];
                param_1[0x35] = iVar6 + 1;
                *(char *)(param_1[0x33] + iVar6) = (char)((uint)pppppcStack_b0 >> 8);
                memw();
                iVar6 = param_1[0x35];
                param_4 = (code *******)(iVar6 + 1);
                param_1[0x35] = (int)param_4;
                *(char *)(param_1[0x33] + iVar6) = (char)pppppcStack_b0;
                memw();
                param_1[0x35] = (int)pppppcStack_b0 + param_1[0x35];
              }
              param_1[0x34] = 0x16;
              *(undefined1 *)param_1[0x33] = 0xc;
              memw();
              param_1[1] = param_1[1] + 1;
              memw();
              pppppppcVar17 = (code *******)FUN_4012a534(param_1);
              goto LAB_4012f927;
            }
          }
        }
LAB_40130a9c:
        if (pppppppcVar17 == (code *******)0xffff9b00) goto LAB_4012f927;
LAB_40130a43:
        param_1[0x35] = 0;
        memw();
        goto LAB_4012f927;
      }
      if (pppppppcVar15 == (code *******)0x1) {
        uVar8 = 0x16;
        uVar29 = 0xffffff68;
        param_4 = (code *******)ppppppcStack_e8;
        goto LAB_4012f6a7;
      }
      if ((int)pppppppcVar15 < 2) {
        ppppppcStack_e8 = (code ******)0xffff8f00;
        if (pppppppcVar15 != (code *******)0x0) goto LAB_4012fa88;
        param_1[1] = 1;
        goto LAB_4012f606;
      }
      cVar5 = *(char *)(*param_1 + 5);
      if ((cVar5 == '\x01') && (*(char *)(param_1[0x11] + 0x244) != '\0')) {
        in_a13 = (code *******)(param_1[0x33] + 4);
        memw();
        local_ac = (code ******)in_a13;
        FUN_401858e4(param_1[4],param_1[5]);
        ppppppcVar21 = local_ac;
        param_4 = (code *******)*param_1;
        ppppppcStack_e8 = (code ******)0xffff9400;
        pppppppcVar17 = (code *******)((int)local_ac + 2);
        if (param_4[0x1e] == (code ******)0x0) goto LAB_4012f6cc;
        pppppppcVar15 = (code *******)((int)local_ac + 3);
        in_a13 = (code *******)param_1[0x7e];
        memw();
        local_ac = (code ******)pppppppcVar15;
        ppppppcStack_e8 =
             (code ******)
             (*(code *)param_4[0x1e])
                       (param_4[0x20],&local_ac,param_1[0x2e] + 0x414d,in_a13,param_1[0x7f]);
        pppppppcVar17 = (code *******)local_ac;
        if ((code *******)ppppppcStack_e8 != (code *******)0x0) goto LAB_4012f6cc;
        *(char *)((int)ppppppcVar21 + 2) = (char)local_ac - (char)pppppppcVar15;
        memw();
        param_1[0x35] = (int)local_ac - param_1[0x33];
        param_1[0x34] = 0x16;
        *(undefined1 *)param_1[0x33] = 3;
        memw();
        param_1[1] = 0x12;
        memw();
        ppppppcStack_e8 = (code ******)FUN_4012a534(param_1);
        pppppppcVar17 = (code *******)local_ac;
        if ((code *******)ppppppcStack_e8 != (code *******)0x0) goto LAB_4012f6cc;
LAB_4013036c:
        pppppppcVar17 = (code *******)local_ac;
        if (*(char *)(*param_1 + 5) == '\x01') {
          memw();
          pppppppcVar17 = (code *******)FUN_40129fc8(param_1);
          goto LAB_4012f695;
        }
        goto LAB_4012f6cc;
      }
      ppppppcStack_e8 = (code ******)0xffff8c00;
      if (*(int *)(*param_1 + 0x4c) == 0) goto LAB_4012f6cc;
      pppppppcVar15 = (code *******)param_1[0x33];
      in_a13 = pppppppcVar15 + 1;
      memw();
      ppppppcStack_e4 = (code ******)pppppppcVar15;
      FUN_401858e4(param_1[4],param_1[5],cVar5,in_a13);
      uVar28 = (*(code *)&SUB_4008cd2c)(0);
      *(byte *)((int)pppppppcVar15 + 6) = (byte)((uint)uVar28 >> 0x18);
      *(byte *)((int)pppppppcVar15 + 7) = (byte)((uint)uVar28 >> 0x10);
      *(byte *)(pppppppcVar15 + 2) = (byte)((uint)uVar28 >> 8);
      *(byte *)((int)pppppppcVar15 + 9) = (byte)uVar28;
      memw();
      memw();
      ppppppcStack_e8 =
           (code ******)
           (**(code **)(*param_1 + 0x4c))
                     (*(undefined4 *)(*param_1 + 0x50),(ushort *)((int)pppppppcVar15 + 10),0x1c);
      pppppppcVar17 = (code *******)local_ac;
      if ((code *******)ppppppcStack_e8 != (code *******)0x0) goto LAB_4012f6cc;
      memw();
      (*(code *)&SUB_4008b3d0)(param_1[0x11] + 0x490,(ushort *)((int)pppppppcVar15 + 6),0x20);
      if ((((*(char *)(param_1[0x11] + 2) != '\x01') &&
           (iVar6 = param_1[0x10], *(int *)(iVar6 + 0x10) != 0)) && (*(int *)(*param_1 + 0x54) != 0)
          ) && (param_1[2] == 0)) {
        FUN_4012c768(auStack_a4);
        uStack_94 = *(undefined4 *)(iVar6 + 0x10);
        memw();
        (*(code *)&SUB_4008b3d0)(auStack_90,iVar6 + 0x14);
        param_4 = *(code ********)(*param_1 + 0x54);
        iVar26 = (*(code *)param_4)(*(undefined4 *)(*param_1 + 0x5c),auStack_a4);
        if (((iVar26 == 0) &&
            (param_4 = (code *******)ppppppcStack_9c,
            *(code ********)(iVar6 + 8) == (code *******)ppppppcStack_9c)) &&
           (param_4 = (code *******)ppppppcStack_98,
           *(code ********)(iVar6 + 0xc) == (code *******)ppppppcStack_98)) {
          FUN_4012cacc(iVar6);
          (*(code *)&SUB_4008b3d0)(iVar6,auStack_a4,0x80);
          (*(code *)&SUB_4008b530)(auStack_a4,0,0x80);
          param_4 = (code *******)apppppcStack_120;
          *(undefined1 *)(param_1[0x11] + 2) = 1;
          memw();
        }
        memw();
        FUN_4012cacc(auStack_a4);
      }
      if (*(char *)(param_1[0x11] + 2) == '\0') {
        param_1[1] = param_1[1] + 1;
        iVar6 = param_1[0x10];
        memw();
        uVar28 = (*(code *)&SUB_4008cd2c)(0);
        *(undefined4 *)(iVar6 + 4) = uVar28;
        iVar6 = param_1[0x10];
        if (*(char *)(param_1[0x11] + 5) == '\0') {
          iVar26 = *param_1;
          *(undefined4 *)(iVar6 + 0x10) = 0x20;
          memw();
          ppppppcStack_e8 =
               (code ******)
               (**(code **)(iVar26 + 0x4c))(*(undefined4 *)(iVar26 + 0x50),iVar6 + 0x14);
          goto LAB_401307c9;
        }
        *(undefined4 *)(iVar6 + 0x10) = 0;
        memw();
        (*(code *)&SUB_4008b530)(iVar6 + 0x14,0,0x20);
      }
      else {
        param_1[1] = 0xc;
        memw();
        ppppppcStack_e8 = (code ******)FUN_4012bd8c(param_1);
LAB_401307c9:
        if ((code *******)ppppppcStack_e8 != (code *******)0x0) {
          memw();
          pppppppcVar17 = (code *******)local_ac;
          goto LAB_4012f6cc;
        }
      }
      pbVar16 = (byte *)((int)ppppppcStack_e4 + 0x27);
      *(byte *)((int)ppppppcStack_e4 + 0x26) = (byte)*(undefined4 *)(param_1[0x10] + 0x10);
      memw();
      memw();
      (*(code *)&SUB_4008b3d0)(pbVar16,param_1[0x10] + 0x14,*(undefined4 *)(param_1[0x10] + 0x10));
      pbVar16 = pbVar16 + *(int *)(param_1[0x10] + 0x10);
      param_4 = (code *******)(pbVar16 + 3);
      iVar6 = 0;
      *pbVar16 = (byte)((uint)*(undefined4 *)(param_1[0x10] + 8) >> 8);
      memw();
      pbVar16[1] = (byte)*(undefined4 *)(param_1[0x10] + 8);
      memw();
      pbVar16[2] = (byte)*(undefined4 *)(param_1[0x10] + 0xc);
      memw();
      if (param_1[0x80] == 1) {
        pbVar7 = pbVar16 + 10;
        pbVar16[5] = 0xff;
        pbVar16[6] = 1;
        memw();
        if (param_1[2] == 0) {
          pbVar16[7] = 0;
          pbVar16[8] = 1;
          pbVar16[9] = 0;
          memw();
          memw();
        }
        else {
          pbVar16[7] = 0;
          memw();
          pbVar16[8] = (char)param_1[0x81] * '\x02' + 1;
          memw();
          pbVar16[9] = (byte)(param_1[0x81] << 1);
          memw();
          memw();
          (*(code *)&SUB_4008b3d0)(pbVar7,param_1 + 0x85,param_1[0x81]);
          iVar6 = param_1[0x81];
          (*(code *)&SUB_4008b3d0)(pbVar7 + iVar6,param_1 + 0x82);
          pbVar7 = pbVar7 + iVar6 + param_1[0x81];
        }
        iVar6 = (int)pbVar7 - (int)(pbVar16 + 5);
      }
      iVar26 = 0;
      if (*(char *)param_1[0x10] != '\0') {
        pbVar7 = (byte *)((int)param_4 + iVar6 + 2);
        *pbVar7 = 0;
        pbVar7[1] = 1;
        pbVar7[2] = 0;
        pbVar7[3] = 1;
        memw();
        pbVar7[4] = *(byte *)param_1[0x10];
        memw();
        iVar26 = 5;
      }
      iVar10 = 0;
      if (*(int *)(param_1[0x10] + 0x78) != 0) {
        pbVar7 = (byte *)((int)param_4 + iVar6 + iVar26 + 2);
        *pbVar7 = 0;
        pbVar7[2] = 0;
        pbVar7[3] = 0;
        iVar10 = 4;
        pbVar7[1] = 4;
        memw();
      }
      iVar10 = iVar6 + iVar26 + iVar10;
      iVar6 = param_1[0x10];
      if (param_1[5] == 0) {
        *(undefined4 *)(iVar6 + 0x7c) = 0;
      }
      memw();
      iVar6 = FUN_4012d7a8(*(undefined4 *)(iVar6 + 8));
      if (((iVar6 == 0) || (iVar6 = FUN_40132c44(*(undefined4 *)(iVar6 + 8)), iVar6 == 0)) ||
         (*(int *)(iVar6 + 4) != 2)) {
        iVar6 = 0;
        *(undefined4 *)(param_1[0x10] + 0x7c) = 0;
      }
      else {
        iVar6 = 0;
        if (*(int *)(param_1[0x10] + 0x7c) != 0) {
          pbVar7 = (byte *)((int)param_4 + iVar10 + 2);
          *pbVar7 = 0;
          pbVar7[1] = 0x16;
          pbVar7[2] = 0;
          pbVar7[3] = 0;
          memw();
          iVar6 = 4;
          memw();
        }
      }
      iVar10 = iVar10 + iVar6;
      iVar6 = 0;
      if ((*(char *)(param_1[0x11] + 6) != '\0') && (param_1[5] != 0)) {
        pbVar7 = (byte *)((int)param_4 + iVar10 + 2);
        *pbVar7 = 0;
        pbVar7[2] = 0;
        pbVar7[3] = 0;
        iVar6 = 4;
        pbVar7[1] = 0x17;
        memw();
      }
      iVar10 = iVar10 + iVar6;
      iVar6 = 0;
      if (*(char *)(param_1[0x11] + 5) != '\0') {
        pbVar7 = (byte *)((int)param_4 + iVar10 + 2);
        *pbVar7 = 0;
        pbVar7[2] = 0;
        pbVar7[3] = 0;
        iVar6 = 4;
        pbVar7[1] = 0x23;
        memw();
      }
      iVar10 = iVar10 + iVar6;
      memw();
      FUN_4012d7a8(*(undefined4 *)(param_1[0x10] + 8));
      iVar6 = FUN_40185b6c();
      if (iVar6 != 0) {
        iVar6 = 0;
        if ((*(byte *)(param_1[0x11] + 3) & 1) != 0) {
          pbVar7 = (byte *)((int)param_4 + iVar10 + 2);
          pbVar7[1] = 0xb;
          pbVar7[3] = 2;
          *pbVar7 = 0;
          pbVar7[2] = 0;
          pbVar7[5] = 0;
          iVar6 = 6;
          pbVar7[4] = 1;
          memw();
        }
        iVar10 = iVar10 + iVar6;
      }
      puVar22 = (ushort *)0x0;
      if (param_1[0x3c] != 0) {
        pbVar7 = (byte *)((int)param_4 + iVar10 + 2);
        *pbVar7 = 0;
        pbVar7[1] = 0x10;
        memw();
        memw();
        iVar6 = (*(code *)&SUB_4008c01c)(param_1[0x3c]);
        puStack_ec = (ushort *)(iVar6 + 7);
        pbVar7[2] = (byte)((uint)(iVar6 + 3) >> 8);
        cVar5 = (char)puStack_ec;
        pbVar7[3] = cVar5 - 4;
        pbVar7[4] = (byte)((uint)(iVar6 + 1) >> 8);
        pbVar7[5] = cVar5 - 6;
        pbVar7[6] = cVar5 - 7;
        memw();
        memw();
        (*(code *)&SUB_4008b3d0)(pbVar7 + 7,param_1[0x3c],iVar6);
        puVar22 = puStack_ec;
      }
      uVar8 = 0;
      if ((*(char *)(*param_1 + 5) == '\x01') && ((short)param_1[0x3d] != 0)) {
        uVar29 = 0;
        if (*(char *)(*param_1 + 0x12) == '\x01') {
          uVar29 = (uint)*(ushort *)((int)param_1 + 0xf6);
        }
        pbVar7 = (byte *)((int)param_4 + (int)((int)puVar22 + iVar10 + 2));
        uVar8 = uVar29 + 9;
        if (uVar8 <= (uint)((param_1[0x33] + 0x4000) - (int)pbVar7)) {
          pbVar7[1] = 0xe;
          *pbVar7 = 0;
          pbVar7[4] = 0;
          pbVar7[3] = (byte)(uVar29 + 5);
          pbVar7[2] = (byte)(uVar29 + 5 >> 8);
          pbVar7[5] = 2;
          memw();
          uVar14 = *(ushort *)(param_1 + 0x3d);
          if ((uVar14 != 0) && ((uVar14 < 3 || ((ushort)(uVar14 - 5) < 2)))) {
            pbVar7[6] = 0;
            pbVar7[7] = (byte)uVar14;
            pbVar7[8] = (byte)uVar29;
            memw();
            memw();
            (*(code *)&SUB_4008b3d0)(pbVar7 + 9,param_1 + 0x3e);
            goto LAB_40130778;
          }
        }
        uVar8 = 0;
      }
LAB_40130778:
      pbVar7 = (byte *)((int)puVar22 + uVar8 + iVar10);
      if (pbVar7 != (byte *)0x0) {
        pbVar16[4] = (byte)pbVar7;
        param_4 = (code *******)((int)param_4 + (int)(pbVar7 + 2));
        pbVar16[3] = (byte)((uint)pbVar7 >> 8);
        memw();
      }
      param_1[0x35] = (int)param_4 - (int)ppppppcStack_e4;
      param_1[0x34] = 0x16;
      *(undefined1 *)param_1[0x33] = 2;
      memw();
LAB_401307a8:
      memw();
      pppppppcVar17 = (code *******)FUN_4012a534(param_1);
      goto LAB_4012f695;
    }
    if (pppppppcVar15 == (code *******)&DAT_0000000c) {
      if (*(char *)(param_1[0x11] + 5) == '\0') {
        pppppppcVar17 = (code *******)FUN_4012a714(param_1);
        goto LAB_4012f695;
      }
      param_1[0x34] = 0x16;
      *(undefined1 *)param_1[0x33] = 4;
      memw();
      in_a13 = (code *******)(param_1[0x33] + 0x4000);
      memw();
      iVar6 = (**(code **)(*param_1 + 0x84))
                        (*(undefined4 *)(*param_1 + 0x8c),param_1[0x10],param_1[0x33] + 10,in_a13,
                         &pppppcStack_b0,&local_ac);
      if (iVar6 != 0) {
        pppppcStack_b0 = (code *****)0x0;
      }
      *(char *)(param_1[0x33] + 4) = (char)((uint)local_ac >> 0x18);
      memw();
      *(char *)(param_1[0x33] + 5) = (char)((uint)local_ac >> 0x10);
      memw();
      *(char *)(param_1[0x33] + 6) = (char)((uint)local_ac >> 8);
      memw();
      *(char *)(param_1[0x33] + 7) = (char)local_ac;
      memw();
      *(char *)(param_1[0x33] + 8) = (char)((uint)pppppcStack_b0 >> 8);
      memw();
      *(char *)(param_1[0x33] + 9) = (char)pppppcStack_b0;
      memw();
      param_1[0x35] = (int)pppppcStack_b0 + 10;
      *(undefined1 *)(param_1[0x11] + 5) = 0;
      memw();
      memw();
      goto LAB_401307a8;
    }
    if ((int)pppppppcVar15 < 0xd) {
      if (pppppppcVar15 == (code *******)&DAT_0000000a) {
        pppppppcVar17 = (code *******)FUN_4012b260(param_1);
        goto LAB_4012f695;
      }
      if (10 < (int)pppppppcVar15) {
        pppppppcVar17 = (code *******)FUN_4012c630(param_1);
        goto LAB_4012f695;
      }
      uVar8 = *(uint *)(*(int *)(param_1[0x11] + 0x14) + 0x10);
      if ((uVar8 != 0) && (((uVar8 < 5 || (uVar8 - 9 < 2)) && (*(int *)(param_1[0x10] + 100) != 0)))
         ) {
        ppppppcStack_e8 = (code ******)FUN_4012a960(param_1,0);
        pppppppcVar17 = (code *******)local_ac;
        if ((code *******)ppppppcStack_e8 != (code *******)0x0) goto LAB_4012f6cc;
        param_1[1] = param_1[1] + 1;
        if ((param_1[0x20] != 0x16) || (*(char *)param_1[0x1e] != '\x0f')) goto LAB_40130f81;
        uVar8 = 0xc;
        if (*(char *)(*param_1 + 5) != '\x01') {
          uVar8 = 4;
        }
        if (*(int *)(param_1[0x10] + 100) == 0) {
          pppppppcVar17 = (code *******)0xffff9400;
          param_4 = (code *******)0x0;
          goto LAB_4012f927;
        }
        param_4 = (code *******)(*(int *)(param_1[0x10] + 100) + 0xcc);
        if (param_1[5] == 3) {
          uVar29 = uVar8 + 2;
          if ((((uint)param_1[0x2a] < uVar29) ||
              (pppppppcVar17 = (code *******)FUN_40185a74(((char *)param_1[0x1e])[uVar8]),
              pppppppcVar17 == (code *******)0x0)) ||
             (iVar6 = FUN_4012d570(param_1,*(undefined1 *)(param_1[0x1e] + uVar8)), iVar6 != 0))
          goto LAB_40130f81;
          puVar19 = auStack_a4;
          if (pppppppcVar17 == (code *******)&DAT_00000004) {
            puVar19 = &uStack_94;
          }
          iVar6 = FUN_40185a10(*(undefined1 *)(param_1[0x1e] + uVar8 + 1));
          if ((iVar6 == 0) || (iVar6 = FUN_401864ec(param_4,iVar6), iVar6 == 0)) goto LAB_40130f81;
          pppppppcVar15 = (code *******)0x0;
        }
        else {
          iVar6 = FUN_401864ec(param_4,4);
          pppppppcVar15 = (code *******)0x14;
          puVar19 = &uStack_94;
          pppppppcVar17 = (code *******)&DAT_00000004;
          uVar29 = uVar8;
          if (iVar6 == 0) {
            pppppppcVar15 = (code *******)0x24;
            puVar19 = auStack_a4;
            pppppppcVar17 = (code *******)ppppppcStack_e8;
          }
        }
        puVar22 = (ushort *)(uVar29 + 2);
        if (((ushort *)param_1[0x2a] < puVar22) ||
           (uVar8 = (uint)CONCAT11(*(undefined1 *)(param_1[0x1e] + uVar29),
                                   ((undefined1 *)(param_1[0x1e] + uVar29))[1]),
           (ushort *)param_1[0x2a] != (ushort *)((int)puVar22 + uVar8))) {
LAB_40130f81:
          param_4 = (code *******)0xffff8280;
          memw();
          goto LAB_4012fcd4;
        }
        memw();
        puStack_ec = puVar22;
        (**(code **)(param_1[0x11] + 0x1c))(param_1,auStack_a4,&local_ac);
        ppppppcStack_e8 =
             (code ******)
             FUN_40139bec(param_4,pppppppcVar17,puVar19,pppppppcVar15,
                          (byte *)((int)puStack_ec + param_1[0x1e]),uVar8);
        in_a13 = pppppppcVar15;
        pppppppcVar17 = (code *******)local_ac;
        if ((code *******)ppppppcStack_e8 == (code *******)0x0) {
          memw();
          FUN_401299ec(param_1);
          in_a13 = pppppppcVar15;
          pppppppcVar17 = (code *******)local_ac;
        }
        goto LAB_4012f6cc;
      }
      iVar6 = 10;
    }
    else {
      if (pppppppcVar15 != (code *******)&DAT_0000000e) {
        if ((int)pppppppcVar15 < 0xe) {
          pppppppcVar17 = (code *******)FUN_4012c514(param_1);
          goto LAB_4012f695;
        }
        if (pppppppcVar15 == (code *******)0xf) {
          FUN_4012cae8(param_1);
          pppppppcVar17 = (code *******)local_ac;
        }
        else {
          ppppppcStack_e8 = (code ******)0xffff9580;
          if (pppppppcVar15 != (code *******)0x12) goto LAB_4012f678;
        }
        goto LAB_4012f6cc;
      }
      iVar6 = 0xf;
    }
  }
  param_1[1] = iVar6;
  memw();
  pppppppcVar17 = (code *******)local_ac;
LAB_4012f6cc:
  local_ac = (code ******)pppppppcVar17;
  uVar29 = uStack_24;
  uVar8 = _DAT_3ffc5708;
  memw();
  memw();
  if (uStack_24 == _DAT_3ffc5708) {
    return (code *******)ppppppcStack_e8;
  }
  memw();
  (*(code *)&SUB_40082ec4)();
  while( true ) {
    in_a13 = (code *******)((int)in_a13 + 1);
    FUN_40185918((int)apppppcStack_20 + uVar29,auStack_b4,*(undefined1 *)(*param_1 + 5),in_a13);
    pppppppcVar17 = in_a13;
    if (iStack_b8 < 3) goto LAB_4012f6c6;
    if (*(char *)(*param_1 + 5) != '\x01') break;
    if (param_1[2] != 0) goto LAB_4012f74f;
    pcVar25 = (char *)param_1[0x1a];
    if ((*pcVar25 != '\0') || (pcVar25[1] != '\0')) goto LAB_4012f6c6;
    (*(code *)&SUB_4008b3d0)((int)param_1 + 0xde,pcVar25 + 2,6);
    iVar6 = FUN_40129a78(param_1);
    if (iVar6 == 0) {
      FUN_40129afc(param_1);
      break;
    }
    param_1[0x24] = 0;
    param_1[0x22] = 0;
    memw();
LAB_4012f6a7:
    bVar1 = param_4 == (code *******)0x0;
    param_4 = (code *******)ppppppcStack_e4;
    if ((bVar1 && param_1[2] == 0) &&
       (param_4 = (code *******)FUN_4012a1b0(param_1,5), param_4 != (code *******)0x0))
    goto LAB_4012fcd4;
    in_a13 = (code *******)param_1[0x1b];
    pppppppcVar17 = in_a13;
    if (*(byte *)in_a13 != uVar8) goto LAB_4012f6c6;
  }
  if (param_1[2] == 0) {
    pppppppcVar15 =
         (code *******)
         ((*(ushort *)param_1[0x1c] & 0xff) << 8 | (uint)(*(ushort *)param_1[0x1c] >> 8));
    pppppppcVar17 = in_a13;
    if ((code *******)0x4000 < pppppppcVar15) goto LAB_4012f6c6;
    iVar6 = 5;
    if (*(char *)(*param_1 + 5) == '\x01') {
      iVar6 = 0xd;
    }
    pppppppcVar17 = (code *******)FUN_4012a1b0(param_1,(byte *)((int)pppppppcVar15 + iVar6));
    if (pppppppcVar17 != (code *******)0x0) goto LAB_4012f695;
    if (*(char *)(*param_1 + 5) == '\x01') {
      param_1[0x24] = (int)((int)pppppppcVar15 + 0xd);
      memw();
    }
    else {
      param_1[0x22] = 0;
      memw();
    }
  }
  else {
LAB_4012f74f:
    pppppppcVar15 = (code *******)param_1[0x2a];
  }
  pcVar25 = (char *)param_1[0x1e];
  (**(code **)(param_1[0x11] + 0x18))(param_1,pcVar25,pppppppcVar15);
  param_4 = (code *******)&DAT_00000004;
  puVar22 = (ushort *)(uint)*(byte *)(*param_1 + 5);
  if (puVar22 == (ushort *)0x1) {
    param_4 = (code *******)&DAT_0000000c;
  }
  pppppppcVar17 = in_a13;
  if ((((pppppppcVar15 < param_4) || (*pcVar25 != '\x01')) || (pcVar25[1] != '\0')) ||
     (pppppppcVar15 !=
      (code *******)((int)param_4 + (CONCAT21(*(undefined2 *)(pcVar25 + 2),pcVar25[3]) & 0xffff))))
  goto LAB_4012f6c6;
  if (puVar22 == (ushort *)0x1) {
    iVar6 = param_1[0x1e];
    uVar8 = (*(ushort *)(iVar6 + 4) & 0xff) << 8 | (uint)(*(ushort *)(iVar6 + 4) >> 8);
    iVar26 = param_1[0x11];
    if (param_1[2] == 1) {
      if (*(uint *)(iVar26 + 0x23c) != uVar8) goto LAB_4012f6c6;
      *(uint *)(iVar26 + 0x23c) = *(uint *)(iVar26 + 0x23c) + 1;
    }
    else {
      *(uint *)(iVar26 + 0x238) = uVar8;
      *(uint *)(iVar26 + 0x23c) = uVar8 + 1;
      memw();
    }
    if (*(char *)(iVar6 + 6) == '\0') {
      if (*(char *)(iVar6 + 7) != '\0') {
        ppppppcStack_e8 = (code ******)0xffff8f80;
        goto LAB_4012fa88;
      }
      if (*(char *)(iVar6 + 8) != '\0') {
        param_4 = (code *******)0xffff8f80;
        goto LAB_4012fcd4;
      }
      memw();
      puStack_f8 = puVar22;
      iVar6 = (*(code *)&SUB_4008b33c)(iVar6 + 1,iVar6 + 9,3);
      puVar22 = puStack_f8;
      pppppppcVar17 = in_a13;
      if (iVar6 == 0) goto LAB_4012f7ac;
      pppppppcVar15 = (code *******)0xffff8f80;
LAB_4012f606:
      memw();
      ppppppcStack_e8 = (code ******)pppppppcVar15;
      pppppppcVar17 = (code *******)local_ac;
      goto LAB_4012f6cc;
    }
    ppppppcStack_e8 = (code ******)0xffff8f80;
  }
  else {
LAB_4012f7ac:
    in_a13 = (code *******)(pcVar25 + (int)param_4);
    pbVar16 = (byte *)((int)pppppppcVar15 - (int)param_4);
    ppppppcStack_e0 = (code ******)in_a13;
    if (pbVar16 < (byte *)0x26) goto LAB_4012f6c6;
    memw();
    FUN_40185918(param_1 + 4,param_1 + 5,puVar22,in_a13);
    iVar6 = param_1[4];
    puVar13 = (undefined1 *)param_1[0x11];
    *puVar13 = (char)iVar6;
    memw();
    param_4 = (code *******)param_1[5];
    puVar13[1] = (char)param_4;
    memw();
    pbVar7 = (byte *)*param_1;
    if (((int)(uint)pbVar7[2] <= iVar6) && ((int)(uint)pbVar7[3] <= (int)param_4)) {
      bVar4 = pbVar7[1];
      if ((int)(uint)*pbVar7 < iVar6) {
        param_1[4] = (uint)*pbVar7;
LAB_4012f8ec:
        param_1[5] = (uint)bVar4;
        memw();
      }
      else if ((int)(uint)bVar4 < (int)param_4) goto LAB_4012f8ec;
      (*(code *)&SUB_4008b3d0)(puVar13 + 0x470,(ushort *)((int)ppppppcStack_e0 + 2),0x20);
      uVar8 = (uint)*(byte *)((int)ppppppcStack_e0 + 0x22);
      param_4 = (code *******)0x20;
      if ((0x20 < uVar8) || (pbVar16 < (byte *)(uVar8 + 0x24))) goto LAB_4012f91a;
      iVar6 = param_1[0x10];
      *(uint *)(iVar6 + 0x10) = uVar8;
      memw();
      (*(code *)&SUB_4008b530)(iVar6 + 0x14,0,0x20);
      pppppppcVar15 = (code *******)(uVar8 + 0x23);
      (*(code *)&SUB_4008b3d0)
                (param_1[0x10] + 0x14,(byte *)((int)ppppppcStack_e0 + 0x23),
                 *(undefined4 *)(param_1[0x10] + 0x10));
      iVar6 = *param_1;
      ppppppcStack_dc = (code ******)pppppppcVar15;
      if (*(char *)(iVar6 + 5) == '\x01') {
        uVar29 = (uint)*(byte *)((int)ppppppcStack_e0 + (int)pppppppcVar15);
        param_4 = (code *******)0x1;
        if (pbVar16 < (byte *)((int)pppppppcVar15 + uVar29 + 3)) {
          uVar28 = 0x46;
          memw();
          goto LAB_4012f91c;
        }
        if ((*(code **)(iVar6 + 0x7c) == (code *)0x0) || (param_1[2] != 0)) {
          pppppppcVar17 = in_a13;
          if (uVar29 != 0) goto LAB_4012f6c6;
        }
        else {
          in_a13 = (code *******)param_1[0x7e];
          iVar6 = (**(code **)(iVar6 + 0x7c))
                            (*(undefined4 *)(iVar6 + 0x80),
                             (byte *)((int)ppppppcStack_e0 + (int)(uVar8 + 0x24)),uVar29,in_a13,
                             param_1[0x7f]);
          if (iVar6 == 0) {
            *(undefined1 *)(param_1[0x11] + 0x244) = 0;
            memw();
            memw();
          }
          else {
            *(undefined1 *)(param_1[0x11] + 0x244) = 1;
            memw();
          }
        }
        ppppppcStack_dc = (code ******)((int)pppppppcVar15 + uVar29 + 1);
      }
      bVar4 = ((byte *)((int)ppppppcStack_e0 + (int)ppppppcStack_dc))[1];
      ppppppcStack_d0 =
           (code ******)(uint)CONCAT11(*(byte *)((int)ppppppcStack_e0 + (int)ppppppcStack_dc),bVar4)
      ;
      param_4 = (code *******)ppppppcStack_dc;
      if (((ppppppcStack_d0 < (code *******)0x2) ||
          (param_4 = (code *******)((int)ppppppcStack_dc + (int)ppppppcStack_d0),
          pbVar16 < (byte *)((int)param_4 + 3))) ||
         (ppppppcStack_d4 = (code ******)((uint)ppppppcStack_d0 & 1), (bVar4 & 1) != 0))
      goto LAB_4012f91a;
      param_4 = (code *******)((int)param_4 + 2);
      if (0xf < *(byte *)((int)ppppppcStack_e0 + (int)param_4) - 1) goto LAB_4012f91a;
      param_4 = (code *******)((int)param_4 + (uint)*(byte *)((int)ppppppcStack_e0 + (int)param_4));
      pbVar7 = (byte *)((int)param_4 + 1);
      if (pbVar16 < pbVar7) goto LAB_4012f91a;
      *(code *******)(param_1[0x10] + 0xc) = ppppppcStack_d4;
      pbVar9 = (byte *)((int)param_4 + 3);
      if (pbVar7 < pbVar16) {
        if ((pbVar16 < pbVar9) ||
           (param_4 = (code *******)
                      (uint)CONCAT11(*(byte *)((int)ppppppcStack_e0 + (int)pbVar7),
                                     ((byte *)((int)ppppppcStack_e0 + (int)param_4))[2]),
           ppppppcStack_d8 = (code ******)param_4, pbVar16 != (byte *)((int)param_4 + (int)pbVar9)))
        goto LAB_4012f91a;
      }
      else {
        memw();
        ppppppcStack_d8 = ppppppcStack_d4;
      }
      puVar22 = (ushort *)((int)ppppppcStack_e0 + (int)pbVar9);
      ppppppcStack_c4 = ppppppcStack_e8;
      ppppppcStack_c8 = ppppppcStack_e8;
      param_4 = (code *******)ppppppcStack_e8;
      goto LAB_4012fa34;
    }
    memw();
    FUN_4012a73c(param_1,2,0x46);
    ppppppcStack_e8 = (code ******)0xffff9180;
  }
  memw();
  pppppppcVar17 = (code *******)local_ac;
  goto LAB_4012f6cc;
LAB_4012f695:
  memw();
  ppppppcStack_e8 = (code ******)pppppppcVar17;
  pppppppcVar17 = (code *******)local_ac;
  goto LAB_4012f6cc;
LAB_4012fa34:
  if ((code *******)ppppppcStack_d8 == (code *******)0x0) goto code_r0x4012fa39;
  if (ppppppcStack_d8 < &DAT_00000004) goto LAB_4012f91a;
  uVar14 = *puVar22 << 8 | *puVar22 >> 8;
  uVar8 = (uint)puVar22[1] << 8;
  uVar29 = (uint)(puVar22[1] >> 8);
  param_4 = (code *******)(uVar8 | uVar29);
  pppppppcVar17 = (code *******)(uVar8 & 0xffff | uVar29);
  ppppppcStack_cc = (code ******)(pppppppcVar17 + 1);
  if (ppppppcStack_d8 < ppppppcStack_cc) goto LAB_4012f91a;
  if (uVar14 == 0xd) {
    ppppppcStack_c4 = (code ******)((int)puVar22 + (int)ppppppcStack_cc);
    if (pppppppcVar17 < (code *******)0x2) goto LAB_4012f91a;
    uVar14 = puVar22[2] >> 8;
    param_4 = (code *******)(((puVar22[2] & 0xff) << 8 | (uint)uVar14) + 2);
    if ((pppppppcVar17 != param_4) || ((uVar14 & 1) != 0)) goto LAB_4012f91a;
    for (pppppppcVar15 = (code *******)(puVar22 + 3); pppppppcVar15 < ppppppcStack_c4;
        pppppppcVar15 = (code *******)((int)pppppppcVar15 + 2)) {
      iVar6 = FUN_40185a10(*(byte *)((int)pppppppcVar15 + 1));
      if (((iVar6 != 0) && (iVar26 = FUN_40185a74(*(byte *)pppppppcVar15), iVar26 != 0)) &&
         (iVar10 = FUN_40185b00(param_1,iVar26), iVar10 == 0)) {
        FUN_40185a40(param_1[0x11] + 8,iVar6,iVar26);
      }
    }
    ppppppcStack_c4 = ppppppcStack_e4;
    memw();
  }
  else if (uVar14 < 0xe) {
    if (uVar14 == 4) {
      if (pppppppcVar17 != (code *******)0x0) goto LAB_4012f91a;
      if (*(char *)(*param_1 + 0xe) == '\x01') {
        *(undefined4 *)(param_1[0x10] + 0x78) = 1;
        memw();
      }
    }
    else if (uVar14 < 5) {
      if (uVar14 == 0) {
        param_4 = *(code ********)(*param_1 + 0x60);
        if (param_4 != (code *******)0x0) {
          if ((pppppppcVar17 < (code *******)0x2) ||
             (pbVar16 = (byte *)((puVar22[2] & 0xff) << 8 | (uint)(puVar22[2] >> 8)),
             pppppppcVar17 != (code *******)(pbVar16 + 2))) goto LAB_4012f91a;
          puVar30 = puVar22 + 3;
          for (; (byte *)0x2 < pbVar16; pbVar16 = pbVar16 + (int)in_a13) {
            in_a13 = (code *******)
                     ((*(ushort *)((int)puVar30 + 1) & 0xff) << 8 |
                     (uint)(*(ushort *)((int)puVar30 + 1) >> 8));
            pbVar7 = (byte *)((int)in_a13 + 3);
            if (pbVar16 < pbVar7) goto LAB_4012f91a;
            if ((byte)*puVar30 == 0) {
              iVar6 = (*(code *)param_4)(*(undefined4 *)(*param_1 + 100),param_1,
                                         (byte *)((int)puVar30 + 3));
              if (iVar6 == 0) goto LAB_4012fb0c;
              FUN_4012a73c(param_1,2,0x70);
              pppppppcVar15 = (code *******)0xffff8700;
              goto LAB_4012f606;
            }
            in_a13 = (code *******)(-3 - (int)in_a13);
            puVar30 = (ushort *)((int)puVar30 + (int)pbVar7);
          }
          if (pbVar16 != (byte *)0x0) {
LAB_4012fc38:
            FUN_4012a73c(param_1,2,0x2f);
            pppppppcVar17 = in_a13;
LAB_4012f6c6:
            in_a13 = pppppppcVar17;
            ppppppcStack_e8 = (code ******)0xffff8700;
            pppppppcVar17 = (code *******)local_ac;
            goto LAB_4012f6cc;
          }
        }
      }
      else if (uVar14 == 1) {
        if ((pppppppcVar17 != (code *******)0x1) || (4 < (byte)puVar22[2])) goto LAB_4012fc38;
        *(byte *)param_1[0x10] = (byte)puVar22[2];
        memw();
        memw();
      }
    }
    else if (uVar14 == 10) {
      if (pppppppcVar17 < (code *******)0x2) goto LAB_4012f91a;
      uVar14 = puVar22[2] >> 8;
      uVar8 = (puVar22[2] & 0xff) << 8 | (uint)uVar14;
      param_4 = (code *******)(uVar8 + 2);
      if (((pppppppcVar17 != param_4) || ((uVar14 & 1) != 0)) ||
         (param_4 = *(code ********)(param_1[0x11] + 0x1d8),
         *(code ********)(param_1[0x11] + 0x1d8) != (code *******)0x0)) goto LAB_4012f91a;
      uVar29 = (uVar8 >> 1) + 1;
      uVar29 = (uVar29 < 0xc) * uVar29 + (uint)(uVar29 >= 0xc) * 0xc;
      piVar18 = (int *)FUN_4013ae30(uVar29,4);
      if (piVar18 == (int *)0x0) {
        FUN_4012a73c(param_1,2,0x50);
        ppppppcStack_e8 = (code ******)0xffff8100;
        param_4 = (code *******)0x0;
        pppppppcVar17 = (code *******)local_ac;
        goto LAB_4012f6cc;
      }
      *(int **)(param_1[0x11] + 0x1d8) = piVar18;
      puVar30 = puVar22 + 3;
      while ((uVar8 != 0 && (1 < uVar29))) {
        memw();
        puStack_f8 = puVar30;
        iVar6 = FUN_40135610(CONCAT11((byte)*puVar30,*(byte *)((int)puVar30 + 1)));
        if (iVar6 != 0) {
          uVar29 = uVar29 - 1;
          *piVar18 = iVar6;
          piVar18 = piVar18 + 1;
        }
        uVar8 = uVar8 - 2;
        puVar30 = puStack_f8 + 1;
        memw();
      }
    }
    else if (uVar14 == 0xb) {
      param_4 = (code *******)param_1[0x11];
      *(byte *)((int)param_4 + 3) = *(byte *)((int)param_4 + 3) | 1;
      memw();
      if ((pppppppcVar17 == (code *******)0x0) ||
         (uVar8 = (uint)(byte)puVar22[2], pppppppcVar17 != (code *******)(uVar8 + 1)))
      goto LAB_4012f91a;
      pbVar16 = (byte *)((int)puVar22 + 5);
      for (; uVar8 != 0; uVar8 = uVar8 - 1) {
        if ((code ******)(uint)*pbVar16 < (code ******)0x2) {
          param_4[0x60] = (code ******)(uint)*pbVar16;
          memw();
          break;
        }
        pbVar16 = pbVar16 + 1;
      }
    }
  }
  else if (uVar14 == 0x16) {
    param_4 = (code *******)0x16;
    if (pppppppcVar17 != (code *******)0x0) goto LAB_4012f91a;
    if ((*(char *)(*param_1 + 9) == '\x01') && (param_1[5] != 0)) {
      *(undefined4 *)(param_1[0x10] + 0x7c) = 1;
      memw();
    }
  }
  else if (uVar14 < 0x17) {
    param_4 = (code *******)&DAT_0000000e;
    if (uVar14 == 0xe) {
      iVar6 = *param_1;
      if (((*(char *)(iVar6 + 5) == '\x01') && (iVar26 = *(int *)(iVar6 + 0xe0), iVar26 != 0)) &&
         (*(int *)(iVar6 + 0xe4) != 0)) {
        if (pppppppcVar17 < (code *******)0x3) goto LAB_4012fcc8;
        *(undefined2 *)(param_1 + 0x3d) = 0;
        memw();
        uVar14 = puVar22[2] >> 8;
        pbVar16 = (byte *)((puVar22[2] & 0xff) << 8 | (uint)uVar14);
        if (((byte *)((int)pppppppcVar17 + -3) < pbVar16) || ((uVar14 & 1) != 0)) goto LAB_4012fcc8;
        for (puVar30 = puVar22 + 3; (byte *)((int)puVar30 + (-6 - (int)puVar22)) < pbVar16;
            puVar30 = puVar30 + 1) {
          sVar2 = CONCAT11((byte)*puVar30,*(byte *)((int)puVar30 + 1));
          iVar10 = (int)sVar2;
          if ((0 < iVar10) && ((iVar10 < 3 || ((iVar10 - 5U & 0xffff) < 2)))) {
            if (sVar2 == *(short *)(iVar26 + (int)ppppppcStack_d4 * 2)) {
              *(short *)(param_1 + 0x3d) = sVar2;
              memw();
              in_a13 = (code *******)ppppppcStack_d4;
              break;
            }
            in_a13 = (code *******)((int)ppppppcStack_d4 + 1);
          }
        }
        pbVar7 = (byte *)((int)(puVar22 + 3) + (int)pbVar16);
        bVar4 = *pbVar7;
        if (pppppppcVar17 != (code *******)(pbVar16 + bVar4 + 3)) goto LAB_4012fcc8;
        if ((*(char *)(iVar6 + 0x12) == '\x01') && (bVar4 != 0)) {
          *(ushort *)((int)param_1 + 0xf6) = (ushort)bVar4;
          memw();
          memw();
          (*(code *)&SUB_4008b3d0)(param_1 + 0x3e,pbVar7 + 1);
        }
      }
    }
    else if ((uVar14 == 0x10) &&
            (in_a13 = *(code ********)(*param_1 + 0xdc), in_a13 != (code *******)0x0)) {
      if ((pppppppcVar17 < &DAT_00000004) ||
         (param_4 = (code *******)((int)pppppppcVar17 + -2),
         (code *******)((puVar22[2] & 0xff) << 8 | (uint)(puVar22[2] >> 8)) != param_4)) {
LAB_4012f91a:
        uVar28 = 0x32;
      }
      else {
        param_4 = (code *******)(puVar22 + 3);
        for (pppppppcVar15 = param_4;
            (code *******)((int)puVar22 + (int)ppppppcStack_cc) != pppppppcVar15;
            pppppppcVar15 = (code *******)((byte *)((int)pppppppcVar15 + 1) + uVar8)) {
          uVar8 = (uint)*(byte *)pppppppcVar15;
          if ((uint)(((int)puVar22 + (int)ppppppcStack_cc) - ((int)pppppppcVar15 + 1)) < uVar8)
          goto LAB_4012f91a;
          if (uVar8 == 0) goto LAB_4012fc38;
        }
        while (ppppppcVar21 = *in_a13, ppppppcVar21 != (code ******)0x0) {
          memw();
          ppppppcStack_f4 = (code ******)in_a13;
          puVar30 = (ushort *)(*(code *)&SUB_4008c01c)(ppppppcVar21);
          pppppppcVar24 = param_4;
          pppppppcVar31 = (code *******)ppppppcStack_f4;
          while (pppppppcVar15 != pppppppcVar24) {
            pbVar16 = (byte *)((int)pppppppcVar24 + 1);
            puVar23 = (ushort *)(uint)*(byte *)pppppppcVar24;
            if (puVar30 == puVar23) {
              memw();
              puStack_f8 = puVar23;
              ppppppcStack_f4 = (code ******)pppppppcVar31;
              pbStack_f0 = pbVar16;
              puStack_ec = puVar30;
              iVar6 = (*(code *)&SUB_4008b33c)(pbVar16,ppppppcVar21,puVar30);
              puVar23 = puStack_f8;
              pppppppcVar31 = (code *******)ppppppcStack_f4;
              puVar30 = puStack_ec;
              pbVar16 = pbStack_f0;
              if (iVar6 == 0) {
                param_1[0x3c] = (int)ppppppcVar21;
                memw();
                in_a13 = (code *******)ppppppcStack_f4;
                goto LAB_4012fb0c;
              }
            }
            pppppppcVar24 = (code *******)(pbVar16 + (int)puVar23);
          }
          in_a13 = pppppppcVar31 + 1;
        }
        uVar28 = 0x78;
      }
LAB_4012f91c:
      FUN_4012a73c(param_1,2,uVar28);
      pppppppcVar17 = (code *******)0xffff8700;
      goto LAB_4012f927;
    }
  }
  else if (uVar14 == 0x23) {
    FUN_4012c768(auStack_a4);
    iVar6 = *param_1;
    pcVar20 = *(code **)(iVar6 + 0x88);
    if ((pcVar20 != (code *)0x0) && (*(int *)(iVar6 + 0x84) != 0)) {
      *(undefined1 *)(param_1[0x11] + 5) = 1;
      memw();
      if ((pppppppcVar17 != (code *******)0x0) && (param_1[2] == 0)) {
        memw();
        in_a13 = pppppppcVar17;
        iVar6 = (*pcVar20)(*(undefined4 *)(iVar6 + 0x8c),auStack_a4,puVar22 + 2);
        if (iVar6 == 0) {
          iVar6 = param_1[0x10];
          uStack_94 = *(undefined4 *)(iVar6 + 0x10);
          memw();
          (*(code *)&SUB_4008b3d0)(auStack_90,iVar6 + 0x14);
          FUN_4012cacc(iVar6);
          (*(code *)&SUB_4008b3d0)(param_1[0x10],auStack_a4,0x80);
          FUN_4013ae54(auStack_a4,0x80);
          iVar6 = param_1[0x11];
          *(undefined1 *)(iVar6 + 2) = 1;
          *(undefined1 *)(iVar6 + 5) = 0;
          memw();
          memw();
        }
        else {
          FUN_4012cacc(auStack_a4);
        }
      }
    }
  }
  else if (uVar14 == 0xff01) {
    if (param_1[2] == 0) {
      if ((pppppppcVar17 != (code *******)0x1) || ((byte)puVar22[2] != 0)) goto LAB_4012fcc8;
      param_1[0x80] = 1;
      ppppppcStack_c8 = ppppppcStack_e4;
      memw();
    }
    else {
      if (((pppppppcVar17 != (code *******)(param_1[0x81] + 1U)) ||
          (param_1[0x81] != (uint)(byte)puVar22[2])) ||
         (iVar6 = FUN_401862dc((byte *)((int)puVar22 + 5),param_1 + 0x85), iVar6 != 0))
      goto LAB_4012fcc8;
      ppppppcStack_c8 = ppppppcStack_e4;
      memw();
    }
  }
  else if (uVar14 == 0x17) {
    param_4 = (code *******)0x17;
    if (pppppppcVar17 != (code *******)0x0) goto LAB_4012f91a;
    if ((*(char *)(*param_1 + 10) == '\x01') && (param_1[5] != 0)) {
      *(undefined1 *)(param_1[0x11] + 6) = 1;
      memw();
      memw();
    }
  }
LAB_4012fb0c:
  ppppppcStack_d8 = (code ******)((int)ppppppcStack_d8 + (-4 - (int)pppppppcVar17));
  puVar22 = (ushort *)((int)puVar22 + (int)ppppppcStack_cc);
  memw();
  param_4 = (code *******)ppppppcStack_cc;
  goto LAB_4012fa34;
code_r0x4012fa39:
  pppppppcVar15 = (code *******)((int)ppppppcStack_e0 + (int)((int)ppppppcStack_dc + 2));
  pppppppcVar17 = (code *******)0x0;
  while (param_4 = (code *******)0x5600, ppppppcStack_d4 = (code ******)pppppppcVar15,
        (ushort)(*(ushort *)((int)pppppppcVar15 + (int)pppppppcVar17) << 8 |
                *(ushort *)((int)pppppppcVar15 + (int)pppppppcVar17) >> 8) != 0x5600) {
    pppppppcVar17 = (code *******)((int)pppppppcVar17 + 2);
    param_4 = (code *******)ppppppcStack_d0;
    if (ppppppcStack_d0 <= pppppppcVar17) goto LAB_40130049;
  }
  if ((int)(uint)*(byte *)(*param_1 + 1) <= param_1[5]) goto LAB_40130049;
  memw();
  FUN_4012a73c(param_1,2,0x56);
  ppppppcStack_e8 = (code ******)0xffff8700;
LAB_4012fa88:
  memw();
  pppppppcVar17 = (code *******)local_ac;
  goto LAB_4012f6cc;
LAB_40130049:
  if ((code *******)ppppppcStack_c4 == (code *******)0x0) {
    iVar6 = FUN_40185b00(param_1,4);
    pppppppcVar17 = (code *******)&DAT_00000004;
    if (iVar6 != 0) {
      pppppppcVar17 = (code *******)ppppppcStack_d8;
    }
    FUN_40185a68(param_1[0x11] + 8,pppppppcVar17);
  }
  do {
    if ((*(byte *)pppppppcVar15 == 0) && (*(byte *)((int)pppppppcVar15 + 1) == 0xff)) {
      if (param_1[2] == 1) goto LAB_4012fcc8;
      param_1[0x80] = 1;
      break;
    }
    pppppppcVar15 = (code *******)((int)pppppppcVar15 + 2);
    param_4 = (code *******)ppppppcStack_d4;
  } while ((code *******)((int)pppppppcVar15 - (int)ppppppcStack_d4) < ppppppcStack_d0);
  iVar6 = param_1[0x80];
  if (((iVar6 != 1) && (*(char *)(*param_1 + 7) == '\x02')) ||
     ((param_1[2] == 1 &&
      (((((uint)ppppppcStack_c8 & 1) == 0 && (param_4 = (code *******)0x0, iVar6 == 1)) ||
       ((iVar6 == 0 && ((*(char *)(*param_1 + 7) == '\0' || (((uint)ppppppcStack_c8 & 1) != 0)))))))
      ))) {
LAB_4012fcc8:
    FUN_4012a73c(param_1,2,0x28);
    param_4 = (code *******)0xffff8700;
LAB_4012fcd4:
    memw();
    ppppppcStack_e8 = (code ******)param_4;
    pppppppcVar17 = (code *******)local_ac;
    goto LAB_4012f6cc;
  }
  piVar18 = *(int **)(*param_1 + (param_1[5] + 0xc) * 4 + 4);
  pppppppcVar17 = (code *******)ppppppcStack_e8;
  while (*piVar18 != 0) {
    ppppppcStack_e0 = ppppppcStack_d8;
    do {
      param_4 = (code *******)*piVar18;
      if ((code *******)
          ((*(ushort *)((int)ppppppcStack_d4 + (int)ppppppcStack_e0) & 0xff) << 8 |
          (uint)(*(ushort *)((int)ppppppcStack_d4 + (int)ppppppcStack_e0) >> 8)) == param_4) {
        memw();
        iVar6 = FUN_4012d7a8();
        if (iVar6 == 0) {
          ppppppcStack_e8 = (code ******)0xffff9400;
          pppppppcVar17 = (code *******)local_ac;
          goto LAB_4012f6cc;
        }
        pppppppcVar17 = (code *******)ppppppcStack_e4;
        if (((*(int *)(iVar6 + 0x18) <= param_1[5]) && (param_1[5] <= *(int *)(iVar6 + 0x20))) &&
           ((((*(char *)(*param_1 + 5) != '\x01' || ((*(byte *)(iVar6 + 0x24) & 4) == 0)) &&
             ((iVar26 = FUN_40185b6c(iVar6), iVar26 == 0 ||
              ((pppppppcVar17 = (code *******)ppppppcStack_e4,
               *(int **)(param_1[0x11] + 0x1d8) != (int *)0x0 &&
               (**(int **)(param_1[0x11] + 0x1d8) != 0)))))) &&
            (((iVar26 = FUN_40185b88(iVar6), iVar26 == 0 ||
              (iVar26 = FUN_40185bd4(*param_1), pppppppcVar17 = (code *******)ppppppcStack_e4,
              iVar26 != 0)) &&
             (((param_1[5] != 3 || (iVar26 = FUN_40185b54(iVar6), iVar26 == 0)) ||
              (iVar26 = FUN_40185a28(param_1[0x11] + 8,iVar26),
              pppppppcVar17 = (code *******)ppppppcStack_e4, iVar26 != 0)))))))) {
          ppppppcStack_dc = (code ******)FUN_40185b28(iVar6);
          param_4 = *(code ********)(param_1[0x11] + 0x1e8);
          if (param_4 == (code *******)0x0) {
            if ((code *******)ppppppcStack_dc != (code *******)0x0) {
              pppppppcVar17 = (code *******)ppppppcStack_e4;
              pppppppcVar15 = *(code ********)(*param_1 + 0xa0);
              if (*(code ********)(*param_1 + 0xa0) != (code *******)0x0) goto LAB_401301ba;
              goto LAB_40130140;
            }
          }
          else {
            pppppppcVar15 = param_4;
            if ((code *******)ppppppcStack_dc != (code *******)0x0) {
LAB_401301ba:
              pppppppcVar17 = (code *******)0x0;
              do {
                pppppcStack_b0 = (code *****)0x0;
                memw();
                iVar26 = FUN_401864ec(*pppppppcVar15 + 0x33,ppppppcStack_dc);
                param_4 = pppppppcVar17;
                if (iVar26 != 0) {
                  in_a13 = (code *******)&pppppcStack_b0;
                  puVar22 = (ushort *)FUN_4012d194(*pppppppcVar15,iVar6,1);
                  if (puVar22 == (ushort *)0x0) {
                    if (ppppppcStack_dc == (code ******)&DAT_00000004) {
                      pbStack_f0 = *(byte **)(param_1[0x11] + 0x1d8);
                      local_ac = (code ******)(*pppppppcVar15)[0x33];
                      ppppcStack_a8 = (code ****)(*pppppppcVar15)[0x34];
                      memw();
                      puStack_ec = puVar22;
                      iVar26 = FUN_40186520(&local_ac);
                      if (2 < iVar26 - 2U) {
                        memw();
                        breakpoint(0x1000,0x40131181,1,0xf);
                        return *(code ********)puStack_ec;
                      }
                      for (pbVar16 = pbStack_f0; *(undefined4 **)pbVar16 != (undefined4 *)0x0;
                          pbVar16 = pbVar16 + 4) {
                        if ((code ****)*ppppcStack_a8 == (code ****)**(undefined4 **)pbVar16)
                        goto LAB_4013028c;
                      }
                    }
                    else {
LAB_4013028c:
                      param_4 = pppppppcVar15;
                      if ((2 < param_1[5]) || ((*pppppppcVar15)[0x52] == (code *****)0x4))
                      goto LAB_40130238;
                      param_4 = pppppppcVar17;
                      if (pppppppcVar17 == (code *******)0x0) {
                        param_4 = pppppppcVar15;
                      }
                    }
                  }
                }
                pppppppcVar15 = (code *******)pppppppcVar15[2];
                pppppppcVar17 = param_4;
              } while (pppppppcVar15 != (code *******)0x0);
              pppppppcVar17 = (code *******)ppppppcStack_e4;
              if (param_4 == (code *******)0x0) goto LAB_40130140;
LAB_40130238:
              *(code ********)(param_1[0x11] + 0x1e4) = param_4;
            }
          }
          *(int *)(param_1[0x10] + 8) = *piVar18;
          *(int *)(param_1[0x11] + 0x14) = iVar6;
          param_1[1] = param_1[1] + 1;
          pppppppcVar17 = (code *******)local_ac;
          if (*(char *)(*param_1 + 5) == '\x01') {
            memw();
            FUN_40129dc0(param_1);
            pppppppcVar17 = (code *******)local_ac;
          }
          goto LAB_4012f6cc;
        }
      }
LAB_40130140:
      param_4 = (code *******)((int)ppppppcStack_e0 + 2);
      ppppppcStack_e0 = (code ******)param_4;
    } while (param_4 < ppppppcStack_d0);
    piVar18 = piVar18 + 1;
    memw();
  }
  if (pppppppcVar17 != (code *******)0x0) {
    memw();
    FUN_4012a73c(param_1,2,0x28);
    ppppppcStack_e8 = (code ******)0xffff9680;
    pppppppcVar17 = (code *******)local_ac;
    goto LAB_4012f6cc;
  }
  FUN_4012a73c(param_1,2,0x28);
  pppppppcVar17 = (code *******)0xffff8c80;
LAB_4012f927:
  memw();
  ppppppcStack_e8 = (code ******)pppppppcVar17;
  pppppppcVar17 = (code *******)local_ac;
  goto LAB_4012f6cc;
}

