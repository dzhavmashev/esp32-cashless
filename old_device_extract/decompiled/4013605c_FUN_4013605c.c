// Function : FUN_4013605c
// Address  : 0x4013605c
// Size     : 49 bytes


int FUN_4013605c(undefined4 param_1,undefined4 param_2,undefined4 param_3,int *param_4,
                undefined1 *param_5,int param_6)

{
  int iVar1;
  
  iVar1 = -0x4f80;
  if ((param_6 != 0) &&
     (iVar1 = FUN_40135e8c(param_1,param_2,param_3,param_4,param_5 + 1,param_6 + -1), iVar1 == 0)) {
    *param_5 = (char)*param_4;
    memw();
    *param_4 = *param_4 + 1;
  }
  memw();
  return iVar1;
}

