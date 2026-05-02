// Function : FUN_400ed5e8
// Address  : 0x400ed5e8
// Size     : 85 bytes


undefined4 FUN_400ed5e8(undefined1 *param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x2c) == 0) {
    iVar1 = FUN_400ed3bc(param_1,*(undefined4 *)(param_1 + 0x30));
    if (((iVar1 == 0) || (*(int *)(param_1 + 0x30) == 0)) || (iVar1 = FUN_400ed370(), iVar1 == 0)) {
      FUN_400ed41c(param_1);
      *param_1 = 3;
    }
    else {
      iVar1 = FUN_400f800c(*(undefined4 *)(param_1 + 0x30));
      if (iVar1 == 0) goto LAB_400ed636;
      FUN_400ed41c(param_1);
      *param_1 = 9;
    }
  }
  else if (*(int *)(param_1 + 0x2c) == 100) {
LAB_400ed636:
    FUN_400ed41c(param_1);
    return 1;
  }
  return 0;
}

