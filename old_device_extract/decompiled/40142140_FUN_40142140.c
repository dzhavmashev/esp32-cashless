// Function : FUN_40142140
// Address  : 0x40142140
// Size     : 166 bytes


/* WARNING: Type propagation algorithm not settling */

int FUN_40142140(int *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int aiStack_138 [78];
  
  FUN_40141b5c(aiStack_138 + 1);
  iVar1 = FUN_40141b80(aiStack_138 + 1,param_2,param_3);
  if (iVar1 == 0) {
    *param_1 = aiStack_138[1];
    uVar2 = (uint)(aiStack_138[1] == 4);
    iVar4 = uVar2 + 3;
    piVar3 = aiStack_138 + iVar4 * 0x10;
    param_1[1] = aiStack_138[iVar4 * 0x10U + 2];
    param_1[2] = aiStack_138[iVar4 * 0x10U + 3];
    iVar6 = aiStack_138[iVar4 * 0x10U + 5];
    param_1[3] = aiStack_138[iVar4 * 0x10U + 4];
    piVar5 = param_1 + 5;
    param_1[4] = iVar6;
    *piVar5 = *piVar3;
    param_1[6] = aiStack_138[iVar4 * 0x10U + 1];
    iVar4 = uVar2 * 8 + 0x15;
    piVar5[iVar4 * 2 + 2] = piVar3[uVar2 * -0x10 + -0x2e];
    piVar5[iVar4 * 2 + 3] = piVar3[uVar2 * -0x10 + -0x2d];
    piVar5[iVar4 * 2 + 4] = piVar3[uVar2 * -0x10 + -0x2c];
    piVar5[iVar4 * 2 + 5] = piVar3[uVar2 * -0x10 + -0x2b];
  }
  memw();
  FUN_40141b70(aiStack_138 + 1);
  return iVar1;
}

