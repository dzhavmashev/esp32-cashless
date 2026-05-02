// Function : FUN_4011b80c
// Address  : 0x4011b80c
// Size     : 1331 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4011b80c(undefined4 param_1,undefined4 param_2,int *param_3)

{
  bool bVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  undefined1 *puVar5;
  int *piVar6;
  uint uVar7;
  uint *puVar8;
  int iVar9;
  ushort uVar10;
  int iVar11;
  uint uVar12;
  undefined4 *puVar13;
  char *pcVar14;
  undefined1 *puVar15;
  undefined4 *puVar16;
  ushort uVar17;
  undefined4 *puVar18;
  int *piVar19;
  uint uVar20;
  char *pcVar21;
  uint uStack_38;
  undefined1 auStack_34 [52];
  
  if (param_3 == (int *)0x0) {
    return;
  }
  uVar7 = (uint)*(ushort *)(param_3 + 2);
  iVar3 = (uint)(uVar7 < 0x224) * 0x224 + (uVar7 >= 0x224) * uVar7;
  memw();
  iVar4 = FUN_4010af90((int)(short)iVar3);
  if (iVar4 == 0) {
    FUN_4010bb10(param_3);
    return;
  }
  (*(code *)&SUB_4008b530)(iVar4,0,(int)(short)iVar3);
  iVar9 = param_3[2];
  iVar11 = param_3[1];
  uVar7 = 0;
  while (uVar7 < *(ushort *)((int)param_3 + 10)) {
    puVar15 = (undefined1 *)(iVar11 + uVar7);
    puVar5 = (undefined1 *)(iVar4 + uVar7);
    uVar7 = uVar7 + 1 & 0xffff;
    *puVar5 = *puVar15;
    memw();
    memw();
  }
  if (*param_3 != 0) {
    iVar11 = *(int *)(*param_3 + 4);
    uVar12 = 0;
    while (uVar20 = uVar7 + uVar12, uVar12 < *(ushort *)(*param_3 + 10)) {
      puVar5 = (undefined1 *)(iVar11 + uVar12);
      uVar12 = uVar12 + 1 & 0xffff;
      *(undefined1 *)(iVar4 + (uVar20 & 0xffff)) = *puVar5;
      memw();
      memw();
    }
  }
  memw();
  iVar11 = (*(code *)&SUB_4008b33c)(iVar4 + 0xec,"ps_pool",4);
  if (iVar11 != 0) goto LAB_4011b874;
  uVar12 = _DAT_3ffbe0dc * 0x3c;
  _DAT_3ffc653c = _DAT_3ffc6538;
  DAT_3ffc6530 = '\0';
  memw();
  uVar7 = _DAT_3ffc6528;
  if (_DAT_3ffc6534 == (undefined4 *)0x0) {
    memw();
    _DAT_3ffc653c = _DAT_3ffc6528;
  }
  else {
    bVar1 = false;
    puVar16 = _DAT_3ffc6534;
    do {
      puVar8 = (uint *)*puVar16;
      memw();
      iVar11 = (*(code *)&SUB_4008b33c)(puVar8 + 1,iVar4 + 0x1c,6);
      uVar20 = *puVar8;
      if (iVar11 == 0) {
        memw();
        iVar11 = (*(code *)&SUB_4008b33c)(puVar8,iVar4 + 0xc,4);
        if (iVar11 == 0) {
          DAT_3ffc6530 = '\x01';
          memw();
        }
        puVar8[3] = uVar12;
        _DAT_3ffc653c = uVar20;
        goto LAB_4011b940;
      }
      if (_DAT_3ffc6538 == uVar20) {
        iVar11 = FUN_40109eec();
        _DAT_3ffc6538 = FUN_40109eec(iVar11 + 1);
        _DAT_3ffc653c = _DAT_3ffc6538;
      }
      if (!bVar1) {
        if (uVar7 < *puVar8) {
          bVar1 = true;
          memw();
        }
        else {
          memw();
          iVar11 = FUN_40109eec(uVar7);
          uVar7 = FUN_40109eec(iVar11 + 1);
        }
      }
      puVar16 = (undefined4 *)puVar16[1];
    } while (puVar16 != (undefined4 *)0x0);
  }
  if (_DAT_3ffc652c < _DAT_3ffc6538) {
    _DAT_3ffc653c = uVar7;
  }
  if (_DAT_3ffc652c < _DAT_3ffc653c) {
    puVar16 = (undefined4 *)0x0;
    _DAT_3ffc6538 = _DAT_3ffc6528;
    puVar8 = (uint *)0x0;
    memw();
  }
  else {
    memw();
    puVar8 = (uint *)FUN_4010af90(0x10);
    (*(code *)&SUB_4008b530)(puVar8,0,0x10);
    *puVar8 = _DAT_3ffc653c;
    memw();
    (*(code *)&SUB_4008b3d0)(puVar8 + 1,iVar4 + 0x1c,6);
    puVar8[3] = uVar12;
    memw();
    puVar16 = (undefined4 *)FUN_4010af90(8);
    puVar16[1] = 0;
    puVar18 = _DAT_3ffc6534;
    *puVar16 = puVar8;
    puVar13 = puVar16;
    if (puVar18 != (undefined4 *)0x0) {
      if (*puVar8 < *(uint *)*puVar18) {
        puVar16[1] = puVar18;
        memw();
      }
      else {
        do {
          puVar13 = puVar18;
          puVar18 = (undefined4 *)puVar13[1];
          if (puVar18 == (undefined4 *)0x0) goto LAB_4011bac5;
        } while (*(uint *)*puVar18 <= *puVar8);
        puVar16[1] = puVar18;
LAB_4011bac5:
        puVar13[1] = puVar16;
        memw();
        puVar13 = _DAT_3ffc6534;
      }
    }
    _DAT_3ffc6534 = puVar13;
    if (_DAT_3ffc653c == _DAT_3ffc652c) {
      _DAT_3ffc6538 = _DAT_3ffc6528;
      memw();
    }
    else {
      memw();
      iVar11 = FUN_40109eec();
      _DAT_3ffc6538 = FUN_40109eec(iVar11 + 1);
      memw();
    }
  }
LAB_4011b940:
  if ((_DAT_3ffc652c < _DAT_3ffc653c) || (_DAT_3ffc653c == 0)) {
    if (puVar16 != (undefined4 *)0x0) {
      memw();
      FUN_40185520(&DAT_3ffc6534,puVar16);
      (*(code *)&SUB_40094d80)(puVar16);
    }
    if (puVar8 != (uint *)0x0) {
      (*(code *)&SUB_40094d80)(puVar8);
    }
LAB_4011b97a:
    FUN_4011b4a0(iVar4);
    *(undefined1 *)(iVar4 + 0xf0) = 0x35;
    *(undefined1 *)(iVar4 + 0xf1) = 1;
    *(undefined1 *)(iVar4 + 0xf2) = 6;
    memw();
    *(undefined1 *)(iVar4 + 0xf3) = 0xff;
    memw();
    memw();
    piVar6 = (int *)FUN_4011b7f4(iVar3);
    if (piVar6 == (int *)0x0) goto LAB_4011b874;
    uVar7 = 0;
    piVar19 = piVar6;
    do {
      iVar3 = piVar19[1];
      uVar12 = 0;
      while (uVar20 = uVar12 + uVar7 & 0xffff, uVar12 < *(ushort *)((int)piVar19 + 10)) {
        puVar5 = (undefined1 *)(iVar3 + uVar12);
        uVar12 = uVar12 + 1 & 0xffff;
        *puVar5 = *(undefined1 *)(iVar4 + uVar20);
        memw();
        memw();
      }
      piVar19 = (int *)*piVar19;
      uVar7 = uVar20;
    } while (piVar19 != (int *)0x0);
LAB_4011bbbc:
    (*(code *)&SUB_4008b530)(auStack_34,0,0x14);
    uStack_38 = _DAT_3ffc6548;
    memw();
    FUN_40113c24(*(undefined4 *)(_DAT_3ffc654c + 0xd4),piVar6,&uStack_38,0x44);
  }
  else {
    pcVar14 = (char *)(iVar4 + 0xf0);
    uStack_38 = _DAT_3ffc653c;
    pcVar21 = pcVar14 + (short)((short)iVar9 + -0xf0);
    uVar17 = 5;
    uVar7 = 0;
    for (; pcVar14 < pcVar21; pcVar14 = pcVar14 + (byte)pcVar14[1] + 2) {
      cVar2 = *pcVar14;
      if (cVar2 == '5') {
        uVar7 = (uint)(byte)pcVar14[2];
      }
      else {
        if (cVar2 == -1) break;
        if (cVar2 == '2') {
          memw();
          iVar9 = (*(code *)&SUB_4008b33c)(&uStack_38,pcVar14 + 2,4);
          uVar17 = 4;
          if (iVar9 == 0) {
            uVar17 = 3;
          }
        }
      }
    }
    if (uVar7 == 3) {
      if ((uVar17 == 5) && (uVar17 = 4, DAT_3ffc6530 != '\0')) {
        uVar17 = 3;
      }
    }
    else {
      if (uVar7 < 4) {
        iVar9 = uVar7 - 1;
        uVar10 = 1;
      }
      else {
        if (uVar7 == 4) {
          uVar17 = 5;
          goto LAB_4011bb20;
        }
        iVar9 = uVar7 - 7;
        uVar10 = 6;
      }
      if (iVar9 == 0) {
        uVar17 = uVar10;
      }
    }
LAB_4011bb20:
    if ((uVar17 & 0xfffd) == 4) {
      if (puVar16 != (undefined4 *)0x0) {
        memw();
        FUN_40185520(&DAT_3ffc6534,puVar16);
        (*(code *)&SUB_40094d80)(puVar16);
      }
      if (puVar8 != (uint *)0x0) {
        (*(code *)&SUB_40094d80)(puVar8);
      }
      _DAT_3ffc653c = 0;
    }
    if (uVar17 != 3) {
      if (uVar17 == 4) goto LAB_4011b97a;
      if (uVar17 != 1) goto LAB_4011b874;
      memw();
      FUN_4011b4a0(iVar4);
      *(undefined1 *)(iVar4 + 0xf0) = 0x35;
      *(undefined1 *)(iVar4 + 0xf2) = 2;
      *(undefined1 *)(iVar4 + 0xf1) = 1;
      memw();
      memw();
      puVar5 = (undefined1 *)FUN_4011b564(iVar4 + 0xf3);
      *puVar5 = 0xff;
      memw();
      memw();
      piVar6 = (int *)FUN_4011b7f4(iVar3);
      if (piVar6 == (int *)0x0) goto LAB_4011b874;
      uVar7 = 0;
      piVar19 = piVar6;
      do {
        iVar3 = piVar19[1];
        uVar12 = 0;
        while (uVar20 = uVar12 + uVar7 & 0xffff, uVar12 < *(ushort *)((int)piVar19 + 10)) {
          puVar5 = (undefined1 *)(iVar3 + uVar12);
          uVar12 = uVar12 + 1 & 0xffff;
          *puVar5 = *(undefined1 *)(iVar4 + uVar20);
          memw();
          memw();
        }
        piVar19 = (int *)*piVar19;
        uVar7 = uVar20;
      } while (piVar19 != (int *)0x0);
      goto LAB_4011bbbc;
    }
    FUN_4011b4a0(iVar4);
    *(undefined1 *)(iVar4 + 0xf0) = 0x35;
    *(undefined1 *)(iVar4 + 0xf1) = 1;
    *(undefined1 *)(iVar4 + 0xf2) = 5;
    memw();
    memw();
    puVar5 = (undefined1 *)FUN_4011b564(iVar4 + 0xf3);
    *puVar5 = 0xff;
    memw();
    memw();
    piVar6 = (int *)FUN_4011b7f4(iVar3);
    if (piVar6 == (int *)0x0) goto LAB_4011b874;
    uVar7 = 0;
    piVar19 = piVar6;
    do {
      iVar3 = piVar19[1];
      uVar12 = 0;
      while (uVar20 = uVar12 + uVar7 & 0xffff, uVar12 < *(ushort *)((int)piVar19 + 10)) {
        puVar5 = (undefined1 *)(iVar3 + uVar12);
        uVar12 = uVar12 + 1 & 0xffff;
        *puVar5 = *(undefined1 *)(iVar4 + uVar20);
        memw();
        memw();
      }
      piVar19 = (int *)*piVar19;
      uVar7 = uVar20;
    } while (piVar19 != (int *)0x0);
    (*(code *)&SUB_4008b530)(auStack_34,0,0x14);
    uStack_38 = _DAT_3ffc6548;
    memw();
    cVar2 = FUN_40113c24(*(undefined4 *)(_DAT_3ffc654c + 0xd4),piVar6,&uStack_38,0x44);
    if (cVar2 == '\0') {
      (*_DAT_3ffc651c)(iVar4 + 0x10);
    }
  }
  if (*(char *)((int)piVar6 + 0xe) != '\0') {
    FUN_4010bb10(piVar6);
  }
LAB_4011b874:
  FUN_4010bb10(param_3);
  (*(code *)&SUB_40094d80)(iVar4);
  return;
}

