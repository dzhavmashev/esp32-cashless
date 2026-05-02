// Function : FUN_400d6d64
// Address  : 0x400d6d64
// Size     : 39 bytes


void FUN_400d6d64(int *param_1)

{
  int iVar1;
  
  if ((*(int **)(*param_1 + 0x28) != (int *)0x0) &&
     (iVar1 = (**(code **)(**(int **)(*param_1 + 0x28) + 0x14))(), iVar1 == 3)) {
    FUN_400dd958(*(undefined4 *)(*param_1 + 0x28));
    FUN_400f0780(0x3ffc5490,&DAT_3f4022d7);
  }
  return;
}

