// Function : FUN_4017c5a0
// Address  : 0x4017c5a0
// Size     : 172 bytes


uint FUN_4017c5a0(undefined4 param_1,int param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint *puVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  uint *puVar8;
  int *piVar9;
  uint *puVar10;
  int *piVar11;
  uint uVar12;
  int iVar13;
  int *in_t0;
  undefined8 uVar14;
  
  iVar3 = (int)param_3 >> 5;
  iVar13 = *(int *)(param_2 + 4);
  iVar2 = iVar3 + *(int *)(param_2 + 0x10);
  iVar6 = iVar2 + 1;
  for (iVar5 = *(int *)(param_2 + 8); iVar5 < iVar6; iVar5 = iVar5 << 1) {
    iVar13 = iVar13 + 1;
  }
  uVar1 = FUN_4017c100(param_1,iVar13);
  piVar9 = (int *)(uVar1 + 0x14);
  piVar7 = (int *)0x0;
  iVar5 = 0;
  piVar11 = piVar9;
  if (uVar1 != 0) goto LAB_4017c5ec;
  param_3 = uVar1;
  piVar7 = in_t0;
  uVar14 = (*(code *)&SUB_40094c54)(&DAT_3f4260d0,0x1d9,0,"/dtoa.c");
  piVar9 = piVar7;
  do {
    iVar5 = (int)((ulonglong)uVar14 >> 0x20);
    *(int *)uVar14 = iVar5;
    piVar7 = (int *)((int)piVar7 + 1);
    piVar11 = (int *)uVar14 + 1;
LAB_4017c5ec:
    uVar14 = CONCAT44(iVar5,piVar11);
  } while ((int)piVar7 < iVar3);
  puVar10 = (uint *)(piVar9 + (uint)(iVar3 < iVar5) * iVar5 + (uint)(iVar3 >= iVar5) * iVar3);
  puVar8 = (uint *)(param_2 + 0x14);
  puVar4 = puVar8 + *(int *)(param_2 + 0x10);
  if ((param_3 & 0x1f) == 0) {
    do {
      uVar12 = *puVar8;
      puVar8 = puVar8 + 1;
      *puVar10 = uVar12;
      puVar10 = puVar10 + 1;
    } while (puVar8 < puVar4);
  }
  else {
    uVar12 = 0;
    do {
      *puVar10 = *puVar8 << 0x20 - (0x20 - (param_3 & 0x1f)) | uVar12;
      uVar12 = *puVar8;
      puVar8 = puVar8 + 1;
      uVar12 = uVar12 >> (0x20 - (param_3 & 0x1f) & 0x1f);
      puVar10 = puVar10 + 1;
    } while (puVar8 < puVar4);
    *puVar10 = uVar12;
    if (uVar12 != 0) {
      iVar6 = iVar2 + 2;
    }
  }
  *(int *)(uVar1 + 0x10) = iVar6 + -1;
  FUN_4017c190(param_1,param_2);
  return uVar1;
}

