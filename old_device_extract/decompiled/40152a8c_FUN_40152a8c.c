// Function : FUN_40152a8c
// Address  : 0x40152a8c
// Size     : 657 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_40152a8c(int *param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  undefined2 *puVar3;
  uint *puVar4;
  undefined2 uVar5;
  uint uVar6;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  uint uVar10;
  uint local_50;
  undefined2 uStack_4c;
  undefined2 *puStack_48;
  int local_44;
  int *piStack_40;
  uint uStack_3c;
  uint uStack_38;
  uint uStack_34;
  uint uStack_30;
  
  iVar7 = *param_1;
  uStack_38 = (int)param_2 >> 0x10;
  uStack_34 = param_2 & 0xffff;
  local_44 = -1;
  uVar10 = uStack_38;
  piStack_40 = param_1;
  if (*(int *)(iVar7 + 0x14c) == 0) {
    memw();
    iVar1 = FUN_401594d4();
    uVar10 = uStack_38;
    if ((iVar1 == 0) || (DAT_3ffc89ec != '\x06')) goto LAB_40152b05;
    uStack_30 = 1;
    uVar2 = 0;
    if (uStack_38 == 0) {
      uVar2 = (**(code **)(_DAT_3ffc89a4 + 0x48))(piStack_40 + 1,uStack_34,&local_44);
      uVar10 = uStack_38;
      if (uVar2 == 0) {
        uStack_30 = 0;
        if (local_44 == -1) {
          FUN_40157594(&DAT_3ffc87f0,0,0x100);
          return 0;
        }
        goto LAB_40152b48;
      }
      iVar1 = local_44 + 6;
      uVar8 = 0x18;
      uStack_30 = 1;
      uVar6 = uStack_38;
    }
    else {
LAB_40152b48:
      uVar8 = 0x18;
      iVar1 = 6;
      uVar6 = uVar2;
      uStack_38 = uVar2;
    }
  }
  else {
LAB_40152b05:
    uStack_38 = 0;
    if ((uStack_34 - 2 < 2) && (*(int *)(iVar7 + 0xb0) != 0)) {
      uStack_38 = 1;
    }
    if (((int)uStack_34 < 3) && (uStack_38 == 0)) {
      uVar6 = 0;
      if (uStack_34 == 1) {
        uVar6 = (uint)(DAT_3ffc89ec == '\x02');
      }
    }
    else {
      uVar6 = 1;
    }
    if ((uVar10 == 0) && (uStack_38 != 0)) {
      uVar2 = 0;
      iVar1 = 0x88;
      uVar8 = 0x1c;
      uStack_30 = 0;
      uStack_38 = 1;
    }
    else {
      uVar2 = 0;
      iVar1 = 6;
      uVar8 = 0x18;
      uStack_30 = 0;
    }
  }
  iVar9 = 0;
  if (_DAT_3ffc8864 != 0) {
    iVar9 = 0x47;
    memw();
    if (DAT_3ffc1a3c != 0) {
      iVar9 = 0;
    }
  }
  memw();
  uStack_3c = uStack_38;
  uStack_38 = uVar10;
  iVar1 = FUN_4015f5c0(&puStack_48,uVar8,iVar1 + iVar9);
  if (iVar1 == 0) {
    FUN_40147fe4(1,0x40,2,0x3f436ab8);
    return 0;
  }
  *(undefined2 *)(iVar1 + 0x14) = 0x18;
  memw();
  if (uVar6 == 0) {
    if (uStack_30 == 0) {
      *puStack_48 = 0;
      goto LAB_40152bcc;
    }
    uVar5 = 3;
  }
  else {
    uVar5 = 1;
    memw();
  }
  *puStack_48 = uVar5;
  memw();
  memw();
LAB_40152bcc:
  puStack_48[1] = (short)param_2;
  memw();
  if (((uStack_30 == 0) || (DAT_3ffc8a69 == '\0')) || (uStack_34 != 1)) {
    puStack_48[2] = (short)uStack_38;
    memw();
  }
  else {
    puStack_48[2] = 0x7e;
    memw();
    memw();
  }
  if ((uStack_38 == 0) && ((uStack_3c & 1) != 0)) {
    uVar8 = *(undefined4 *)(iVar7 + 0xb0);
    puStack_48[3] = 0x8010;
    memw();
    memw();
    (*(code *)&SUB_4008b3d0)(puStack_48 + 4,uVar8,0x80);
    *(undefined2 *)(iVar1 + 0x16) = 0x88;
    memw();
    *(int *)(*(int *)(iVar1 + 4) + 4) = *(int *)(*(int *)(iVar1 + 4) + 4) + 0x1c;
    memw();
    puVar3 = (undefined2 *)FUN_40147b98(piStack_40,iVar1);
    *(int *)(*(int *)(iVar1 + 4) + 4) = *(int *)(*(int *)(iVar1 + 4) + 4) + -0x18;
    puVar4 = *(uint **)(iVar1 + 0x2c);
    if (puVar3 == (undefined2 *)0x0) {
      puVar4[4] = puVar4[4] & 0xfffff0ff;
      memw();
    }
    else {
      *puVar4 = *puVar4 | 1;
      if (iVar7 == _DAT_3ffc8804) {
        *(byte *)(*(int *)(iVar1 + 0x2c) + 0x10) = (byte)*puVar3 | 0x40;
        memw();
        memw();
      }
      else {
        *(byte *)(*(int *)(iVar1 + 0x2c) + 0x10) = (byte)*puVar3;
        memw();
      }
      *(uint *)(*(int *)(iVar1 + 0x2c) + 0x10) =
           *(uint *)(*(int *)(iVar1 + 0x2c) + 0x10) & 0xfffff0ff |
           (**(byte **)(puVar3 + 0x50) & 0xf) << 8;
      memw();
    }
  }
  else {
    *(undefined2 *)(iVar1 + 0x16) = 6;
    memw();
  }
  iVar7 = local_44;
  if ((uVar2 != 0) && ((uStack_30 & 1) != 0)) {
    memw();
    (*(code *)&SUB_4008b3d0)(puStack_48 + 3,uVar2,local_44);
    *(short *)(iVar1 + 0x16) = (short)iVar7 + *(short *)(iVar1 + 0x16);
    memw();
  }
  if (_DAT_3ffc8864 != 0) {
    memw();
    local_50 = (uint)DAT_3ffc1a3c;
    if (DAT_3ffc1a3c == 0) {
      puStack_48 = (undefined2 *)((int)puStack_48 + (uint)*(ushort *)(iVar1 + 0x16));
      uStack_4c = 0;
      memw();
      memw();
      FUN_4014eb04(0,&local_50);
      (*_DAT_3ffc79e4)(puStack_48,&local_50);
      *(short *)(iVar1 + 0x16) = *(short *)(iVar1 + 0x16) + 0x47;
      memw();
    }
  }
  memw();
  return iVar1;
}

