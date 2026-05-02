// Function : FUN_4017c3d8
// Address  : 0x4017c3d8
// Size     : 284 bytes


int FUN_4017c3d8(undefined4 param_1,int param_2,int param_3)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  ushort *puVar4;
  int iVar5;
  int iVar6;
  ushort *puVar7;
  uint uVar8;
  int iVar9;
  uint *puVar10;
  uint uVar11;
  uint *puVar12;
  uint *puVar13;
  int iVar14;
  uint *puVar15;
  uint uVar16;
  
  iVar3 = param_2;
  if (*(int *)(param_2 + 0x10) < *(int *)(param_3 + 0x10)) {
    iVar3 = param_3;
    param_3 = param_2;
  }
  iVar9 = *(int *)(iVar3 + 0x10);
  iVar6 = *(int *)(param_3 + 0x10);
  iVar5 = iVar9 + iVar6;
  iVar14 = *(int *)(iVar3 + 4);
  if (*(int *)(iVar3 + 8) < iVar5) {
    iVar14 = iVar14 + 1;
  }
  iVar14 = FUN_4017c100(param_1,iVar14);
  if (iVar14 == 0) {
    iVar14 = (*(code *)&SUB_40094c54)(&DAT_3f4260d0,0x15d,0,"/dtoa.c");
  }
  puVar13 = (uint *)(iVar14 + 0x14);
  puVar15 = puVar13 + iVar5;
  for (puVar1 = puVar13; puVar1 < puVar15; puVar1 = puVar1 + 1) {
    *puVar1 = 0;
  }
  puVar4 = (ushort *)(param_3 + 0x14);
  puVar1 = (uint *)(iVar3 + 0x14) + iVar9;
  puVar7 = puVar4 + iVar6 * 2;
  for (; puVar4 < puVar7; puVar4 = puVar4 + 2) {
    uVar8 = (uint)*puVar4;
    if (uVar8 != 0) {
      uVar2 = 0;
      puVar10 = puVar13;
      puVar12 = (uint *)(iVar3 + 0x14);
      do {
        uVar11 = (*puVar12 & 0xffff) * uVar8 + (*puVar10 & 0xffff) + uVar2;
        uVar16 = (*puVar12 >> 0x10) * uVar8 + (*puVar10 >> 0x10) + (uVar11 >> 0x10);
        uVar2 = uVar16 >> 0x10;
        puVar12 = puVar12 + 1;
        *puVar10 = uVar16 * 0x10000 | uVar11 & 0xffff;
        puVar10 = puVar10 + 1;
      } while (puVar12 < puVar1);
      *puVar10 = uVar2;
    }
    uVar8 = (uint)puVar4[1];
    if (uVar8 != 0) {
      uVar11 = *puVar13;
      puVar12 = (uint *)(iVar3 + 0x14);
      uVar2 = 0;
      puVar10 = puVar13;
      do {
        uVar2 = (ushort)*puVar12 * uVar8 + (uint)*(ushort *)((int)puVar10 + 2) + uVar2;
        *puVar10 = uVar2 * 0x10000 | uVar11 & 0xffff;
        uVar11 = *(ushort *)((int)puVar12 + 2) * uVar8 + (uint)(ushort)puVar10[1] + (uVar2 >> 0x10);
        puVar12 = puVar12 + 1;
        puVar10 = puVar10 + 1;
        uVar2 = uVar11 >> 0x10;
      } while (puVar12 < puVar1);
      *puVar10 = uVar11;
    }
    puVar13 = puVar13 + 1;
  }
  while ((0 < iVar5 && (puVar15 = puVar15 + -1, *puVar15 == 0))) {
    iVar5 = iVar5 + -1;
  }
  *(int *)(iVar14 + 0x10) = iVar5;
  return iVar14;
}

