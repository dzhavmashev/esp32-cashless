// Function : FUN_4013d79c
// Address  : 0x4013d79c
// Size     : 27 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4013d79c(void)

{
  int iVar1;
  
  do {
    iVar1 = (*(code *)&SUB_40084594)(&DAT_3ff02814);
  } while (iVar1 != 1);
  memw();
  _DAT_3ff02814 = iVar1;
  memw();
  return;
}

