// Function : FUN_400e7808
// Address  : 0x400e7808
// Size     : 68 bytes


void FUN_400e7808(undefined1 *param_1)

{
  int iVar1;
  undefined1 uVar2;
  
  iVar1 = FUN_400f1a9c();
  if ((uint)(iVar1 - *(int *)(param_1 + 8)) < 0x96) {
    if (param_1[0xc] != '\0') {
      return;
    }
  }
  else {
    if ((uint)(iVar1 - *(int *)(param_1 + 8)) < 10000) {
      if (param_1[0xc] == '\0') {
        return;
      }
      FUN_400f1a40(*param_1,0);
      uVar2 = 0;
      goto LAB_400e7842;
    }
    *(int *)(param_1 + 8) = iVar1;
  }
  FUN_400f1a40(*param_1,1);
  uVar2 = 1;
LAB_400e7842:
  param_1[0xc] = uVar2;
  return;
}

