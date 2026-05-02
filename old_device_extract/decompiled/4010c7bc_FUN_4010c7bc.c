// Function : FUN_4010c7bc
// Address  : 0x4010c7bc
// Size     : 57 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4010c7bc(undefined1 param_1)

{
  int iVar1;
  
  iVar1 = FUN_4010b058(0);
  if (iVar1 != 0) {
    (*(code *)&SUB_4008b530)(iVar1,0,0x48);
    *(undefined1 *)(iVar1 + 0x33) = 0x40;
    *(undefined1 *)(iVar1 + 0x3b) = 0x40;
    memw();
    *(undefined1 *)(iVar1 + 0x38) = param_1;
    memw();
    *(int *)(iVar1 + 0x34) = _DAT_3ffc6330;
    _DAT_3ffc6330 = iVar1;
  }
  memw();
  return;
}

