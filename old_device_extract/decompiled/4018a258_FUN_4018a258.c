// Function : FUN_4018a258
// Address  : 0x4018a258
// Size     : 1333 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

byte FUN_4018a258(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  byte bVar1;
  ushort uVar2;
  bool bVar3;
  short sVar4;
  short sVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  byte bVar10;
  byte *pbVar11;
  uint uVar12;
  byte bVar13;
  byte bVar14;
  byte bVar15;
  byte *pbVar16;
  byte bVar17;
  byte bVar18;
  char *pcVar19;
  
  uVar6 = *(uint *)(*(int *)(param_2 + 0x10) + 0x18) & 0xfff;
  _DAT_3ffc791c = _DAT_3ffc791c + 1;
  if (param_1 == 0) goto LAB_4018a744;
  iVar7 = *(int *)(param_1 + 0xe4);
  if ((iVar7 == 0) && (iVar7 = *(int *)(param_1 + 0xe8), iVar7 == 0)) {
    memw();
    FUN_40147fe4(1,0x800,1,"b empty","om user",0x39c);
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  *(byte *)(iVar7 + 0x2b8) = (byte)((uint)*(undefined4 *)(*(int *)(param_2 + 0x10) + 0x14) >> 0x1f);
  memw();
  if ((**(uint **)(param_2 + 0x2c) & 0x20) == 0) {
    if (0xf < uVar6) {
      pbVar16 = *(byte **)(*(int *)(param_2 + 4) + 4);
      bVar15 = *pbVar16;
      bVar17 = bVar15 & 3;
      if ((bVar15 & 3) == 0) {
        bVar13 = bVar15 & 0xc;
        bVar1 = pbVar16[1];
        bVar14 = bVar15 & 0xf0;
        bVar10 = bVar1 & 3;
        pbVar11 = pbVar16 + 10;
        if (bVar10 == 2) {
          memw();
          iVar8 = (*(code *)&SUB_4008b33c)(pbVar16 + 4,pbVar16 + 0x10,6);
          if (iVar8 == 0) {
            bVar17 = 1;
          }
        }
        if ((((_DAT_3ffc8864 == 0) || ((bVar15 & 0xc) != 0)) || (bVar14 != 0x80)) ||
           (iVar8 = (*_DAT_3ffc79c4)(pbVar11,0,param_3), (iVar8 - 2U & 0xfffffffd) != 0)) {
          memw();
          iVar8 = (*(code *)&SUB_4008b33c)(pbVar11,iVar7 + 4,6);
          if ((((iVar8 != 0) && ((bVar3 = (bVar15 & 0xc) != 0, bVar14 != 0xd0 || (bVar3)))) &&
              (((DAT_3ffc9022 & 1) == 0 || ((bVar3 || ((bVar14 != 0x80 && (bVar14 != 0x50)))))))) &&
             ((_DAT_3ffc8864 == 0 || ((bVar14 != 0x80 || (bVar3)))))) goto LAB_4018a72a;
        }
        *(char *)(param_1 + 0x144) = (char)param_4;
        memw();
        sVar4 = (short)uVar6;
        if ((bVar15 & 4) == 0) {
          if ((pbVar16[4] & 1) != 0) goto LAB_4018a4f5;
          iVar8 = FUN_40186998(pbVar16);
          uVar2 = *(ushort *)(pbVar16 + 0x16);
          *(ushort *)(param_2 + 0x1c) = uVar2 >> 4;
          memw();
          if ((bVar15 & 0xc) != 0) {
            bVar18 = 1;
            if ((bVar13 != 8) || ((bVar15 & 0xc0) != 0xc0)) goto LAB_4018a4a4;
            iVar8 = FUN_40186a78(pbVar16);
            *(short *)(param_2 + 0x14) = (short)iVar8;
            *(short *)(param_2 + 0x16) = (sVar4 + -4) - (short)iVar8;
            memw();
            memw();
            goto LAB_4018a528;
          }
          if (bVar14 != 0xd0) {
            if (bVar14 != 0x50) {
              bVar18 = 1;
              if (bVar14 == 0xb0) {
                bVar18 = bVar13;
              }
              iVar8 = 0x11;
              goto LAB_4018a4a4;
            }
            memw();
            iVar8 = FUN_401569d8(pbVar11);
            if (iVar8 != 0) {
              memw();
              FUN_40147fe4(1,0x24,5,0x3f43617b,pbVar16[10],pbVar16[0xb],pbVar16[0xc],pbVar16[0xd],
                           pbVar16[0xe],pbVar16[0xf]);
              goto LAB_4018a72a;
            }
LAB_4018a406:
            iVar8 = 0x11;
            bVar18 = 1;
            memw();
LAB_4018a4a4:
            pcVar19 = (char *)(iVar7 + iVar8 + 0xf6);
            if (*pcVar19 == '\0') {
              if ((((bVar18 != 0) && ((pbVar16[1] & 8) != 0)) &&
                  (*(ushort *)(iVar8 * 2 + iVar7 + 0xd2) == uVar2)) &&
                 (*(int *)(param_1 + 0xe8) != iVar7)) {
                FUN_40147fe4(1,0x24,5,0x3f436157,uVar2,iVar8);
                goto LAB_4018a72a;
              }
            }
            else {
              *pcVar19 = '\0';
              memw();
              memw();
            }
            *(ushort *)(iVar8 * 2 + iVar7 + 0xd2) = uVar2;
            memw();
            goto LAB_4018a4f5;
          }
          pbVar11 = pbVar16 + 0x20;
          if ((pbVar16[1] >> 6 & 1) == 0) {
            pbVar11 = pbVar16 + 0x18;
          }
          if (*pbVar11 != 0x7f) goto LAB_4018a406;
          memw();
          iVar8 = (*(code *)&SUB_4008b33c)(pbVar11 + 1,"ostap.c",3);
          if (iVar8 != 0) goto LAB_4018a406;
          if ((int)(pbVar11 + (8 - (int)pbVar16)) <= (int)uVar6) {
            sVar5 = FUN_40186a78(pbVar16);
            *(short *)(param_2 + 0x14) = sVar5;
            *(short *)(param_2 + 0x16) = (sVar4 + -4) - sVar5;
            memw();
            memw();
            goto LAB_4018a6b7;
          }
        }
        else {
          memw();
LAB_4018a4f5:
          memw();
          iVar8 = FUN_40186a78(pbVar16);
          *(short *)(param_2 + 0x14) = (short)iVar8;
          *(short *)(param_2 + 0x16) = (sVar4 + -4) - (short)iVar8;
          memw();
          if (bVar13 == 4) {
            FUN_40158fcc(iVar7,param_2,bVar14);
            goto LAB_4018a72a;
          }
          if (bVar13 == 8) {
LAB_4018a528:
            _DAT_3ffc7920 = _DAT_3ffc7920 + 1;
            if (*(int *)(param_1 + 0xe4) == 0) {
              memw();
            }
            else if (iVar8 <= (int)uVar6) {
              bVar13 = 8;
              if (1 < (byte)(bVar10 - 2)) goto LAB_4018a72a;
              memw();
              iVar9 = FUN_4018a03c(iVar7,param_2);
              if (iVar9 != 0) {
                return 8;
              }
              goto LAB_4018a569;
            }
            goto LAB_4018a74a;
          }
          if ((bVar15 & 0xc) != 0) goto LAB_4018a72a;
          memw();
LAB_4018a6b7:
          _DAT_3ffc7926 = _DAT_3ffc7926 + 1;
          memw();
          if (bVar17 == 0) {
            if ((bVar1 & 3) != 0) {
              memw();
              FUN_40147fe4(1,0x24,5,0x3f436142,bVar10);
              bVar13 = 0;
              goto LAB_4018a72a;
            }
            if ((0x17 < uVar6) &&
               (((_DAT_3ffc89f4 == 0 || ((pbVar16[4] & 1) == 0)) ||
                (iVar7 = FUN_40159110(param_2), iVar7 == 0)))) {
              FUN_401596b0(param_1,param_2,bVar14,param_3,param_4);
            }
          }
        }
        bVar13 = 0;
        goto LAB_4018a72a;
      }
    }
LAB_4018a744:
    bVar13 = 0xff;
    goto LAB_4018a72a;
  }
  pbVar16 = *(byte **)(*(int *)(param_2 + 4) + 4);
  bVar10 = pbVar16[1] & 3;
  memw();
  iVar8 = FUN_40186a78(pbVar16);
  bVar14 = 0x80;
  bVar17 = 0;
  memw();
LAB_4018a569:
  if (bVar10 == 2) {
    uVar12 = pbVar16[1] & 0x40;
    if ((pbVar16[1] & 0x40) == 0) {
      *(uint *)(*(int *)(param_2 + 4) + 4) =
           *(int *)(*(int *)(param_2 + 4) + 4) + (uint)*(ushort *)(param_2 + 0x14);
      memw();
    }
    else {
      memw();
      uVar12 = FUN_40147c10(iVar7,param_2,iVar8);
      if (uVar12 == 0) goto LAB_4018a74a;
    }
    if (bVar14 == 0x80) {
      bVar15 = pbVar16[0x18];
    }
    else {
      bVar15 = 0;
    }
    param_2 = FUN_4014c2d0(param_2,pbVar16,uVar6,iVar8);
    if (param_2 == 0) {
      return 8;
    }
    iVar7 = FUN_401581f0(param_1,iVar7,param_2);
    if (iVar7 != 1) {
      if ((uVar12 == 0) && (bVar13 = 8, DAT_3ffc89ed != '\x01')) goto LAB_4018a72a;
      if ((char)bVar15 < '\0') {
        _DAT_3ffc792e = _DAT_3ffc792e + 1;
        memw();
        memw();
        param_2 = FUN_4014c004(param_1,param_2);
        if (param_2 == 0) {
          return 8;
        }
      }
      if ((_DAT_3ffc8864 != 0) && ((*(uint *)(param_2 + 0x1c) & 0x10000) != 0)) {
        if (*(int *)(param_1 + 0x98) == 5) {
          iVar7 = (*_DAT_3ffc79d0)();
          (**(code **)(_DAT_3ffc1a34 + 0xe8))(param_1 + 0x18,iVar7 * 1000,0);
        }
        iVar7 = *(int *)(*(int *)(param_2 + 4) + 4);
        uVar6 = **(uint **)(param_2 + 0x10);
        uVar12 = uVar6 >> 8 & 0x1f;
        if (((uVar6 & 0xc000) == 0x4000) &&
           (uVar6 = (*(uint **)(param_2 + 0x10))[1], uVar12 = 0x18,
           (uVar6 & 0x7f) == (int)uVar6 >> 0x1f)) {
          uVar12 = 0x10;
        }
        if (_DAT_3ffc7908 != (code *)0x0) {
          (*_DAT_3ffc7908)(0,iVar7,*(undefined2 *)(param_2 + 0x16),iVar7 + 6,
                           *(undefined2 *)(param_2 + 0x1c),uVar12);
        }
        FUN_4015fb50(param_2);
        return 8;
      }
      if (_DAT_3ffc7a88 != (code *)0x0) {
        FUN_4018b168(*(undefined4 *)(*(int *)(param_2 + 4) + 4),*(undefined2 *)(param_2 + 0x16));
        bVar13 = 8;
        if (bVar17 == 0) {
          (*_DAT_3ffc7a88)(*(undefined4 *)(*(int *)(param_2 + 4) + 4),
                           *(undefined2 *)(param_2 + 0x16),param_2);
          return 8;
        }
        goto LAB_4018a72a;
      }
    }
  }
LAB_4018a74a:
  bVar13 = 8;
LAB_4018a72a:
  FUN_4015fb50(param_2);
  return bVar13;
}

