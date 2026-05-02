// Function : FUN_40152468
// Address  : 0x40152468
// Size     : 896 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_40152468(int *param_1,int param_2)

{
  ushort *puVar1;
  undefined2 uVar2;
  int iVar3;
  undefined2 *puVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  undefined2 *puVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  int iVar15;
  uint uVar16;
  undefined4 local_50;
  undefined2 uStack_4c;
  undefined2 *apuStack_48 [2];
  int iStack_40;
  ushort *puStack_3c;
  int iStack_38;
  int iStack_34;
  ushort *puStack_30;
  
  iStack_34 = param_2;
  if ((param_1 == (int *)0x0) || (iStack_40 = *param_1, iStack_40 == 0)) {
    memw();
    FUN_40147fe4(1,0x800,1,"",&PTR_LAB_3f423ddc,0xb48);
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  iStack_38 = FUN_401521a8(3);
  memw();
  iVar3 = FUN_401517dc(3);
  iVar5 = _DAT_3ffbfc54;
  uVar14 = 0;
  uVar6 = (uint)*(byte *)(iStack_40 + 0x169);
  iVar15 = uVar6 + 0x2e;
  if (7 < uVar6) {
    iVar15 = 0x36;
    uVar14 = 0;
    if (uVar6 != 8) {
      uVar14 = uVar6 - 6 & 0xffff;
    }
  }
  uVar6 = 0;
  if (_DAT_3ffc881c != (ushort *)0x0) {
    uVar6 = (uint)*_DAT_3ffc881c;
  }
  uVar13 = 0;
  uVar8 = 0;
  if (_DAT_3ffc8830 == (ushort *)0x0) {
    uVar13 = 0;
    if (_DAT_3ffc8824 != (ushort *)0x0) {
      uVar13 = (uint)*_DAT_3ffc8824;
    }
    if (_DAT_3ffc8828 == (ushort *)0x0) {
      uVar8 = 0;
    }
    else {
      uVar8 = (uint)*_DAT_3ffc8828;
    }
  }
  puStack_3c = _DAT_3ffc8854;
  if (_DAT_3ffc8854 != (ushort *)0x0) {
    puStack_3c = (ushort *)(uint)*_DAT_3ffc8854;
  }
  uVar16 = 0;
  if (_DAT_3ffc8830 != (ushort *)0x0) {
    uVar16 = (uint)*_DAT_3ffc8830;
  }
  if (_DAT_3ffc8864 == 0) {
    iVar11 = 0;
    iVar9 = 0;
  }
  else {
    iVar11 = 0x47;
    iVar9 = 0x27;
    if (_DAT_3ffc1a40 == 0) {
      iVar9 = 0;
    }
  }
  iVar12 = 0;
  if ((_DAT_3ffc8884 != 0) && (iVar12 = 0, *(int *)(_DAT_3ffc8884 + 4) != 0)) {
    iVar12 = *(byte *)(_DAT_3ffc8884 + 8) + 10;
  }
  iVar7 = 0;
  if (_DAT_3ffc8a64 != 0) {
    iVar7 = 0x20;
  }
  uVar6 = (int)puStack_3c +
          iVar7 + iVar12 + iVar9 + iVar11 + uVar16 + uVar8 + uVar13 + uVar6 + iVar15 + uVar14 + 
                                                  iStack_38 + iVar3 + 0x65 & 0xffff;
  memw();
  iVar3 = FUN_4015f5c0(apuStack_48,0x18,uVar6);
  if (iVar3 == 0) {
    FUN_40147fe4(1,0x40,2,0x3f436ad6,uVar6);
  }
  else {
    *(undefined2 *)(iVar3 + 0x14) = 0x18;
    memw();
    memw();
    uVar2 = FUN_401523bc(param_1);
    iVar15 = _DAT_3ffbfc54;
    *apuStack_48[0] = uVar2;
    memw();
    puVar4 = apuStack_48[0] + 2;
    apuStack_48[0][1] = *(undefined2 *)(iVar15 + 0x9a);
    memw();
    if (iStack_34 == 0x20) {
      puVar10 = apuStack_48[0] + 5;
      memw();
      apuStack_48[0] = puVar4;
      (*(code *)&SUB_4008b3d0)(puVar4,param_1 + 1,6);
      puVar4 = puVar10;
    }
    apuStack_48[0] = puVar4;
    iVar15 = *(int *)(iVar5 + 4);
    *(undefined1 *)apuStack_48[0] = 0;
    puVar4 = apuStack_48[0] + 1;
    *(char *)((int)apuStack_48[0] + 1) = (char)iVar15;
    memw();
    if (iVar15 != 0) {
      memw();
      puVar4 = (undefined2 *)(*(code *)&SUB_4008b3d0)(puVar4,iVar5 + 8,iVar15);
    }
    apuStack_48[0] = (undefined2 *)((int)puVar4 + iVar15);
    memw();
    apuStack_48[0] = (undefined2 *)FUN_40151fe8(apuStack_48[0],(int)param_1 + 0x73);
    if ((((DAT_3ffc89ed < 0xe) && ((1 << (DAT_3ffc89ed & 0x1f) & 0x27b0U) != 0)) &&
        (_DAT_3ffc8828 != (ushort *)0x0)) && (_DAT_3ffc8830 == (ushort *)0x0)) {
      puStack_30 = _DAT_3ffc8828;
      memw();
      iVar5 = (*(code *)&SUB_4008b3d0)
                        (apuStack_48[0],_DAT_3ffc8828 + 1,*(byte *)((int)_DAT_3ffc8828 + 3) + 2);
      apuStack_48[0] = (undefined2 *)(iVar5 + *(byte *)((int)puStack_30 + 3) + 2);
    }
    memw();
    apuStack_48[0] = (undefined2 *)FUN_40152040(apuStack_48[0],(int)param_1 + 0x73);
    if (((*(uint *)(iStack_40 + 0x158) & 0x80000) != 0) && ((param_1[3] & 0xc0U) != 0)) {
      memw();
      iVar5 = FUN_4014d650();
      if (iVar5 != 0) {
        apuStack_48[0] = (undefined2 *)FUN_4014bd38(apuStack_48[0],param_1);
      }
    }
    puVar1 = _DAT_3ffc8824;
    if ((((byte)(DAT_3ffc89ed - 2) < 2) || (DAT_3ffc89ed == 6)) &&
       ((_DAT_3ffc8824 != (ushort *)0x0 && (_DAT_3ffc8830 == (ushort *)0x0)))) {
      memw();
      iVar5 = (*(code *)&SUB_4008b3d0)
                        (apuStack_48[0],_DAT_3ffc8824 + 1,*(byte *)((int)_DAT_3ffc8824 + 3) + 2);
      apuStack_48[0] = (undefined2 *)(iVar5 + *(byte *)((int)puVar1 + 3) + 2);
    }
    if ((((DAT_3ffc89ec == '\a') || ((byte)(DAT_3ffc89ed - 0xb) < 2)) && (_DAT_3ffc8a64 != 0)) &&
       (*(code **)(_DAT_3ffc8a64 + 8) != (code *)0x0)) {
      memw();
      iVar5 = (**(code **)(_DAT_3ffc8a64 + 8))(apuStack_48[0]);
      apuStack_48[0] = (undefined2 *)((int)apuStack_48[0] + iVar5);
    }
    if (((*(uint *)(iStack_40 + 0xa4) & 0x2000) != 0) && ((param_1[3] & 2U) != 0)) {
      puVar4 = (undefined2 *)((int)apuStack_48[0] + 9);
      memw();
      (*(code *)&SUB_4008b3d0)(apuStack_48[0],&DAT_3f423dfd,9);
      apuStack_48[0] = puVar4;
    }
    if (((*(uint *)(iStack_40 + 0x158) & 0x10000000) != 0) && ((param_1[3] & 0xc0U) != 0)) {
      memw();
      apuStack_48[0] = (undefined2 *)FUN_4014bd74(apuStack_48[0],param_1);
    }
    if (_DAT_3ffc8854 != (ushort *)0x0) {
      memw();
      apuStack_48[0] = (undefined2 *)FUN_401517c4(apuStack_48[0]);
    }
    memw();
    apuStack_48[0] = (undefined2 *)FUN_40152070(apuStack_48[0],&DAT_3ffc87f0);
    if ((_DAT_3ffc8830 != (ushort *)0x0) && (*(int *)(_DAT_3ffca40c + 8) == 2)) {
      memw();
      apuStack_48[0] = (undefined2 *)FUN_401517c4();
    }
    if (_DAT_3ffc8864 != 0) {
      local_50 = 0;
      uStack_4c = 0;
      memw();
      memw();
      FUN_4014eb04(0,&local_50);
      apuStack_48[0] = (undefined2 *)(*_DAT_3ffc79e4)(apuStack_48[0],&local_50);
      if (_DAT_3ffc1a40 != 0) {
        memw();
        apuStack_48[0] = (undefined2 *)(*_DAT_3ffc79f0)(0,apuStack_48[0],&local_50);
      }
    }
    if ((_DAT_3ffc8884 != 0) && (*(int *)(_DAT_3ffc8884 + 4) != 0)) {
      memw();
      apuStack_48[0] =
           (undefined2 *)
           FUN_4014c140(apuStack_48[0],_DAT_3ffc8884 + 1,*(int *)(_DAT_3ffc8884 + 4),
                        *(undefined1 *)(_DAT_3ffc8884 + 8));
    }
    memw();
    apuStack_48[0] = (undefined2 *)FUN_401521c0(apuStack_48[0],3);
    memw();
    apuStack_48[0] = (undefined2 *)FUN_40152170(apuStack_48[0],3);
    uVar14 = (int)apuStack_48[0] -
             (*(int *)(*(int *)(iVar3 + 4) + 4) + (uint)*(ushort *)(iVar3 + 0x14));
    *(short *)(iVar3 + 0x16) = (short)uVar14;
    memw();
    if (uVar6 < (uVar14 & 0xffff)) {
      memw();
      FUN_40147fe4(1,0x800,1,"",&PTR_LAB_3f423ddc,0xbe8);
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
  }
  return iVar3;
}

