// Function : FUN_40132190
// Address  : 0x40132190
// Size     : 243 bytes


void FUN_40132190(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  uint *puVar7;
  int *piVar8;
  undefined4 uVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  
  memw();
  (*(code *)&SUB_4008b530)(*(undefined4 *)(param_5 + 8),0,*(int *)(param_5 + 4) << 2);
  uVar11 = 0;
  uVar1 = *(uint *)(param_3 + 4);
  uVar2 = *(uint *)(param_2 + 4);
  piVar8 = *(int **)(param_5 + 8);
  piVar6 = piVar8;
  while (uVar11 != uVar1) {
    iVar12 = *(int *)(*(int *)(param_1 + 8) + uVar11 * 4);
    iVar3 = **(int **)(param_2 + 8);
    iVar5 = *piVar6;
    memw();
    FUN_40185c20((uVar1 < uVar2) * uVar1 + (uVar1 >= uVar2) * uVar2,*(int **)(param_2 + 8),piVar6,
                 iVar12);
    FUN_40185c20(uVar1,*(undefined4 *)(param_3 + 8),piVar6,(iVar12 * iVar3 + iVar5) * param_4);
    uVar11 = uVar11 + 1;
    *piVar6 = iVar12;
    piVar6[uVar1 + 2] = 0;
    memw();
    piVar6 = piVar6 + 1;
  }
  iVar5 = (uVar1 + 1) * 4 + -4;
  piVar8 = piVar8 + uVar1;
  puVar7 = (uint *)(piVar8 + uVar1);
  memw();
  (*(code *)&SUB_4008b3d0)(*(int *)(param_1 + 8),piVar8,iVar5);
  *puVar7 = *puVar7 + 1;
  iVar3 = 0;
  uVar2 = 0;
  iVar12 = *(int *)(param_3 + 8);
  while (iVar3 != iVar5) {
    uVar11 = *(uint *)((int)piVar8 + iVar3);
    uVar10 = *(uint *)(iVar12 + iVar3);
    uVar4 = uVar11 - uVar2;
    uVar2 = (uint)(uVar4 < uVar10) + (uint)(uVar11 < uVar2);
    *(uint *)((int)piVar8 + iVar3) = uVar4 - uVar10;
    iVar3 = iVar3 + 4;
    memw();
  }
  uVar11 = *puVar7;
  uVar9 = *(undefined4 *)(param_1 + 8);
  *puVar7 = uVar11 - uVar2;
  memw();
  FUN_401863a8(uVar1,uVar9,piVar8,uVar11 - uVar2 & 0xff);
  return;
}

