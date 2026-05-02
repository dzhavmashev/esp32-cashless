// Function : FUN_40188b88
// Address  : 0x40188b88
// Size     : 714 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40188b88(int param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  uint *puVar9;
  undefined1 *puVar10;
  undefined1 *puVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  int iVar15;
  int iVar16;
  undefined1 auStack_70 [40];
  int iStack_48;
  int iStack_40;
  uint uStack_3c;
  int iStack_38;
  undefined1 *puStack_34;
  int iStack_30;
  int iStack_2c;
  
  FUN_40164748(*(undefined4 *)(param_1 + 0x24),*(undefined4 *)(param_1 + 0x2c));
  iStack_40 = *(int *)(param_1 + 0x24);
  bVar1 = (byte)(*(char *)(*(int *)(param_1 + 0x24) + 0x82) - 4U) < 2;
  uVar4 = *(uint *)(*(int *)(param_1 + 0x2c) + 0x10) >> 0x14 & 0xf;
  iVar6 = _DAT_3ffc0034 + uVar4 * 0x30;
  *(undefined1 *)(iVar6 + 0x4c) = 0;
  *(undefined1 *)(iVar6 + 0x41) = 1;
  *(undefined1 *)(iVar6 + 0x40) = 1;
  memw();
  uVar5 = 0;
  *(undefined4 *)(iVar6 + 0x44) = 0;
  *(undefined1 *)(iVar6 + 0x2f) = *(undefined1 *)(param_1 + 0x1b);
  memw();
  iVar6 = 1;
  iStack_48 = param_1;
  uStack_3c = (uint)*(byte *)(*(int *)(*(int *)(param_1 + 4) + 4) + 3);
  memw();
  puVar7 = auStack_70;
  iVar16 = uVar4 * 2;
  while( true ) {
    puVar11 = *(undefined1 **)(puVar7 + 0x28);
    if (puVar11 == (undefined1 *)0x0) goto LAB_40188cc9;
    memw();
    memw();
    **(uint **)(puVar11 + 8) = **(uint **)(puVar11 + 8) & 0xbfffffff;
    memw();
    puStack_34 = puVar11;
    iStack_30 = iVar16;
    iStack_2c = iVar6;
    iVar2 = FUN_40162ea4(iStack_40,uVar5,uStack_3c,puVar11,bVar1);
    puVar11 = puStack_34;
    iVar16 = _DAT_3ffc0034;
    iVar3 = _DAT_3ffc0034 + uVar4 * 0x30;
    iVar6 = iStack_2c;
    if ((((*(char *)(iVar3 + 0x4c) != '\0') && (iStack_2c != 0)) && (bVar1)) &&
       (iVar6 = 1, auStack_70 != puVar7)) {
      memw();
      memw();
      **(uint **)(puVar7 + 8) = **(uint **)(puVar7 + 8) | 0x40000000;
      *(undefined1 *)(iVar3 + 0x41) = 2;
      memw();
      uVar13 = **(uint **)(*(int *)(puVar7 + 4) + 4) & 3;
      uVar14 = 0;
      if (uVar13 != 0) {
        uVar14 = 4 - uVar13 & 0xff;
      }
      *(uint *)(iVar16 + (iStack_30 + uVar4) * 0x10 + 0x44) =
           uVar5 - ((**(uint **)(*(int *)(puVar7 + 4) + 4) >> 0xc & 0x7f) * 4 + uVar14);
      iVar6 = 0;
    }
    if (iVar2 == 0) break;
    uVar5 = uVar5 + iVar2;
    puVar7 = puStack_34;
    iVar16 = iStack_30;
  }
  *(undefined4 *)(*(int *)(puVar7 + 8) + 8) = 0;
  memw();
  puVar10 = puVar7;
  while (puVar8 = *(undefined1 **)(puVar10 + 0x28), puVar8 != (undefined1 *)0x0) {
    *(undefined4 *)(*(int *)(puVar8 + 8) + 8) = 0;
    puVar10 = puVar8;
  }
  *(undefined4 *)(puVar7 + 0x28) = 0;
  iVar2 = iVar16 + uVar4 * 0x30;
  iVar3 = *(int *)(iVar2 + 0x20);
  *(int *)(puVar10 + 0x28) = iVar3;
  if (iVar3 == 0) {
    *(undefined1 **)(iVar2 + 0x24) = puVar10 + 0x28;
  }
  *(undefined1 **)(iVar16 + uVar4 * 0x30 + 0x20) = puVar11;
  memw();
