// Function : FUN_400f0990
// Address  : 0x400f0990
// Size     : 133 bytes


int FUN_400f0990(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  if ((param_3 == 0) || (param_2 == 0)) {
    return 0;
  }
  iVar3 = param_1 + 0x10;
  iVar1 = (*(code *)&LAB_40183a7b_1)(iVar3);
  iVar1 = param_3 + iVar1;
  iVar2 = FUN_400f0b60(iVar3,iVar1 + 1);
  if (iVar2 == 0) {
    return 0;
  }
  if ((*(byte *)(param_1 + 0x1f) & 0x80) == 0) {
    uVar4 = *(uint *)(param_1 + 0x18);
    iVar2 = *(int *)(param_1 + 0x10);
  }
  else {
    uVar4 = *(uint *)(param_1 + 0x1c) >> 0x18 & 0x7f;
    iVar2 = iVar3;
  }
  func_0x4008b3d8(iVar2 + uVar4,param_2,param_3);
  if ((*(byte *)(param_1 + 0x1f) & 0x80) == 0) {
    *(int *)(param_1 + 0x18) = iVar1;
    if (*(int *)(param_1 + 0x10) != 0) {
      *(undefined1 *)(*(int *)(param_1 + 0x10) + iVar1) = 0;
      goto LAB_400f09e9;
    }
  }
  else {
    *(byte *)(param_1 + 0x1f) = *(byte *)(param_1 + 0x1f) & 0x80 | (byte)iVar1 & 0x7f;
    *(undefined1 *)(param_1 + iVar1 + 0x10) = 0;
LAB_400f09e9:
    if ((*(byte *)(param_1 + 0x1f) & 0x80) != 0) goto LAB_400f09fa;
  }
  iVar3 = *(int *)(param_1 + 0x10);
LAB_400f09fa:
  *(undefined1 *)(iVar3 + iVar1) = 0;
  return param_3;
}

