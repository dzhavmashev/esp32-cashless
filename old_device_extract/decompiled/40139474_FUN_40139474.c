// Function : FUN_40139474
// Address  : 0x40139474
// Size     : 40 bytes


int * FUN_40139474(int param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = &DAT_3f42209c;
  while( true ) {
    if (*piVar1 == 0) {
      return (int *)0x0;
    }
    if ((piVar1[1] == *(int *)(param_1 + 4)) &&
       (iVar2 = (*(code *)&SUB_4008b33c)(*piVar1,*(undefined4 *)(param_1 + 8)), iVar2 == 0)) break;
    piVar1 = piVar1 + 6;
  }
  return piVar1;
}

