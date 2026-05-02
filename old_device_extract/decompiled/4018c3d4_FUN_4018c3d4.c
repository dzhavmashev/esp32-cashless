// Function : FUN_4018c3d4
// Address  : 0x4018c3d4
// Size     : 127 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4018c3d4(undefined4 param_1,undefined4 param_2,undefined4 param_3,char param_4)

{
  int iVar1;
  undefined4 local_30;
  undefined4 auStack_2c [11];
  
  auStack_2c[0] = 0;
  local_30 = 0;
  memw();
  FUN_4018bd88(&DAT_3ffca1d8);
  memw();
  if (((DAT_3ffc1a3c != '\0') && (_DAT_3ffc1a40 != 0)) && (_DAT_3ffc7a3c != (code *)0x0)) {
    (*_DAT_3ffc7a3c)();
  }
  if (DAT_3ffca1e5 != '\0') {
    if ((param_4 == '\0') &&
       (iVar1 = FUN_4018bb20(param_2,param_3,&local_30,auStack_2c), iVar1 != 0)) {
      FUN_4018b38c(param_1,auStack_2c[0],local_30);
    }
    _DAT_3ffca1f6 = _DAT_3ffca1f6 + 1;
    memw();
    _DAT_3ffc7c14 = _DAT_3ffc7c14 + 1;
    memw();
    FUN_4018c33c(local_30,param_4);
    FUN_40161a0c(auStack_2c[0]);
  }
  return;
}

