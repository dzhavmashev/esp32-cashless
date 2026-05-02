// Function : FUN_4017b1ac
// Address  : 0x4017b1ac
// Size     : 262 bytes


uint FUN_4017b1ac(int param_1,int param_2)

{
  uint *puVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  uint *puVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint *puVar10;
  uint *puVar11;
  int iVar12;
  
  uVar9 = 0;
  if (*(int *)(param_2 + 0x10) <= *(int *)(param_1 + 0x10)) {
    iVar3 = *(int *)(param_2 + 0x10) + -1;
    puVar10 = (uint *)(param_2 + 0x14);
    puVar1 = puVar10 + iVar3;
    puVar5 = (uint *)(param_1 + 0x14);
    puVar2 = puVar5 + iVar3;
    uVar4 = *puVar2 / (*puVar1 + 1);
    if (*puVar1 + 1 <= *puVar2) {
      iVar12 = 0;
      puVar11 = puVar5;
      do {
        uVar6 = *puVar10;
        puVar10 = puVar10 + 1;
        uVar9 = (uVar6 & 0xffff) * uVar4 + uVar9;
        uVar6 = (uVar6 >> 0x10) * uVar4 + (uVar9 >> 0x10);
        uVar8 = ((*puVar11 & 0xffff) + iVar12) - (uVar9 & 0xffff);
        uVar9 = uVar6 >> 0x10;
        iVar7 = ((*puVar11 >> 0x10) - (uVar6 & 0xffff)) + ((int)uVar8 >> 0x10);
        iVar12 = iVar7 >> 0x10;
        *puVar11 = iVar7 * 0x10000 | uVar8 & 0xffff;
        puVar11 = puVar11 + 1;
      } while (puVar10 <= puVar1);
      if (*puVar2 == 0) {
        while ((puVar2 = puVar2 + -1, puVar5 < puVar2 && (*puVar2 == 0))) {
          iVar3 = iVar3 + -1;
        }
        *(int *)(param_1 + 0x10) = iVar3;
      }
    }
    iVar12 = FUN_4017c64c(param_1,param_2);
    uVar9 = uVar4;
    if (-1 < iVar12) {
      uVar9 = uVar4 + 1;
      puVar10 = (uint *)(param_1 + 0x14);
      puVar2 = (uint *)(param_2 + 0x14);
      iVar12 = 0;
      do {
        uVar4 = ((*puVar10 & 0xffff) + iVar12) - (*puVar2 & 0xffff);
        iVar7 = ((*puVar10 >> 0x10) - (*puVar2 >> 0x10)) + ((int)uVar4 >> 0x10);
        iVar12 = iVar7 >> 0x10;
        *puVar10 = iVar7 * 0x10000 | uVar4 & 0xffff;
        puVar2 = puVar2 + 1;
        puVar10 = puVar10 + 1;
      } while (puVar2 <= puVar1);
      puVar1 = puVar5 + iVar3;
      if (*puVar1 == 0) {
        while ((puVar1 = puVar1 + -1, puVar5 < puVar1 && (*puVar1 == 0))) {
          iVar3 = iVar3 + -1;
        }
        *(int *)(param_1 + 0x10) = iVar3;
      }
    }
  }
  return uVar9;
}

