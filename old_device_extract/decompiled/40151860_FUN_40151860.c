// Function : FUN_40151860
// Address  : 0x40151860
// Size     : 88 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int * FUN_40151860(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  
  memw();
  iVar1 = FUN_40165f44();
  if (iVar1 == 0) {
    piVar2 = (int *)FUN_4015fb34(param_1,1,param_2);
  }
  else if (param_3 == 0) {
    piVar3 = (int *)FUN_4015fb34(param_1,9,param_2);
    piVar2 = (int *)0x0;
    if (piVar3 != (int *)0x0) {
      *piVar3 = 0;
      memw();
      return piVar3;
    }
  }
  else {
    piVar2 = (int *)FUN_4015fb34(0,9,param_2);
    if (piVar2 != (int *)0x0) {
      *piVar2 = param_3;
      *(undefined4 *)(piVar2[1] + 4) = param_1;
      if (_DAT_3ffc7a60 != (code *)0x0) {
        memw();
        (*_DAT_3ffc7a60)(param_3);
        return piVar2;
      }
    }
  }
  return piVar2;
}

