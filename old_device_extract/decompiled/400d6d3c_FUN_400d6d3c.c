// Function : FUN_400d6d3c
// Address  : 0x400d6d3c
// Size     : 39 bytes


void FUN_400d6d3c(int *param_1)

{
  int iVar1;
  
  if ((*(int **)(*param_1 + 0x28) != (int *)0x0) &&
     (iVar1 = (**(code **)(**(int **)(*param_1 + 0x28) + 0x14))(), iVar1 == 3)) {
    FUN_400dd958(*(undefined4 *)(*param_1 + 0x28));
    FUN_400f0780(0x3ffc5490,"TooDeep");
  }
  return;
}

