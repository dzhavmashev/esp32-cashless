// Function : FUN_400f3354
// Address  : 0x400f3354
// Size     : 48 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400f3354(void)

{
  memw();
  if (DAT_3ffc5544 == '\0') {
    memw();
    DAT_3ffc5544 = '\x01';
    _DAT_3ffc5548 = (*(code *)&SUB_4008fcc8)(1);
    if (_DAT_3ffc5548 == 0) {
      memw();
      DAT_3ffc5544 = '\0';
    }
  }
  return;
}

