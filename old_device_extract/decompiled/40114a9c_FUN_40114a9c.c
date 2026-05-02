// Function : FUN_40114a9c
// Address  : 0x40114a9c
// Size     : 1242 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40114a9c(undefined4 param_1,undefined4 param_2,int *param_3,int param_4)

{
  byte bVar1;
  int iVar2;
  int *piVar3;
  char *pcVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  code *pcVar8;
  uint uVar9;
  byte bVar10;
  uint uVar11;
  int *piVar12;
  bool bVar13;
  uint uVar14;
  uint uVar15;
  undefined4 uVar16;
  char *pcVar17;
  int iVar18;
  uint uVar19;
  int iStack_38;
  uint auStack_24 [9];
  
  iVar2 = _DAT_3ffc83bc;
  piVar3 = *(int **)(_DAT_3ffc83bc + 200);
  if ((piVar3 != (int *)0x0) && ((char)piVar3[1] != '\0')) {
    if (param_4 == 0) goto LAB_40114ad1;
    if (*(char *)(param_4 + 0x14) == '\0') goto LAB_40114ad1;
    pcVar4 = "DHCP: hostname is too long!";
    pcVar17 = "e_reply";
    uVar16 = 0x8be;
LAB_40114ac5:
    memw();
    (*(code *)&SUB_40094c54)("ONS_LEN",uVar16,pcVar17,pcVar4 + 0x14);
LAB_40114ad1:
    if ((0x2b < *(ushort *)((int)param_3 + 10)) && (pcVar4 = (char *)param_3[1], *pcVar4 == '\x02'))
    {
      uVar9 = 0;
      while (((uVar9 & 0xff) < 6 && ((uVar9 & 0xff) < (uint)*(byte *)(iVar2 + 0xea)))) {
        iVar18 = iVar2 + uVar9;
        iVar5 = uVar9 + 0x1c;
        uVar9 = uVar9 + 1;
        if (pcVar4[iVar5] != *(char *)(iVar18 + 0xe4)) goto LAB_40114b6e;
      }
      iVar5 = FUN_40109eec(*(undefined4 *)(pcVar4 + 4));
      if ((iVar5 == *piVar3) &&
         ((*(code *)&SUB_4008b530)(&DAT_3ffc8428,0,0xd), 0x2b < *(ushort *)((int)param_3 + 10))) {
        bVar13 = false;
        uVar9 = 0xf0;
        uVar14 = (uint)*(ushort *)(param_3 + 2);
        piVar12 = param_3;
LAB_40114b44:
        do {
          uVar6 = (uint)*(ushort *)((int)piVar12 + 10);
          if (uVar9 < uVar6) {
            iStack_38 = piVar12[1];
            memw();
            uVar6 = uVar9;
LAB_40114d09:
            uVar16 = _DAT_3ffc8440;
            if (uVar14 <= uVar6) goto LAB_40114d1c;
            bVar1 = *(byte *)(iStack_38 + uVar6);
            if (bVar1 == 0xff) goto LAB_40114d1c;
            uVar19 = uVar6 + 2 & 0xffff;
            if (uVar19 < uVar6) break;
            if (uVar6 + 1 < (uint)*(ushort *)((int)piVar12 + 10)) {
              bVar10 = ((byte *)(iStack_38 + uVar6))[1];
LAB_40114b9f:
              uVar15 = (uint)bVar10;
              if (bVar1 == 0x2a) {
LAB_40114cad:
                if (((uVar15 & 3) == 0) &&
                   (uVar7 = (uVar15 < 4) * uVar15 + (uint)(uVar15 >= 4) * 4, uVar7 <= uVar15)) {
                  uVar11 = 0xc;
                  goto LAB_40114c4a;
                }
                break;
              }
              uVar7 = uVar15;
              if (bVar1 < 0x2b) {
                if (bVar1 == 3) {
                  if (3 < uVar15) {
                    uVar7 = 4;
                    uVar11 = 7;
                    goto LAB_40114c4a;
                  }
                  break;
                }
                if (bVar1 < 4) {
                  if (bVar1 == 0) goto LAB_40114ce5;
                  if (bVar1 == 1) {
                    if (uVar15 != 4) break;
                    uVar11 = 6;
                  }
                  else {
LAB_40114bbc:
                    uVar7 = 0;
                    uVar11 = 0xffffffff;
                  }
                }
                else {
                  if (bVar1 == 6) goto LAB_40114c88;
                  if (bVar1 != 0x1a) goto LAB_40114bbc;
                  if (uVar15 != 2) break;
                  uVar11 = 8;
                }
              }
              else {
                uVar11 = uVar15;
                if (bVar1 == 0x35) {
                  if (uVar15 != 1) break;
                }
                else if (bVar1 < 0x36) {
                  if (bVar1 != 0x33) goto LAB_40114bfa;
                  if (uVar15 != 4) break;
                  uVar11 = 3;
                }
                else if (bVar1 == 0x3a) {
                  if (uVar15 != 4) break;
                }
                else if (bVar1 == 0x3b) {
                  if (uVar15 != 4) break;
                  uVar11 = 5;
                }
                else {
                  if (bVar1 != 0x36) goto LAB_40114bbc;
                  if (uVar15 != 4) break;
                  uVar11 = 2;
                }
              }
            }
            else {
              if (*piVar12 != 0) {
                bVar10 = **(byte **)(*piVar12 + 4);
                goto LAB_40114b9f;
              }
              if (bVar1 == 0x2a) {
                uVar15 = 0;
                goto LAB_40114cad;
              }
              if (bVar1 < 0x2b) {
                if (bVar1 == 3) break;
                if (3 < bVar1) {
                  if (bVar1 != 6) {
                    bVar10 = 0x1a;
                    goto LAB_40114f55;
                  }
                  uVar15 = 0;
LAB_40114c88:
                  if (((uVar15 & 3) == 0) &&
                     (uVar7 = (uVar15 < 0xc) * uVar15 + (uint)(uVar15 >= 0xc) * 0xc, uVar7 <= uVar15
                     )) {
                    uVar11 = 9;
                    goto LAB_40114c4a;
                  }
                  break;
                }
                if (bVar1 != 0) {
                  if (bVar1 != 1) goto LAB_40114f48;
                  break;
                }
LAB_40114ce5:
                uVar6 = uVar6 + 1 & 0xffff;
                goto LAB_40114ce8;
              }
              if (bVar1 == 0x35) break;
              if (0x35 < bVar1) {
                if ((bVar1 != 0x3a) && (bVar1 != 0x3b)) {
                  bVar10 = 0x36;
LAB_40114f55:
                  if (bVar1 != bVar10) {
LAB_40114f48:
                    uVar15 = 0;
                    goto LAB_40114bbc;
                  }
                }
                break;
              }
              if (bVar1 == 0x33) break;
              uVar15 = 0;
LAB_40114bfa:
              if (bVar1 != 0x34) goto LAB_40114bbc;
              if ((uVar9 != 0xf0) || (uVar15 != 1)) break;
              uVar15 = 1;
              uVar7 = 1;
              uVar11 = 0;
            }
LAB_40114c4a:
            if (0xfffd < uVar15 + uVar6) break;
            uVar6 = uVar19 + uVar15 & 0xffff;
            if (uVar7 != 0) {
              auStack_24[0] = 0;
              while( true ) {
                if (0xc < uVar11) {
                  pcVar4 = "invalid server address type";
                  pcVar17 = "changed";
                  uVar16 = 0x843;
                  memw();
                  goto LAB_40114ac5;
                }
                if ((&DAT_3ffc8428)[uVar11] != '\0') goto LAB_40114ce8;
                iVar18 = (uVar7 < 4) * uVar7 + (uint)(uVar7 >= 4) * 4;
                memw();
                iVar5 = FUN_4010bfb8(piVar12,auStack_24,iVar18,uVar19);
                if (iVar18 != iVar5) goto LAB_40114b6e;
                if (uVar7 < 5) break;
                if ((uVar7 & 3) != 0) goto LAB_40114b6e;
                (&DAT_3ffc8428)[uVar11] = '\x01';
                memw();
                uVar7 = uVar7 - 4 & 0xff;
                memw();
                uVar16 = FUN_40109eec(auStack_24[0]);
                *(undefined4 *)(&DAT_3ffc8438 + uVar11 * 4) = uVar16;
                uVar15 = uVar19 + 4 & 0xffff;
                if (uVar15 < uVar19) goto LAB_40114b6e;
                uVar11 = uVar11 + 1;
                memw();
                uVar19 = uVar15;
              }
              if (uVar7 == 4) {
LAB_40114de0:
                memw();
                auStack_24[0] = FUN_40109eec(auStack_24[0]);
              }
              else if (uVar7 == 2) {
                memw();
                auStack_24[0] = FUN_40185290(auStack_24[0] & 0xffff);
              }
              else {
                if (uVar7 == 3) goto LAB_40114de0;
                if (uVar7 != 1) break;
                auStack_24[0] = auStack_24[0] & 0xff;
                memw();
              }
              (&DAT_3ffc8428)[uVar11] = 1;
              memw();
              *(uint *)(&DAT_3ffc8438 + uVar11 * 4) = auStack_24[0];
              memw();
            }
LAB_40114ce8:
            uVar19 = (uint)*(ushort *)((int)piVar12 + 10);
            if (uVar19 <= uVar6) {
              uVar6 = uVar6 - uVar19 & 0xffff;
              uVar14 = uVar14 - uVar19 & 0xffff;
              if ((uVar14 <= uVar6) || (piVar12 = (int *)*piVar12, piVar12 == (int *)0x0)) break;
              iStack_38 = piVar12[1];
            }
            goto LAB_40114d09;
          }
          piVar12 = (int *)*piVar12;
          uVar9 = uVar9 - uVar6 & 0xffff;
          uVar14 = uVar14 - uVar6 & 0xffff;
        } while (piVar12 != (int *)0x0);
      }
    }
  }
LAB_40114b6e:
  FUN_4010bb10(param_3);
  return;
LAB_40114d1c:
  if (DAT_3ffc8428 != '\0') {
    DAT_3ffc8428 = '\0';
    memw();
    if (_DAT_3ffc8438 == 1) {
LAB_40114e61:
      uVar14 = 0xec;
      uVar9 = 0x6c;
      piVar12 = param_3;
      goto LAB_40114b44;
    }
    if (_DAT_3ffc8438 == 2) goto LAB_40114e4c;
    if (_DAT_3ffc8438 == 3) {
      bVar13 = true;
      goto LAB_40114e61;
    }
  }
  if (!bVar13) {
    if (DAT_3ffc8429 == '\0') goto LAB_40114b6e;
    iVar5 = param_3[1];
    if (DAT_3ffc843c == '\x05') {
      if ((*(char *)((int)piVar3 + 5) == '\x01') || ((byte)(*(char *)((int)piVar3 + 5) - 3U) < 3)) {
        memw();
        FUN_401140b4(iVar2,iVar5);
        FUN_401141b8(iVar2);
      }
      goto LAB_40114b6e;
    }
    if (DAT_3ffc843c != '\x06') {
      if (((DAT_3ffc843c == '\x02') && (*(char *)((int)piVar3 + 5) == '\x06')) &&
         (DAT_3ffc842a != '\0')) {
        iVar18 = *(int *)(iVar2 + 200);
        *(undefined2 *)(iVar18 + 10) = 0;
        memw();
        memw();
        uVar16 = FUN_40109eec(uVar16);
        *(undefined4 *)(iVar18 + 0x24) = uVar16;
        *(undefined1 *)(iVar18 + 0x38) = 0;
        *(undefined4 *)(iVar18 + 0x30) = 0;
        *(undefined4 *)(iVar18 + 0x2c) = 0;
        *(undefined4 *)(iVar18 + 0x28) = 0;
        *(undefined1 *)(iVar18 + 0x34) = 0;
        memw();
        *(undefined4 *)(iVar18 + 0x3c) = *(undefined4 *)(iVar5 + 0x10);
        memw();
        FUN_401147a4(iVar2);
      }
      goto LAB_40114b6e;
    }
    if (2 < (byte)(*(char *)((int)piVar3 + 5) - 3U)) {
      if (*(char *)((int)piVar3 + 5) == '\x01') {
        bVar13 = true;
      }
      if (!bVar13) goto LAB_40114b6e;
    }
    iVar5 = *(int *)(iVar2 + 200);
    FUN_4018541c(iVar5,0xc);
    FUN_4010b270(iVar2,&DAT_3f411ef4,&DAT_3f411ef4,&DAT_3f411ef4);
    pcVar8 = *(code **)(iVar5 + 0x54);
    if (pcVar8 != (code *)0x0) {
      (*pcVar8)(iVar2);
    }
    FUN_40114954(iVar2);
    goto LAB_40114b6e;
  }
LAB_40114e4c:
  bVar13 = false;
  uVar14 = 0x6c;
  uVar9 = 0x2c;
  memw();
  piVar12 = param_3;
  goto LAB_40114b44;
}

