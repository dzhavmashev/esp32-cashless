// Function : FUN_400f9608
// Address  : 0x400f9608
// Size     : 64 bytes


int FUN_400f9608(undefined4 param_1,undefined4 param_2,undefined1 param_3)

{
  int iVar1;
  undefined1 uStack_25;
  int *apiStack_24 [9];
  
  FUN_400f9390();
  iVar1 = FUN_400f9350(param_1,apiStack_24);
  if (iVar1 == 0) {
    memw();
    memw();
    uStack_25 = param_3;
    iVar1 = (**(code **)(*apiStack_24[0] + 0x2c))(apiStack_24[0],1,param_2,&uStack_25);
  }
  FUN_400f9378();
  return iVar1;
}

