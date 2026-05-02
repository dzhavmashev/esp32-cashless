// Function : FUN_401517dc
// Address  : 0x401517dc
// Size     : 49 bytes


uint FUN_401517dc(int param_1)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 * 8 + 0x3ffc8890);
  uVar1 = 0;
  if ((iVar2 != 0) && (uVar1 = 0, *(int *)(iVar2 + 4) != 0)) {
    uVar1 = (uint)*(byte *)(iVar2 + 8);
  }
  iVar2 = *(int *)(param_1 * 8 + 0x3ffc8894);
  if ((iVar2 != 0) && (*(int *)(iVar2 + 4) != 0)) {
    uVar1 = uVar1 + *(byte *)(iVar2 + 8);
  }
  return uVar1;
}

