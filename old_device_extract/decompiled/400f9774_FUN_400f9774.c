// Function : FUN_400f9774
// Address  : 0x400f9774
// Size     : 48 bytes


int FUN_400f9774(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int *apiStack_24 [9];
  
  FUN_400f9390();
  iVar1 = FUN_400f9350(param_1,apiStack_24);
  if (iVar1 == 0) {
    iVar1 = (**(code **)(*apiStack_24[0] + 8))(apiStack_24[0],param_2,param_3);
  }
  FUN_400f9378();
  return iVar1;
}

