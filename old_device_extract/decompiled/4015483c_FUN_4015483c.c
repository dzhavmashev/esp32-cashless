// Function : FUN_4015483c
// Address  : 0x4015483c
// Size     : 64 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4015483c(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = _DAT_3ffc8804;
  iVar2 = param_1[4];
  if (iVar2 == param_1[5]) {
    param_1[5] = 0;
    param_1[4] = 0;
    memw();
  }
  else {
    param_1[4] = *(int *)(iVar2 + 0x28);
    *(undefined4 *)(iVar2 + 0x28) = 0;
  }
  if (iVar2 != 0) {
    param_1[6] = param_1[6] + -1;
    *param_1 = *param_1 + -1;
    *(int *)(iVar1 + 0x138) = *(int *)(iVar1 + 0x138) + -1;
  }
  memw();
  return;
}

