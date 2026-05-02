// Function : FUN_40107690
// Address  : 0x40107690
// Size     : 92 bytes


int * FUN_40107690(undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)(*(code *)&SUB_400841f0)(1,8,0x804);
  if (piVar1 != (int *)0x0) {
    iVar2 = (*(code *)&SUB_400841f0)(1,0x54,0x804);
    piVar1[1] = iVar2;
    if (iVar2 != 0) {
      iVar2 = (*(code *)&SUB_4008fa34)(param_1,param_2,iVar2);
      *piVar1 = iVar2;
      if (iVar2 != 0) goto LAB_401076de;
    }
    if (piVar1[1] != 0) {
      (*(code *)&SUB_40094d80)();
    }
    memw();
    (*(code *)&SUB_40094d80)(piVar1);
    piVar1 = (int *)0x0;
  }
LAB_401076de:
  memw();
  return piVar1;
}

