// Function : FUN_4010c180
// Address  : 0x4010c180
// Size     : 46 bytes


void FUN_4010c180(undefined4 param_1,undefined2 param_2,undefined1 param_3)

{
  int iVar1;
  ushort auStack_22 [17];
  
  iVar1 = (*(code *)&LAB_4018533b_1)(param_1,param_2,auStack_22);
  if ((iVar1 != 0) && ((uint)auStack_22[0] < (uint)*(ushort *)(iVar1 + 10))) {
    *(undefined1 *)(*(int *)(iVar1 + 4) + (uint)auStack_22[0]) = param_3;
    memw();
  }
  memw();
  return;
}

