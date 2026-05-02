// Function : FUN_400dc760
// Address  : 0x400dc760
// Size     : 168 bytes


void FUN_400dc760(int *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  
  iVar5 = *param_1;
  iVar2 = param_1[1];
  uVar6 = (iVar2 - iVar5 >> 2) * -0x33333333;
  uVar3 = 1;
  if (uVar6 != 0) {
    uVar3 = uVar6;
  }
  uVar3 = uVar6 + uVar3;
  if ((uVar3 < uVar6) || (0xccccccc < uVar3)) {
    uVar3 = 0xccccccc;
  }
  else if (uVar3 == 0) {
    iVar1 = 0;
    goto LAB_400dc799;
  }
  iVar1 = (*(code *)&LAB_40170217_1)(uVar3 * 0x14);
LAB_400dc799:
  iVar4 = iVar1 + (param_2 - iVar5);
  FUN_400f0d04(iVar4,param_3);
  *(undefined4 *)(iVar4 + 0x10) = *(undefined4 *)(param_3 + 0x10);
  iVar4 = FUN_400dc710(iVar5,param_2,iVar1);
  iVar4 = FUN_400dc710(param_2,iVar2,iVar4 + 0x14);
  FUN_400dc588(iVar5,iVar2);
  if (iVar5 != 0) {
    FUN_4016fa48(iVar5);
  }
  param_1[1] = iVar4;
  *param_1 = iVar1;
  param_1[2] = iVar1 + uVar3 * 0x14;
  return;
}

