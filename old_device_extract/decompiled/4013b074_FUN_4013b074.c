// Function : FUN_4013b074
// Address  : 0x4013b074
// Size     : 157 bytes


undefined4 FUN_4013b074(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = param_1 + 8;
  iVar3 = *(int *)(param_1 + 4);
  iVar1 = FUN_401317d8(iVar2);
  if (iVar3 != iVar1) {
    return 0xffffbf80;
  }
  if (0x400 < *(uint *)(param_1 + 4)) {
    return 0xffffbf80;
  }
  iVar1 = FUN_40131ad8(iVar2,0);
  if (iVar1 < 1) {
    return 0xffffbf80;
  }
  iVar1 = FUN_4018601c(iVar2,0);
  if (iVar1 == 0) {
    return 0xffffbf80;
  }
  if (param_2 != 0) {
    iVar1 = FUN_40131ad8(param_1 + 0x2c,0);
    if (iVar1 < 1) {
      return 0xffffbf80;
    }
    iVar1 = FUN_4018601c(param_1 + 0x2c,0);
    if (iVar1 == 0) {
      return 0xffffbf80;
    }
    iVar1 = FUN_40131ad8(param_1 + 0x38,0);
    if (iVar1 < 1) {
      return 0xffffbf80;
    }
    iVar1 = FUN_4018601c(param_1 + 0x38,0);
    if (iVar1 == 0) {
      return 0xffffbf80;
    }
  }
  iVar1 = FUN_40131ad8(param_1 + 0x14,0);
  if ((0 < iVar1) &&
     ((param_2 == 0 ||
      (((iVar1 = FUN_40131ad8(param_1 + 0x44,0), 0 < iVar1 &&
        (iVar1 = FUN_40131ad8(param_1 + 0x50,0), 0 < iVar1)) &&
       (iVar1 = FUN_40131ad8(param_1 + 0x5c,0), 0 < iVar1)))))) {
    return 0;
  }
  return 0xffffbf80;
}

