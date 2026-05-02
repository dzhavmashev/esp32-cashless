// Function : FUN_40154880
// Address  : 0x40154880
// Size     : 79 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40154880(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = _DAT_3ffc8804;
  iVar2 = FUN_4015483c(param_1 + 0x108);
  if (iVar2 != 0) {
    FUN_4015fb44();
    *(int *)(param_1 + 0x114) = *(int *)(param_1 + 0x114) + 1;
    iVar3 = *(int *)(param_1 + 0x108);
    iVar2 = *(int *)(param_1 + 0x10c);
    *(int *)(iVar1 + 0x140) = *(int *)(iVar1 + 0x140) + 1;
    if (iVar3 + iVar2 == 0) {
      memw();
      FUN_401547bc(param_1);
    }
    _DAT_3ffc7950 = _DAT_3ffc7950 + 1;
    memw();
  }
  memw();
  return;
}

