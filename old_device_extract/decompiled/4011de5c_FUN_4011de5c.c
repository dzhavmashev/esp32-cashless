// Function : FUN_4011de5c
// Address  : 0x4011de5c
// Size     : 42 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4011de5c(void)

{
  int iVar1;
  
  for (iVar1 = _DAT_3ffc87d8; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x20)) {
    if (*(int *)(iVar1 + 0x1c) == 0) {
      FUN_4011de2c(iVar1);
      if (*(int *)(iVar1 + 0x1c) != 0) {
        (*(code *)&SUB_40094924)(*(int *)(iVar1 + 0x1c),iVar1 + 0x14);
      }
    }
  }
  return;
}

