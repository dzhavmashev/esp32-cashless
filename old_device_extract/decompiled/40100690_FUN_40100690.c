// Function : FUN_40100690
// Address  : 0x40100690
// Size     : 31 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_40100690(int param_1)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = _DAT_3ffc5858;
  if (param_1 != 0) {
    do {
      if (piVar2 == (int *)0x0) {
        return 0;
      }
      iVar1 = *piVar2;
      piVar2 = (int *)piVar2[1];
    } while (param_1 != iVar1);
  }
  iVar1 = 0;
  if (piVar2 != (int *)0x0) {
    iVar1 = *piVar2;
  }
  return iVar1;
}

