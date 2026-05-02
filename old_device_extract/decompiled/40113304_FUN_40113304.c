// Function : FUN_40113304
// Address  : 0x40113304
// Size     : 60 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40113304(int param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  
  piVar3 = (int *)0x0;
  piVar4 = _DAT_3ffc6374;
  do {
    piVar2 = piVar4;
    piVar1 = piVar3;
    if (piVar2 == (int *)0x0) {
      return;
    }
    piVar4 = (int *)*piVar2;
    piVar3 = piVar2;
  } while ((piVar2[2] != param_1) || (piVar2[3] != param_2));
  if (piVar1 != (int *)0x0) {
    *piVar1 = (int)piVar4;
    memw();
    piVar4 = _DAT_3ffc6374;
  }
  _DAT_3ffc6374 = piVar4;
  memw();
  FUN_4010b078(0xc);
  return;
}

