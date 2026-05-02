// Function : FUN_401708bc
// Address  : 0x401708bc
// Size     : 64 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_401708bc(void)

{
  int *piVar1;
  int *piVar2;
  
  (*(code *)&LAB_400fc63a_2)(0x3ffc7eac,0);
  _DAT_3ffc7eb4 = (int *)0x0;
  piVar2 = (int *)FUN_40184c34();
  _DAT_3ffc7eb8 = piVar2;
  if (piVar2 != (int *)0x0) {
    _DAT_3ffc7eb4 = (int *)(*(code *)&SUB_40094d60)();
  }
  piVar1 = _DAT_3ffc7eb4;
  if (_DAT_3ffc7eb4 == (int *)0x0) {
    _DAT_3ffc7eb8 = _DAT_3ffc7eb4;
    _DAT_3ffc7eb0 = _DAT_3ffc7eb4;
  }
  else {
    _DAT_3ffc7eb0 = _DAT_3ffc7eb4;
    *_DAT_3ffc7eb4 = (int)piVar2;
    piVar1[1] = 0;
  }
  return;
}

