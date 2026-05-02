// Function : FUN_4013d838
// Address  : 0x4013d838
// Size     : 43 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4013d838(void)

{
  _DAT_3ff00490 = (*(code *)&SUB_40084594)(&DAT_3ff00490);
  _DAT_3ff00490 = _DAT_3ff00490 | 1;
  memw();
  memw();
  FUN_400f55ec(0x20);
  (*(code *)&SUB_400864a0)(0x3ffc78cc);
  return;
}

