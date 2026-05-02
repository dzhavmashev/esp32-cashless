// Function : FUN_40185bb8
// Address  : 0x40185bb8
// Size     : 26 bytes


undefined4 FUN_40185bb8(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (((param_1[0x11] != 0) && (iVar1 = *(int *)(param_1[0x11] + 0x1e4), iVar1 != 0)) ||
     (iVar1 = *(int *)(*param_1 + 0xa0), uVar2 = 0, iVar1 != 0)) {
    uVar2 = *(undefined4 *)(iVar1 + 4);
  }
  return uVar2;
}

