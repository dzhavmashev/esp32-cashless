// Function : FUN_400eedf4
// Address  : 0x400eedf4
// Size     : 173 bytes


void FUN_400eedf4(int *param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  
  iVar5 = *param_1;
  iVar6 = param_1[1];
  uVar4 = (iVar6 - iVar5 >> 3) * -0x3b13b13b;
  uVar3 = 1;
  if (uVar4 != 0) {
    uVar3 = uVar4;
  }
  uVar3 = uVar4 + uVar3;
  if ((uVar3 < uVar4) || (0x2762762 < uVar3)) {
    uVar3 = 0x2762762;
  }
  else if (uVar3 == 0) {
    iVar2 = 0;
    goto LAB_400eee29;
  }
  iVar2 = (*(code *)&LAB_40170217_1)(uVar3 * 0x68);
LAB_400eee29:
  FUN_400eecf0(iVar2 + (param_2 - iVar5),param_3);
  iVar1 = FUN_400eedac(iVar5,param_2,iVar2);
  iVar1 = FUN_400eedac(param_2,iVar6,iVar1 + 0x68);
  FUN_400eed94(iVar5,iVar6);
  if (iVar5 != 0) {
    FUN_4016fa48(iVar5);
  }
  param_1[1] = iVar1;
  *param_1 = iVar2;
  param_1[2] = iVar2 + uVar3 * 0x68;
  return;
}

