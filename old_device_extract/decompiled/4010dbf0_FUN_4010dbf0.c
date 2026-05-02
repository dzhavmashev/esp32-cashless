// Function : FUN_4010dbf0
// Address  : 0x4010dbf0
// Size     : 1074 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4010dbf0(void)

{
  byte bVar1;
  short sVar2;
  char cVar3;
  byte bVar4;
  uint uVar5;
  uint *puVar6;
  uint uVar7;
  uint uVar8;
  code *pcVar9;
  int iVar10;
  int iVar11;
  ushort uVar12;
  uint uVar13;
  undefined4 uVar14;
  char *pcVar15;
  
  _DAT_3ffc8414 = _DAT_3ffc8414 + 1;
  DAT_3ffc6334 = DAT_3ffc6334 + '\x01';
  memw();
  puVar6 = (uint *)&DAT_3ffc840c;
LAB_4010dc0d:
  do {
    uVar5 = 0;
    uVar7 = *puVar6;
LAB_4010dc11:
    do {
      do {
        uVar8 = uVar7;
        if (uVar8 == 0) {
          uVar7 = _DAT_3ffc8418;
          while( true ) {
            uVar5 = uVar7;
            if (uVar5 == 0) {
              memw();
              return;
            }
            if (*(uint *)(uVar5 + 0x3c) != 10) break;
            if ((uint)(_DAT_3ffc8414 - *(int *)(uVar5 + 0x4c)) < 0xf1) {
              uVar7 = *(uint *)(uVar5 + 0x34);
              uVar8 = uVar5;
            }
            else {
              FUN_4010d2e0(uVar5);
              puVar6 = (uint *)&DAT_3ffc8418;
              uVar7 = _DAT_3ffc8418;
              if (uVar8 == 0) {
                if (_DAT_3ffc8418 != uVar5) {
                  pcVar15 = "tw_pcbs";
                  uVar14 = 0x5b8;
                  goto LAB_4010dc33;
                }
                _DAT_3ffc8418 = *(uint *)(uVar5 + 0x34);
                memw();
              }
              else {
                if (_DAT_3ffc8418 == uVar5) {
                  pcVar15 = "ME-WAIT";
                  uVar14 = 0x5b4;
                  goto LAB_4010dc33;
                }
                *(undefined4 *)(uVar8 + 0x34) = *(undefined4 *)(uVar5 + 0x34);
              }
              uVar7 = *(uint *)(uVar5 + 0x34);
              memw();
              FUN_4010ca80(uVar5);
            }
          }
          pcVar15 = "ve_pcbs";
          uVar14 = 0x5a6;
          puVar6 = (uint *)&DAT_3ffc8418;
          uVar7 = *(uint *)(uVar5 + 0x3c);
        }
        else {
          uVar7 = *(uint *)(uVar8 + 0x3c);
          if (uVar7 != 0) goto LAB_4010dc3c;
          pcVar15 = "!LISTEN";
          uVar14 = 0x4bf;
        }
LAB_4010dc33:
        while( true ) {
          while( true ) {
            (*(code *)&SUB_40094c54)(" LISTEN",uVar14,"eg_copy",pcVar15);
LAB_4010dc3c:
            if (uVar7 != 1) break;
            pcVar15 = "CLOSED\n";
            uVar14 = 0x4c0;
          }
          if (uVar7 != 10) break;
          pcVar15 = "LISTEN\n";
          uVar14 = 0x4c1;
        }
        if (*(char *)(uVar8 + 0x4a) == DAT_3ffc6334) {
          uVar5 = uVar8;
          uVar7 = *(uint *)(uVar8 + 0x34);
          goto LAB_4010dc11;
        }
        *(char *)(uVar8 + 0x4a) = DAT_3ffc6334;
        memw();
        if (uVar7 != 2) {
          iVar10 = 1;
          if (0xb < *(byte *)(uVar8 + 0x6e)) goto LAB_4010dca5;
LAB_4010dc83:
          if (*(byte *)(uVar8 + 0xcd) == 0) {
            sVar2 = *(short *)(uVar8 + 0x5c);
            if ((-1 < sVar2) && (sVar2 != 0x7fff)) {
              *(short *)(uVar8 + 0x5c) = sVar2 + 1;
              memw();
            }
            if (*(short *)(uVar8 + 0x6c) <= *(short *)(uVar8 + 0x5c)) {
              memw();
              cVar3 = FUN_40110a18(uVar8);
              if ((cVar3 == '\0') ||
                 ((*(int *)(uVar8 + 0x9c) == 0 && (*(int *)(uVar8 + 0x98) != 0)))) {
                if (1 < *(int *)(uVar8 + 0x3c) - 2U) {
                  uVar7 = (uint)*(byte *)(uVar8 + 0x6e);
                  iVar10 = ((int)*(short *)(uVar8 + 0x68) >> 3) + (int)*(short *)(uVar8 + 0x6a) <<
                           0x20 - (0x20 - ((byte)(&DAT_3f4109a3)
                                                 [(uVar7 < 0xc) * uVar7 + (uint)(uVar7 >= 0xc) * 0xc
                                                 ] & 0x1f));
                  if (0x7ffe < iVar10) {
                    iVar10 = 0x7fff;
                  }
                  *(short *)(uVar8 + 0x6c) = (short)iVar10;
                  memw();
                }
                uVar13 = (uint)*(ushort *)(uVar8 + 0x74);
                uVar7 = (uint)*(ushort *)(uVar8 + 0x8c);
                uVar7 = (uVar7 < uVar13) * uVar7 + (uVar7 >= uVar13) * uVar13 >> 1;
                uVar12 = *(short *)(uVar8 + 0x5e) << 1;
                *(undefined2 *)(uVar8 + 0x5c) = 0;
                *(short *)(uVar8 + 0x76) = (short)uVar7;
                memw();
                if (uVar7 < uVar12) {
                  *(ushort *)(uVar8 + 0x76) = uVar12;
                }
                *(short *)(uVar8 + 0x74) = *(short *)(uVar8 + 0x5e);
                *(undefined2 *)(uVar8 + 0x96) = 0;
                memw();
                memw();
                FUN_40112ffc(uVar8);
                iVar10 = 0;
                goto LAB_4010dca5;
              }
            }
            goto LAB_4010ddc8;
          }
          if (*(uint *)(uVar8 + 0x9c) == 0) {
            if (*(int *)(uVar8 + 0x98) != 0) {
              if (0xb < *(byte *)(uVar8 + 0xce)) goto LAB_4010deb0;
              bVar4 = (&DAT_3f41099b)[*(byte *)(uVar8 + 0xcd)];
              bVar1 = *(byte *)(uVar8 + 0xcc);
              if (bVar1 < bVar4) {
                *(byte *)(uVar8 + 0xcc) = bVar1 + 1;
                memw();
                if ((byte)(bVar1 + 1) < bVar4) goto LAB_4010ddc8;
              }
              if (*(short *)(uVar8 + 0x8c) == 0) {
                cVar3 = FUN_401130a8(uVar8);
                if (cVar3 == '\0') goto LAB_4010ddde;
              }
              else {
                cVar3 = FUN_40110694(uVar8);
                if ((cVar3 != '\0') || (cVar3 = FUN_40112a70(uVar8), cVar3 != '\0')) {
LAB_4010ddde:
                  *(undefined1 *)(uVar8 + 0xcc) = 0;
                  memw();
                  if (*(byte *)(uVar8 + 0xcd) < 7) {
                    *(byte *)(uVar8 + 0xcd) = *(byte *)(uVar8 + 0xcd) + 1;
                    memw();
                    memw();
                  }
                }
              }
LAB_4010ddc8:
              iVar10 = 0;
              memw();
              goto LAB_4010dca5;
            }
            pcVar15 = "ht data";
            uVar14 = 0x4d6;
            uVar7 = 0;
          }
          else {
            pcVar15 = "E-WAIT\n";
            uVar14 = 0x4d5;
            memw();
            uVar7 = *(uint *)(uVar8 + 0x9c);
          }
          goto LAB_4010dc33;
        }
        if (*(byte *)(uVar8 + 0x6e) < 6) goto LAB_4010dc83;
LAB_4010deb0:
        iVar10 = 1;
LAB_4010dca5:
        iVar11 = *(int *)(uVar8 + 0x3c);
        if (((iVar11 == 6) && ((*(ushort *)(uVar8 + 0x46) & 0x10) != 0)) &&
           (0x28 < (uint)(_DAT_3ffc8414 - *(int *)(uVar8 + 0x4c)))) {
          iVar10 = iVar10 + 1;
        }
        uVar7 = *(byte *)(uVar8 + 0x31) & 8;
        if ((*(byte *)(uVar8 + 0x31) & 8) != 0) {
          uVar7 = (uint)(iVar11 == 4);
          if (iVar11 != 4) {
            uVar13 = 1;
            if (iVar11 != 7) {
              uVar13 = uVar7;
            }
            if (uVar13 == 0) goto LAB_4010dd15;
          }
          uVar13 = _DAT_3ffc8414 - *(int *)(uVar8 + 0x4c);
          if ((uint)(*(int *)(uVar8 + 0xc4) * *(int *)(uVar8 + 200) + *(int *)(uVar8 + 0xc0)) / 500
              < uVar13) {
            iVar10 = iVar10 + 1;
            uVar7 = 1;
          }
          else {
            uVar7 = 0;
            if (((uint)*(byte *)(uVar8 + 0xcf) * *(int *)(uVar8 + 0xc4) + *(int *)(uVar8 + 0xc0)) /
                500 < uVar13) {
              uVar7 = 0;
              cVar3 = FUN_40113060(uVar8);
              if (cVar3 == '\0') {
                *(char *)(uVar8 + 0xcf) = *(char *)(uVar8 + 0xcf) + '\x01';
                memw();
                memw();
                uVar7 = 0;
              }
            }
          }
        }
LAB_4010dd15:
        if ((*(int *)(uVar8 + 0xa0) != 0) &&
           ((uint)(*(short *)(uVar8 + 0x6c) * 6) <= (uint)(_DAT_3ffc8414 - *(int *)(uVar8 + 0x4c))))
        {
          FUN_4010d2c8(uVar8);
        }
        if (*(int *)(uVar8 + 0x3c) == 3) {
          iVar11 = *(int *)(uVar8 + 0x4c);
          uVar13 = 0x28;
LAB_4010dd4a:
          if ((uint)(_DAT_3ffc8414 - iVar11) <= uVar13) goto LAB_4010dd4d;
        }
        else {
          if (*(int *)(uVar8 + 0x3c) == 9) {
            iVar11 = *(int *)(uVar8 + 0x4c);
            uVar13 = 0xf0;
            goto LAB_4010dd4a;
          }
LAB_4010dd4d:
          if (iVar10 == 0) {
            bVar4 = *(char *)(uVar8 + 0x48) + 1;
            *(byte *)(uVar8 + 0x48) = bVar4;
            memw();
            uVar7 = *(uint *)(uVar8 + 0x34);
            uVar5 = uVar8;
            if (bVar4 < *(byte *)(uVar8 + 0x49)) goto LAB_4010dc11;
            *(undefined1 *)(uVar8 + 0x48) = 0;
            DAT_3ffc8408 = '\0';
            memw();
            if (*(code **)(uVar8 + 0xb8) != (code *)0x0) {
              cVar3 = (**(code **)(uVar8 + 0xb8))(*(undefined4 *)(uVar8 + 0x38),uVar8);
              if (DAT_3ffc8408 != '\0') goto LAB_4010dc0d;
              if (cVar3 != '\0') goto LAB_4010dc11;
            }
            memw();
            FUN_40112a70(uVar8);
            goto LAB_4010dc11;
          }
        }
        pcVar9 = *(code **)(uVar8 + 0xbc);
        FUN_4010d2e0(uVar8);
        if (uVar5 == 0) {
          if (*puVar6 == uVar8) {
            *puVar6 = *(uint *)(uVar8 + 0x34);
            memw();
            goto LAB_4010df06;
          }
          pcVar15 = "ve_pcbs";
          uVar14 = 0x576;
          goto LAB_4010dc33;
        }
        if (*puVar6 == uVar8) {
          pcVar15 = " buffer";
          uVar14 = 0x572;
          goto LAB_4010dc33;
        }
        *(undefined4 *)(uVar5 + 0x34) = *(undefined4 *)(uVar8 + 0x34);
LAB_4010df06:
        if (uVar7 != 0) {
          memw();
          FUN_40110c08(uVar8,*(undefined4 *)(uVar8 + 0x7c),*(undefined4 *)(uVar8 + 0x50),uVar8,
                       uVar8 + 0x18,*(undefined2 *)(uVar8 + 0x42),*(undefined2 *)(uVar8 + 0x44));
        }
        uVar14 = *(undefined4 *)(uVar8 + 0x38);
        uVar7 = *(uint *)(uVar8 + 0x34);
        memw();
        FUN_4010ca80(uVar8);
        DAT_3ffc8408 = '\0';
        memw();
      } while (pcVar9 == (code *)0x0);
      memw();
      (*pcVar9)(uVar14,0xfffffff3);
    } while (DAT_3ffc8408 == '\0');
  } while( true );
}

