// Function : FUN_40123394
// Address  : 0x40123394
// Size     : 66 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40123394(void)

{
  (*(code *)&SUB_40086460)(0x3ffc75f4);
  DAT_3ffc75dc = DAT_3ffc75dc + '\x01';
  memw();
  if (_DAT_3ffc75e0 == 0) {
    memw();
    _DAT_3ffc75e0 = (*(code *)&SUB_40083fe0)(0x54,0x808);
  }
  memw();
  (*(code *)&SUB_400864a0)(0x3ffc75f4);
  return;
}

