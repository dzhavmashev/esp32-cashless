// Function : FUN_401344b0
// Address  : 0x401344b0
// Size     : 44 bytes


int FUN_401344b0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5)

{
  int iVar1;
  
  iVar1 = FUN_401368dc(param_1,param_2,param_4,param_5);
  if (iVar1 == 0) {
    memw();
    iVar1 = FUN_4013633c(param_1,param_3,param_2,param_1 + 0x28,param_4,param_5,0);
  }
  return iVar1;
}

