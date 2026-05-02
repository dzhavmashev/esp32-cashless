// Function : FUN_40170b1c
// Address  : 0x40170b1c
// Size     : 140 bytes


void FUN_40170b1c(int *param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int local_60 [24];
  
  piVar3 = local_60;
  (*(code *)&SUB_4008b3d0)(local_60,param_1,0x38);
  iVar1 = *(int *)(param_2 + 0x10);
  if (iVar1 == 0) {
    iVar4 = param_1[4];
    iVar6 = *(int *)(iVar4 + -0xc);
    uVar2 = *(uint *)(param_2 + 4) >> 2;
    *param_1 = param_1[5] + -0x10;
    iVar1 = iVar6 + uVar2 * -0x10;
    for (iVar5 = 1; iVar5 < (int)uVar2; iVar5 = iVar5 + 1) {
      param_1[iVar5] = iVar1;
      iVar1 = iVar1 + 0x10;
    }
    for (; (int)uVar2 < 4; uVar2 = uVar2 + 1) {
      param_1[uVar2] = *piVar3;
      piVar3 = piVar3 + 1;
    }
  }
  else {
    iVar4 = *(int *)(iVar1 + 4);
    iVar6 = *(int *)(iVar4 + -0xc);
    *param_1 = iVar1;
    param_1[1] = iVar1 + 0x10;
    param_1[2] = iVar1 + 0x20;
    param_1[3] = iVar1 + 0x30;
  }
  param_1[5] = iVar4;
  param_1[4] = iVar6;
  uVar2 = param_1[0xc] & 0x7fffffff;
  if (*(char *)(param_2 + 0xb) != '\0') {
    uVar2 = param_1[0xc] | 0x80000000;
  }
  param_1[0xc] = uVar2;
  return;
}

