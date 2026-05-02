// Function : FUN_4015c48c
// Address  : 0x4015c48c
// Size     : 42 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_4015c48c(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = _DAT_3ffca0b0;
  while( true ) {
    if (iVar2 == 0) {
      return 0;
    }
    iVar1 = (*(code *)&SUB_4008b33c)(param_1,iVar2,6);
    if (iVar1 == 0) break;
    iVar2 = *(int *)(iVar2 + 8);
  }
  return 1;
}

