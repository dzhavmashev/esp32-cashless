// Function : FUN_4012481c
// Address  : 0x4012481c
// Size     : 916 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4012481c(int param_1,undefined1 *param_2,uint param_3,int param_4,int param_5,int param_6,
                 uint param_7,int param_8,int param_9,uint param_10)

{
  bool bVar1;
  undefined2 uVar2;
  int iVar3;
  uint uVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  uint uVar8;
  uint uVar9;
  undefined4 uVar10;
  int iVar11;
  uint uVar12;
  undefined1 uVar13;
  undefined1 *puVar14;
  undefined1 *in_t0;
  undefined1 *puStack_74;
  uint uStack_64;
  undefined1 auStack_44 [16];
  undefined1 auStack_34 [16];
  undefined1 *puStack_24;
  
  memw();
  memw();
  puStack_24 = _DAT_3ffc5708;
  if (((param_10 == 0) && (param_10 = 3, (*(uint *)(param_2 + 0x1bc) & 0x18580) == 0)) &&
     (param_10 = 1, *(int *)(param_2 + 0x1b8) != 2)) {
    param_10 = 2;
  }
  uVar12 = param_3 & 8;
  bVar1 = param_10 - 2 < 2;
  iVar3 = 0;
  uVar4 = param_7;
  if (param_9 != 0 && bVar1) {
    uVar4 = param_7 & 0x80000007;
    if ((int)uVar4 < 0) {
      uVar4 = (uVar4 - 1 | 0xfffffff8) + 1;
    }
    iVar3 = 0;
    if (uVar4 != 0) {
      iVar3 = 8 - uVar4;
    }
    uVar4 = param_7 + iVar3 + 8;
  }
  uVar8 = uVar4 + 99;
  memw();
  puVar5 = (undefined1 *)(*(code *)&SUB_40094dd8)(1,uVar8);
  puVar14 = in_t0;
  if (puVar5 == (undefined1 *)0x0) goto LAB_40124b21;
  uVar13 = 0xfe;
  uStack_64 = uVar8 & 0xffff;
  *puVar5 = (char)*(undefined4 *)(param_1 + 0x2c);
  puVar5[1] = 3;
  memw();
  uVar9 = uStack_64 - 4 & 0xffff;
  iVar11 = *(int *)(param_2 + 0x1b4);
  *(ushort *)(puVar5 + 2) = (ushort)(uVar9 << 8) | (ushort)(uVar9 >> 8);
  memw();
  if (iVar11 == 2) {
    uVar13 = 2;
  }
  param_3 = param_10 | param_3;
  puVar5[4] = uVar13;
  memw();
  if (param_9 == 0) {
    if (iVar11 != 2) goto LAB_40124919;
  }
  else {
    uVar9 = 0x1000;
    if (iVar11 != 2) {
LAB_40124919:
      uVar9 = param_8 << 4;
    }
    param_3 = param_3 | uVar9;
    memw();
  }
  puVar5[5] = (char)(param_3 >> 8);
  puVar5[6] = (char)param_3;
  memw();
  if (uVar12 == 0) {
    uVar10 = *(undefined4 *)(param_1 + 0x10);
    if (iVar11 == 2) {
      puVar5[7] = 0;
      puVar5[8] = 0;
      memw();
      goto LAB_40124966;
    }
  }
  else {
    uVar10 = *(undefined4 *)(param_2 + 0x1b8);
  }
  memw();
  uVar2 = FUN_4018511c(uVar10);
  puVar5[7] = (char)((ushort)uVar2 >> 8);
  puVar5[8] = (char)uVar2;
  memw();
  memw();
LAB_40124966:
  *(undefined4 *)(param_2 + 0x150) = *(undefined4 *)(param_2 + 0x144);
  memw();
  (*(code *)&SUB_4008b3d0)(param_2 + 0x148,param_2 + 0x13c,8);
  *(undefined4 *)(param_2 + 0x144) = *(undefined4 *)(param_2 + 0x138);
  memw();
  (*(code *)&SUB_4008b3d0)(param_2 + 0x13c,param_2 + 0x130,8);
  puVar14 = param_2 + 0x124;
  *(undefined4 *)(param_2 + 0x138) = *(undefined4 *)(param_2 + 300);
  memw();
  (*(code *)&SUB_4008b3d0)(param_2 + 0x130,puVar14,8);
  FUN_40185048(puVar14,8);
  (*(code *)&SUB_4008b3d0)(puVar5 + 9,puVar14,8);
  *(undefined4 *)(param_2 + 300) = 1;
  if (param_5 != 0) {
    memw();
    (*(code *)&SUB_4008b3d0)(puVar5 + 0x11,param_5,0x20);
  }
  if (param_4 != 0) {
    (*(code *)&SUB_4008b3d0)(puVar5 + 0x41,param_4,8);
  }
  if (param_9 == 0) {
    if (param_6 != 0) {
      (*(code *)&SUB_4008b3d0)(puVar5 + 99,param_6,param_7);
      puVar5[0x61] = (char)(param_7 >> 8);
      puVar5[0x62] = (char)param_7;
      memw();
    }
  }
  else if ((param_6 != 0) && (param_9 != 0)) {
    puVar6 = (undefined1 *)(*(code *)&SUB_40094dd8)(1,uVar4);
    puStack_74 = puVar6;
    if (puVar6 == (undefined1 *)0x0) goto LAB_40124ac5;
    (*(code *)&SUB_4008b3d0)(puVar6,param_6,param_7);
    if (iVar3 != 0) {
      puVar6[param_7] = 0xdd;
      memw();
    }
    puVar14 = param_2 + 0xc4;
    puVar7 = puVar5 + 99;
    if (!bVar1) goto LAB_40124b3b;
    iVar3 = uVar4 - 8;
    if ((int)(uVar4 - 8) < 0) {
      iVar3 = uVar4 - 1;
    }
    memw();
    iVar3 = FUN_40102614(puVar14,0x10,iVar3 >> 3,puVar6,puVar7);
    if (iVar3 == 0) goto LAB_40124b96;
    (*(code *)&SUB_40094d80)(puVar5);
    goto LAB_40124b1b;
  }
  do {
    if ((param_3 & 0x100) == 0) {
LAB_40124a57:
      iVar3 = (*(code *)&SUB_40094d60)(0x100);
      if (iVar3 != 0) {
        (*(code *)&SUB_4008b3d0)(iVar3,param_2 + 8,6);
        (*(code *)&SUB_4008b3d0)(iVar3 + 6,param_1 + 0x5c);
        *(undefined2 *)(iVar3 + 0xc) = 0x8e88;
        memw();
        memw();
        (*(code *)&SUB_4008b3d0)(iVar3 + 0xe,puVar5,uVar8);
        FUN_40153080(1,iVar3,uStack_64 + 0xe & 0xffff);
        (*(code *)&SUB_40094d80)(iVar3);
      }
    }
    else if (*(int *)(param_2 + 0x114) != 0) {
      memw();
      FUN_40106090(param_2 + 0xac,*(undefined4 *)(param_2 + 0x104),*(undefined4 *)(param_2 + 0x1bc),
                   param_10,puVar5,uVar8,puVar5 + 0x51);
      goto LAB_40124a57;
    }
LAB_40124ac5:
    memw();
    puVar6 = puVar5;
LAB_40124b1b:
    (*(code *)&SUB_40094d80)(puVar6);
    puVar14 = in_t0;
LAB_40124b21:
    param_2 = puStack_24;
    puVar7 = _DAT_3ffc5708;
    memw();
    memw();
    if (puStack_24 == _DAT_3ffc5708) {
      return;
    }
    (*(code *)&SUB_40082ec4)();
    in_t0 = puVar14;
LAB_40124b3b:
    iVar3 = *(int *)(param_2 + 4);
    memw();
    (*(code *)&SUB_4008b3d0)(puVar5 + 0x31,iVar3 + 0x34,0x10);
    FUN_40185048(iVar3 + 0x24,0x20);
    (*(code *)&SUB_4008b3d0)(auStack_44,puVar5 + 0x31,0x10);
    (*(code *)&SUB_4008b3d0)(auStack_34,puVar14,0x10);
    (*(code *)&SUB_4008b3d0)(puVar7,puStack_74,uVar4);
    FUN_40102340(auStack_44,0x20,0x100,puVar7,uVar4);
LAB_40124b96:
    puVar5[0x61] = (char)(uVar4 >> 8);
    puVar5[0x62] = (char)uVar4;
    memw();
    memw();
    (*(code *)&SUB_40094d80)(puStack_74);
  } while( true );
}

