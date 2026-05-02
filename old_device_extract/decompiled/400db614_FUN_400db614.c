// Function : FUN_400db614
// Address  : 0x400db614
// Size     : 182 bytes


void FUN_400db614(int *param_1,int param_2,undefined2 *param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined2 *puVar7;
  
  iVar5 = *param_1;
  iVar6 = param_1[1];
  uVar4 = (iVar6 - iVar5 >> 3) * -0x55555555;
  uVar3 = 1;
  if (uVar4 != 0) {
    uVar3 = uVar4;
  }
  uVar3 = uVar4 + uVar3;
  if ((uVar3 < uVar4) || (0xaaaaaaa < uVar3)) {
    uVar3 = 0xaaaaaaa;
  }
  else if (uVar3 == 0) {
    iVar2 = 0;
    goto LAB_400db649;
  }
  iVar2 = (*(code *)&LAB_40170217_1)(uVar3 * 0x18);
LAB_400db649:
  puVar7 = (undefined2 *)(iVar2 + (param_2 - iVar5));
  *puVar7 = *param_3;
  FUN_400f0d04(puVar7 + 2,param_3 + 2);
  *(undefined4 *)(puVar7 + 10) = *(undefined4 *)(param_3 + 10);
  iVar1 = FUN_400db5c4(iVar5,param_2,iVar2);
  iVar1 = FUN_400db5c4(param_2,iVar6,iVar1 + 0x18);
  FUN_400db318(iVar5,iVar6);
  FUN_400da458(iVar5);
  param_1[1] = iVar1;
  *param_1 = iVar2;
  param_1[2] = iVar2 + uVar3 * 0x18;
  return;
}

