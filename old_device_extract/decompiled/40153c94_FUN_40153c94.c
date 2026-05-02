// Function : FUN_40153c94
// Address  : 0x40153c94
// Size     : 561 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_40153c94(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,byte param_6,byte param_7,byte param_8)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint *puVar6;
  uint uVar7;
  uint uVar8;
  undefined1 *puVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  ushort uVar14;
  undefined1 *apuStack_50 [4];
  uint uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  uint uStack_30;
  int iStack_2c;
  
  uVar5 = (uint)param_6;
  uStack_30 = (uint)param_7;
  uStack_40 = (uint)param_8;
  memw();
  uStack_3c = param_3;
  uStack_38 = param_4;
  uStack_34 = param_5;
  iStack_2c = FUN_401521a8(1);
  iVar4 = _DAT_3ffc8800;
  memw();
  iVar1 = FUN_401517dc(1);
  iVar10 = 0;
  uVar7 = (uint)*(byte *)(iVar4 + 0x169);
  iVar3 = uVar7 + 0x24;
  if (7 < uVar7) {
    iVar3 = 0x2c;
    iVar10 = 0;
    if (uVar7 != 8) {
      iVar10 = uVar7 - 6;
    }
  }
  uVar7 = 0;
  if (_DAT_3ffc8850 != (ushort *)0x0) {
    uVar7 = (uint)*_DAT_3ffc8850;
  }
  uVar11 = 0;
  if (_DAT_3ffc882c != (ushort *)0x0) {
    uVar11 = (uint)*_DAT_3ffc882c;
  }
  uVar8 = 0;
  if (_DAT_3ffc8818 != (ushort *)0x0) {
    uVar8 = (uint)*_DAT_3ffc8818;
  }
  iVar13 = 0;
  if (_DAT_3ffc8864 != 0) {
    iVar13 = 0x47;
  }
  iVar12 = 0;
  if ((_DAT_3ffc887c != 0) && (iVar12 = 0, *(int *)(_DAT_3ffc887c + 4) != 0)) {
    iVar12 = *(byte *)(_DAT_3ffc887c + 8) + 10;
  }
  iVar1 = FUN_4015f5c0(apuStack_50,0x18,
                       iStack_2c + iVar1 + uVar8 + uVar11 + uVar7 + iVar10 + iVar3 + iVar13 + iVar12
                      );
  if (iVar1 == 0) {
    uVar14 = 0;
    if (_DAT_3ffc8850 != (ushort *)0x0) {
      uVar14 = *_DAT_3ffc8850;
    }
    FUN_40147fe4(1,0x40,2,0x3f436aea,uVar14);
    return 1;
  }
  *(undefined2 *)(iVar1 + 0x14) = 0x18;
  memw();
  iVar4 = iVar4 + 0x169;
  *apuStack_50[0] = 0;
  puVar9 = apuStack_50[0] + 2;
  apuStack_50[0][1] = param_6;
  memw();
  if (uVar5 != 0) {
    memw();
    puVar9 = (undefined1 *)(*(code *)&SUB_4008b3d0)(puVar9,uStack_34,uVar5);
  }
  apuStack_50[0] = puVar9 + uVar5;
  memw();
  apuStack_50[0] = (undefined1 *)FUN_40151fe8(apuStack_50[0],iVar4);
  memw();
  apuStack_50[0] = (undefined1 *)FUN_40152040(apuStack_50[0],iVar4);
  memw();
  apuStack_50[0] = (undefined1 *)FUN_40152090(apuStack_50[0],&DAT_3ffc87f0);
  if (_DAT_3ffc8850 != (ushort *)0x0) {
    memw();
    apuStack_50[0] = (undefined1 *)FUN_401517c4();
  }
  if (_DAT_3ffc882c != (ushort *)0x0) {
    memw();
    apuStack_50[0] = (undefined1 *)FUN_401517c4(apuStack_50[0]);
  }
  if (_DAT_3ffc8864 != 0) {
    memw();
    apuStack_50[0] = (undefined1 *)(*_DAT_3ffc79e4)(apuStack_50[0],param_2);
  }
  if ((_DAT_3ffc887c != 0) && (*(int *)(_DAT_3ffc887c + 4) != 0)) {
    memw();
    apuStack_50[0] =
         (undefined1 *)
         FUN_4014c140(apuStack_50[0],_DAT_3ffc887c + 1,*(int *)(_DAT_3ffc887c + 4),
                      *(undefined1 *)(_DAT_3ffc887c + 8));
  }
  memw();
  apuStack_50[0] = (undefined1 *)FUN_401521c0(apuStack_50[0],1);
  memw();
  apuStack_50[0] = (undefined1 *)FUN_40152170(apuStack_50[0],1);
  puVar6 = *(uint **)(iVar1 + 4);
  uVar14 = *(ushort *)(iVar1 + 0x14);
  uVar5 = (int)apuStack_50[0] - (puVar6[1] + (uint)uVar14);
  *(short *)(iVar1 + 0x16) = (short)uVar5;
  memw();
  memw();
  memw();
  *puVar6 = *puVar6 | 0x80000000;
  memw();
  memw();
  *puVar6 = *puVar6 | 0x40000000;
  memw();
  memw();
  *puVar6 = *puVar6 & 0xdfffffff;
  memw();
  memw();
  *puVar6 = *puVar6 & 0xff000fff | ((uint)uVar14 + (uVar5 & 0xffff) & 0xfff) << 0xc;
  memw();
  FUN_40151c80(param_1,iVar1,0x40,0x10,param_2,uStack_3c,uStack_38);
  FUN_40153a2c(param_1,iVar1,7,0x10,uStack_40);
  *(uint *)(*(int *)(iVar1 + 0x2c) + 0x10) =
       *(uint *)(*(int *)(iVar1 + 0x2c) + 0x10) & 0xfffdffff | (uStack_40 & 1) << 0x11;
  *(int *)(*(int *)(iVar1 + 0x2c) + 0x14) = 1 << 0x20 - (0x20 - (uStack_30 & 0x1f));
  memw();
  uVar2 = FUN_4015fb20(iVar1);
  return uVar2;
}

