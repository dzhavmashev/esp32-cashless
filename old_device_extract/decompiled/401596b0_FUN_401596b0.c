// Function : FUN_401596b0
// Address  : 0x401596b0
// Size     : 2152 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_401596b0(int param_1,int param_2,uint param_3,int param_4,int param_5)

{
  byte bVar1;
  undefined2 uVar2;
  short sVar3;
  bool bVar4;
  byte *pbVar5;
  int iVar6;
  int iVar7;
  code *pcVar8;
  byte *pbVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  byte *pbVar14;
  undefined4 uVar15;
  uint local_e0;
  char cStack_dc;
  undefined4 *puStack_94;
  int iStack_8c;
  undefined4 uStack_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  int iStack_4c;
  undefined4 uStack_48;
  undefined1 auStack_44 [20];
  byte *pbStack_30;
  int iStack_2c;
  byte *pbStack_28;
  uint uStack_24;
  
  iVar11 = *(int *)(param_1 + 0xe4);
  memw();
  iStack_2c = param_5;
  pbStack_28 = (byte *)param_3;
  FUN_4014eb04(0,auStack_44);
  (*(code *)&SUB_4008b530)(&local_e0,0,0x84);
  iVar10 = *(int *)(*(int *)(param_2 + 4) + 4);
  pbVar9 = (byte *)(iVar10 + 0x18);
  uVar12 = (uint)*(ushort *)(param_2 + 0x16);
  pbStack_30 = pbVar9 + uVar12;
  if (pbStack_28 != (byte *)0x80) {
    if ((int)pbStack_28 < 0x81) {
      if (pbStack_28 == (byte *)0x30) {
LAB_40159b4a:
        DAT_3ffc792a = DAT_3ffc792a + '\x01';
        memw();
        if (*(int *)(param_1 + 0x98) != 3) {
          return;
        }
        if (uVar12 < 6) {
          return;
        }
        memw();
        uStack_24 = uVar12;
        FUN_40147fe4(1,4,4,0x3f433cac,pbStack_28);
        FUN_40158a34(iVar11,iVar10,pbStack_30,pbStack_28,param_4);
        if (*(code **)(_DAT_3ffc89a4 + 0x50) == (code *)0x0) {
          return;
        }
        if ((_DAT_3ffc8a58 & 1 << ((byte)((int)pbStack_28 >> 4) & 0x1f)) == 0) {
          return;
        }
        memw();
        (**(code **)(_DAT_3ffc89a4 + 0x50))
                  ((int)pbStack_28 >> 4,pbVar9,uStack_24,iVar10 + 10,(int)(char)param_4,
                   *(undefined1 *)(*(int *)(param_2 + 0x2c) + 8),0,0);
        return;
      }
      if (pbStack_28 == (byte *)0x50) {
        pbStack_30 = (byte *)0x1;
        memw();
        goto LAB_4015974f;
      }
      if (pbStack_28 == (byte *)0x10) {
        memw();
        goto LAB_40159b4a;
      }
    }
    else {
      if (pbStack_28 == (byte *)0xb0) {
        DAT_3ffc792b = DAT_3ffc792b + '\x01';
        memw();
        if (uVar12 < 6) {
          return;
        }
        uVar12 = (uint)*(ushort *)(iVar10 + 0x1a);
        uVar2 = *(undefined2 *)(iVar10 + 0x1c);
        sVar3 = *(short *)(iVar10 + 0x18);
        memw();
        FUN_40147fe4(1,4,4,0x3f433ce2,uVar12,uVar2);
        if (sVar3 == 1) {
          memw();
          FUN_401584f4(iVar11,iVar10,iVar10 + 0x1e,pbStack_30,param_4,iStack_2c,uVar12,uVar2);
          return;
        }
        if (sVar3 == 0) {
          FUN_401583bc(iVar11,iVar10,param_4,iStack_2c,uVar12,uVar2);
          return;
        }
        if (sVar3 != 3) {
          return;
        }
        if ((*(byte *)(iVar10 + 1) & 8) == 0) {
LAB_40159b33:
          FUN_40159500(iVar11,iVar10 + 0x1e,(int)pbStack_30 - (iVar10 + 0x1e),uVar12,uVar2);
          return;
        }
        pbVar9 = (byte *)(uint)DAT_3ffc89f7;
        uVar15 = 0x3f433cc2;
        if (pbVar9 != (byte *)uVar12) goto LAB_40159b33;
        goto LAB_40159f25;
      }
      if ((int)pbStack_28 < 0xb1) {
        if (pbStack_28 == (byte *)0xa0) {
          DAT_3ffc792c = DAT_3ffc792c + '\x01';
          memw();
          if ((1 < *(int *)(param_1 + 0x98) - 2U) && (*(int *)(param_1 + 0x98) != 5)) {
            return;
          }
          memw();
          uStack_24 = uVar12;
          iVar6 = (*(code *)&SUB_4008b33c)(iVar10 + 4,auStack_44,6);
          if ((iVar6 != 0) &&
             (iVar6 = (*(code *)&SUB_4008b33c)(iVar10 + 4,&DAT_3f4239bb,6), iVar6 != 0)) {
            return;
          }
          if ((_DAT_3ffc89f4 == 0) || ((*(uint *)(*(int *)(param_1 + 0xe4) + 0xc) & 1) == 0)) {
            if ((*(byte *)(iVar10 + 1) & 0x40) != 0) {
              FUN_40147fe4(1,4,4,0x3f433c66);
              return;
            }
          }
          else if ((*(byte *)(iVar10 + 1) & 0x40) == 0) {
            uVar12 = uStack_24;
            if ((*(byte *)(iVar10 + 4) & 1) == 0) {
LAB_40159c33:
              if ((int)uVar12 < 2) {
                return;
              }
              if (1 < (ushort)(*(short *)(iVar10 + 0x18) - 6U)) {
                return;
              }
              if (*(char *)(iVar11 + 0x2fb) != '\0') {
                return;
              }
              FUN_40159330();
              return;
            }
          }
          else {
            iVar11 = FUN_4015f004(param_2,*(undefined4 *)
                                           (&DAT_3ffc8930 + (uint)*(byte *)(iVar11 + 0x134) * 4));
            if (iVar11 != 0) {
              return;
            }
            pbStack_30 = pbVar9 + *(ushort *)(param_2 + 0x16);
            memw();
          }
          if ((int)pbStack_30 - (int)pbVar9 < 2) {
            return;
          }
          uVar12 = (uint)*(ushort *)(iVar10 + 0x18);
          FUN_40147fe4(1,4,4,0x3f433c4d,uVar12);
          uVar13 = 0xa0;
LAB_40159d56:
          FUN_40157594(&DAT_3ffc87f0,0,uVar12 << 8 | uVar13);
          return;
        }
      }
      else {
        if (pbStack_28 == (byte *)0xc0) {
          DAT_3ffc792c = DAT_3ffc792c + '\x01';
          memw();
          if ((1 < *(int *)(param_1 + 0x98) - 2U) && (*(int *)(param_1 + 0x98) != 5)) {
            return;
          }
          if ((_DAT_3ffc89f4 != 0) && ((*(uint *)(*(int *)(param_1 + 0xe4) + 0xc) & 1) != 0)) {
            if ((*(byte *)(iVar10 + 1) & 0x40) == 0) {
              if ((*(byte *)(iVar10 + 4) & 1) == 0) goto LAB_40159c33;
            }
            else {
              memw();
              iVar11 = FUN_4015f004(param_2,*(undefined4 *)
                                             (&DAT_3ffc8930 + (uint)*(byte *)(iVar11 + 0x134) * 4));
              if (iVar11 != 0) {
                return;
              }
              pbStack_30 = pbVar9 + *(ushort *)(param_2 + 0x16);
              memw();
            }
          }
          if ((int)pbStack_30 - (int)pbVar9 < 2) {
            return;
          }
          uVar12 = (uint)*(ushort *)(iVar10 + 0x18);
          FUN_40147fe4(1,4,4,0x3f433c93,uVar12);
          uVar13 = 0xc0;
          goto LAB_40159d56;
        }
        if (pbStack_28 == (byte *)0xd0) {
          DAT_3ffc792d = DAT_3ffc792d + '\x01';
          memw();
          if ((_DAT_3ffc89f4 == 0) || ((*(byte *)(iVar10 + 1) & 0x40) == 0)) {
            if ((*(byte *)(iVar10 + 1) & 0x40) == 0) {
              uVar12 = FUN_4015ed68(iVar10 + 10);
              pbStack_28 = (byte *)(*(byte *)(iVar10 + 1) & 3);
              pbVar5 = pbVar9;
              if ((*(byte *)(iVar10 + 1) & 3) == 0) {
                memw();
                uStack_24 = uVar12;
                iVar6 = (*(code *)&SUB_4008b33c)(iVar10 + 4,&DAT_3f4239bb,6);
                pbVar14 = pbStack_28;
                if (uStack_24 != 0) {
                  pbVar14 = (byte *)0x1;
                }
                if (pbVar14 != (byte *)0x0) {
                  if (iVar6 != 0) {
                    pbStack_28 = (byte *)0x1;
                  }
                  if (pbStack_28 != (byte *)0x0) {
                    return;
                  }
                }
              }
            }
            else {
              pbVar5 = pbVar9 + _DAT_3ffbfebc;
            }
            pbStack_28 = pbVar5;
            if (((*pbStack_28 < 9) && ((1 << (*pbStack_28 & 0x1f) & 399U) != 0)) &&
               (_DAT_3ffc89f4 != 0)) {
              return;
            }
          }
          else {
            memw();
            iVar6 = FUN_4015ed68(iVar10 + 10);
            if ((((*(byte *)(iVar10 + 1) & 3) == 0) && (iVar6 != 0)) &&
               (*(byte *)(iVar6 + 0xb9) == *(byte *)(iVar10 + 0x1b) >> 6)) {
              iVar6 = FUN_4015efa4(param_2);
            }
            else {
              if (iVar11 == 0) {
                return;
              }
              iVar6 = FUN_4015f004(param_2,*(undefined4 *)
                                            (&DAT_3ffc8930 + (uint)*(byte *)(iVar11 + 0x134) * 4));
            }
            if (iVar6 != 0) {
              return;
            }
            pbStack_30 = pbVar9 + *(ushort *)(param_2 + 0x16);
            if ((*(byte *)(iVar10 + 1) & 0x40) == 0) {
              memw();
              pbStack_28 = pbVar9;
            }
            else {
              pbStack_28 = pbVar9 + _DAT_3ffbfebc;
            }
          }
          if (((*(code **)(_DAT_3ffc89a4 + 0x50) != (code *)0x0) && ((_DAT_3ffc8a58 & 0x2000) != 0))
             && ((_DAT_3ffc8a5c & 1 << (*pbStack_28 & 0x1f)) != 0)) {
            memw();
            iVar6 = (**(code **)(_DAT_3ffc89a4 + 0x50))
                              (0xd,pbVar9,(int)pbStack_30 - (int)pbVar9,iVar10 + 10,
                               (int)(char)param_4,*(undefined1 *)(*(int *)(param_2 + 0x2c) + 8),0,0)
            ;
            if (iVar6 == 0) {
              return;
            }
          }
          memw();
          iVar6 = FUN_4015eae0();
          if (iVar6 != 0) {
            memw();
            iVar6 = FUN_4015eaec(iVar10,pbVar9,(int)pbStack_30 - (int)pbVar9,
                                 *(undefined1 *)(*(int *)(param_2 + 0x2c) + 8));
            if (iVar6 == 0) {
              return;
            }
          }
          bVar4 = true;
          if (((1 < (byte)(*pbStack_28 + 0x82)) && (bVar4 = false, *pbStack_28 == 4)) &&
             (pbStack_28[1] == 0x21)) {
            bVar4 = true;
          }
          if ((iVar11 == 0) && (bVar4)) {
            iVar11 = *(int *)(param_1 + 0xe8);
          }
          if ((iVar11 == 0) || (!bVar4)) {
            if (iVar11 == 0) {
              return;
            }
            if (*(int *)(param_1 + 0x98) != 5) {
              return;
            }
          }
          iVar6 = FUN_4014d708(iVar11,param_2);
          if (iVar6 != 0) {
            return;
          }
          FUN_4015ecb4(iVar11,iVar10,pbVar9,pbStack_30);
          return;
        }
      }
    }
    uVar15 = 0x3f433c23;
    pbVar9 = pbStack_28;
LAB_40159f25:
    FUN_40147fe4(1,4,4,uVar15,pbVar9);
    return;
  }
  pbStack_30 = (byte *)0x0;
LAB_4015974f:
  _DAT_3ffc7928 = _DAT_3ffc7928 + 1;
  memw();
  if ((pbStack_30 != (byte *)0x0) || (*(int *)(param_1 + 0xe4) == 0)) goto LAB_401597bf;
  memw();
  iVar6 = (*(code *)&SUB_4008b33c)(iVar10 + 10,*(int *)(param_1 + 0xe4) + 4,6);
  if (iVar6 != 0) goto LAB_401597bf;
  if (DAT_3ffc7a98 == '\0') {
    if (-0x19 < param_4) {
      DAT_3ffc7a98 = '\x01';
      goto LAB_401597a3;
    }
  }
  else {
    iVar6 = (uint)(_DAT_3ffc7a90 < _DAT_3ffc7a94) * _DAT_3ffc7a94 +
            (uint)(_DAT_3ffc7a90 >= _DAT_3ffc7a94) * _DAT_3ffc7a90;
    if ((int)((uint)(param_4 < iVar6) * iVar6 + (uint)(param_4 >= iVar6) * param_4) < -0x2d) {
      DAT_3ffc7a98 = (char)pbStack_30;
LAB_401597a3:
      memw();
    }
  }
  uVar12 = (uint)DAT_3ffc7a8c;
  DAT_3ffc7a8c = DAT_3ffc7a8c + 1 & 1;
  *(int *)(&DAT_3ffc7a90 + uVar12 * 4) = param_4;
  memw();
LAB_401597bf:
  if ((iVar11 != 0) && ((*(byte *)(iVar10 + 1) & 3) == 0)) {
    memw();
    iVar6 = (*(code *)&SUB_4008b33c)(iVar10 + 0x10,iVar11 + 4,6);
    if ((iVar6 == 0) && (*(char *)(iVar11 + 0x2f6) == '\0')) {
      *(undefined1 *)(iVar11 + 0x2f6) = 1;
      memw();
    }
  }
  memw();
  iVar6 = FUN_4014c834(*(undefined4 *)(param_1 + 0xe8),param_2,&local_e0,pbStack_30,param_4);
  if ((iVar6 == 0) &&
     ((((_DAT_3ffc8864 == 0 || (iStack_8c != 0)) || (iVar6 = FUN_4015a384(), iVar6 == 0)) ||
      (iVar6 = (*(code *)&SUB_4008b33c)(local_e0,*(int *)(param_1 + 0xe4) + 4,6), iVar6 == 0)))) {
    iVar6 = FUN_40156b40(param_2,&local_e0,pbStack_30);
    if (iVar6 == -1) {
      return;
    }
    if (_DAT_3ffc8864 != 0) {
      iStack_2c = FUN_4015a384();
      iVar6 = 0;
      if (iStack_2c != 0) {
        pbStack_28 = *(byte **)(param_1 + 0xe4);
        iVar6 = (int)pbStack_28 + 4;
        uStack_24 = local_e0;
        memw();
        iVar7 = (*(code *)&SUB_4008b33c)(local_e0,iVar6,6);
        if (iVar7 == 0) {
          param_4 = (int)*(char *)((int)pbStack_28 + 0xa4);
          (*_DAT_3ffc79bc)(uStack_24,uStack_78);
        }
      }
      iStack_4c = iStack_8c;
      uStack_48 = uStack_78;
      uStack_5c = uStack_88;
      uStack_58 = uStack_84;
      uStack_54 = uStack_80;
      uStack_50 = uStack_7c;
      memw();
      (*_DAT_3ffc79a8)(iStack_2c,local_e0,iVar6,param_4,&iStack_4c,&uStack_5c);
    }
    iVar6 = _DAT_3ffc8864;
    if (((*(int *)(param_1 + 0xe4) != 0) && (*(int *)(param_1 + 0x98) == 5)) &&
       ((_DAT_3ffc8864 == 0 ||
        ((iVar7 = (*(code *)&SUB_4008b33c)(local_e0,iVar11 + 4,6), iVar7 == 0 &&
         ((memw(), DAT_3ffc1a3c != '\0' || (iStack_8c != 0)))))))) {
      if ((puStack_94 != (undefined4 *)0x0) &&
         ((pbStack_30 == (byte *)0x0 &&
          (iVar10 = (*(code *)&SUB_4008b33c)(iVar10 + 0x10,iVar11 + 4,6), iVar10 == 0)))) {
        if ((iVar6 != 0) && (memw(), DAT_3ffc1a3c != '\0')) {
          memw();
          uStack_5c = CONCAT13(*(undefined1 *)((int)puStack_94 + 3),(int3)pbStack_30);
          memw();
          bVar1 = *(byte *)(puStack_94 + 1);
          uStack_58 = CONCAT31((int3)((uint)uStack_58 >> 8),
                               (bVar1 < 0xf) * '\x0f' + (bVar1 >= 0xf) * bVar1);
          memw();
          memw();
          puStack_94 = &uStack_5c;
        }
        FUN_40158754(param_1,puStack_94);
      }
      if ((*(byte *)(*(int *)(param_1 + 0xe4) + 10) & 4) != 0) {
        if (*(char *)(_DAT_3ffc8800 + 0x94) != '\0') {
          if (pbStack_30 != (byte *)0x0) {
            FUN_40162278(*(undefined2 *)(iVar11 + 0x28),*(undefined4 *)(iVar11 + 0x20),
                         *(undefined4 *)(iVar11 + 0x18),*(undefined4 *)(iVar11 + 0x1c));
          }
          *(undefined1 *)(_DAT_3ffc8800 + 0x94) = 0;
          memw();
          memw();
          FUN_40161690();
        }
        if (0xe9fc < (ushort)(*(short *)(*(int *)(param_1 + 0xe4) + 0x28) - 100U)) {
          *(undefined2 *)(*(int *)(param_1 + 0xe4) + 0x28) = 100;
          memw();
        }
        memw();
        (**(code **)(_DAT_3ffc1a34 + 0xec))(param_1 + 0x18);
        if (_DAT_3ffc8864 == 0) {
          iVar10 = (uint)*(ushort *)(param_1 + 0x23a) * 1000;
          pcVar8 = *(code **)(_DAT_3ffc1a34 + 0xe8);
        }
        else {
          if ((((byte)(cStack_dc - 1U) < 0xd) && (cStack_dc != *(char *)(_DAT_3ffbfdf0 + 0x50))) &&
             (DAT_3ffc89d7 != '\x01')) {
            FUN_40147fe4(1,0x8000,2,0x3f436c69);
            memw();
            if (DAT_3ffc1a3c != '\0') {
              FUN_4014f5cc(0);
              return;
            }
            uStack_5c = CONCAT31(uStack_5c._1_3_,1);
            memw();
            memw();
            FUN_40147270(0x22,&uStack_5c,6);
            return;
          }
          memw();
          if (DAT_3ffc1a3c == '\0') {
            iVar10 = (*_DAT_3ffc79d0)();
            iVar10 = iVar10 * 1000;
          }
          else {
            uVar13 = (uint)*(ushort *)(param_1 + 0x23a) * 1000;
            uVar12 = (uint)*(ushort *)(*(int *)(param_1 + 0xe4) + 0x28) * 0x96;
            iVar10 = (uVar13 < uVar12) * uVar12 + (uVar13 >= uVar12) * uVar13;
          }
          pcVar8 = *(code **)(_DAT_3ffc1a34 + 0xe8);
        }
        (*pcVar8)(param_1 + 0x18,iVar10,0);
        return;
      }
    }
  }
  return;
}

