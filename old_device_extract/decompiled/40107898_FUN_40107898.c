// Function : FUN_40107898
// Address  : 0x40107898
// Size     : 48 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40107898(int *param_1)

{
  FUN_4011b020();
  *param_1 = (int)_DAT_3ffc58c0;
  if (_DAT_3ffc58c0 != (int *)0x0) {
    *(int **)((int)_DAT_3ffc58c0 + 4) = param_1;
  }
  memw();
  _DAT_3ffc58c4 = _DAT_3ffc58c4 + 1;
  memw();
  memw();
  _DAT_3ffc58c0 = param_1;
  FUN_4011b040();
  return;
}

