// Function : FUN_401863f0
// Address  : 0x401863f0
// Size     : 62 bytes


void FUN_401863f0(uint *param_1,uint *param_2,int *param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = *param_1;
  uVar1 = *param_2;
  *param_1 = uVar1 + uVar2;
  uVar3 = (uint)(uVar1 + uVar2 < *param_2);
  uVar1 = uVar3 + param_1[1];
  param_1[1] = uVar1;
  uVar2 = param_2[1];
  param_1[1] = uVar1 + uVar2;
  *param_3 = (uint)(uVar1 < uVar3) + *param_3 + (uint)(uVar1 + uVar2 < param_2[1]);
  memw();
  return;
}

