// Function : FUN_40152804
// Address  : 0x40152804
// Size     : 639 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40152804(int *param_1,int param_2)

{
  undefined2 uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  byte bVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  undefined4 local_40;
  undefined2 uStack_3c;
  undefined2 *apuStack_38 [2];
  int iStack_30;
  int iStack_2c;
  
  if ((param_1 == (int *)0x0) || (iVar6 = *param_1, iVar6 == 0)) {
    FUN_40147fe4(1,0x800,1,"",&PTR_LAB_3f423ddc,0xbf8);
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  iStack_2c = FUN_401521a8(4);
  memw();
  iVar2 = FUN_401517dc(4);
  uVar8 = 0;
  uVar3 = (uint)*(byte *)(iVar6 + 0x169);
  iVar9 = uVar3 + 8;
  if (7 < uVar3) {
    iVar9 = 0x10;
    uVar8 = 0;
    if (uVar3 != 8) {
      uVar8 = uVar3 - 6 & 0xffff;
    }
  }
  uVar3 = 0;
  if (_DAT_3ffc8858 != (ushort *)0x0) {
    uVar3 = (uint)*_DAT_3ffc8858;
  }
  if (_DAT_3ffc8864 == 0) {
    iVar4 = 0;
    iVar11 = 0;
    iVar10 = 0;
  }
  else {
    iVar11 = 0x27;
    iVar10 = 0x17;
    iVar4 = 0x47;
    if (_DAT_3ffc1a40 == 0) {
      iVar11 = 0;
    }
  }
  iVar7 = 0;
  if ((_DAT_3ffc8888 != 0) && (iVar7 = 0, *(int *)(_DAT_3ffc8888 + 4) != 0)) {
    iVar7 = *(byte *)(_DAT_3ffc8888 + 8) + 10;
  }
  uVar3 = iVar7 + iVar11 + iVar10 + iVar4 + uVar3 + iVar9 + uVar8 + iStack_2c + iVar2 + 0x59 &
          0xffff;
  memw();
  iStack_30 = iVar6 + 0x100;
  iVar2 = FUN_4015f5c0(apuStack_38,0x18,uVar3);
  if (iVar2 != 0) {
    *(undefined2 *)(iVar2 + 0x14) = 0x18;
    memw();
    memw();
    uVar1 = FUN_401523bc(param_1);
    *apuStack_38[0] = uVar1;
    apuStack_38[0][1] = (short)param_2;
    memw();
    if (param_2 == 0) {
      apuStack_38[0][2] = *(undefined2 *)((int)param_1 + 0x26);
      memw();
    }
    apuStack_38[0] = apuStack_38[0] + 3;
    memw();
    apuStack_38[0] = (undefined2 *)FUN_40151fe8(apuStack_38[0],(int)param_1 + 0x73);
    memw();
    apuStack_38[0] = (undefined2 *)FUN_40152040(apuStack_38[0],(int)param_1 + 0x73);
    if (((byte)(*(char *)(iStack_30 + 0x68) - 2U) < 2) &&
       ((byte)(*(char *)((int)param_1 + 0x31) - 2U) < 2)) {
      *(undefined1 *)apuStack_38[0] = 0x2a;
      *(undefined1 *)((int)apuStack_38[0] + 1) = 1;
      memw();
      bVar5 = 2;
      if ((_DAT_3ffc880c & 0x100000) == 0) {
        bVar5 = 0;
      }
      if ((_DAT_3ffc880c & 0x200000) != 0) {
        bVar5 = bVar5 | 4;
      }
      *(byte *)(apuStack_38[0] + 1) = bVar5;
      memw();
      apuStack_38[0] = (undefined2 *)((int)apuStack_38[0] + 3);
    }
    if (((*(uint *)(iVar6 + 0x158) & 0x80000) != 0) && ((param_1[3] & 0x40U) != 0)) {
      memw();
      apuStack_38[0] = (undefined2 *)FUN_4014bd38(apuStack_38[0],param_1);
      memw();
      apuStack_38[0] = (undefined2 *)FUN_4014bef8(apuStack_38[0],param_1);
    }
    if (((*(uint *)(iVar6 + 0xa4) & 0x2000) != 0) && ((param_1[3] & 2U) != 0)) {
      memw();
      apuStack_38[0] = (undefined2 *)FUN_401520b8(apuStack_38[0],0);
    }
    if ((param_1[3] & 0xc0U) == 0xc0) {
      memw();
      apuStack_38[0] = (undefined2 *)FUN_4014bd74(apuStack_38[0],param_1);
      memw();
      apuStack_38[0] = (undefined2 *)FUN_4014bf3c(apuStack_38[0],param_1);
    }
    if (_DAT_3ffc8858 != (ushort *)0x0) {
      memw();
      apuStack_38[0] = (undefined2 *)FUN_401517c4(apuStack_38[0]);
    }
    if (_DAT_3ffc8864 != 0) {
      local_40 = 0;
      uStack_3c = 0;
      memw();
      memw();
      FUN_4014eb04(1,&local_40);
      apuStack_38[0] = (undefined2 *)(*_DAT_3ffc79e4)(apuStack_38[0],&local_40);
      memw();
      apuStack_38[0] = (undefined2 *)(*_DAT_3ffc79e8)(apuStack_38[0],&local_40);
      if (_DAT_3ffc1a40 != 0) {
        memw();
        apuStack_38[0] = (undefined2 *)(*_DAT_3ffc79f0)(0x10,apuStack_38[0],&local_40);
      }
    }
    if ((_DAT_3ffc8888 != 0) && (*(int *)(_DAT_3ffc8888 + 4) != 0)) {
      memw();
      apuStack_38[0] =
           (undefined2 *)
           FUN_4014c140(apuStack_38[0],_DAT_3ffc8888 + 1,*(int *)(_DAT_3ffc8888 + 4),
                        *(undefined1 *)(_DAT_3ffc8888 + 8));
    }
    memw();
    apuStack_38[0] = (undefined2 *)FUN_401521c0(apuStack_38[0],4);
    memw();
    apuStack_38[0] = (undefined2 *)FUN_40152170(apuStack_38[0],4);
    uVar8 = (int)apuStack_38[0] -
            (*(int *)(*(int *)(iVar2 + 4) + 4) + (uint)*(ushort *)(iVar2 + 0x14));
    *(short *)(iVar2 + 0x16) = (short)uVar8;
    memw();
    if ((uVar8 & 0xffff) <= uVar3) {
      return;
    }
    memw();
    FUN_40147fe4(1,0x800,1,"",&PTR_LAB_3f423ddc,0xc71);
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  FUN_40147fe4(1,0x40,2,0x3f436ac2,uVar3);
  return;
}

