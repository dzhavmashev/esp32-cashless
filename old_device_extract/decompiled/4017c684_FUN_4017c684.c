// Function : FUN_4017c684
// Address  : 0x4017c684
// Size     : 224 bytes


int FUN_4017c684(undefined4 param_1,int param_2,int param_3,undefined4 param_4,uint param_5)

{
  int iVar1;
  uint *puVar2;
  uint *puVar3;
  uint *puVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  int iVar8;
  uint *puVar9;
  uint *puVar10;
  int iVar11;
  uint *puVar12;
  
  iVar1 = FUN_4017c64c(param_2,param_3);
  if (iVar1 == 0) {
    iVar1 = FUN_4017c100(param_1,0);
    if (iVar1 != 0) {
      *(undefined4 *)(iVar1 + 0x10) = 1;
      *(undefined4 *)(iVar1 + 0x14) = 0;
      return iVar1;
    }
    uVar6 = 0x232;
  }
  else {
    iVar8 = param_2;
    if (iVar1 >= 0) {
      iVar8 = param_3;
      param_3 = param_2;
    }
    param_2 = iVar8;
    param_5 = (uint)(iVar1 < 0);
    iVar1 = FUN_4017c100(param_1,*(undefined4 *)(param_3 + 4));
    if (iVar1 != 0) goto LAB_4017c6d9;
    uVar6 = 0x240;
  }
  iVar1 = (*(code *)&SUB_40094c54)(&DAT_3f4260d0,uVar6,0,"/dtoa.c");
LAB_4017c6d9:
  iVar11 = *(int *)(param_3 + 0x10);
  iVar8 = *(int *)(param_2 + 0x10);
  puVar10 = (uint *)(param_2 + 0x14);
  puVar4 = (uint *)(param_3 + 0x14);
  *(uint *)(iVar1 + 0xc) = param_5;
  puVar12 = puVar4 + iVar11;
  puVar9 = puVar10 + iVar8;
  iVar8 = 0;
  puVar2 = (uint *)(iVar1 + 0x14);
  do {
    uVar7 = ((*puVar4 & 0xffff) + iVar8) - (*puVar10 & 0xffff);
    iVar5 = ((*puVar4 >> 0x10) - (*puVar10 >> 0x10)) + ((int)uVar7 >> 0x10);
    iVar8 = iVar5 >> 0x10;
    puVar3 = puVar2 + 1;
    *puVar2 = iVar5 * 0x10000 | uVar7 & 0xffff;
    puVar10 = puVar10 + 1;
    puVar4 = puVar4 + 1;
    puVar2 = puVar3;
  } while (puVar10 < puVar9);
  for (; puVar4 < puVar12; puVar4 = puVar4 + 1) {
    uVar7 = (*puVar4 & 0xffff) + iVar8;
    iVar5 = (*puVar4 >> 0x10) + ((int)uVar7 >> 0x10);
    iVar8 = iVar5 >> 0x10;
    *puVar3 = iVar5 * 0x10000 | uVar7 & 0xffff;
    puVar3 = puVar3 + 1;
  }
  while (puVar3 = puVar3 + -1, *puVar3 == 0) {
    iVar11 = iVar11 + -1;
  }
  *(int *)(iVar1 + 0x10) = iVar11;
  return iVar1;
}

