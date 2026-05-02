// Function : FUN_401077f0
// Address  : 0x401077f0
// Size     : 100 bytes


int * FUN_401077f0(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)(*(code *)&SUB_40083fe0)(8,0x804);
  if (piVar1 != (int *)0x0) {
    iVar2 = (*(code *)&SUB_400841f0)(1,param_1 * param_2 + 0x54,0x804);
    piVar1[1] = iVar2;
    if (iVar2 != 0) {
      iVar2 = (*(code *)&SUB_4008f8e0)(param_1,param_2,iVar2 + 0x54,iVar2,0);
      *piVar1 = iVar2;
      if (iVar2 != 0) goto LAB_40107846;
    }
    if (piVar1[1] != 0) {
      (*(code *)&SUB_40094d80)();
    }
    memw();
    (*(code *)&SUB_40094d80)(piVar1);
    piVar1 = (int *)0x0;
  }
LAB_40107846:
  memw();
  return piVar1;
}

