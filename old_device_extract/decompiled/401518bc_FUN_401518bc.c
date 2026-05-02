// Function : FUN_401518bc
// Address  : 0x401518bc
// Size     : 36 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_401518bc(int *param_1)

{
  if (*param_1 != 0) {
    *(int *)(param_1[1] + 4) = param_1[4] + 0x24;
    if (_DAT_3ffc7a68 != (code *)0x0) {
      memw();
      (*_DAT_3ffc7a68)();
    }
  }
  FUN_4015fb44(param_1);
  return;
}

