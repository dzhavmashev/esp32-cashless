// Function : FUN_401594d4
// Address  : 0x401594d4
// Size     : 37 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_401594d4(void)

{
  uint uVar1;
  
  uVar1 = 0;
  if ((*(int *)(_DAT_3ffc89a4 + 0x48) != 0) && (uVar1 = 0, *(int *)(_DAT_3ffc89a4 + 0x4c) != 0)) {
    uVar1 = FUN_40165f28();
    uVar1 = uVar1 & 1;
  }
  return uVar1;
}

