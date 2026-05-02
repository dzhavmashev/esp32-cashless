// Function : FUN_4010d4ec
// Address  : 0x4010d4ec
// Size     : 48 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4010d4ec(void)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  uVar4 = 0;
  iVar3 = 0;
  for (iVar1 = _DAT_3ffc8418; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x34)) {
    uVar2 = _DAT_3ffc8414 - *(int *)(iVar1 + 0x4c);
    if (uVar4 <= uVar2) {
      iVar3 = iVar1;
      uVar4 = uVar2;
    }
  }
  if (iVar3 != 0) {
    FUN_4010d4dc();
  }
  return;
}

