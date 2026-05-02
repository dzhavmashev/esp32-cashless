// Function : FUN_4010efac
// Address  : 0x4010efac
// Size     : 4036 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4010efac(int *param_1)

{
  bool bVar1;
  bool bVar2;
  byte bVar3;
  short *psVar4;
  byte bVar5;
  char cVar6;
  undefined2 uVar7;
  ushort uVar8;
  int iVar9;
  uint *puVar10;
  uint *puVar11;
  uint *puVar12;
  uint *puVar13;
  uint uVar14;
  uint uVar15;
  short sVar16;
  uint *puVar17;
  uint *puVar18;
  undefined4 uVar19;
  uint *puVar20;
  uint *puVar21;
  char *pcVar22;
  char *pcVar23;
  short sVar24;
  
  if (param_1 != (int *)0x0) goto LAB_4010efc4;
  pcVar23 = "cv_wnd\n";
  uVar19 = 0x83;
  pcVar22 = "arseopt";
LAB_4010efbb:
  do {
    (*(code *)&SUB_40094c54)("id cseg",uVar19,pcVar22,pcVar23);
LAB_4010efc4:
    _DAT_3ffc6358 = (short *)param_1[1];
    if (*(ushort *)((int)param_1 + 10) < 0x14) goto LAB_4010efe5;
    if (DAT_3ffc83f8 == '\x06') {
LAB_4010efdc:
      uVar14 = 0xff;
      uVar15 = _DAT_3ffc83e4 & 0xff;
    }
    else {
      iVar9 = (*(code *)&LAB_40185492_2)(_DAT_3ffc83e4,_DAT_3ffc83b8);
      if (iVar9 != 0) goto LAB_4010efe5;
      if (DAT_3ffc83f8 == '\x06') goto LAB_4010efdc;
      uVar14 = _DAT_3ffc83e4 & 0xf0;
      uVar15 = 0xe0;
    }
    if ((uVar14 == uVar15) ||
       (iVar9 = FUN_4011dc38(param_1,6,(short)param_1[2],&DAT_3ffc83cc,&DAT_3ffc83e4), iVar9 != 0))
    goto LAB_4010efe5;
    uVar14 = FUN_40185288(_DAT_3ffc6358[6]);
    uVar14 = (uVar14 >> 0xc & 0x3f) << 2;
    if ((uVar14 < 0x14) || (*(ushort *)(param_1 + 2) < uVar14)) goto LAB_4010efe5;
    _DAT_3ffc6356 = (short)uVar14 + -0x14;
    memw();
    _DAT_3ffc6350 = iVar9;
    if (uVar14 <= *(ushort *)((int)param_1 + 10)) {
      memw();
      memw();
      _DAT_3ffc6354 = _DAT_3ffc6356;
      FUN_4010ba9c(param_1);
LAB_4010f085:
      psVar4 = _DAT_3ffc6358;
      uVar7 = FUN_40185288(*_DAT_3ffc6358);
      *(char *)psVar4 = (char)uVar7;
      *(char *)((int)psVar4 + 1) = (char)((ushort)uVar7 >> 8);
      psVar4 = _DAT_3ffc6358;
      memw();
      memw();
      uVar7 = FUN_40185288(_DAT_3ffc6358[1]);
      *(char *)(psVar4 + 1) = (char)uVar7;
      *(char *)((int)psVar4 + 3) = (char)((ushort)uVar7 >> 8);
      psVar4 = _DAT_3ffc6358;
      memw();
      memw();
      _DAT_3ffc6348 = (int *)FUN_40109eec(*(undefined4 *)(_DAT_3ffc6358 + 2));
      *(char *)((int)psVar4 + 5) = (char)((uint)_DAT_3ffc6348 >> 8);
      *(char *)(psVar4 + 3) = (char)((uint)_DAT_3ffc6348 >> 0x10);
      *(char *)(psVar4 + 2) = (char)_DAT_3ffc6348;
      *(char *)((int)psVar4 + 7) = (char)((uint)_DAT_3ffc6348 >> 0x18);
      psVar4 = _DAT_3ffc6358;
      memw();
      memw();
      _DAT_3ffc6344 = FUN_40109eec(*(undefined4 *)(_DAT_3ffc6358 + 4));
      *(char *)((int)psVar4 + 9) = (char)(_DAT_3ffc6344 >> 8);
      *(char *)(psVar4 + 5) = (char)(_DAT_3ffc6344 >> 0x10);
      *(char *)(psVar4 + 4) = (char)_DAT_3ffc6344;
      *(char *)((int)psVar4 + 0xb) = (char)(_DAT_3ffc6344 >> 0x18);
      psVar4 = _DAT_3ffc6358;
      memw();
      memw();
      uVar7 = FUN_40185288(_DAT_3ffc6358[7]);
      *(char *)(psVar4 + 7) = (char)uVar7;
      *(char *)((int)psVar4 + 0xf) = (char)((ushort)uVar7 >> 8);
      memw();
      memw();
      bVar5 = FUN_40185288(_DAT_3ffc6358[6]);
      psVar4 = _DAT_3ffc6358;
      DAT_3ffc633d = bVar5 & 0x3f;
      memw();
      uVar8 = *(ushort *)(param_1 + 2);
      if ((bVar5 & 3) == 0) {
        memw();
        _DAT_3ffc633e = uVar8;
      }
      else {
        _DAT_3ffc633e = uVar8 + 1;
        memw();
        if ((ushort)(uVar8 + 1) < uVar8) {
          memw();
          goto LAB_4010efe5;
        }
      }
      puVar10 = _DAT_3ffc840c;
      puVar11 = (uint *)0x0;
LAB_4010f1f0:
      puVar13 = puVar10;
      if (puVar13 == (uint *)0x0) break;
      uVar14 = puVar13[0xf];
      if (uVar14 == 0) {
        pcVar23 = "tot_len";
        uVar19 = 0xfb;
        pcVar22 = "arseopt";
        goto LAB_4010efbb;
      }
      if (uVar14 == 10) {
        pcVar23 = " CLOSED";
        uVar19 = 0xfc;
        pcVar22 = "arseopt";
        goto LAB_4010efbb;
      }
      if (uVar14 == 1) {
        pcVar23 = "ME-WAIT";
        uVar19 = 0xfd;
        pcVar22 = "arseopt";
        goto LAB_4010efbb;
      }
      if ((((char)puVar13[0xc] != '\0') &&
          ((char)puVar13[0xc] != (char)(*(char *)(_DAT_3ffc83bc + 0xee) + '\x01'))) ||
         (((short)puVar13[0x11] != *_DAT_3ffc6358 ||
          ((*(short *)((int)puVar13 + 0x42) != _DAT_3ffc6358[1] ||
           ((char)puVar13[0xb] != DAT_3ffc83e0)))))) {
LAB_4010f3e8:
        puVar10 = (uint *)puVar13[0xd];
        puVar11 = puVar13;
        goto LAB_4010f1f0;
      }
      if (DAT_3ffc83e0 == '\x06') {
        bVar2 = false;
        if ((((_DAT_3ffc83cc == puVar13[6]) && (puVar13[7] == _DAT_3ffc83d0)) &&
            (puVar13[8] == _DAT_3ffc83d4)) && (puVar13[9] == _DAT_3ffc83d8)) {
          bVar2 = (char)puVar13[10] == DAT_3ffc83dc;
        }
      }
      else {
        bVar2 = _DAT_3ffc83cc == puVar13[6];
      }
      if ((!bVar2) || ((char)puVar13[5] != DAT_3ffc83f8)) goto LAB_4010f3e8;
      if (DAT_3ffc83f8 == '\x06') {
        bVar2 = false;
        if (((_DAT_3ffc83e4 == *puVar13) && (puVar13[1] == _DAT_3ffc83e8)) &&
           ((puVar13[2] == _DAT_3ffc83ec && (puVar13[3] == _DAT_3ffc83f0)))) {
          bVar2 = (char)puVar13[4] == DAT_3ffc83f4;
        }
      }
      else {
        bVar2 = _DAT_3ffc83e4 == *puVar13;
      }
      if (!bVar2) goto LAB_4010f3e8;
      if ((uint *)puVar13[0xd] == puVar13) {
        pcVar23 = " LISTEN";
        uVar19 = 0x10d;
        pcVar22 = "arseopt";
        goto LAB_4010efbb;
      }
      if (puVar11 != (uint *)0x0) {
        puVar11[0xd] = puVar13[0xd];
        puVar13[0xd] = (uint)_DAT_3ffc840c;
        bVar2 = puVar13 == _DAT_3ffc840c;
        _DAT_3ffc840c = puVar13;
        if (bVar2) {
          pcVar23 = " cache)";
          uVar19 = 0x115;
          pcVar22 = "arseopt";
          memw();
          goto LAB_4010efbb;
        }
      }
      _DAT_3ffc6368 = psVar4;
      _DAT_3ffc6338 = 0;
      _DAT_3ffc635c = 0;
      DAT_3ffc633c = 0;
      _DAT_3ffc6340 = 0;
      memw();
      _DAT_3ffc6360 = param_1;
      _DAT_3ffc6364 = uVar8;
      if ((bVar5 & 8) != 0) {
        *(byte *)((int)param_1 + 0xd) = *(byte *)((int)param_1 + 0xd) | 1;
        memw();
      }
      if (puVar13[0x29] != 0) {
        memw();
        cVar6 = FUN_4010da64(puVar13);
        if ((cVar6 == -0xd) || ((puVar13[0x29] != 0 && (_DAT_3ffc633e != 0)))) {
          if (*(short *)((int)puVar13 + 0x56) == 0) {
            FUN_40110c68(puVar13);
          }
          goto LAB_4010ff69;
        }
      }
      bVar5 = DAT_3ffc633d;
      _DAT_3ffc8420 = puVar13;
      if ((DAT_3ffc633d & 4) != 0) {
        if (puVar13[0xf] == 2) {
          if (puVar13[0x1f] != _DAT_3ffc6344) goto LAB_4010f82c;
LAB_4010f88c:
          DAT_3ffc633c = DAT_3ffc633c | 8;
          memw();
          uVar8 = *(ushort *)((int)puVar13 + 0x46) & 0xfffe;
          goto LAB_4010f8a2;
        }
        if ((int *)puVar13[0x14] == _DAT_3ffc6348) {
          if (puVar13[0xf] != 0) goto LAB_4010f88c;
          pcVar23 = "ME-WAIT";
          uVar19 = 0x33c;
          pcVar22 = "receive";
          param_1 = _DAT_3ffc6348;
          goto LAB_4010efbb;
        }
        iVar9 = (int)_DAT_3ffc6348 - (int)puVar13[0x14];
        if ((iVar9 < 0) || (0 < (int)(iVar9 - (uint)(ushort)puVar13[0x15]))) goto LAB_4010f82c;
LAB_4010f872:
        uVar8 = *(ushort *)((int)puVar13 + 0x46) | 2;
LAB_4010f8a2:
        *(ushort *)((int)puVar13 + 0x46) = uVar8;
        memw();
        memw();
        goto LAB_4010f82c;
      }
      bVar3 = DAT_3ffc633d & 2;
      if (((DAT_3ffc633d & 2) != 0) && (1 < puVar13[0xf] - 2)) {
        *(ushort *)((int)puVar13 + 0x46) = *(ushort *)((int)puVar13 + 0x46) | 2;
        memw();
        memw();
        goto LAB_4010f82c;
      }
      if ((*(ushort *)((int)puVar13 + 0x46) & 0x10) == 0) {
        puVar13[0x13] = _DAT_3ffc8414;
      }
      *(undefined2 *)((int)puVar13 + 0xce) = 0;
      memw();
      memw();
      FUN_4010e180(puVar13);
      uVar14 = puVar13[0xf];
      if (uVar14 == 5) {
        FUN_4010e334(puVar13);
        if ((DAT_3ffc633c & 0x20) == 0) {
          if ((((DAT_3ffc633d & 0x10) == 0) || (puVar13[0x1f] != _DAT_3ffc6344)) ||
             (puVar13[0x26] != 0)) goto LAB_4010f82c;
          uVar14 = 6;
        }
        else {
          if ((((DAT_3ffc633d & 0x10) != 0) && (puVar13[0x1f] == _DAT_3ffc6344)) &&
             (puVar13[0x26] == 0)) {
            *(ushort *)((int)puVar13 + 0x46) = *(ushort *)((int)puVar13 + 0x46) | 2;
            memw();
            memw();
            FUN_4010d2e0(puVar13);
            puVar10 = _DAT_3ffc840c;
            if (puVar13 == _DAT_3ffc840c) goto LAB_4010fc84;
            goto LAB_4010fca0;
          }
          *(ushort *)((int)puVar13 + 0x46) = *(ushort *)((int)puVar13 + 0x46) | 2;
          memw();
          uVar14 = 8;
          memw();
        }
        goto LAB_4010fbc1;
      }
      if (uVar14 < 6) {
        if (uVar14 != 3) {
          if (3 < uVar14) goto LAB_4010fc34;
          if (uVar14 != 2) goto LAB_4010f82c;
          if (((bVar5 & 0x12) != 0x12) || (puVar13[0x1c] + 1 != _DAT_3ffc6344)) {
            if ((bVar5 & 0x10) != 0) {
              memw();
              FUN_40110c08(puVar13,_DAT_3ffc6344,(uint)_DAT_3ffc633e + (int)_DAT_3ffc6348,
                           &DAT_3ffc83e4,&DAT_3ffc83cc,_DAT_3ffc6358[1],*_DAT_3ffc6358);
              if (*(byte *)((int)puVar13 + 0x6e) < 6) {
                *(undefined2 *)(puVar13 + 0x17) = 0;
                memw();
                memw();
                FUN_40113034(puVar13);
              }
            }
            goto LAB_4010f82c;
          }
          uVar15 = (int)_DAT_3ffc6348 + 1;
          uVar14 = (int)_DAT_3ffc6348 - 1;
          puVar13[0x1c] = puVar13[0x1c] + 1;
          puVar13[0x14] = uVar15;
          puVar13[0x16] = uVar15;
          sVar24 = _DAT_3ffc6358[7];
          uVar7 = *(undefined2 *)((int)puVar13 + 0x5e);
          *(short *)(puVar13 + 0x23) = sVar24;
          *(short *)((int)puVar13 + 0x8e) = sVar24;
          memw();
          puVar13[0x20] = uVar14;
          puVar13[0xf] = 4;
          if ((char)puVar13[0xb] == '\x06') {
            memw();
            uVar19 = FUN_401172d4(puVar13,puVar13 + 6);
          }
          else {
            uVar19 = FUN_401167b0();
          }
          iVar9 = FUN_4010cf7c(uVar7,uVar19,puVar13 + 6);
          uVar14 = iVar9 * 2;
          *(short *)((int)puVar13 + 0x5e) = (short)iVar9;
          memw();
          uVar7 = 0x111c;
          if ((uint)(iVar9 << 2) < (uint)(uVar14 < 0x111c) * 0x111c + (uVar14 >= 0x111c) * uVar14) {
            uVar7 = (undefined2)(iVar9 << 2);
          }
          else if (0x111c < uVar14) {
            uVar7 = (undefined2)uVar14;
          }
          *(undefined2 *)(puVar13 + 0x1d) = uVar7;
          memw();
          if (*(ushort *)((int)puVar13 + 0x92) == 0) {
            pcVar23 = " CLOSED";
            uVar19 = 0x371;
            pcVar22 = "receive";
            memw();
            param_1 = (int *)0x0;
            goto LAB_4010efbb;
          }
          param_1 = (int *)(*(ushort *)((int)puVar13 + 0x92) - 1);
          *(short *)((int)puVar13 + 0x92) = (short)param_1;
          memw();
          if ((uint *)puVar13[0x27] == (uint *)0x0) {
            if ((uint *)puVar13[0x26] == (uint *)0x0) {
              pcVar23 = "len > 0";
              uVar19 = 0x379;
              pcVar22 = "receive";
              memw();
              goto LAB_4010efbb;
            }
            puVar13[0x26] = *(uint *)puVar13[0x26];
          }
          else {
            puVar13[0x27] = *(uint *)puVar13[0x27];
            memw();
          }
          memw();
          FUN_4010ce44();
          if (puVar13[0x27] == 0) {
            *(undefined2 *)(puVar13 + 0x17) = 0xffff;
            memw();
          }
          else {
            *(undefined2 *)(puVar13 + 0x17) = 0;
            *(undefined1 *)((int)puVar13 + 0x6e) = 0;
            memw();
            memw();
          }
          if ((code *)puVar13[0x2d] == (code *)0x0) goto LAB_4010f872;
          memw();
          cVar6 = (*(code *)puVar13[0x2d])(puVar13[0xe],puVar13,0);
          if (cVar6 == -0xd) goto LAB_4010ff69;
          goto LAB_4010f872;
        }
        if ((bVar5 & 0x10) == 0) {
          if ((bVar3 != 0) && ((int *)(puVar13[0x14] - 1) == _DAT_3ffc6348)) {
            FUN_40110ad4(puVar13);
          }
          goto LAB_4010f82c;
        }
        if (((int)((_DAT_3ffc6344 - 1) - puVar13[0x1c]) < 0) ||
           (0 < (int)(_DAT_3ffc6344 - puVar13[0x1f]))) {
          memw();
          FUN_40110c08(puVar13,_DAT_3ffc6344,(uint)_DAT_3ffc633e + (int)_DAT_3ffc6348,&DAT_3ffc83e4,
                       &DAT_3ffc83cc,_DAT_3ffc6358[1],*_DAT_3ffc6358);
          goto LAB_4010f82c;
        }
        puVar13[0xf] = 4;
        if (puVar13[0x2a] == 0) goto LAB_4010fb2d;
        if (*(int *)(puVar13[0x2a] + 0x44) == 0) {
          pcVar23 = "to free";
          uVar19 = 0x3ad;
          pcVar22 = "receive";
          param_1 = (int *)0x0;
          goto LAB_4010efbb;
        }
        FUN_4010caa8(puVar13);
        if (*(code **)(puVar13[0x2a] + 0x44) == (code *)0x0) goto LAB_4010fb2d;
        cVar6 = (**(code **)(puVar13[0x2a] + 0x44))(puVar13[0xe],puVar13,0);
        if (cVar6 != '\0') {
          if (cVar6 != -0xd) goto LAB_4010fb2d;
          goto LAB_4010ff69;
        }
        FUN_4010e334(puVar13);
        if (_DAT_3ffc6340 != 0) {
          _DAT_3ffc6340 = _DAT_3ffc6340 + -1;
          memw();
        }
        uVar15 = (uint)*(ushort *)((int)puVar13 + 0x5e) * 2;
        uVar14 = (uint)*(ushort *)((int)puVar13 + 0x5e) << 2;
        uVar7 = 0x111c;
        if (uVar14 < (uint)(uVar15 < 0x111c) * 0x111c + (uVar15 >= 0x111c) * uVar15) {
          uVar7 = (undefined2)uVar14;
        }
        else if (0x111c < uVar15) {
          uVar7 = (undefined2)uVar15;
        }
        *(undefined2 *)(puVar13 + 0x1d) = uVar7;
        memw();
      }
      else {
        if (uVar14 != 7) {
          if (uVar14 < 7) {
            FUN_4010e334(puVar13);
            if ((DAT_3ffc633c & 0x20) == 0) goto LAB_4010f82c;
            *(ushort *)((int)puVar13 + 0x46) = *(ushort *)((int)puVar13 + 0x46) | 2;
            memw();
            memw();
            FUN_4010d2e0(puVar13);
            puVar10 = _DAT_3ffc840c;
            if (puVar13 != _DAT_3ffc840c) goto LAB_4010fd2f;
          }
          else {
            if (uVar14 != 8) {
              if ((((uVar14 == 9) && (FUN_4010e334(puVar13), (DAT_3ffc633d & 0x10) != 0)) &&
                  (puVar13[0x1f] == _DAT_3ffc6344)) && (puVar13[0x26] == 0)) {
                DAT_3ffc633c = DAT_3ffc633c | 0x10;
                memw();
                memw();
              }
              goto LAB_4010f82c;
            }
            FUN_4010e334(puVar13);
            if ((((DAT_3ffc633d & 0x10) == 0) || (puVar13[0x1f] != _DAT_3ffc6344)) ||
               (puVar13[0x26] != 0)) goto LAB_4010f82c;
            FUN_4010d2e0(puVar13);
            puVar10 = _DAT_3ffc840c;
            if (puVar13 != _DAT_3ffc840c) goto LAB_4010fd74;
          }
LAB_4010fc84:
          _DAT_3ffc840c = (uint *)puVar13[0xd];
          memw();
          goto LAB_4010fca3;
        }
LAB_4010fc34:
        FUN_4010e334(puVar13);
      }
      if ((DAT_3ffc633c & 0x20) == 0) goto LAB_4010f82c;
      *(ushort *)((int)puVar13 + 0x46) = *(ushort *)((int)puVar13 + 0x46) | 2;
      memw();
      uVar14 = 7;
LAB_4010fbc1:
      puVar13[0xf] = uVar14;
      memw();
      goto LAB_4010f82c;
    }
    if (*param_1 == 0) {
      pcVar23 = "id pbuf";
      uVar19 = 0xc2;
      pcVar22 = "arseopt";
    }
    else {
      FUN_4010ba9c(param_1,0x14);
      sVar16 = _DAT_3ffc6356;
      sVar24 = *(short *)((int)param_1 + 10);
      memw();
      memw();
      _DAT_3ffc6354 = sVar24;
      FUN_4010ba9c(param_1,sVar24);
      uVar8 = sVar16 - sVar24;
      iVar9 = *param_1;
      if (*(ushort *)(iVar9 + 10) < uVar8) goto LAB_4010efe5;
      _DAT_3ffc6350 = *(int *)(iVar9 + 4);
      memw();
      FUN_4010ba9c(iVar9,uVar8);
      sVar16 = (sVar24 + (short)param_1[2]) - sVar16;
      *(short *)(param_1 + 2) = sVar16;
      memw();
      if (*(short *)((int)param_1 + 10) == 0) {
        if (*(short *)(*param_1 + 8) == sVar16) goto LAB_4010f085;
        pcVar23 = "en == 0";
        uVar19 = 0xe0;
        pcVar22 = "arseopt";
      }
      else {
        pcVar23 = "!= NULL";
        uVar19 = 0xdf;
        pcVar22 = "arseopt";
        memw();
      }
    }
  } while( true );
  memw();
  puVar10 = _DAT_3ffc8418;
  while( true ) {
    if (puVar10 == (uint *)0x0) {
      puVar11 = (uint *)0x0;
      puVar13 = _DAT_3ffc841c;
      puVar18 = puVar11;
      puVar20 = puVar11;
      goto LAB_4010f56b;
    }
    if (puVar10[0xf] != 10) break;
    if (((((char)puVar10[0xc] == '\0') ||
         ((char)puVar10[0xc] == (char)(*(char *)(_DAT_3ffc83bc + 0xee) + '\x01'))) &&
        (sVar24 = *_DAT_3ffc6358, (short)puVar10[0x11] == sVar24)) &&
       ((sVar16 = _DAT_3ffc6358[1], *(short *)((int)puVar10 + 0x42) == sVar16 &&
        (DAT_3ffc83e0 == (char)puVar10[0xb])))) {
      bVar2 = false;
      if (DAT_3ffc83e0 == '\x06') {
        bVar1 = bVar2;
        if (((_DAT_3ffc83cc == puVar10[6]) && (_DAT_3ffc83d0 == puVar10[7])) &&
           ((_DAT_3ffc83d4 == puVar10[8] && (_DAT_3ffc83d8 == puVar10[9])))) {
          bVar1 = (char)puVar10[10] == DAT_3ffc83dc;
        }
      }
      else {
        bVar1 = _DAT_3ffc83cc == puVar10[6];
      }
      if ((bVar1) && (DAT_3ffc83f8 == (char)puVar10[5])) {
        if (DAT_3ffc83f8 == '\x06') {
          if ((((_DAT_3ffc83e4 == *puVar10) && (_DAT_3ffc83e8 == puVar10[1])) &&
              (_DAT_3ffc83ec == puVar10[2])) && (_DAT_3ffc83f0 == puVar10[3])) {
            bVar2 = (char)puVar10[4] == DAT_3ffc83f4;
          }
        }
        else {
          bVar2 = _DAT_3ffc83e4 == *puVar10;
        }
        if (bVar2) {
          if ((bVar5 & 4) != 0) goto LAB_4010efe5;
          uVar14 = (uint)_DAT_3ffc633e;
          if ((bVar5 & 2) == 0) {
            if ((bVar5 & 1) != 0) {
              puVar10[0x13] = _DAT_3ffc8414;
            }
          }
          else if ((-1 < (int)((int)_DAT_3ffc6348 - puVar10[0x14])) &&
                  ((int)(((int)_DAT_3ffc6348 - puVar10[0x14]) - (uint)(ushort)puVar10[0x15]) < 1)) {
            iVar9 = uVar14 + (int)_DAT_3ffc6348;
            goto LAB_4010f502;
          }
          if (uVar14 == 0) goto LAB_4010efe5;
          *(ushort *)((int)puVar10 + 0x46) = *(ushort *)((int)puVar10 + 0x46) | 2;
          memw();
          goto LAB_4010f549;
        }
      }
    }
    puVar10 = (uint *)puVar10[0xd];
  }
  pcVar23 = " cache)";
  uVar19 = 0x11f;
  pcVar22 = "arseopt";
  goto LAB_4010efbb;
LAB_4010f56b:
  puVar12 = puVar13;
  if (puVar12 == (uint *)0x0) goto code_r0x4010f56d;
  puVar17 = puVar10;
  puVar21 = puVar20;
  if (((((char)puVar12[0xc] == '\0') ||
       ((char)puVar12[0xc] == (char)(*(char *)(_DAT_3ffc83bc + 0xee) + '\x01'))) &&
      (*(short *)((int)puVar12 + 0x42) == _DAT_3ffc6358[1])) &&
     ((puVar17 = puVar12, puVar21 = puVar18, (char)puVar12[5] != '.' &&
      (puVar17 = puVar10, puVar21 = puVar20, DAT_3ffc83f8 == (char)puVar12[5])))) {
    uVar14 = *puVar12;
    if (DAT_3ffc83f8 == '\x06') {
      if (((_DAT_3ffc83e4 == uVar14) && (_DAT_3ffc83e8 == puVar12[1])) &&
         ((_DAT_3ffc83ec == puVar12[2] &&
          ((_DAT_3ffc83f0 == puVar12[3] && ((char)puVar12[4] == DAT_3ffc83f4))))))
      goto LAB_4010f5f1;
      puVar13 = puVar11;
      if ((uVar14 == 0) && ((puVar12[1] == 0 && (puVar12[2] == 0)))) {
        puVar13 = (uint *)(uint)(puVar12[3] == 0);
      }
    }
    else {
      if (_DAT_3ffc83e4 == uVar14) goto LAB_4010f5f1;
      puVar13 = (uint *)(uint)(uVar14 == 0);
    }
    if (puVar13 != (uint *)0x0) {
      puVar17 = puVar12;
      puVar21 = puVar18;
    }
  }
  puVar13 = (uint *)puVar12[0xd];
  puVar10 = puVar17;
  puVar18 = puVar12;
  puVar20 = puVar21;
  goto LAB_4010f56b;
code_r0x4010f56d:
  puVar12 = puVar10;
  puVar18 = puVar20;
  if (puVar10 == (uint *)0x0) {
    memw();
    uVar14 = FUN_40185288(_DAT_3ffc6358[6]);
    if ((uVar14 & 4) == 0) {
      iVar9 = (uint)_DAT_3ffc633e + (int)_DAT_3ffc6348;
      sVar24 = *_DAT_3ffc6358;
      sVar16 = _DAT_3ffc6358[1];
      memw();
LAB_4010f502:
      memw();
      FUN_40110c08(puVar10,_DAT_3ffc6344,iVar9,&DAT_3ffc83e4,&DAT_3ffc83cc,sVar16,sVar24);
    }
  }
  else {
LAB_4010f5f1:
    if (puVar18 != (uint *)0x0) {
      puVar18[0xd] = puVar12[0xd];
      puVar12[0xd] = (uint)_DAT_3ffc841c;
      _DAT_3ffc841c = puVar12;
    }
    if ((bVar5 & 4) == 0) {
      if ((bVar5 & 0x10) != 0) {
        iVar9 = (uint)_DAT_3ffc633e + (int)_DAT_3ffc6348;
        sVar24 = *psVar4;
        sVar16 = psVar4[1];
        memw();
        puVar10 = puVar12;
        goto LAB_4010f502;
      }
      if (((bVar5 & 2) != 0) && (*(byte *)((int)puVar12 + 0x49) < (byte)puVar12[0x12])) {
        puVar10 = (uint *)FUN_4010d734((char)puVar12[0x10]);
        if (puVar10 == (uint *)0x0) {
          if ((code *)puVar12[0x11] != (code *)0x0) {
            (*(code *)puVar12[0x11])(puVar12[0xe],0,0xffffffff);
          }
        }
        else {
          *(char *)((int)puVar12 + 0x49) = *(char *)((int)puVar12 + 0x49) + '\x01';
          memw();
          *(ushort *)((int)puVar10 + 0x46) = *(ushort *)((int)puVar10 + 0x46) | 0x200;
          cVar6 = DAT_3ffc83f8;
          memw();
          *(char *)(puVar10 + 5) = DAT_3ffc83f8;
          memw();
          *puVar10 = _DAT_3ffc83e4;
          if (cVar6 == '\x06') {
            puVar10[1] = _DAT_3ffc83e8;
            puVar10[2] = _DAT_3ffc83ec;
            puVar10[3] = _DAT_3ffc83f0;
            cVar6 = DAT_3ffc83f4;
          }
          else {
            puVar10[3] = 0;
            puVar10[2] = 0;
            puVar10[1] = 0;
            memw();
            cVar6 = '\0';
          }
          *(char *)(puVar10 + 4) = cVar6;
          cVar6 = DAT_3ffc83e0;
          uVar14 = _DAT_3ffc83cc;
          memw();
          *(char *)(puVar10 + 0xb) = DAT_3ffc83e0;
          memw();
          puVar10[6] = uVar14;
          if (cVar6 == '\x06') {
            puVar10[7] = _DAT_3ffc83d0;
            puVar10[8] = _DAT_3ffc83d4;
            cVar6 = DAT_3ffc83dc;
            puVar10[9] = _DAT_3ffc83d8;
          }
          else {
            cVar6 = '\0';
            puVar10[9] = 0;
            puVar10[8] = 0;
            puVar10[7] = 0;
            memw();
          }
          *(char *)(puVar10 + 10) = cVar6;
          psVar4 = _DAT_3ffc6358;
          memw();
          *(undefined2 *)((int)puVar10 + 0x42) = *(undefined2 *)((int)puVar12 + 0x42);
          memw();
          *(short *)(puVar10 + 0x11) = *psVar4;
          memw();
          puVar10[0xf] = 3;
          uVar14 = (int)_DAT_3ffc6348 + 1;
          puVar10[0x14] = uVar14;
          puVar10[0x16] = uVar14;
          memw();
          uVar14 = FUN_4010cf50(puVar10);
          puVar10[0x20] = (int)_DAT_3ffc6348 - 1;
          uVar15 = puVar12[0xe];
          puVar10[0x21] = uVar14;
          puVar10[0x1f] = uVar14;
          puVar10[0x1c] = uVar14;
          puVar10[0x22] = uVar14;
          puVar10[0xe] = uVar15;
          puVar10[0x2a] = (uint)puVar12;
          *(byte *)((int)puVar10 + 0x31) = *(byte *)((int)puVar12 + 0x31) & 0xc;
          memw();
          *(char *)(puVar10 + 0xc) = (char)puVar12[0xc];
          memw();
          puVar10[0xd] = (uint)_DAT_3ffc840c;
          memw();
          _DAT_3ffc840c = puVar10;
          FUN_40113284();
          DAT_3ffc8408 = 1;
          memw();
          memw();
          FUN_4010e180(puVar10);
          sVar24 = _DAT_3ffc6358[7];
          *(short *)(puVar10 + 0x23) = sVar24;
          *(short *)((int)puVar10 + 0x8e) = sVar24;
          memw();
          uVar7 = *(undefined2 *)((int)puVar10 + 0x5e);
          if ((char)puVar10[0xb] == '\x06') {
            memw();
            uVar19 = FUN_401172d4();
          }
          else {
            uVar19 = FUN_401167b0(puVar10,puVar10 + 6);
          }
          uVar7 = FUN_4010cf7c(uVar7,uVar19,puVar10 + 6);
          *(undefined2 *)((int)puVar10 + 0x5e) = uVar7;
          memw();
          memw();
          cVar6 = FUN_40110868(puVar10,0x12);
          if (cVar6 == '\0') {
LAB_4010f549:
            memw();
            FUN_40112a70(puVar10);
          }
          else {
            FUN_4010d3fc(puVar10,0);
          }
        }
      }
    }
  }
LAB_4010efe5:
  memw();
  FUN_4010bb10(param_1);
  goto LAB_4010ff80;
  while (puVar10 = (uint *)puVar11[0xd], puVar13 != (uint *)puVar11[0xd]) {
LAB_4010fca0:
    puVar11 = puVar10;
    if (puVar11 == (uint *)0x0) goto LAB_4010fca3;
  }
  goto LAB_4010fc93;
  while (puVar10 = (uint *)puVar11[0xd], puVar13 != (uint *)puVar11[0xd]) {
LAB_4010fd2f:
    puVar11 = puVar10;
    if (puVar11 == (uint *)0x0) goto LAB_4010fca3;
  }
  goto LAB_4010fc93;
  while (puVar10 = (uint *)puVar11[0xd], puVar13 != (uint *)puVar11[0xd]) {
LAB_4010fd74:
    puVar11 = puVar10;
    if (puVar11 == (uint *)0x0) goto LAB_4010fca3;
  }
LAB_4010fc93:
  puVar11[0xd] = puVar13[0xd];
  memw();
LAB_4010fca3:
  DAT_3ffc8408 = 1;
  memw();
  puVar13[0xf] = 10;
  puVar13[0xd] = (uint)_DAT_3ffc8418;
  memw();
  _DAT_3ffc8418 = puVar13;
  FUN_40113284();
LAB_4010f82c:
  if ((DAT_3ffc633c & 8) != 0) {
    if ((code *)puVar13[0x2f] != (code *)0x0) {
      memw();
      (*(code *)puVar13[0x2f])(puVar13[0xe],0xfffffff2);
    }
    FUN_4010d33c(&DAT_3ffc840c,puVar13);
    FUN_4010ca80(puVar13);
    goto LAB_4010ff69;
  }
  if (_DAT_3ffc6340 != 0) {
    if (((code *)puVar13[0x2b] != (code *)0x0) &&
       (cVar6 = (*(code *)puVar13[0x2b])(puVar13[0xe],puVar13), cVar6 == -0xd)) goto LAB_4010ff69;
    _DAT_3ffc6340 = 0;
    memw();
  }
  memw();
  iVar9 = FUN_4010e220(puVar13);
  if (iVar9 != 0) goto LAB_4010ff69;
  if (_DAT_3ffc6338 == 0) goto LAB_4010fe09;
  param_1 = (int *)puVar13[0x29];
  if (param_1 != (int *)0x0) {
    pcVar23 = "!= NULL";
    uVar19 = 0x1e6;
    pcVar22 = "arseopt";
    goto LAB_4010efbb;
  }
  if ((*(ushort *)((int)puVar13 + 0x46) & 0x10) == 0) {
    if ((code *)puVar13[0x2c] == (code *)0x0) {
      cVar6 = FUN_4010da34(0,puVar13,_DAT_3ffc6338,0);
    }
    else {
      cVar6 = (*(code *)puVar13[0x2c])(puVar13[0xe],puVar13);
    }
    if (cVar6 != -0xd) {
      if (cVar6 != '\0') {
        puVar13[0x29] = _DAT_3ffc6338;
      }
LAB_4010fe09:
      if ((DAT_3ffc633c & 0x20) != 0) {
        uVar14 = puVar13[0x29];
        if (uVar14 == 0) {
          if ((short)puVar13[0x15] != 0x1680) {
            *(short *)(puVar13 + 0x15) = (short)puVar13[0x15] + 1;
            memw();
          }
          if ((code *)puVar13[0x2c] != (code *)0x0) {
            memw();
            cVar6 = (*(code *)puVar13[0x2c])(puVar13[0xe],puVar13,0);
            if (cVar6 == -0xd) goto LAB_4010ff69;
            if (cVar6 == -1) {
              *(ushort *)((int)puVar13 + 0x46) = *(ushort *)((int)puVar13 + 0x46) | 8;
              memw();
              memw();
            }
          }
        }
        else {
          *(byte *)(uVar14 + 0xd) = *(byte *)(uVar14 + 0xd) | 0x20;
          memw();
        }
      }
      _DAT_3ffc8420 = (uint *)0x0;
      memw();
      iVar9 = FUN_4010e220(puVar13);
      if (iVar9 == 0) {
        FUN_40112a70(puVar13);
      }
    }
  }
  else {
    FUN_4010bb10(_DAT_3ffc6338);
LAB_4010fb2d:
    memw();
    FUN_4010d4dc(puVar13);
  }
LAB_4010ff69:
  _DAT_3ffc8420 = (uint *)0x0;
  _DAT_3ffc6338 = 0;
  if (_DAT_3ffc6360 != (int *)0x0) {
    memw();
    FUN_4010bb10();
    _DAT_3ffc6360 = (int *)0x0;
  }
LAB_4010ff80:
  memw();
  return;
}

