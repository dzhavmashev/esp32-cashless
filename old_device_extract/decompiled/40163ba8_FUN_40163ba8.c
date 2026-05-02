// Function : FUN_40163ba8
// Address  : 0x40163ba8
// Size     : 63 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40163ba8(uint param_1)

{
  int iVar1;
  
  param_1 = param_1 & 0xff;
  if ((*(char *)(_DAT_3ffc0034 + param_1 * 0x30 + 0x29) == '\0') &&
     (*(int *)(_DAT_3ffc0034 + (param_1 + 1) * 0x30 + 4) != 0)) {
    FUN_40163b5c();
  }
  while (iVar1 = FUN_40162d70(param_1), iVar1 != 0) {
    FUN_4018a7b8();
  }
  return;
}

