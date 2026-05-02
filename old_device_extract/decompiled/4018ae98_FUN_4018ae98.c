// Function : FUN_4018ae98
// Address  : 0x4018ae98
// Size     : 716 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_4018ae98(undefined4 param_1,undefined2 param_2,undefined4 param_3)

{
  undefined1 uVar1;
  undefined1 uVar2;
  char cVar3;
  ushort uVar4;
  bool bVar5;
  ushort uVar6;
  uint uVar7;
  int iVar8;
  undefined1 *puVar9;
  uint *puVar10;
  bool bVar11;
  uint *puVar12;
  uint *puVar13;
  uint uVar14;
  int iVar15;
  uint uVar16;
  uint uVar17;
  int iVar18;
  int iStack_4c;
  
  puVar13 = _DAT_3ffc06fc;
  puVar10 = (uint *)_DAT_3ffc06fc[1];
  memw();
  uVar6 = FUN_4018b754(puVar10);
  uVar7 = uVar6 + 0x18;
  iStack_4c = 0;
  if (uVar6 != 0) {
    puVar9 = (undefined1 *)((int)puVar10 + uVar7);
    memw();
    iStack_4c = FUN_40165300(puVar10 + 6,puVar9);
    if (iStack_4c == 1) {
      uVar1 = *(undefined1 *)((int)puVar10 + 0x19);
      *puVar9 = (char)puVar10[6];
      memw();
      uVar2 = *(undefined1 *)((int)puVar10 + 0x1a);
      puVar9[1] = uVar1;
      memw();
      uVar1 = *(undefined1 *)((int)puVar10 + 0x1b);
      puVar9[2] = uVar2;
      puVar9[3] = uVar1;
      memw();
      memw();
    }
    else if (iStack_4c == 2) {
      uVar6 = 0;
      uVar7 = 0x18;
    }
  }
  bVar5 = true;
  memw();
  do {
    while( true ) {
      memw();
      if (((*puVar13 & 0x40000000) != 0) &&
         ((memw(), (*puVar13 & 0x40000000) == 0 ||
          (memw(), (*puVar13 >> 0xc & 0xfff) <= uVar7 + 0x18)))) goto LAB_4018b155;
      puVar12 = (uint *)(puVar13[1] + uVar7);
      uVar16 = *puVar12 & 0xfff;
      if (0x627 < uVar16 - 0x18) goto LAB_4018b15a;
      memw();
      uVar17 = uVar7 + 4;
      if (uVar17 < (*puVar13 >> 0xc & 0xfff)) {
        uVar4 = (ushort)puVar12[1];
      }
      else {
        uVar4 = **(ushort **)(puVar13[2] + 4);
      }
      uVar14 = uVar16;
      if (((uVar4 & 0x4000) != 0) && (uVar14 = uVar16 - 8, (*puVar10 & 0x30000000) == 0)) {
        uVar14 = uVar16;
      }
      cVar3 = *(char *)((int)puVar12 + 3);
      if (((cVar3 == '\0') || ((byte)(cVar3 + 0x1fU) < 6)) || ((byte)(cVar3 + 0x10U) < 0xd)) break;
      uVar14 = uVar14 + uVar7;
      memw();
      if ((*puVar13 >> 0xc & 0xfff) <= uVar14) {
        memw();
        if ((*puVar13 & 0x40000000) != 0) goto LAB_4018b155;
        memw();
        uVar14 = uVar14 - (*puVar13 >> 0xc & 0xfff);
        puVar13 = (uint *)puVar13[2];
      }
      uVar7 = (*(code *)&SUB_4000ab7c)(uVar14,4);
    }
    memw();
    iVar8 = FUN_4018b928(0,7,uVar16 + 0x1c);
    if (iVar8 == 0) goto LAB_4018b15a;
    (*(code *)&SUB_4008b3d0)(*(undefined4 *)(*(int *)(iVar8 + 4) + 4),puVar10,0x18);
    iVar15 = *(int *)(*(int *)(iVar8 + 4) + 4);
    uVar1 = *(undefined1 *)((int)puVar12 + 1);
    *(char *)(iVar15 + 0x18) = (char)*puVar12;
    memw();
    uVar2 = *(undefined1 *)((int)puVar12 + 2);
    *(undefined1 *)(iVar15 + 0x19) = uVar1;
    memw();
    uVar1 = *(undefined1 *)((int)puVar12 + 3);
    *(undefined1 *)(iVar15 + 0x1a) = uVar2;
    *(undefined1 *)(iVar15 + 0x1b) = uVar1;
    memw();
    memw();
    if (uVar14 + uVar7 < (*puVar13 >> 0xc & 0xfff)) {
      (*(code *)&SUB_4008b3d0)
                (*(int *)(*(int *)(iVar8 + 4) + 4) + 0x1c,puVar13[1] + uVar17,uVar14 - 4);
      iVar15 = (*(code *)&SUB_4000ab7c)(uVar14,4);
      bVar11 = false;
      uVar7 = uVar7 + iVar15;
    }
    else {
      memw();
      iVar15 = (*puVar13 >> 0xc & 0xfff) - uVar7;
      iVar18 = uVar14 - iVar15;
      memw();
      (*(code *)&SUB_4008b3d0)
                (*(int *)(*(int *)(iVar8 + 4) + 4) + 0x1c,puVar13[1] + uVar17,iVar15 + -4);
      memw();
      if ((*puVar13 >> 0x1e & 1) == 1) {
        if (iVar18 != 0) {
          FUN_4018a7b8(iVar8);
          break;
        }
        bVar11 = true;
        uVar7 = 0;
      }
      else {
        uVar7 = 0;
        puVar13 = (uint *)puVar13[2];
        bVar11 = false;
        if (iVar18 != 0) {
          memw();
          (*(code *)&SUB_4008b3d0)
                    (*(int *)(*(int *)(iVar8 + 4) + 4) + iVar15 + 0x18,puVar13[1],iVar18);
          uVar7 = (*(code *)&SUB_4000ab7c)(iVar18,4);
          bVar11 = false;
        }
      }
    }
    if ((uVar6 != 0) && (bVar5)) {
      FUN_40165378(_DAT_3ffc06fc[1] + 0x18,uVar6,*(int *)(iVar8 + 0x10),
                   *(int *)(iVar8 + 0x10) + 0x1c,uVar14,iStack_4c);
      bVar5 = false;
    }
    *(undefined4 *)(*(int *)(iVar8 + 0x2c) + 4) = param_3;
    *(undefined1 *)(*(int *)(iVar8 + 0x2c) + 8) = DAT_3ffc0728;
    memw();
    *(undefined1 *)(*(int *)(iVar8 + 0x2c) + 9) = DAT_3ffc0729;
    memw();
    **(uint **)(iVar8 + 0x2c) = **(uint **)(iVar8 + 0x2c) | 0x10;
    if ((DAT_3ffc072c == '\x01') && ((int)*puVar10 < 0)) {
      memw();
      FUN_401656dc(iVar8);
    }
    if ((*puVar10 & 0x30000000) == 0) {
      FUN_4018a7b8(iVar8);
    }
    else {
      FUN_40160f8c(iVar8);
    }
  } while (!bVar11);
LAB_4018b155:
  memw();
  uVar7 = *puVar13;
LAB_4018b15a:
  FUN_4018b770(param_1,param_2);
  return uVar7;
}

