// Function : FUN_40113380
// Address  : 0x40113380
// Size     : 32 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_40113380(void)

{
  int iVar1;
  
  iVar1 = -1;
  if (_DAT_3ffc6374 != 0) {
    iVar1 = FUN_4011b010();
    iVar1 = *(int *)(_DAT_3ffc6374 + 4) - iVar1;
    iVar1 = (uint)(-1 < iVar1) * iVar1;
  }
  return iVar1;
}

