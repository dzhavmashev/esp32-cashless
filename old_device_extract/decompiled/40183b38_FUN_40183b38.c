// Function : FUN_40183b38
// Address  : 0x40183b38
// Size     : 29 bytes


void FUN_40183b38(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *param_1;
  iVar2 = *(int *)(iVar1 + 4);
  param_1[1] = iVar2;
  iVar2 = *(int *)(iVar1 + 8) - iVar2;
  param_1[3] = iVar2;
  param_1[2] = 0;
  if (iVar2 == 0) {
    *(undefined1 *)(iVar1 + 0x10) = 1;
  }
  return;
}

