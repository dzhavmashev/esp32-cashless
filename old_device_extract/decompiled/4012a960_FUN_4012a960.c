// Function : FUN_4012a960
// Address  : 0x4012a960
// Size     : 2285 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_4012a960(uint *param_1,uint param_2,undefined4 param_3,uint param_4)

{
  byte bVar1;
  ushort uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  char cVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  char *pcVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  undefined4 uVar16;
  uint uVar17;
  uint uVar18;
  byte *pbVar19;
  byte bVar20;
  int iStack_44;
  undefined1 auStack_40 [8];
  byte bStack_38;
  int iStack_34;
  uint uStack_30;
  int iStack_2c;
  uint uStack_28;
  uint *puStack_24;
  
  memw();
  memw();
  puStack_24 = _DAT_3ffc5708;
  uVar6 = param_1[0x2c];
  if (uVar6 == 0) goto LAB_4012a981;
  iVar9 = 0;
  param_1[0x2c] = 0;
  memw();
LAB_4012ae5c:
  do {
    param_1 = puStack_24;
    memw();
    memw();
    if (puStack_24 == _DAT_3ffc5708) {
      return iVar9;
    }
    (*(code *)&SUB_40082ec4)();
LAB_4012ae76:
    if (*(char *)(param_4 + 5) == '\x01') {
      param_1[0x24] = uStack_30;
    }
    else {
      iVar9 = FUN_4012a1b0(param_1);
      if (iVar9 != 0) goto LAB_4012afff;
      param_1[0x22] = 0;
      memw();
    }
    if (param_1[0x12] == 0) {
LAB_4012ae88:
      if (*(char *)(*param_1 + 5) == '\x01') {
LAB_4012ae90:
        memw();
        FUN_40129afc(param_1);
      }
      if (uStack_28 < 0x4001) {
        FUN_40185894(param_1);
        param_1[0x1d] = param_1[0x1c] + 2;
        param_1[0x20] = (uint)bStack_38;
        *(byte *)param_1[0x1b] = bStack_38;
        memw();
        param_1[0x1e] = iStack_34 + iStack_2c;
        param_1[0x21] = uStack_28;
        *(char *)param_1[0x1c] = (char)(uStack_28 >> 8);
        memw();
        *(char *)(param_1[0x1c] + 1) = (char)uStack_28;
        memw();
        memw();
        goto LAB_4012a9be;
      }
LAB_4012af39:
      iVar9 = -0x7200;
    }
    else {
      iVar9 = FUN_401295b8(param_1,param_1[0x12],auStack_40);
      if (iVar9 == 0) {
        if (uStack_28 == 0) {
          if ((bStack_38 == 0x17) || (param_1[5] != 3)) {
            uVar15 = param_1[0x2b];
            param_1[0x2b] = uVar15 + 1;
            if (3 < (int)(uVar15 + 1)) {
              iVar9 = -0x7180;
              memw();
              goto LAB_4012af3c;
            }
            goto LAB_4012af88;
          }
          goto LAB_4012af39;
        }
        param_1[0x2b] = 0;
LAB_4012af88:
        uVar15 = 8;
        if (*(char *)(*param_1 + 5) == '\x01') goto LAB_4012ae90;
        do {
          uVar10 = uVar15;
          uVar15 = 2;
          if (*(char *)(*param_1 + 5) != '\x01') {
            uVar15 = 0;
          }
          if (uVar10 <= uVar15) break;
          pcVar12 = (char *)(param_1[0x1a] + (uVar10 - 1));
          cVar5 = *pcVar12 + '\x01';
          *pcVar12 = cVar5;
          memw();
          uVar15 = uVar10 - 1;
        } while (cVar5 == '\0');
        uVar15 = 0;
        if (*(char *)(*param_1 + 5) == '\x01') {
          uVar15 = 2;
        }
        if (uVar10 != uVar15) goto LAB_4012ae88;
        iVar9 = -0x6b80;
        memw();
      }
    }
LAB_4012af3c:
    param_4 = 0xffff8e80;
    if (*(char *)(*param_1 + 5) == '\x01') {
      if (iVar9 != -0x7180) goto LAB_4012afff;
      param_4 = param_1[1] - 0xb;
      if ((param_4 & 0xfffffffd) != 0) {
        uVar15 = *(uint *)(*param_1 + 0x2c);
        if (uVar15 == 0) {
LAB_4012ae35:
          param_1[0x24] = 0;
          param_1[0x22] = 0;
          memw();
LAB_4012adea:
          iVar9 = -0x6580;
LAB_4012aded:
          param_4 = iVar9 + 0x6680;
          if ((param_4 & 0xfffffeff) != 0) {
            if (((iVar9 == 0) && (param_4 = 0, param_1[0x20] == 0x16)) &&
               (param_4 = param_2, param_2 == 1)) {
              memw();
              FUN_401299ec(param_1);
            }
            goto LAB_4012ae5c;
          }
LAB_4012a981:
          uVar15 = param_1[0x2a];
          if (uVar15 != 0) {
            if (param_1[0x1f] == 0) {
              if (uVar15 < param_1[0x21]) {
                param_1[0x21] = param_1[0x21] - uVar15;
                memw();
                (*(code *)&SUB_4008b4c8)(param_1[0x1e],param_1[0x1e] + uVar15);
              }
              else {
                param_1[0x21] = 0;
                memw();
              }
              param_1[0x2a] = 0;
LAB_4012a9b8:
              if (param_1[0x21] == 0) goto LAB_4012aaf3;
              goto LAB_4012a9be;
            }
            goto LAB_4012a98c;
          }
          if (param_1[0x1f] != 0) goto LAB_4012a9b8;
          param_1[0x21] = 0;
LAB_4012aaf3:
          uVar15 = param_1[0x11];
          if (*(char *)(*param_1 + 5) == '\x01') {
            if (param_1[0x24] < param_1[0x22]) {
              if (uVar15 != 0) goto LAB_4012ab94;
              goto LAB_4012abd6;
            }
            if (uVar15 == 0) goto LAB_4012abd6;
            if ((param_1[1] - 10 & 0xfffffffd) == 0) {
              if (*(char *)(uVar15 + 0x1f8) == '\0') goto LAB_4012ab94;
              param_1[0x20] = 0x14;
              param_1[0x21] = 1;
              *(undefined1 *)param_1[0x1e] = 1;
              param_1[0x22] = 0;
              param_1[0x24] = 0;
              *(undefined1 *)(uVar15 + 0x1f8) = 0;
              memw();
              memw();
LAB_4012a9be:
              memw();
              iVar9 = FUN_4012a454(param_1);
              if (iVar9 == -0x6480) break;
              goto LAB_4012aded;
            }
            if ((*(uint *)(uVar15 + 0x1fc) & 5) == 5) {
              iVar9 = *(int *)(uVar15 + 0x200);
              uVar10 = ((uint)*(byte *)(iVar9 + 1) << 0x10 | (uint)*(byte *)(iVar9 + 2) << 8 |
                       (uint)*(byte *)(iVar9 + 3)) + 0xc;
              if (uVar10 < 0x4001) {
                param_1[0x20] = 0x16;
                param_1[0x2a] = uVar10;
                param_1[0x21] = uVar10;
                memw();
                (*(code *)&SUB_4008b3d0)(param_1[0x1e]);
                goto LAB_4012a9be;
              }
            }
LAB_4012ab94:
            if (((*(int *)(uVar15 + 0x22c) != 0) && (param_1[0x22] <= param_1[0x24])) &&
               (*(uint *)(uVar15 + 0x234) == (uint)(ushort)param_1[0x23])) {
              uVar10 = *(uint *)(uVar15 + 0x230);
              param_4 = 0x414d - (param_1[0x1b] - param_1[0x19]);
              if (uVar10 <= param_4) {
                (*(code *)&SUB_4008b3d0)(param_1[0x1b],*(int *)(uVar15 + 0x22c),uVar10);
                param_1[0x22] = uVar10;
                param_1[0x24] = 0;
                memw();
                FUN_401291f4(param_1[0x11]);
                goto LAB_4012abd6;
              }
              goto LAB_4012a98c;
            }
          }
LAB_4012abd6:
          uVar16 = 0xd;
          if (*(char *)(*param_1 + 5) != '\x01') {
            uVar16 = 5;
          }
          iVar9 = FUN_4012a1b0(param_1,uVar16);
          if (iVar9 != 0) goto LAB_4012afff;
          iVar9 = FUN_4012a874(param_1,param_1[0x1b],param_1[0x22],auStack_40);
          param_4 = *param_1;
          if (iVar9 == 0) goto LAB_4012ae76;
          if (*(char *)(param_4 + 5) != '\x01') goto LAB_4012afff;
          if (iVar9 == -0x6480) {
            uVar15 = param_1[0x11];
            if (((uVar15 != 0) && (bStack_38 == 0x16)) &&
               ((*(int *)(uVar15 + 0x22c) == 0 && (uStack_30 <= 0x8000U - *(int *)(uVar15 + 500)))))
            {
              *(uint *)(uVar15 + 0x234) = (ushort)param_1[0x23] + 1;
              *(uint *)(uVar15 + 0x230) = uStack_30;
              memw();
              iVar9 = FUN_4013ae30();
              *(int *)(uVar15 + 0x22c) = iVar9;
              if (iVar9 != 0) {
                memw();
                (*(code *)&SUB_4008b3d0)(iVar9,iStack_34,uStack_30);
                *(uint *)(uVar15 + 500) = *(int *)(uVar15 + 500) + uStack_30;
              }
            }
          }
          else if (iVar9 != -0x6700) goto LAB_4012ae35;
          memw();
          FUN_40185894(param_1);
          param_1[0x1e] = param_1[0x1c] + 2;
          param_1[0x1d] = param_1[0x1c] + 2;
          param_1[0x20] = (uint)bStack_38;
          param_1[0x21] = uStack_28;
          if ((((((*(ushort *)param_1[0x1a] & 0xff) == 0 && *(ushort *)param_1[0x1a] >> 8 == 0) &&
                (uVar15 = *param_1, *(char *)(uVar15 + 4) == '\x01')) && (param_1[1] == 0x10)) &&
              ((bStack_38 == 0x16 && (uVar10 = param_1[0x22], 0xd < uVar10)))) &&
             ((pcVar12 = (char *)param_1[0x19], pcVar12[0xd] == '\x01' &&
              ((*(int *)(uVar15 + 0x78) != 0 && (*(code **)(uVar15 + 0x7c) != (code *)0x0)))))) {
            uVar11 = param_1[0x7e];
            param_4 = param_1[0x7f];
            uVar8 = param_1[0x2e];
            if ((0x3c < uVar10) &&
               (((((*pcVar12 == '\x16' && (pcVar12[3] == '\0')) && (pcVar12[4] == '\0')) &&
                 ((pcVar12[0x13] == '\0' && (pcVar12[0x14] == '\0')))) && (pcVar12[0x15] == '\0'))))
            {
              uVar17 = (byte)pcVar12[0x3b] + 0x3d;
              if ((uVar17 <= uVar10) &&
                 (uVar17 + (byte)pcVar12[(byte)pcVar12[0x3b] + 0x3c] <= uVar10)) {
                memw();
                iVar9 = (**(code **)(uVar15 + 0x7c))
                                  (*(undefined4 *)(uVar15 + 0x80),pcVar12 + uVar17,
                                   (uint)(byte)pcVar12[(byte)pcVar12[0x3b] + 0x3c],uVar11,param_4);
                if (iVar9 != 0) {
                  (*(code *)&SUB_4008b3d0)(uVar8,pcVar12,0x19);
                  *(undefined1 *)(uVar8 + 0xd) = 3;
                  *(undefined1 *)(uVar8 + 0x19) = 0xfe;
                  *(undefined1 *)(uVar8 + 0x1a) = 0xff;
                  memw();
                  iStack_44 = uVar8 + 0x1c;
                  memw();
                  iVar9 = (**(code **)(*param_1 + 0x78))
                                    (*(undefined4 *)(*param_1 + 0x80),&iStack_44,uVar8 + 0x4000,
                                     uVar11,param_4);
                  if (iVar9 == 0) {
                    iVar9 = iStack_44 - uVar8;
                    cVar5 = (char)iVar9;
                    *(char *)(uVar8 + 0x1b) = cVar5 + -0x1c;
                    uVar4 = (undefined1)((uint)(iVar9 + -0x19) >> 0x10);
                    uVar3 = (undefined1)((uint)(iVar9 + -0x19) >> 8);
                    *(undefined1 *)(uVar8 + 0x17) = uVar3;
                    *(undefined1 *)(uVar8 + 0xf) = uVar3;
                    *(char *)(uVar8 + 0x18) = cVar5 + -0x19;
                    *(char *)(uVar8 + 0x10) = cVar5 + -0x19;
                    *(undefined1 *)(uVar8 + 0x16) = uVar4;
                    *(undefined1 *)(uVar8 + 0xe) = uVar4;
                    *(char *)(uVar8 + 0xb) = (char)((uint)(iVar9 + -0xd) >> 8);
                    *(char *)(uVar8 + 0xc) = cVar5 + -0xd;
                    memw();
                    memw();
                    (*(code *)param_1[9])(param_1[0xc],param_1[0x2e]);
                    goto LAB_4012ade4;
                  }
                  goto LAB_4012a98c;
                }
                iVar9 = FUN_4012ce00(param_1,1);
                if (iVar9 != 0) goto LAB_4012afff;
                iVar9 = -0x6780;
                goto LAB_4012ae5c;
              }
            }
            iVar9 = -0x7900;
            goto LAB_4012ae5c;
          }
LAB_4012ade4:
          param_1[0x24] = uStack_30;
          goto LAB_4012adea;
        }
        param_4 = param_1[6] + 1;
        param_1[6] = param_4;
        if (param_4 < uVar15) goto LAB_4012ae35;
        memw();
        goto LAB_4012ae5c;
      }
    }
    else if (iVar9 != -0x7180) goto LAB_4012afff;
    FUN_4012a73c(param_1,2,0x14);
    iVar9 = -0x7180;
  } while( true );
  uVar15 = param_1[0x11];
  if (uVar15 == 0) goto LAB_4012adea;
  if (param_1[0x20] == 0x14) {
    *(undefined1 *)(uVar15 + 0x1f8) = 1;
    memw();
    memw();
    goto LAB_4012adea;
  }
  if (param_1[0x20] != 0x16) goto LAB_4012adea;
  uVar2 = *(ushort *)(param_1[0x1e] + 4);
  param_4 = (uVar2 & 0xff) << 8 | (uint)(uVar2 >> 8);
  if (param_4 < *(uint *)(uVar15 + 0x23c)) {
LAB_4012a98c:
    iVar9 = -0x6c00;
    memw();
    goto LAB_4012ae5c;
  }
  param_4 = param_4 - *(uint *)(uVar15 + 0x23c);
  if (3 < param_4) goto LAB_4012adea;
  iVar9 = uVar15 + param_4 * 0xc;
  bVar1 = *(byte *)(iVar9 + 0x1fc);
  bVar20 = bVar1 & 1;
  uVar11 = param_1[0x2a];
  uVar10 = uVar11 - 0xc;
  if ((bVar1 & 1) == 0) {
    memw();
    iVar7 = FUN_40129108(param_1);
    if (iVar7 == 1) {
      bVar20 = 1;
    }
    *(byte *)(iVar9 + 0x1fc) = bVar1 & 0xfd | bVar20 << 1;
    memw();
    if (0x4000 < uVar11) goto LAB_4012adea;
    if (0x8000 < *(uint *)(uVar15 + 500)) goto LAB_4012a98c;
    uVar8 = uVar11;
    if (iVar7 == 1) {
      uVar8 = (uint)((uVar10 & 7) != 0) + (uVar10 >> 3) + uVar11;
    }
    if (0x8000 - *(uint *)(uVar15 + 500) < uVar8) {
      if (param_4 != 0) goto LAB_4012adea;
      memw();
      FUN_401291f4(uVar15);
      if (0x8000U - *(int *)(uVar15 + 500) < uVar8) {
        iVar9 = 3;
        while( true ) {
          memw();
          FUN_40129090(param_1,iVar9);
          if (uVar8 <= 0x8000U - *(int *)(uVar15 + 500)) break;
          iVar9 = iVar9 + -1;
          if (iVar9 == -1) {
            iVar9 = -0x6a00;
            goto LAB_4012ae5c;
          }
        }
      }
    }
    iVar9 = FUN_4013ae30(1,uVar8);
    iVar7 = uVar15 + param_4 * 0xc;
    *(int *)(iVar7 + 0x200) = iVar9;
    if (iVar9 == 0) {
      iVar9 = -0x7f00;
      goto LAB_4012ae5c;
    }
    uVar17 = param_1[0x1e];
    *(uint *)(iVar7 + 0x204) = uVar8;
    memw();
    (*(code *)&SUB_4008b3d0)(iVar9,uVar17,6);
    (*(code *)&SUB_4008b530)(*(int *)(iVar7 + 0x200) + 6,0,3);
    iVar9 = *(int *)(iVar7 + 0x200);
    *(undefined1 *)(iVar9 + 9) = *(undefined1 *)(iVar9 + 1);
    memw();
    *(undefined1 *)(iVar9 + 0xb) = *(undefined1 *)(iVar9 + 3);
    *(undefined1 *)(iVar9 + 10) = *(undefined1 *)(iVar9 + 2);
    memw();
    *(byte *)(iVar7 + 0x1fc) = *(byte *)(iVar7 + 0x1fc) | 1;
    memw();
    *(uint *)(uVar15 + 500) = *(int *)(uVar15 + 500) + uVar8;
  }
  else {
    iVar9 = (*(code *)&SUB_4008b33c)(*(undefined4 *)(iVar9 + 0x200),param_1[0x1e],4);
    if (iVar9 != 0) goto LAB_4012adea;
  }
  iVar9 = uVar15 + param_4 * 0xc;
  uVar8 = iVar9 + 0x1f0;
  if ((*(byte *)(iVar9 + 0x1fc) & 4) != 0) goto LAB_4012adea;
  uVar18 = param_1[0x1e];
  bVar1 = *(byte *)(uVar18 + 8);
  uVar13 = (uint)*(byte *)(uVar18 + 6) << 0x10 | (uint)*(byte *)(uVar18 + 7) << 8 | (uint)bVar1;
  iVar7 = *(int *)(iVar9 + 0x200);
  uVar17 = (uint)*(byte *)(uVar18 + 9) << 0x10 | (uint)*(byte *)(uVar18 + 10) << 8 |
           (uint)*(byte *)(uVar18 + 0xb);
  memw();
  (*(code *)&SUB_4008b3d0)(iVar7 + uVar13 + 0xc,uVar18 + 0xc,uVar17);
  if ((*(byte *)(iVar9 + 0x1fc) & 2) == 0) {
    *(byte *)(iVar9 + 0x1fc) = *(byte *)(iVar9 + 0x1fc) | 4;
    memw();
    memw();
    goto LAB_4012adea;
  }
  uVar18 = bVar1 & 7;
  iVar9 = -uVar18;
  uVar14 = iVar9 + 8;
  iVar7 = iVar7 + uVar11;
  if (uVar14 == 8) {
LAB_4012b1d0:
    uVar11 = uVar17 & 7;
    if (uVar11 != 0) {
      pbVar19 = (byte *)(iVar7 + (uVar17 + uVar13 >> 3));
      uVar17 = uVar17 - uVar11;
      bVar1 = *pbVar19;
      uVar11 = 1 << 0x20 - (0x20 - (8 - uVar11 & 0x1f));
      uVar8 = uVar11 & 0xff | (uint)bVar1;
      *pbVar19 = (byte)uVar11 | bVar1;
      memw();
    }
    memw();
    (*(code *)&SUB_4008b530)(iVar7 + (uVar13 >> 3),0xff,uVar17 >> 3,uVar8);
  }
  else {
    if (uVar14 < uVar17) {
      pbVar19 = (byte *)(iVar7 + (uVar13 >> 3));
      uVar17 = (uVar17 - 8) + uVar18;
      uVar13 = uVar13 + uVar14;
      *pbVar19 = (byte)(1 << 0x20 - (0x20 - (iVar9 + 7U & 0x1f))) | *pbVar19;
      memw();
      uVar8 = uVar14;
      goto LAB_4012b1d0;
    }
    uVar17 = uVar14 - uVar17;
    pbVar19 = (byte *)(iVar7 + (uVar13 >> 3));
    while (uVar17 != uVar14) {
      uVar11 = uVar17 & 0x1f;
      uVar17 = uVar17 + 1;
      *pbVar19 = (byte)(1 << 0x20 - (0x20 - uVar11)) | *pbVar19;
      memw();
      memw();
    }
  }
  for (uVar11 = 0; uVar11 != uVar10 >> 3; uVar11 = uVar11 + 1) {
    if (*(char *)(iVar7 + uVar11) != -1) goto LAB_4012b236;
  }
  for (uVar8 = 0; uVar17 = uVar6, uVar8 < (uVar10 & 7); uVar8 = uVar8 + 1) {
    if (((uint)*(byte *)(iVar7 + uVar11) & 1 << (7U - (char)uVar8 & 0x1f)) == 0) goto LAB_4012b236;
  }
LAB_4012b149:
  iVar9 = uVar15 + param_4 * 0xc;
  *(byte *)(iVar9 + 0x1fc) = *(byte *)(iVar9 + 0x1fc) & 0xfb | (uVar17 == 0) << 2;
  memw();
  memw();
  goto LAB_4012adea;
LAB_4012b236:
  uVar17 = 0xffffffff;
  goto LAB_4012b149;
LAB_4012afff:
  param_4 = 0xffff9a80;
  if (iVar9 != -0x6580) goto LAB_4012ae5c;
  goto LAB_4012adea;
}

