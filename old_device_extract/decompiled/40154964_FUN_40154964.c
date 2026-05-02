// Function : FUN_40154964
// Address  : 0x40154964
// Size     : 110 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_40154964(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = _DAT_3ffc8804;
  iVar2 = FUN_4015492c(param_1 + 0x108);
  if (iVar2 == 0) {
    *(int *)(param_1 + 0x114) = *(int *)(param_1 + 0x114) + 1;
    *(int *)(iVar1 + 0x140) = *(int *)(iVar1 + 0x140) + 1;
    memw();
    FUN_4015fb44(param_2);
    return 1;
  }
  if (*(int *)(param_1 + 0x11c) == 0) {
    *(int *)(param_1 + 0x118) = param_2;
    memw();
  }
  else {
    *(int *)(*(int *)(param_1 + 0x11c) + 0x28) = param_2;
  }
  iVar2 = *(int *)(param_1 + 0x120);
  *(undefined4 *)(param_2 + 0x28) = 0;
  iVar3 = *(int *)(param_1 + 0x108) + 1;
  *(int *)(param_1 + 0x120) = iVar2 + 1;
  iVar2 = *(int *)(iVar1 + 0x138);
  *(int *)(param_1 + 0x11c) = param_2;
  *(int *)(param_1 + 0x108) = iVar3;
  *(int *)(iVar1 + 0x138) = iVar2 + 1;
  if (iVar3 == 1) {
    memw();
    FUN_401547bc(param_1);
  }
  return 0;
}

