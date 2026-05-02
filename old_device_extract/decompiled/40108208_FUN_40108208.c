// Function : FUN_40108208
// Address  : 0x40108208
// Size     : 26 bytes


int * FUN_40108208(undefined4 param_1)

{
  int *piVar1;
  
  piVar1 = (int *)FUN_401079dc(param_1);
  if ((piVar1 != (int *)0x0) && (*piVar1 == 0)) {
    FUN_40108194();
    piVar1 = (int *)0x0;
  }
  return piVar1;
}

