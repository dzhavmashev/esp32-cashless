// Function : FUN_40183b58
// Address  : 0x40183b58
// Size     : 28 bytes


void FUN_40183b58(int *param_1,undefined1 param_2)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = param_1[2];
  uVar2 = iVar1 + 1;
  if (uVar2 < (uint)param_1[3]) {
    param_1[2] = uVar2;
    *(undefined1 *)(param_1[1] + iVar1) = param_2;
  }
  else {
    *(undefined1 *)(*param_1 + 0x10) = 1;
  }
  return;
}

