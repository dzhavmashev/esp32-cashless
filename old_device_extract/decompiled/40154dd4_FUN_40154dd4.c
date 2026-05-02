// Function : FUN_40154dd4
// Address  : 0x40154dd4
// Size     : 54 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_40154dd4(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = _DAT_3ffbfc54 + 0x488;
  if ((((*(int *)(_DAT_3ffbfc54 + 0x490) == 0) && (_DAT_3ffc8800 != 0)) &&
      (*(int *)(_DAT_3ffc8800 + 0x98) == 5)) &&
     ((iVar2 = *(int *)(_DAT_3ffc8800 + 0xe4), iVar2 != 0 && (*(char *)(iVar2 + 0x2af) != '\0')))) {
    iVar1 = iVar2 + 0x2ac;
  }
  return iVar1;
}

