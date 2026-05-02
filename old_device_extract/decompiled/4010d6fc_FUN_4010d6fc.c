// Function : FUN_4010d6fc
// Address  : 0x4010d6fc
// Size     : 53 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4010d6fc(int param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  uVar2 = 0;
  iVar3 = 0;
  for (iVar4 = _DAT_3ffc840c; iVar4 != 0; iVar4 = *(int *)(iVar4 + 0x34)) {
    if ((*(int *)(iVar4 + 0x3c) == param_1) &&
       (uVar1 = _DAT_3ffc8414 - *(int *)(iVar4 + 0x4c), uVar2 <= uVar1)) {
      uVar2 = uVar1;
      iVar3 = iVar4;
    }
  }
  if (iVar3 != 0) {
    FUN_4010d3fc();
  }
  return;
}

