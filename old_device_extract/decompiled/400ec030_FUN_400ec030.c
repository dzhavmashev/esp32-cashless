// Function : FUN_400ec030
// Address  : 0x400ec030
// Size     : 144 bytes


void FUN_400ec030(undefined2 *param_1,undefined1 *param_2,undefined4 *param_3,int param_4)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = 0;
  for (iVar4 = 0; iVar4 != param_4; iVar4 = iVar4 + 1) {
    iVar2 = func_0x4008c024(param_3[iVar4 * 2]);
    iVar3 = iVar3 + iVar2 + 3;
  }
  iVar4 = FUN_400ebc28(param_1,iVar3 + 2,1);
  if (iVar4 == 0) {
    uVar1 = 1;
  }
  else {
    **(undefined1 **)(param_1 + 2) = 0x82;
    iVar3 = FUN_401845b0(iVar3 + 2,*(int *)(param_1 + 2) + 1);
    *(char *)(*(int *)(param_1 + 2) + iVar3 + 1) = (char)((ushort)*param_1 >> 8);
    *(char *)(*(int *)(param_1 + 2) + iVar3 + 2) = (char)*param_1;
    iVar3 = iVar3 + 3;
    for (iVar4 = 0; iVar4 != param_4; iVar4 = iVar4 + 1) {
      iVar2 = FUN_400ec628(*param_3,*(int *)(param_1 + 2) + iVar3);
      iVar2 = iVar3 + iVar2;
      iVar3 = iVar2 + 1;
      *(undefined1 *)(*(int *)(param_1 + 2) + iVar2) = *(undefined1 *)(param_3 + 1);
      param_3 = param_3 + 2;
    }
    uVar1 = 0;
  }
  *param_2 = uVar1;
  return;
}

