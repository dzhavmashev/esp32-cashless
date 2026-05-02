// Function : FUN_400f957c
// Address  : 0x400f957c
// Size     : 44 bytes


int FUN_400f957c(undefined4 param_1)

{
  int iVar1;
  int *apiStack_24 [9];
  
  FUN_400f9390();
  iVar1 = FUN_400f9350(param_1,apiStack_24);
  if (iVar1 == 0) {
    iVar1 = (**(code **)(*apiStack_24[0] + 0x20))();
  }
  FUN_400f9378();
  return iVar1;
}

