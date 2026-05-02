// Function : FUN_401006b0
// Address  : 0x401006b0
// Size     : 76 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_401006b0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  iVar1 = FUN_40100598();
  piVar3 = _DAT_3ffc5858;
  if (iVar1 == 0) {
    for (; piVar3 != (int *)0x0; piVar3 = (int *)piVar3[1]) {
      if (param_1 == *piVar3) {
        FUN_401005b0();
        return 1;
      }
    }
    FUN_401005b0();
  }
  else {
    uVar2 = (*(code *)&SUB_40094b80)();
    FUN_4012113c(1,"jects.c","objects",uVar2,"jects.c",iVar1);
  }
  return 0;
}

