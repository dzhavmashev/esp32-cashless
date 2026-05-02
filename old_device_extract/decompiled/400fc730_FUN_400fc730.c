// Function : FUN_400fc730
// Address  : 0x400fc730
// Size     : 45 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400fc730(int param_1)

{
  int *piVar1;
  
  (*(code *)&SUB_40092a98)(0x3ffbdcd4,0xffffffff);
  for (piVar1 = _DAT_3ffc56ec; (piVar1 != (int *)0x0 && (*piVar1 != param_1));
      piVar1 = (int *)piVar1[2]) {
  }
  (*(code *)&SUB_40092bec)(0x3ffbdcd4);
  return;
}

