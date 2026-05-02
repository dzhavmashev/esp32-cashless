// Function : FUN_40147660
// Address  : 0x40147660
// Size     : 52 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40147660(int param_1)

{
  DAT_3ffc89c5 = 1;
  memw();
  if (((param_1 != 0) && (*(int *)(param_1 + 0x2c) != 0)) && (_DAT_3ffc89b0 != (code *)0x0)) {
    memw();
    (*_DAT_3ffc89b0)(*(char *)(*(int *)(param_1 + 0x2c) + 0x13) != '\x01');
  }
  return;
}

