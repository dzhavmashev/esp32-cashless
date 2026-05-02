// Function : FUN_401871bc
// Address  : 0x401871bc
// Size     : 66 bytes


undefined4 FUN_401871bc(undefined4 param_1,undefined4 param_2,undefined4 param_3,code *param_4)

{
  int iVar1;
  
  iVar1 = (*param_4)(param_1,param_2);
  if (iVar1 < 0) {
    iVar1 = (*param_4)(param_2);
    if (iVar1 < 0) {
      return param_2;
    }
    iVar1 = (*param_4)(param_1,param_3);
    if (iVar1 < 0) {
      return param_3;
    }
  }
  else {
    iVar1 = (*param_4)(param_2,param_3);
    if (0 < iVar1) {
      return param_2;
    }
    iVar1 = (*param_4)(param_1,param_3);
    if (-1 < iVar1) {
      return param_3;
    }
  }
  return param_1;
}

