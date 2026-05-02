// Function : FUN_40107770
// Address  : 0x40107770
// Size     : 70 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_40107770(void)

{
  int iVar1;
  
  if (DAT_3ffc58bc == '\0') {
    iVar1 = FUN_400fc7ac(&DAT_3ffc58b8,0x401073e8);
    if (iVar1 != 0) {
      return 0;
    }
    DAT_3ffc58bc = '\x01';
    memw();
  }
  memw();
  iVar1 = FUN_400fc83c(_DAT_3ffc58b8);
  if ((iVar1 == 0) && (iVar1 = (*(code *)&SUB_4008fa78)(1,0), iVar1 != 0)) {
    FUN_400fc864(_DAT_3ffc58b8,iVar1);
  }
  return iVar1;
}

