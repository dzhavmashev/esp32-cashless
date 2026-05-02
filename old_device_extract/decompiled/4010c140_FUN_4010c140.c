// Function : FUN_4010c140
// Address  : 0x4010c140
// Size     : 38 bytes


uint FUN_4010c140(undefined4 param_1,undefined2 param_2)

{
  int iVar1;
  uint uVar2;
  ushort auStack_22 [17];
  
  iVar1 = (*(code *)&LAB_4018533b_1)(param_1,param_2,auStack_22);
  uVar2 = 0xffffffff;
  if ((iVar1 != 0) && ((uint)auStack_22[0] < (uint)*(ushort *)(iVar1 + 10))) {
    uVar2 = (uint)*(byte *)(*(int *)(iVar1 + 4) + (uint)auStack_22[0]);
  }
  return uVar2;
}

