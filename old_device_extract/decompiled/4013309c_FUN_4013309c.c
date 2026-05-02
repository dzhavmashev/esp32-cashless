// Function : FUN_4013309c
// Address  : 0x4013309c
// Size     : 87 bytes


int FUN_4013309c(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5,int param_6,int *param_7)

{
  int iVar1;
  int aiStack_24 [9];
  
  memw();
  iVar1 = FUN_40132cfc(param_1,param_2,param_3);
  if (iVar1 == 0) {
    if (*param_1 == 0) {
      iVar1 = -0x6100;
    }
    else {
      param_1[9] = 0;
      memw();
      iVar1 = FUN_40132d58(param_1,param_4,param_5,param_6,param_7);
      if ((iVar1 == 0) && (iVar1 = FUN_40132f28(param_1,param_6 + *param_7,aiStack_24), iVar1 == 0))
      {
        *param_7 = *param_7 + aiStack_24[0];
      }
    }
  }
  memw();
  return iVar1;
}

