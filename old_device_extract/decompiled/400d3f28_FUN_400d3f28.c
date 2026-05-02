// Function : FUN_400d3f28
// Address  : 0x400d3f28
// Size     : 32 bytes


undefined4 FUN_400d3f28(undefined4 *param_1)

{
  int iVar1;
  
  *(undefined1 *)((int)param_1 + param_1[9] + 4) = 0;
  iVar1 = FUN_400f1050(*param_1,param_1 + 1);
  if (iVar1 != 0) {
    param_1[9] = 0;
  }
  return param_1[9];
}

