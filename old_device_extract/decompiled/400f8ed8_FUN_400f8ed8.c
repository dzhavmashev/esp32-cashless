// Function : FUN_400f8ed8
// Address  : 0x400f8ed8
// Size     : 108 bytes


int * FUN_400f8ed8(int *param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == (int *)0x0) {
    (*(code *)&SUB_40094c54)("i_flash/partition.c",0x186,"on_read","!= NULL");
  }
  piVar2 = (int *)0x0;
  if ((char)param_1[5] != '\0') {
    piVar2 = param_1 + 5;
  }
  iVar1 = FUN_400f8e3c(param_1[1],param_1[2],piVar2);
  while( true ) {
    if (iVar1 == 0) {
      return (int *)0x0;
    }
    piVar2 = (int *)FUN_400f8e98(iVar1);
    if ((((*piVar2 == *param_1) && (piVar2[3] == param_1[3])) && (param_1[4] == piVar2[4])) &&
       (*(char *)((int)param_1 + 0x25) == *(char *)((int)piVar2 + 0x25))) break;
    iVar1 = FUN_400f8db8(iVar1);
  }
  (*(code *)&SUB_40094d80)(iVar1);
  return piVar2;
}

