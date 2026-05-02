// Function : FUN_4012c844
// Address  : 0x4012c844
// Size     : 70 bytes


int FUN_4012c844(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5)

{
  int iVar1;
  int iVar2;
  
  iVar2 = param_1 + 0xb4;
  param_1 = param_1 + 0xc0;
  memw();
  FUN_40131548(iVar2);
  FUN_40131548(param_1);
  iVar1 = FUN_4013183c(iVar2,param_2,param_3);
  if ((iVar1 != 0) || (iVar1 = FUN_4013183c(param_1,param_4,param_5), iVar1 != 0)) {
    FUN_40131548(iVar2);
    FUN_40131548(param_1);
  }
  return iVar1;
}

