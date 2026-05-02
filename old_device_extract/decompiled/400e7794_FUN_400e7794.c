// Function : FUN_400e7794
// Address  : 0x400e7794
// Size     : 110 bytes


void FUN_400e7794(undefined1 *param_1)

{
  int iVar1;
  undefined1 uVar2;
  uint uVar3;
  
  iVar1 = FUN_400f1a9c();
  uVar3 = iVar1 - *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 4) == 4) {
    if (uVar3 < *(uint *)(param_1 + 0x10)) {
      return;
    }
    param_1[0xc] = param_1[0xc] ^ 1;
    FUN_400f1a40(*param_1);
    *(int *)(param_1 + 8) = iVar1;
    return;
  }
  if (uVar3 < 200) {
    if (param_1[0xc] != '\0') {
      return;
    }
  }
  else {
    if (uVar3 < *(uint *)(param_1 + 0x10)) {
      if (param_1[0xc] == '\0') {
        return;
      }
      FUN_400f1a40(*param_1,0);
      uVar2 = 0;
      goto LAB_400e77fa;
    }
    *(int *)(param_1 + 8) = iVar1;
  }
  FUN_400f1a40(*param_1,1);
  uVar2 = 1;
LAB_400e77fa:
  param_1[0xc] = uVar2;
  return;
}

