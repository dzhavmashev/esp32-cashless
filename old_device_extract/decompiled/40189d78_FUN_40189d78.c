// Function : FUN_40189d78
// Address  : 0x40189d78
// Size     : 37 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_40189d78(void)

{
  int iVar1;
  
  iVar1 = 0x103;
  if (_DAT_3ffc78f4 != 0) {
    iVar1 = (**(code **)(_DAT_3ffc17c4 + 0x2c))();
    iVar1 = -(uint)(iVar1 != 1);
  }
  return iVar1;
}

