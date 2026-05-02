// Function : FUN_401320e0
// Address  : 0x401320e0
// Size     : 99 bytes


int FUN_401320e0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_40131ad8(param_3,0);
  if (iVar1 < 0) {
    return -10;
  }
  iVar2 = FUN_40131da0(0,param_1,param_2,param_3);
  iVar1 = iVar2;
  while( true ) {
    if (iVar1 != 0) {
      return iVar1;
    }
    iVar1 = FUN_40131ad8(param_1,0);
    if (-1 < iVar1) break;
    iVar1 = FUN_40131d18(param_1,param_1,param_3);
  }
  do {
    iVar1 = FUN_401860ec(param_1,param_3);
    if (iVar1 < 0) {
      return iVar2;
    }
    iVar1 = FUN_40131d30(param_1,param_1,param_3);
  } while (iVar1 == 0);
  return iVar1;
}

