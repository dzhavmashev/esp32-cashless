// Function : FUN_4013d7fc
// Address  : 0x4013d7fc
// Size     : 57 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4013d7fc(void)

{
  int iVar1;
  
  (*(code *)&SUB_40086460)(0x3ffc78cc);
  FUN_400f552c(0x20);
  _DAT_3ff00490 = (*(code *)&SUB_40084594)(&DAT_3ff00490);
  _DAT_3ff00490 = _DAT_3ff00490 & 0xfffffffe;
  memw();
  do {
    memw();
    iVar1 = (*(code *)&SUB_40084594)(0x3ff02818);
  } while (iVar1 != 1);
  return;
}

