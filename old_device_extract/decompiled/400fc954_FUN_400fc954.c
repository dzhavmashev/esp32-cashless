// Function : FUN_400fc954
// Address  : 0x400fc954
// Size     : 58 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int * FUN_400fc954(int param_1,undefined1 *param_2)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  
  *param_2 = 1;
  memw();
  piVar1 = (int *)*_DAT_3ffc570c;
  piVar2 = (int *)0x0;
  while (piVar1 != (int *)0x0) {
    piVar3 = piVar1;
    if ((*piVar1 != param_1) && (piVar3 = piVar2, (char)piVar1[1] == '\0')) {
      *param_2 = 0;
      memw();
    }
    piVar1 = (int *)piVar1[2];
    memw();
    piVar2 = piVar3;
  }
  memw();
  return piVar2;
}

