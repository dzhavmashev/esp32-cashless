// Function : FUN_4017f2b8
// Address  : 0x4017f2b8
// Size     : 65 bytes


undefined4 FUN_4017f2b8(int param_1,int *param_2,int *param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  for (iVar2 = *param_3; iVar2 <= param_1; iVar2 = iVar2 + 1) {
    iVar1 = param_2[2];
    iVar3 = iVar1 + 4;
    param_2[2] = iVar3;
    if (iVar3 < 0x19) {
      iVar1 = param_2[1];
    }
    else {
      if (iVar1 < 0x19) {
        param_2[2] = 0x24;
      }
      iVar1 = *param_2;
    }
    *(undefined4 *)(param_4 + iVar2 * 4) = *(undefined4 *)(iVar1 + param_2[2] + -4);
  }
  *param_3 = iVar2;
  return *(undefined4 *)(param_4 + param_1 * 4);
}

