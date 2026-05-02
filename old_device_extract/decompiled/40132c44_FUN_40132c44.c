// Function : FUN_40132c44
// Address  : 0x40132c44
// Size     : 24 bytes


int FUN_40132c44(int param_1)

{
  int *piVar1;
  
  for (piVar1 = &DAT_3f41d570; (piVar1[1] != 0 && (*piVar1 != param_1)); piVar1 = piVar1 + 2) {
  }
  return piVar1[1];
}

