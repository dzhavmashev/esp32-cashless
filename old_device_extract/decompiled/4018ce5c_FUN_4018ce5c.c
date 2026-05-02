// Function : FUN_4018ce5c
// Address  : 0x4018ce5c
// Size     : 51 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4018ce5c(void)

{
  memw();
  _DAT_3ff73cb8 = _DAT_3ff73cb8 | 0x17ff;
  memw();
  memw();
  (*(code *)&SUB_40008534)(0x20);
  do {
    memw();
  } while ((_DAT_3ff73cb8 & 0x2000) != 0);
  return;
}

