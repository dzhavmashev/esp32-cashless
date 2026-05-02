// Function : FUN_4011dd58
// Address  : 0x4011dd58
// Size     : 39 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_4011dd58(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = 0;
  for (iVar3 = _DAT_3ffc87d8; iVar3 != 0; iVar3 = *(int *)(iVar3 + 0x20)) {
    iVar2 = FUN_401855c4(iVar3,param_1);
    if (iVar2 != 0) {
      iVar2 = FUN_4018e3f4(*(undefined4 *)(iVar3 + 0x1c));
      iVar1 = iVar1 + iVar2;
    }
  }
  return iVar1;
}

