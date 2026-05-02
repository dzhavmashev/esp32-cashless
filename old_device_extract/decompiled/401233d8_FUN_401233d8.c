// Function : FUN_401233d8
// Address  : 0x401233d8
// Size     : 71 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_401233d8(void)

{
  (*(code *)&SUB_40086460)(0x3ffc75f4);
  DAT_3ffc75dc = DAT_3ffc75dc + -1;
  memw();
  if (DAT_3ffc75dc == '\0') {
    memw();
    memw();
    DAT_3ffc75f1 = DAT_3ffc75dc;
    (*(code *)&SUB_40094d80)(_DAT_3ffc75e0);
    _DAT_3ffc75e0 = 0;
  }
  memw();
  (*(code *)&SUB_400864a0)(0x3ffc75f4);
  return;
}