LAB_40188cc9:
  if ((**(uint **)(param_1 + 0x2c) & 0x400000) == 0) {
    puVar9 = *(uint **)(*(int *)(param_1 + 4) + 4);
    memw();
    iStack_2c = iVar6;
    iVar16 = (*(code *)&SUB_4000ab7c)(*puVar9 & 0xfff,4);
    iVar6 = iStack_2c;
    if (uVar5 != (((*puVar9 >> 0xc & 0x7f) + 1) * 4 + iVar16 & 0xffff)) {
      FUN_40147fe4(6,0x800,1,&DAT_3f4010e0,"s_func_app.c",0x9f4);
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
  }
  puVar11 = (undefined1 *)(uVar4 * 3);
  iVar16 = uVar4 * 0x30;
  iStack_38 = iVar16 + 0x20;
  memw();
  while ((puVar10 = *(undefined1 **)(_DAT_3ffc0034 + (int)puVar11 * 0x10 + 0x20),
         puVar10 != (undefined1 *)0x0 && ((**(uint **)(puVar10 + 0x2c) & 0x40000) != 0))) {
    memw();
    puStack_34 = puVar11;
    iStack_30 = iVar16;
    iStack_2c = iVar6;
    FUN_40187d70(puVar10);
    memw();
    memw();
    **(uint **)(puVar10 + 8) = **(uint **)(puVar10 + 8) & 0xbfffffff;
    memw();
    iVar3 = FUN_40162ea4(iStack_40,uVar5,uStack_3c,puVar10,bVar1);
    iVar16 = iStack_30;
    puVar11 = puStack_34;
    iVar2 = _DAT_3ffc0034;
    iVar12 = _DAT_3ffc0034 + iStack_30;
    iVar6 = iStack_2c;
    if ((*(char *)(iVar12 + 0x4c) != '\0') && ((iStack_2c != 0 && (bVar1)))) {
      memw();
      memw();
      **(uint **)(puVar7 + 8) = **(uint **)(puVar7 + 8) | 0x40000000;
      *(undefined1 *)(iVar12 + 0x41) = 2;
      memw();
      uVar13 = **(uint **)(*(int *)(puVar7 + 4) + 4) & 3;
      uVar14 = 0;
      if (uVar13 != 0) {
        uVar14 = 4 - uVar13 & 0xff;
      }
      *(uint *)(iVar2 + (int)puStack_34 * 0x10 + 0x44) =
           uVar5 - ((**(uint **)(*(int *)(puVar7 + 4) + 4) >> 0xc & 0x7f) * 4 + uVar14);
      iVar6 = 0;
    }
    if (iVar3 == 0) break;
    iVar12 = iVar2 + (int)puStack_34 * 0x10;
    iVar15 = *(int *)(*(int *)(iVar12 + 0x20) + 0x28);
    *(int *)(iVar12 + 0x20) = iVar15;
    if (iVar15 == 0) {
      *(int *)(iVar12 + 0x24) = iVar2 + iStack_38;
    }
    uVar5 = uVar5 + iVar3;
    *(undefined1 **)(puVar7 + 0x28) = puVar10;
    *(undefined4 *)(*(int *)(puVar7 + 8) + 8) = *(undefined4 *)(puVar10 + 4);
    *(undefined4 *)(puVar10 + 0x28) = 0;
    puVar7 = puVar10;
  }
  uVar13 = **(uint **)(*(int *)(puVar7 + 4) + 4) & 3;
  uVar14 = 0;
  if (uVar13 != 0) {
    uVar14 = 4 - uVar13 & 0xff;
  }
  uVar5 = uVar5 - ((**(uint **)(*(int *)(puVar7 + 4) + 4) >> 0xc & 0x7f) * 4 + uVar14);
  if (iVar6 == 1) {
    *(uint *)(_DAT_3ffc0034 + uVar4 * 0x30 + 0x44) = uVar5;
  }
  memw();
  FUN_40163a28(param_1,puVar7,uVar5 & 0xffff);
  iVar6 = _DAT_3ffc0034;
  *(int *)(_DAT_3ffc0034 + (uVar4 + 1) * 0x30 + 4) = param_1;
  *(undefined1 *)(iVar6 + uVar4 * 0x30 + 0x29) = 1;
  memw();
  memw();
  return;
}

