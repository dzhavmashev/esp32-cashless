// Function : FUN_40119200
// Address  : 0x40119200
// Size     : 3735 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40119200(int param_1,uint param_2)

{
  bool bVar1;
  ushort uVar2;
  undefined4 uVar3;
  byte bVar4;
  byte bVar5;
  char cVar6;
  byte *pbVar7;
  uint *puVar8;
  undefined4 uVar9;
  uint uVar10;
  char *pcVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  undefined1 uVar15;
  char cVar16;
  char cVar17;
  uint uVar18;
  int iVar19;
  uint *puVar20;
  int iVar21;
  undefined1 *puVar22;
  uint *puVar23;
  undefined4 *puVar24;
  short sVar25;
  uint uVar26;
  uint uVar27;
  int iVar28;
  char *pcVar29;
  uint uVar30;
  uint in_t0;
  byte *pbStack_58;
  uint uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  char cStack_38;
  uint uStack_34;
  uint uStack_30;
  uint uStack_2c;
  uint uStack_28;
  byte bStack_24;
  
  pbVar7 = *(byte **)(param_1 + 4);
  bVar5 = *pbVar7;
  if (bVar5 == 0x87) {
    uVar2 = *(ushort *)(param_1 + 10);
    if (0x17 < uVar2) {
      bStack_24 = 0;
      uStack_34 = *(uint *)(pbVar7 + 8);
      uStack_30 = *(uint *)(pbVar7 + 0xc);
      uStack_2c = *(uint *)(pbVar7 + 0x10);
      uStack_28 = *(uint *)(pbVar7 + 0x14);
      if ((uStack_34 & 0xc0ff) == 0x80fe) {
        bStack_24 = *(char *)(param_2 + 0xee) + 1;
      }
      memw();
      if (((*(char *)(_DAT_3ffc83c4 + 7) == -1) && (pbVar7[1] == 0)) && ((uStack_34 & 0xff) != 0xff)
         ) {
        pbStack_58 = (byte *)0x0;
        if ((0x19 < uVar2) && ((ushort)((ushort)pbVar7[0x19] * 8 + 0x18) <= uVar2)) {
          pbStack_58 = pbVar7 + 0x18;
        }
        puVar8 = (uint *)(param_2 + 0x4c);
        puVar20 = puVar8;
        puVar23 = (uint *)(param_2 + 0x94);
        do {
          if (((((*puVar23 & 0x10) != 0) ||
               (((*puVar23 & 8) != 0 &&
                (((_DAT_3ffc83cc == 0 && _DAT_3ffc83d0 == 0) && _DAT_3ffc83d4 == 0) &&
                 _DAT_3ffc83d8 == 0)))) && (uStack_34 == *puVar20)) &&
             ((((uStack_30 == puVar20[1] && (uStack_2c == puVar20[2])) && (uStack_28 == puVar20[3]))
              && ((byte)puVar20[4] == bStack_24)))) {
            if (((_DAT_3ffc83cc == 0 && _DAT_3ffc83d0 == 0) && _DAT_3ffc83d4 == 0) &&
                _DAT_3ffc83d8 == 0) {
              uVar18 = param_2;
              do {
                if (((((*(char *)(uVar18 + 0x94) != '\0') && (uStack_34 == *puVar8)) &&
                     ((uStack_30 == puVar8[1] &&
                      ((uStack_2c == puVar8[2] && (uStack_28 == puVar8[3])))))) &&
                    (bStack_24 == (byte)puVar8[4])) &&
                   (FUN_40118a08(param_2,puVar8,0x22), (*(byte *)(uVar18 + 0x94) & 8) != 0)) {
                  FUN_40118ff0(param_2,uVar18 - param_2);
                }
                uVar18 = uVar18 + 1;
                puVar8 = puVar8 + 6;
              } while (param_2 + 3 != uVar18);
              goto LAB_40119225;
            }
            if (pbStack_58 == (byte *)0x0) goto LAB_40119225;
            cVar6 = FUN_40118980(&DAT_3ffc83cc);
            if (cVar6 < 0) {
              cVar6 = FUN_401190e4();
              if (cVar6 < 0) goto LAB_40119225;
              iVar19 = cVar6 * 0x2c;
              uVar15 = *(undefined1 *)(param_2 + 0xea);
              *(uint *)(&DAT_3ffc8530 + iVar19) = param_2;
              memw();
              (*(code *)&SUB_4008b3d0)((short)cVar6 * 0x2c + 0x3ffc8534,pbStack_58 + 2,uVar15);
              *(uint *)(&DAT_3ffc851c + iVar19) = _DAT_3ffc83cc;
              *(uint *)(&DAT_3ffc8520 + iVar19) = _DAT_3ffc83d0;
              *(uint *)(&DAT_3ffc8524 + iVar19) = _DAT_3ffc83d4;
              *(uint *)(&DAT_3ffc8528 + iVar19) = _DAT_3ffc83d8;
              (&DAT_3ffc852c)[iVar19] = DAT_3ffc83dc;
              (&DAT_3ffc8540)[iVar19] = 4;
              memw();
              *(undefined4 *)(&DAT_3ffc8544 + iVar19) = 5;
              memw();
            }
            else {
              iVar19 = cVar6 * 0x2c;
              if ((&DAT_3ffc8540)[iVar19] == '\x01') {
                uVar15 = *(undefined1 *)(param_2 + 0xea);
                *(uint *)(&DAT_3ffc8530 + iVar19) = param_2;
                memw();
                (*(code *)&SUB_4008b3d0)((short)cVar6 * 0x2c + 0x3ffc8534,pbStack_58 + 2,uVar15);
                (&DAT_3ffc8540)[iVar19] = 4;
                memw();
                *(undefined4 *)(&DAT_3ffc8544 + iVar19) = 5;
              }
            }
            memw();
            FUN_40118a08(param_2,&uStack_34,0x60);
            goto LAB_40119225;
          }
          puVar20 = puVar20 + 6;
          puVar23 = (uint *)((int)puVar23 + 1);
        } while (puVar20 != (uint *)(param_2 + 0x94));
        memw();
      }
    }
  }
  else if (bVar5 < 0x88) {
    if (bVar5 == 2) {
      if (0x2f < *(ushort *)(param_1 + 10)) {
        uStack_34 = *(uint *)(pbVar7 + 0x20);
        uStack_30 = *(uint *)(pbVar7 + 0x24);
        uStack_2c = *(uint *)(pbVar7 + 0x28);
        uStack_28 = *(uint *)(pbVar7 + 0x2c);
        if (((uStack_34 & 0xc0ff) == 0x80fe) ||
           (bStack_24 = 0, ((uStack_34 & 0x8fff) - 0x1ff & 0xfffffeff) == 0)) {
          bStack_24 = *(char *)(param_2 + 0xee) + 1;
        }
        memw();
        memw();
        iVar19 = FUN_401189c4(&uStack_34);
        if (-1 < iVar19) {
          uVar18 = FUN_40109eec(*(undefined4 *)(pbVar7 + 4));
          if (0xfffe < uVar18) {
            uVar18 = 0xffff;
          }
          *(short *)(iVar19 * 0x30 + 0x3ffc8620) = (short)uVar18;
          memw();
          memw();
        }
      }
    }
    else if ((((bVar5 == 0x86) && (0xf < *(ushort *)(param_1 + 10))) &&
             ((_DAT_3ffc83cc & 0xc0ff) == 0x80fe)) &&
            ((*(char *)(_DAT_3ffc83c4 + 7) == -1 && (pbVar7[1] == 0)))) {
      uVar15 = 0;
      if ((2 < *(byte *)(param_2 + 0xf0)) && (cVar6 = FUN_40118b78(param_2), cVar6 != '\0')) {
        uVar15 = 1;
      }
      cVar6 = DAT_3ffc83dc;
      uVar12 = _DAT_3ffc83d8;
      uVar26 = _DAT_3ffc83d4;
      uVar10 = _DAT_3ffc83d0;
      uVar18 = _DAT_3ffc83cc;
      puVar24 = (undefined4 *)&DAT_3ffc846c;
      *(undefined1 *)(param_2 + 0xf0) = uVar15;
      memw();
      cVar16 = '\0';
      do {
        puVar20 = (uint *)*puVar24;
        if ((((puVar20 != (uint *)0x0) && (param_2 == puVar20[5])) &&
            ((uVar18 == *puVar20 &&
             (((uVar10 == puVar20[1] && (uVar26 == puVar20[2])) && (uVar12 == puVar20[3])))))) &&
           ((char)puVar20[4] == cVar6)) goto LAB_40119a50;
        cVar16 = cVar16 + '\x01';
        puVar24 = puVar24 + 3;
      } while (cVar16 != '\x03');
      memw();
      bVar5 = FUN_40118980(&DAT_3ffc83cc);
      if ((bVar5 & 0x80) != 0) {
        bVar5 = FUN_401190e4();
        if ((char)bVar5 < 0) goto LAB_40119225;
        iVar19 = (char)bVar5 * 0x2c;
        *(uint *)(&DAT_3ffc851c + iVar19) = _DAT_3ffc83cc;
        *(uint *)(&DAT_3ffc8520 + iVar19) = _DAT_3ffc83d0;
        *(uint *)(&DAT_3ffc8524 + iVar19) = _DAT_3ffc83d4;
        uVar18 = _DAT_3ffc83d8;
        (&DAT_3ffc852c)[iVar19] = DAT_3ffc83dc;
        *(undefined4 *)(&DAT_3ffc853c + iVar19) = 0;
        (&DAT_3ffc8540)[iVar19] = 1;
        memw();
        *(uint *)(&DAT_3ffc8528 + iVar19) = uVar18;
        *(uint *)(&DAT_3ffc8530 + iVar19) = param_2;
        *(undefined4 *)(&DAT_3ffc8544 + iVar19) = 1;
        memw();
        FUN_40118c68(param_2,&DAT_3ffc851c + (short)(char)bVar5 * 0x2c);
      }
      puVar22 = &DAT_3ffc846c;
      (&DAT_3ffc8541)[(char)bVar5 * 0x2c] = 1;
      memw();
      cVar17 = '\x02';
      cVar6 = '\x03';
      do {
        cVar16 = cVar17;
        if (*(undefined1 **)(puVar22 + 0x18) == &DAT_3ffc851c + (short)(char)bVar5 * 0x2c)
        goto LAB_40119a50;
        cVar16 = cVar6;
        if (*(undefined1 **)(puVar22 + 0x18) == (undefined1 *)0x0) {
          cVar16 = cVar17;
        }
        cVar17 = cVar17 + -1;
        puVar22 = puVar22 + -0xc;
        cVar6 = cVar16;
      } while (cVar17 != -1);
      iVar19 = (int)cVar16;
      if (iVar19 == 3) {
        (&DAT_3ffc8541)[(char)bVar5 * 0x2c] = 0;
        memw();
        memw();
      }
      else {
        *(undefined1 **)(&DAT_3ffc846c + iVar19 * 0xc) = &DAT_3ffc851c + (short)(char)bVar5 * 0x2c;
        if (-1 < iVar19) {
LAB_40119a50:
          iVar19 = (int)cVar16;
          memw();
          uVar9 = FUN_40185290(*(undefined2 *)(pbVar7 + 6));
          *(undefined4 *)(iVar19 * 0xc + 0x3ffc8470) = uVar9;
          if (*(int *)(pbVar7 + 0xc) != 0) {
            memw();
            _DAT_3ffbe0d0 = FUN_40109eec();
          }
          if (*(int *)(pbVar7 + 8) != 0) {
            memw();
            _DAT_3ffbe0d4 = FUN_40109eec();
          }
          uVar18 = 0x10;
          (&DAT_3ffc8474)[iVar19 * 0xc] = pbVar7[5];
          memw();
          while (1 < (int)(*(ushort *)(param_1 + 8) - uVar18)) {
            memw();
            uVar10 = FUN_4010c140(param_1,uVar18 + 1 & 0xffff);
            if ((int)uVar10 < 1) break;
            uVar26 = (uVar10 & 0xff) << 3;
            if ((int)(*(ushort *)(param_1 + 8) - uVar18) < (int)uVar26) break;
            if ((uint)*(ushort *)(param_1 + 10) == (uint)*(ushort *)(param_1 + 8)) {
              pcVar11 = (char *)(*(int *)(param_1 + 4) + uVar18);
            }
            else {
              if (0x20 < uVar26) {
                iVar21 = FUN_4010c168(param_1,uVar18);
                if (iVar21 != 0x19) break;
                uVar26 = 0x20;
              }
              pcVar11 = &DAT_3ffc6492;
              uVar26 = FUN_4010bfb8(param_1,&DAT_3ffc6492,uVar26,uVar18);
            }
            cVar6 = *pcVar11;
            if (cVar6 == '\x03') {
              if (uVar26 < 0x20) break;
              uVar26 = *(uint *)(pcVar11 + 0x10);
              if ((uVar26 & 0xc0ff) != 0x80fe) {
                uVar12 = *(uint *)(pcVar11 + 0x14);
                if (((pcVar11[3] & 0x80U) != 0) && (pcVar11[2] == '@')) {
                  uVar9 = *(undefined4 *)(pcVar11 + 0x18);
                  uVar3 = *(undefined4 *)(pcVar11 + 0x1c);
                  memw();
                  iVar21 = FUN_40109eec(*(undefined4 *)(pcVar11 + 4));
                  if (((uVar26 != _DAT_3ffc8490) ||
                      ((uVar12 != _DAT_3ffc8494 || (DAT_3ffc84a0 != '\0')))) ||
                     (param_2 != _DAT_3ffc84a4)) {
                    if ((iVar21 == 0) || ((_DAT_3ffc84a4 != 0 && (_DAT_3ffc84a8 != 0))))
                    goto LAB_40119d6e;
                    DAT_3ffc84a0 = '\0';
                    memw();
                    _DAT_3ffc8490 = uVar26;
                    _DAT_3ffc8494 = uVar12;
                    uRam3ffc8498 = uVar9;
                    uRam3ffc849c = uVar3;
                    _DAT_3ffc84a4 = param_2;
                  }
                  memw();
                  _DAT_3ffc84a8 = iVar21;
                }
LAB_40119d6e:
                if ((pcVar11[3] & 0x40U) != 0) {
                  memw();
                  uVar13 = FUN_40109eec(*(undefined4 *)(pcVar11 + 4));
                  memw();
                  uVar14 = FUN_40109eec(*(undefined4 *)(pcVar11 + 8));
                  if ((uVar14 <= uVar13) && (pcVar11[2] == '@')) {
                    puVar23 = (uint *)(param_2 + 100);
                    pcVar29 = (char *)0x2;
                    pcVar11 = (char *)0x1;
                    puVar20 = puVar23;
                    do {
                      cVar6 = pcVar11[param_2 + 0x94];
                      if ((((cVar6 != '\0') &&
                           (uVar27 = *(uint *)(pcVar11 + (int)pcVar11 * 3 + param_2 + 0x98),
                           uVar27 != 0)) && (uVar26 == *puVar20)) &&
                         ((uVar12 == puVar20[1] && ((char)puVar20[4] == '\0')))) {
                        if ((uVar13 < 0x1c21) && (uVar13 <= uVar27)) {
                          if (0x1c20 < uVar27) {
                            *(undefined4 *)(param_2 + (int)(pcVar11 + 0x24) * 4 + 8) = 0x1c20;
                          }
                        }
                        else {
                          uVar26 = param_2 + (int)(pcVar11 + 0x24) * 4;
                          *(uint *)(uVar26 + 8) = uVar13;
                          if (uVar13 == 0) {
                            pcVar29 = "_free_q";
                            memw();
                            uVar13 = in_t0;
                            (*(code *)&SUB_40094c54)("p6_frag",0xde,"_free_q","!= NULL");
                            puVar20 = (uint *)0x1c20;
                            uVar14 = uVar13;
                            in_t0 = uVar13;
                            goto LAB_40119e6c;
                          }
                        }
                        if ((uVar14 != 0) && (cVar6 == '\x10')) {
                          memw();
                          FUN_4010b840(param_2,pcVar11,0x30);
                        }
                        *(uint *)(param_2 + (int)(pcVar11 + 0x28) * 4 + 4) = uVar14;
                        memw();
                        goto LAB_40119b79;
                      }
LAB_40119e6c:
                      puVar20 = puVar20 + 6;
                      bVar1 = pcVar11 != (char *)0x2;
                      pcVar11 = pcVar29;
                    } while (bVar1);
                    if (((*(char *)(param_2 + 0xef) != '\0') &&
                        (iVar21 = 1, (*(byte *)(param_2 + 0x94) & 0xbf) != 0)) && (uVar13 != 0)) {
                      uVar30 = *(uint *)(param_2 + 0x54);
                      uVar27 = *(uint *)(param_2 + 0x58);
                      iVar28 = 0;
                      while( true ) {
                        if (*(char *)(param_2 + iVar21 + 0x94) == '\0') {
                          if (iVar28 == 0) {
                            iVar28 = iVar21;
                          }
                        }
                        else if (((uVar26 == *puVar23) && (uVar12 == puVar23[1])) &&
                                ((uVar30 == puVar23[2] &&
                                 ((uVar27 == puVar23[3] && ((char)puVar23[4] == '\0'))))))
                        goto LAB_40119b79;
                        puVar23 = puVar23 + 6;
                        if (iVar21 == 2) break;
                        iVar21 = 2;
                      }
                      if (iVar28 != 0) {
                        iVar28 = (int)(char)iVar28;
                        iVar21 = param_2 + iVar28 * 0x18;
                        *(uint *)(iVar21 + 0x4c) = uVar26;
                        *(undefined1 *)(iVar21 + 0x5c) = 0;
                        *(uint *)(iVar21 + 0x50) = uVar12;
                        *(uint *)(iVar21 + 0x54) = uVar30;
                        *(uint *)(iVar21 + 0x58) = uVar27;
                        *(undefined1 *)(iVar21 + 0x60) = 6;
                        memw();
                        iVar21 = param_2 + iVar28 * 4;
                        *(uint *)(iVar21 + 0x98) = uVar13;
                        *(uint *)(iVar21 + 0xa4) = uVar14;
                        memw();
                        FUN_4010b840(param_2,iVar28,8);
                      }
                    }
                  }
                }
              }
            }
            else if (cVar6 == '\x05') {
              if (uVar26 < 8) break;
              uVar26 = FUN_40109eec(*(undefined4 *)(pcVar11 + 4));
              if (uVar26 - 0x500 < 0xfb00) {
                sVar25 = (short)uVar26;
                uVar2 = *(ushort *)(param_2 + 0xe0);
                uVar12 = (uint)uVar2;
                if (uVar12 != 0) {
                  bVar1 = uVar12 < (uVar26 & 0xffff);
                  sVar25 = bVar1 * uVar2 + (ushort)!bVar1 * sVar25;
                }
                *(short *)(param_2 + 0xe2) = sVar25;
                memw();
                memw();
              }
            }
            else if (cVar6 == '\x01') {
              if (uVar26 < 8) break;
              iVar21 = *(int *)(&DAT_3ffc846c + iVar19 * 0xc);
              if ((iVar21 != 0) && (*(char *)(iVar21 + 0x24) == '\x01')) {
                memw();
                (*(code *)&SUB_4008b3d0)(iVar21 + 0x18,pcVar11 + 2,*(undefined1 *)(param_2 + 0xea));
                iVar21 = *(int *)(&DAT_3ffc846c + iVar19 * 0xc);
                *(undefined1 *)(iVar21 + 0x24) = 2;
                memw();
                *(undefined4 *)(iVar21 + 0x28) = _DAT_3ffbe0d4;
              }
            }
LAB_40119b79:
            uVar18 = uVar18 + (uVar10 & 0xff) * 8 & 0xffff;
            memw();
          }
        }
      }
    }
  }
  else if (bVar5 == 0x88) {
    uVar2 = *(ushort *)(param_1 + 10);
    if (0x17 < uVar2) {
      bStack_24 = 0;
      uStack_34 = *(uint *)(pbVar7 + 8);
      uStack_30 = *(uint *)(pbVar7 + 0xc);
      uStack_2c = *(uint *)(pbVar7 + 0x10);
      uStack_28 = *(uint *)(pbVar7 + 0x14);
      if ((uStack_34 & 0xc0ff) == 0x80fe) {
        bStack_24 = *(char *)(param_2 + 0xee) + 1;
      }
      memw();
      if (((*(char *)(_DAT_3ffc83c4 + 7) == -1) && (pbVar7[1] == 0)) && ((uStack_34 & 0xff) != 0xff)
         ) {
        if (DAT_3ffc83e4 == -1) {
          puVar20 = (uint *)(param_2 + 0x4c);
          iVar19 = 0;
          do {
            if (((((*(byte *)(param_2 + iVar19 + 0x94) & 0xbf) != 0) && (uStack_34 == *puVar20)) &&
                ((uStack_30 == puVar20[1] &&
                 ((uStack_2c == puVar20[2] && (uStack_28 == puVar20[3])))))) &&
               ((byte)puVar20[4] == bStack_24)) {
              memw();
              FUN_40118ff0(param_2);
              goto LAB_40119225;
            }
            iVar19 = iVar19 + 1;
            puVar20 = puVar20 + 6;
          } while (iVar19 != 3);
          if ((((0x19 < uVar2) && ((ushort)((ushort)pbVar7[0x19] * 8 + 0x18) <= uVar2)) &&
              (cVar6 = FUN_40118980(&uStack_34), -1 < cVar6)) && ((pbVar7[4] & 0x20) != 0)) {
            (*(code *)&SUB_4008b3d0)
                      ((short)cVar6 * 0x2c + 0x3ffc8534,pbVar7 + 0x1a,
                       *(undefined1 *)(param_2 + 0xea));
          }
        }
        else {
          cVar6 = FUN_40118980(&uStack_34);
          iVar19 = (int)cVar6;
          if (-1 < iVar19) {
            if (((pbVar7[4] & 0x20) != 0) || ((&DAT_3ffc8540)[iVar19 * 0x2c] == '\x01')) {
              if ((uVar2 < 0x1a) || (uVar2 < (ushort)((ushort)pbVar7[0x19] * 8 + 0x18)))
              goto LAB_40119225;
              (*(code *)&SUB_4008b3d0)
                        ((short)cVar6 * 0x2c + 0x3ffc8534,pbVar7 + 0x1a,
                         *(undefined1 *)(param_2 + 0xea));
            }
            iVar21 = iVar19 * 0x2c;
            *(uint *)(&DAT_3ffc8530 + iVar21) = param_2;
            (&DAT_3ffc8540)[iVar21] = 2;
            memw();
            *(undefined4 *)(&DAT_3ffc8544 + iVar21) = _DAT_3ffbe0d4;
            if ((*(int *)(&DAT_3ffc853c + iVar21) != 0) && (iVar19 < 5)) {
              memw();
              FUN_40118ee0(iVar19);
            }
          }
        }
      }
    }
  }
  else if ((bVar5 == 0x89) && (uVar2 = *(ushort *)(param_1 + 10), 0x27 < uVar2)) {
    uStack_48 = *(uint *)(pbVar7 + 0x18);
    uStack_44 = *(undefined4 *)(pbVar7 + 0x1c);
    uStack_40 = *(undefined4 *)(pbVar7 + 0x20);
    uStack_3c = *(undefined4 *)(pbVar7 + 0x24);
    cStack_38 = '\0';
    if ((uStack_48 & 0xc0ff) == 0x80fe) {
      cStack_38 = *(char *)(param_2 + 0xee) + '\x01';
    }
    memw();
    if (((((_DAT_3ffc83cc & 0xc0ff) == 0x80fe) && (*(char *)(_DAT_3ffc83c4 + 7) == -1)) &&
        (pbVar7[1] == 0)) && ((uStack_48 & 0xff) != 0xff)) {
      pbStack_58 = (byte *)0x0;
      if ((0x29 < uVar2) && ((ushort)((ushort)pbVar7[0x29] * 8 + 0x28) <= uVar2)) {
        pbStack_58 = pbVar7 + 0x28;
      }
      memw();
      iVar19 = FUN_401189c4(&uStack_48);
      if (-1 < iVar19) {
        uVar18 = *(uint *)(pbVar7 + 8);
        uVar10 = *(uint *)(pbVar7 + 0xc);
        uVar26 = *(uint *)(pbVar7 + 0x10);
        uVar12 = *(uint *)(pbVar7 + 0x14);
        bVar5 = 0;
        if ((*(uint *)(pbVar7 + 8) & 0xc0ff) == 0x80fe) {
          bVar5 = *(char *)(param_2 + 0xee) + 1;
        }
        iVar19 = iVar19 * 0x30;
        *(uint *)(iVar19 + 0x3ffc860c) = uVar18;
        *(uint *)(iVar19 + 0x3ffc8610) = uVar10;
        *(uint *)(iVar19 + 0x3ffc8614) = uVar26;
        *(uint *)(iVar19 + 0x3ffc8618) = uVar12;
        *(byte *)(iVar19 + 0x3ffc861c) = bVar5;
        memw();
        uStack_34 = uVar18;
        uStack_30 = uVar10;
        uStack_2c = uVar26;
        uStack_28 = uVar12;
        bStack_24 = bVar5;
        if ((pbStack_58 != (byte *)0x0) && (*pbStack_58 == 2)) {
          memw();
          bVar4 = FUN_40118980(&uStack_34);
          if ((bVar4 & 0x80) != 0) {
            bVar4 = FUN_401190e4();
            if ((char)bVar4 < 0) goto LAB_40119225;
            iVar19 = (char)bVar4 * 0x2c;
            uVar15 = *(undefined1 *)(param_2 + 0xea);
            *(uint *)(&DAT_3ffc8530 + iVar19) = param_2;
            memw();
            (*(code *)&SUB_4008b3d0)((short)(char)bVar4 * 0x2c + 0x3ffc8534,pbStack_58 + 2,uVar15);
            *(uint *)(&DAT_3ffc8528 + iVar19) = uVar12;
            (&DAT_3ffc8540)[iVar19] = 4;
            (&DAT_3ffc852c)[iVar19] = bVar5;
            memw();
            *(uint *)(&DAT_3ffc851c + iVar19) = uVar18;
            *(uint *)(&DAT_3ffc8520 + iVar19) = uVar10;
            *(uint *)(&DAT_3ffc8524 + iVar19) = uVar26;
            *(undefined4 *)(&DAT_3ffc8544 + iVar19) = 5;
          }
          iVar19 = (char)bVar4 * 0x2c;
          if ((&DAT_3ffc8540)[iVar19] == '\x01') {
            memw();
            (*(code *)&SUB_4008b3d0)
                      ((short)(char)bVar4 * 0x2c + 0x3ffc8534,pbStack_58 + 2,
                       *(undefined1 *)(param_2 + 0xea));
            (&DAT_3ffc8540)[iVar19] = 4;
            memw();
            *(undefined4 *)(&DAT_3ffc8544 + iVar19) = 5;
            memw();
          }
        }
      }
    }
  }
LAB_40119225:
  memw();
  FUN_4010bb10(param_1);
  return;
}

