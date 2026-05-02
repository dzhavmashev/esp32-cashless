// Function : FUN_40165ee0
// Address  : 0x40165ee0
// Size     : 33 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_40165ee0(void)

{
  int iVar1;
  
  iVar1 = 0x1800;
  if ((_DAT_3ffc8b18 & 1) == 0) {
    iVar1 = 0xc00;
  }
  if (_DAT_3ffc8b00 == 0) {
    iVar1 = iVar1 + 0x200;
  }
  return iVar1;
}

