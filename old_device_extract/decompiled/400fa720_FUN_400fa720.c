// Function : FUN_400fa720
// Address  : 0x400fa720
// Size     : 92 bytes


void FUN_400fa720(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  FUN_400fa6e4(param_1 + 0x38);
  iVar1 = *(int *)(param_1 + 0x28);
  if (iVar1 != 0) {
    iVar2 = iVar1 + *(int *)(iVar1 + -4) * 0x54;
    for (iVar3 = iVar2; iVar1 != iVar3; iVar3 = iVar3 + -0x54) {
      FUN_400fafec(iVar3 + -0x10);
    }
    FUN_4016fffc(iVar2 + (((uint)(iVar2 - iVar1) >> 2) * 0x3cf3cf3d & 0x3fffffff) * -0x54 + -4);
  }
  return;
}

