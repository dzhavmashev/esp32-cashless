// Function : FUN_40162358
// Address  : 0x40162358
// Size     : 55 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40162358(void)

{
  _DAT_3ffca2f8 = 0;
  memw();
  (**(code **)(_DAT_3ffc1a34 + 0xec))(0x3ffca2cc);
  if (DAT_3ffca2f5 != '\0') {
    FUN_40161328();
    DAT_3ffca2f5 = '\x01';
    memw();
    memw();
    FUN_401615fc();
  }
  return;
}

