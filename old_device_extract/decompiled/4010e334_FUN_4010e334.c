// Function : FUN_4010e334
// Address  : 0x4010e334
// Size     : 3160 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4010e334(int param_1)

{
  short sVar1;
  short sVar2;
  short sVar3;
  ushort uVar4;
  short sVar5;
  undefined2 uVar6;
  ushort uVar7;
  int iVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  int *piVar11;
  uint uVar12;
  undefined4 *puVar13;
  int iVar14;
  int *piVar15;
  short sVar16;
  uint uVar17;
  int iVar18;
  int *piVar19;
  undefined4 uVar20;
  uint uVar21;
  char *pcVar22;
  
  if (param_1 != 0) goto LAB_4010e34c;
  pcVar22 = " length";
  uVar20 = 0x480;
LAB_4010e343:
  while( true ) {
    (*(code *)&SUB_40094c54)("id cseg",uVar20,"egments",pcVar22);
LAB_4010e34c:
    iVar8 = _DAT_3ffc6348;
    iVar14 = _DAT_3ffc6344;
    if (3 < *(uint *)(param_1 + 0x3c)) break;
    pcVar22 = "lid pcb";
    uVar20 = 0x481;
  }
  if ((DAT_3ffc633d & 0x10) != 0) {
    uVar4 = *(ushort *)(param_1 + 0x8c);
    iVar18 = *(int *)(param_1 + 0x84);
    if (((*(int *)(param_1 + 0x80) - _DAT_3ffc6348 < 0) ||
        ((*(int *)(param_1 + 0x80) == _DAT_3ffc6348 && (iVar18 - _DAT_3ffc6344 < 0)))) ||
       ((iVar18 == _DAT_3ffc6344 && ((uint)uVar4 < (uint)*(ushort *)(_DAT_3ffc6358 + 0xe))))) {
      uVar7 = *(ushort *)(_DAT_3ffc6358 + 0xe);
      *(ushort *)(param_1 + 0x8c) = uVar7;
      memw();
      if (*(ushort *)(param_1 + 0x8e) < uVar7) {
        *(ushort *)(param_1 + 0x8e) = uVar7;
        memw();
      }
      *(int *)(param_1 + 0x80) = iVar8;
      *(int *)(param_1 + 0x84) = iVar14;
    }
    uVar21 = iVar14 - *(int *)(param_1 + 0x70);
    if ((int)uVar21 < 1) {
      if ((((_DAT_3ffc633e == 0) &&
           ((uint)*(ushort *)(param_1 + 0x8c) + *(int *)(param_1 + 0x84) == (uint)uVar4 + iVar18))
          && ((*(ushort *)(param_1 + 0x5c) & 0x8000) == 0)) && (*(int *)(param_1 + 0x70) == iVar14))
      {
        if (*(char *)(param_1 + 0x6f) != -1) {
          *(char *)(param_1 + 0x6f) = *(char *)(param_1 + 0x6f) + '\x01';
          memw();
        }
        if (*(byte *)(param_1 + 0x6f) < 4) {
          if (*(byte *)(param_1 + 0x6f) != 3) goto LAB_4010e449;
        }
        else {
          uVar4 = *(ushort *)(param_1 + 0x74) + *(short *)(param_1 + 0x5e);
          if (uVar4 < *(ushort *)(param_1 + 0x74)) {
            uVar4 = 0xffff;
          }
          *(ushort *)(param_1 + 0x74) = uVar4;
          memw();
          memw();
        }
        FUN_40110b90(param_1);
      }
      else {
        *(undefined1 *)(param_1 + 0x6f) = 0;
        memw();
        memw();
      }
    }
    else if (iVar14 - *(int *)(param_1 + 0x7c) < 1) {
      if ((*(ushort *)(param_1 + 0x46) & 4) != 0) {
        *(ushort *)(param_1 + 0x46) = *(ushort *)(param_1 + 0x46) & 0xfffb;
        *(ushort *)(param_1 + 0x74) = *(ushort *)(param_1 + 0x76);
        *(undefined2 *)(param_1 + 0x96) = 0;
        memw();
      }
      uVar21 = uVar21 & 0xffff;
      *(short *)(param_1 + 0x6c) = (*(short *)(param_1 + 0x68) >> 3) + *(short *)(param_1 + 0x6a);
      memw();
      uVar12 = (uint)*(ushort *)(param_1 + 0x74);
      *(undefined2 *)(param_1 + 0x6e) = 0;
      memw();
      *(int *)(param_1 + 0x70) = iVar14;
      if (uVar12 < *(ushort *)(param_1 + 0x76)) {
        iVar14 = 2;
        if ((*(ushort *)(param_1 + 0x46) >> 0xb & 1) != 0) {
          iVar14 = 1;
        }
        uVar17 = (uint)*(ushort *)(param_1 + 0x5e) * iVar14 & 0xffff;
        uVar21 = (uVar17 < uVar21) * uVar17 + (uVar17 >= uVar21) * uVar21;
LAB_4010e572:
        uVar6 = (undefined2)(uVar12 + uVar21);
        if ((uVar12 + uVar21 & 0xffff) < uVar12) {
          uVar6 = 0xffff;
        }
        *(undefined2 *)(param_1 + 0x74) = uVar6;
        memw();
        memw();
      }
      else {
        uVar21 = *(ushort *)(param_1 + 0x96) + uVar21;
        uVar17 = uVar21 & 0xffff;
        sVar3 = (short)uVar21;
        if (uVar17 < *(ushort *)(param_1 + 0x96)) {
          sVar3 = -1;
LAB_4010e638:
          *(ushort *)(param_1 + 0x96) = sVar3 - *(ushort *)(param_1 + 0x74);
          memw();
          uVar21 = (uint)*(ushort *)(param_1 + 0x5e);
          memw();
          goto LAB_4010e572;
        }
        if (uVar12 <= uVar17) goto LAB_4010e638;
        *(short *)(param_1 + 0x96) = sVar3;
        memw();
      }
      memw();
      uVar20 = FUN_4010e26c(param_1 + 0x92,*(undefined4 *)(param_1 + 0x9c),
                            *(undefined4 *)(param_1 + 0x98));
      *(undefined4 *)(param_1 + 0x9c) = uVar20;
      memw();
      iVar14 = FUN_4010e26c(param_1 + 0x92,*(undefined4 *)(param_1 + 0x98),uVar20);
      *(int *)(param_1 + 0x98) = iVar14;
      *(ushort *)(param_1 + 0x5c) = -(ushort)(*(int *)(param_1 + 0x9c) == 0);
      *(undefined1 *)(param_1 + 0x48) = 0;
      memw();
      if (iVar14 == 0) {
        *(undefined2 *)(param_1 + 0x94) = 0;
        memw();
      }
      if (_DAT_3ffc83c4 != 0) {
        memw();
        FUN_4011a828(&DAT_3ffc83cc);
      }
      *(short *)(param_1 + 0x90) = *(short *)(param_1 + 0x90) + _DAT_3ffc6340;
      memw();
      if (((*(ushort *)(param_1 + 0x46) & 0x800) != 0) &&
         (((iVar14 = *(int *)(param_1 + 0x9c), iVar14 == 0 &&
           (iVar14 = *(int *)(param_1 + 0x98), iVar14 == 0)) ||
          (iVar8 = *(int *)(param_1 + 0x78),
          iVar14 = FUN_40109eec(*(undefined4 *)(*(int *)(iVar14 + 0xc) + 4)), iVar8 - iVar14 < 1))))
      {
        *(ushort *)(param_1 + 0x46) = *(ushort *)(param_1 + 0x46) & 0xf7ff;
        memw();
        memw();
      }
    }
    else {
      FUN_40110c68(param_1);
    }
LAB_4010e449:
    sVar3 = _DAT_3ffc8414;
    if ((*(int *)(param_1 + 0x60) != 0) && (*(int *)(param_1 + 100) - _DAT_3ffc6344 < 0)) {
      sVar2 = (short)*(int *)(param_1 + 0x60);
      sVar1 = (short)((uint)(int)*(short *)(param_1 + 0x68) >> 3);
      sVar16 = (_DAT_3ffc8414 - sVar2) - sVar1;
      sVar5 = sVar16 + *(short *)(param_1 + 0x68);
      *(short *)(param_1 + 0x68) = sVar5;
      memw();
      if (sVar16 < 0) {
        sVar16 = sVar1 + (sVar2 - sVar3);
      }
      sVar16 = (*(short *)(param_1 + 0x6a) - (*(short *)(param_1 + 0x6a) >> 2)) + sVar16;
      *(short *)(param_1 + 0x6a) = sVar16;
      *(short *)(param_1 + 0x6c) = sVar16 + (sVar5 >> 3);
      memw();
      *(undefined4 *)(param_1 + 0x60) = 0;
    }
  }
  iVar14 = *(int *)(param_1 + 0x50);
  if ((_DAT_3ffc633e == 0) || (6 < *(uint *)(param_1 + 0x3c))) {
    if ((-1 < _DAT_3ffc6348 - iVar14) &&
       ((int)(((_DAT_3ffc6348 + 1) - iVar14) - (uint)*(ushort *)(param_1 + 0x54)) < 1)) {
      return;
    }
    *(ushort *)(param_1 + 0x46) = *(ushort *)(param_1 + 0x46) | 2;
    memw();
    memw();
    return;
  }
  uVar21 = iVar14 - _DAT_3ffc6348;
  if ((-1 < (int)(uVar21 - 1)) && ((int)(((1 - _DAT_3ffc6348) - (uint)_DAT_3ffc633e) + iVar14) < 1))
  {
    if (_DAT_3ffc6360 == 0) {
      pcVar22 = "g state";
      uVar20 = 0x599;
      memw();
    }
    else if (uVar21 < 0xffff) {
      uVar4 = *(ushort *)(_DAT_3ffc6360 + 8);
      uVar12 = uVar21 & 0xffff;
      if (uVar12 <= uVar4) {
        _DAT_3ffc6364 = _DAT_3ffc6364 - (short)uVar21;
        memw();
        piVar19 = (int *)_DAT_3ffc6360;
        while (*(ushort *)((int)piVar19 + 10) < uVar12) {
          *(ushort *)(piVar19 + 2) = uVar4 - (short)uVar21;
          uVar12 = uVar12 - *(ushort *)((int)piVar19 + 10) & 0xffff;
          *(undefined2 *)((int)piVar19 + 10) = 0;
          memw();
          piVar19 = (int *)*piVar19;
          memw();
        }
        memw();
        FUN_4010ba9c();
        iVar14 = _DAT_3ffc6368;
        iVar8 = *(int *)(param_1 + 0x50);
        _DAT_3ffc6348 = iVar8;
        *(char *)(_DAT_3ffc6368 + 4) = (char)iVar8;
        *(char *)(iVar14 + 5) = (char)((uint)iVar8 >> 8);
        *(char *)(iVar14 + 6) = (char)((uint)iVar8 >> 0x10);
        *(char *)(iVar14 + 7) = (char)((uint)iVar8 >> 0x18);
        memw();
        goto LAB_4010e6f0;
      }
      pcVar22 = "offset!";
      uVar20 = 0x59c;
    }
    else {
      pcVar22 = "!= NULL";
      uVar20 = 0x59a;
    }
    goto LAB_4010e343;
  }
  if (_DAT_3ffc6348 - iVar14 < 0) {
    *(ushort *)(param_1 + 0x46) = *(ushort *)(param_1 + 0x46) | 2;
    memw();
    memw();
  }
LAB_4010e6f0:
  uVar4 = _DAT_3ffc6364;
  iVar14 = *(int *)(param_1 + 0x50);
  if ((_DAT_3ffc6348 - iVar14 < 0) ||
     (0 < (int)(((_DAT_3ffc6348 + 1) - iVar14) - (uint)*(ushort *)(param_1 + 0x54))))
  goto LAB_4010ecf5;
  if (_DAT_3ffc6348 == iVar14) {
    memw();
    uVar21 = FUN_40185288(*(undefined2 *)(_DAT_3ffc6368 + 0xc));
    _DAT_3ffc633e = uVar4 + ((uVar21 & 3) != 0);
    memw();
    if (*(ushort *)(param_1 + 0x54) < _DAT_3ffc633e) {
      memw();
      uVar21 = FUN_40185288(*(undefined2 *)(_DAT_3ffc6368 + 0xc));
      if ((uVar21 & 1) != 0) {
        uVar4 = *(ushort *)(_DAT_3ffc6368 + 0xc);
        uVar21 = FUN_40185288((uint)uVar4);
        uVar21 = FUN_40185288(uVar21 & 0x3e);
        iVar14 = _DAT_3ffc6368;
        uVar21 = uVar4 & 0xffffc0ff | uVar21 & 0xffff;
        *(char *)(_DAT_3ffc6368 + 0xc) = (char)uVar21;
        *(char *)(iVar14 + 0xd) = (char)(uVar21 >> 8);
        memw();
      }
      _DAT_3ffc6364 = *(ushort *)(param_1 + 0x54);
      memw();
      memw();
      uVar21 = FUN_40185288(*(undefined2 *)(_DAT_3ffc6368 + 0xc));
      if ((uVar21 & 2) != 0) {
        _DAT_3ffc6364 = _DAT_3ffc6364 - 1;
        memw();
      }
      memw();
      FUN_4010bd2c(_DAT_3ffc6360,_DAT_3ffc6364);
      uVar4 = _DAT_3ffc6364;
      uVar21 = FUN_40185288(*(undefined2 *)(_DAT_3ffc6368 + 0xc));
      _DAT_3ffc633e = uVar4 + ((uVar21 & 3) != 0);
      memw();
      if ((uint)_DAT_3ffc633e + _DAT_3ffc6348 !=
          (uint)*(ushort *)(param_1 + 0x54) + *(int *)(param_1 + 0x50)) {
        pcVar22 = " short!";
        uVar20 = 0x5d1;
        memw();
        goto LAB_4010e343;
      }
    }
    if (*(int *)(param_1 + 0xa0) != 0) {
      uVar21 = FUN_40185288(*(undefined2 *)(_DAT_3ffc6368 + 0xc));
      if ((uVar21 & 1) == 0) {
        piVar19 = (int *)*(int *)(param_1 + 0xa0);
        while (piVar19 != (int *)0x0) {
          iVar14 = *(int *)(piVar19[3] + 4);
          if ((int)(((uint)_DAT_3ffc633e + _DAT_3ffc6348) -
                   ((uint)*(ushort *)(piVar19 + 2) + iVar14)) < 0) {
            if (0 < (int)(((uint)_DAT_3ffc633e + _DAT_3ffc6348) - iVar14)) {
              _DAT_3ffc6364 = (short)iVar14 - (short)_DAT_3ffc6348;
              memw();
              memw();
              uVar21 = FUN_40185288(*(undefined2 *)(_DAT_3ffc6368 + 0xc));
              if (((uVar21 & 2) != 0) ||
                 (uVar21 = FUN_40185288(*(undefined2 *)(_DAT_3ffc6368 + 0xc)), (uVar21 & 1) != 0)) {
                _DAT_3ffc6364 = _DAT_3ffc6364 - 1;
                memw();
              }
              memw();
              FUN_4010bd2c(_DAT_3ffc6360,_DAT_3ffc6364);
              uVar4 = _DAT_3ffc6364;
              uVar21 = FUN_40185288(*(undefined2 *)(_DAT_3ffc6368 + 0xc));
              _DAT_3ffc633e = uVar4 + ((uVar21 & 3) != 0);
              memw();
              if ((uint)_DAT_3ffc633e + _DAT_3ffc6348 != *(int *)(piVar19[3] + 4)) {
                pcVar22 = "cv_wnd\n";
                uVar20 = 0x605;
                memw();
                goto LAB_4010e343;
              }
            }
            break;
          }
          uVar21 = FUN_40185288(*(undefined2 *)(piVar19[3] + 0xc));
          if (((uVar21 & 1) != 0) &&
             (uVar21 = FUN_40185288(*(undefined2 *)(_DAT_3ffc6368 + 0xc)), (uVar21 & 2) == 0)) {
            uVar4 = *(ushort *)(_DAT_3ffc6368 + 0xc);
            memw();
            uVar21 = FUN_40185288(1);
            iVar14 = _DAT_3ffc6368;
            uVar21 = (uint)uVar4 | uVar21 & 0xffff;
            *(char *)(_DAT_3ffc6368 + 0xd) = (char)(uVar21 >> 8);
            *(char *)(iVar14 + 0xc) = (char)uVar21;
            uVar4 = _DAT_3ffc6364;
            memw();
            memw();
            uVar21 = FUN_40185288();
            _DAT_3ffc633e = uVar4 + ((uVar21 & 3) != 0);
            memw();
          }
          iVar14 = *piVar19;
          memw();
          FUN_4010ce44(piVar19);
          piVar19 = (int *)iVar14;
        }
        *(int **)(param_1 + 0xa0) = piVar19;
        memw();
      }
      else {
        while (*(undefined4 **)(param_1 + 0xa0) != (undefined4 *)0x0) {
          *(undefined4 *)(param_1 + 0xa0) = **(undefined4 **)(param_1 + 0xa0);
          memw();
          FUN_4010ce44();
        }
      }
    }
    uVar4 = _DAT_3ffc633e;
    uVar21 = (uint)_DAT_3ffc633e;
    *(uint *)(param_1 + 0x50) = _DAT_3ffc6348 + uVar21;
    if (uVar21 <= *(ushort *)(param_1 + 0x54)) {
      *(ushort *)(param_1 + 0x54) = *(ushort *)(param_1 + 0x54) - uVar4;
      memw();
      memw();
      FUN_4010cd5c(param_1);
      if (*(short *)(_DAT_3ffc6360 + 8) != 0) {
        _DAT_3ffc6338 = _DAT_3ffc6360;
        _DAT_3ffc6360 = 0;
      }
      memw();
      uVar21 = FUN_40185288(*(undefined2 *)(_DAT_3ffc6368 + 0xc));
      if ((uVar21 & 1) != 0) {
        DAT_3ffc633c = DAT_3ffc633c | 0x20;
        memw();
      }
      memw();
      do {
        puVar9 = *(undefined4 **)(param_1 + 0xa0);
        if (puVar9 == (undefined4 *)0x0) {
LAB_4010ec7c:
          uVar4 = *(ushort *)(param_1 + 0x46);
          uVar7 = uVar4 | 1;
          if ((uVar4 & 1) != 0) {
            uVar7 = uVar4 & 0xfffe | 2;
          }
          *(ushort *)(param_1 + 0x46) = uVar7;
          memw();
          if (_DAT_3ffc83c4 == 0) {
            return;
          }
          memw();
          FUN_4011a828(&DAT_3ffc83cc);
          return;
        }
        iVar14 = *(int *)(puVar9[3] + 4);
        if (iVar14 != *(int *)(param_1 + 0x50)) goto LAB_4010ec7c;
        uVar4 = *(ushort *)(param_1 + 0x54);
        uVar7 = *(ushort *)(puVar9 + 2);
        memw();
        _DAT_3ffc6348 = iVar14;
        uVar21 = FUN_40185288(*(undefined2 *)(puVar9[3] + 0xc));
        if ((uint)uVar4 < (uint)((uVar21 & 3) != 0) + (uint)uVar7) {
          *(undefined2 *)(puVar9 + 2) = *(undefined2 *)(param_1 + 0x54);
          memw();
          memw();
          uVar21 = FUN_40185288(*(undefined2 *)(puVar9[3] + 0xc));
          if (((uVar21 & 2) != 0) ||
             (uVar21 = FUN_40185288(*(undefined2 *)(puVar9[3] + 0xc)), (uVar21 & 1) != 0)) {
            *(short *)(puVar9 + 2) = *(short *)(puVar9 + 2) + -1;
            memw();
          }
          memw();
          FUN_4010bd2c(puVar9[1],*(undefined2 *)(puVar9 + 2));
          FUN_4010ce5c(*puVar9);
          *puVar9 = 0;
        }
        uVar4 = *(ushort *)(puVar9 + 2);
        memw();
        uVar21 = FUN_40185288(*(undefined2 *)(puVar9[3] + 0xc));
        iVar14 = puVar9[3];
        *(uint *)(param_1 + 0x50) =
             (uint)((uVar21 & 3) != 0) + (uint)uVar4 + *(int *)(param_1 + 0x50);
        uVar4 = *(ushort *)(param_1 + 0x54);
        uVar7 = *(ushort *)(puVar9 + 2);
        memw();
        uVar21 = FUN_40185288(*(undefined2 *)(iVar14 + 0xc));
        if ((uint)uVar4 < (uint)((uVar21 & 3) != 0) + (uint)uVar7) goto code_r0x4010eb8d;
        sVar3 = *(short *)(puVar9 + 2);
        memw();
        uVar21 = FUN_40185288(*(undefined2 *)(puVar9[3] + 0xc));
        *(ushort *)(param_1 + 0x54) =
             *(short *)(param_1 + 0x54) - ((ushort)((uVar21 & 3) != 0) + sVar3);
        memw();
        memw();
        FUN_4010cd5c(param_1);
        if (*(short *)(puVar9[1] + 8) != 0) {
          if (_DAT_3ffc6338 == 0) {
            memw();
            _DAT_3ffc6338 = puVar9[1];
          }
          else {
            FUN_4010be44();
          }
          puVar9[1] = 0;
        }
        memw();
        uVar21 = FUN_40185288(*(undefined2 *)(puVar9[3] + 0xc));
        if ((uVar21 & 1) != 0) {
          DAT_3ffc633c = DAT_3ffc633c | 0x20;
          memw();
          if (*(int *)(param_1 + 0x3c) == 4) {
            *(undefined4 *)(param_1 + 0x3c) = 7;
          }
        }
        *(undefined4 *)(param_1 + 0xa0) = *puVar9;
        memw();
        FUN_4010ce44(puVar9);
      } while( true );
    }
    pcVar22 = " queue\n";
    uVar20 = 0x60f;
    memw();
    goto LAB_4010e343;
  }
  piVar19 = *(int **)(param_1 + 0xa0);
  piVar15 = (int *)0x0;
  if (*(int **)(param_1 + 0xa0) != (int *)0x0) {
    do {
      piVar11 = piVar19;
      iVar14 = *(int *)(piVar11[3] + 4);
      if (_DAT_3ffc6348 == iVar14) {
        if ((*(ushort *)(piVar11 + 2) < _DAT_3ffc6364) && (iVar14 = FUN_4010ce70(), iVar14 != 0)) {
          if (piVar15 == (int *)0x0) {
LAB_4010ed59:
            *(int *)(param_1 + 0xa0) = iVar14;
            memw();
          }
          else {
            *piVar15 = iVar14;
          }
LAB_4010ed3f:
          memw();
          FUN_4010e09c(iVar14,piVar11);
        }
        goto LAB_4010ecc8;
      }
      if (piVar15 == (int *)0x0) {
        if (_DAT_3ffc6348 - iVar14 < 0) {
          iVar14 = FUN_4010ce70(&DAT_3ffc635c);
          if (iVar14 != 0) goto LAB_4010ed59;
          goto LAB_4010ecc8;
        }
      }
      else if ((-1 < (_DAT_3ffc6348 + -1) - *(int *)(piVar15[3] + 4)) &&
              ((_DAT_3ffc6348 + 1) - iVar14 < 1)) {
        iVar14 = FUN_4010ce70(&DAT_3ffc635c);
        if (iVar14 != 0) {
          if (0 < (int)(((uint)*(ushort *)(piVar15 + 2) + *(int *)(piVar15[3] + 4)) - _DAT_3ffc6348)
             ) {
            *(short *)(piVar15 + 2) = (short)_DAT_3ffc6348 - (short)*(int *)(piVar15[3] + 4);
            memw();
            memw();
            FUN_4010bd2c(piVar15[1]);
          }
          *piVar15 = iVar14;
          memw();
          goto LAB_4010ed3f;
        }
        goto LAB_4010ecc8;
      }
      piVar19 = (int *)*piVar11;
      piVar15 = piVar11;
    } while ((int *)*piVar11 != (int *)0x0);
    if ((_DAT_3ffc6348 - iVar14 < 1) ||
       (uVar21 = FUN_40185288(*(undefined2 *)(piVar11[3] + 0xc)), (uVar21 & 1) != 0))
    goto LAB_4010ecc8;
    iVar14 = FUN_4010ce70(&DAT_3ffc635c);
    *piVar11 = iVar14;
    if (iVar14 == 0) goto LAB_4010ecc8;
    if (0 < (int)(((uint)*(ushort *)(piVar11 + 2) + *(int *)(piVar11[3] + 4)) - _DAT_3ffc6348)) {
      *(short *)(piVar11 + 2) = (short)_DAT_3ffc6348 - (short)*(int *)(piVar11[3] + 4);
      memw();
      memw();
      FUN_4010bd2c(piVar11[1]);
    }
    if ((int)((((uint)_DAT_3ffc633e + _DAT_3ffc6348) - *(int *)(param_1 + 0x50)) -
             (uint)*(ushort *)(param_1 + 0x54)) < 1) goto LAB_4010ecc8;
    uVar21 = FUN_40185288(*(undefined2 *)(*(int *)(*piVar11 + 0xc) + 0xc));
    if ((uVar21 & 1) != 0) {
      uVar12 = (uint)*(ushort *)(*(int *)(*piVar11 + 0xc) + 0xc);
      uVar21 = FUN_40185288(uVar12);
      uVar21 = FUN_40185288(uVar21 & 0x3e);
      uVar21 = uVar12 & 0xffffc0ff | uVar21 & 0xffff;
      iVar14 = *(int *)(*piVar11 + 0xc);
      *(char *)(iVar14 + 0xc) = (char)uVar21;
      *(char *)(iVar14 + 0xd) = (char)(uVar21 >> 8);
      memw();
    }
    iVar14 = *piVar11;
    *(short *)(iVar14 + 8) =
         (*(short *)(param_1 + 0x54) - (short)_DAT_3ffc6348) +
         (short)*(undefined4 *)(param_1 + 0x50);
    memw();
    memw();
    uVar21 = FUN_40185288(*(undefined2 *)(*(int *)(iVar14 + 0xc) + 0xc));
    iVar14 = *piVar11;
    if ((uVar21 & 2) != 0) {
      *(short *)(iVar14 + 8) = *(short *)(iVar14 + 8) + -1;
      memw();
    }
    memw();
    FUN_4010bd2c(*(undefined4 *)(iVar14 + 4),*(undefined2 *)(iVar14 + 8));
    sVar3 = *(short *)(*piVar11 + 8);
    uVar21 = FUN_40185288(*(undefined2 *)(*(int *)(*piVar11 + 0xc) + 0xc));
    _DAT_3ffc633e = sVar3 + (ushort)((uVar21 & 3) != 0);
    memw();
    if ((uint)_DAT_3ffc633e + _DAT_3ffc6348 ==
        (uint)*(ushort *)(param_1 + 0x54) + *(int *)(param_1 + 0x50)) goto LAB_4010ecc8;
    pcVar22 = " short!";
    uVar20 = 0x71c;
    memw();
    goto LAB_4010e343;
  }
  uVar20 = FUN_4010ce70(&DAT_3ffc635c);
  *(undefined4 *)(param_1 + 0xa0) = uVar20;
LAB_4010ecc8:
  uVar4 = 0;
  puVar9 = *(undefined4 **)(param_1 + 0xa0);
  puVar13 = (undefined4 *)0x0;
  do {
    puVar10 = puVar9;
    if (puVar10 == (undefined4 *)0x0) {
LAB_4010ecf5:
      memw();
      FUN_40110c68(param_1);
      return;
    }
    memw();
    sVar3 = FUN_40185360(puVar10[1]);
    uVar4 = uVar4 + sVar3;
    if (4 < uVar4) {
      FUN_4010ce5c(puVar10);
      if (puVar13 == (undefined4 *)0x0) {
        *(undefined4 *)(param_1 + 0xa0) = 0;
      }
      else {
        *puVar13 = 0;
        memw();
      }
      goto LAB_4010ecf5;
    }
    puVar9 = (undefined4 *)*puVar10;
    puVar13 = puVar10;
  } while( true );
code_r0x4010eb8d:
  pcVar22 = "cv_wnd\n";
  uVar20 = 0x644;
  goto LAB_4010e343;
}

