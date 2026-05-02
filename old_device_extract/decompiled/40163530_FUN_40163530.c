// Function : FUN_40163530
// Address  : 0x40163530
// Size     : 72 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_40163530(void)

{
  int iVar1;
  
  iVar1 = FUN_401882b4();
  if (iVar1 == 0) {
    return 0;
  }
  if (*(int *)(_DAT_3ffc0034 + 0x334) == 0) {
    if (*(int *)(_DAT_3ffc0034 + 0x33c) != 0) {
      return 0;
    }
    if ((((*(char *)(_DAT_3ffc0034 + 0x29) != '\0') || (*(int *)(_DAT_3ffc0034 + 0x34) == 0)) &&
        (*(int *)(_DAT_3ffc0034 + 0x20) == 0)) && (*(int *)(_DAT_3ffc0034 + 0x344) == 0)) {
      return iVar1;
    }
  }
  return 0;
}

