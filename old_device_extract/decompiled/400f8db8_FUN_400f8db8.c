// Function : FUN_400f8db8
// Address  : 0x400f8db8
// Size     : 130 bytes


int * FUN_400f8db8(int *param_1)

{
  int iVar1;
  int iVar2;
  
  if (param_1 == (int *)0x0) {
    (*(code *)&SUB_40094c54)("i_flash/partition.c",0x6a,"ion_get","LBMultiHit");
  }
  if (param_1[3] != 0) {
    (*(code *)&SUB_40086460)(0x3ffc55a4);
    while ((iVar2 = param_1[3], iVar2 != 0 &&
           ((((*param_1 != 0xff && (*param_1 != *(int *)(iVar2 + 4))) ||
             ((param_1[1] != 0xff && (param_1[1] != *(int *)(iVar2 + 8))))) ||
            ((param_1[2] != 0 &&
             (iVar1 = (*(code *)&SUB_4008bdec)(param_1[2],iVar2 + 0x14), iVar1 != 0))))))) {
      param_1[3] = *(int *)(iVar2 + 0x2c);
      memw();
    }
    (*(code *)&SUB_400864a0)(0x3ffc55a4);
    iVar2 = param_1[3];
    if (iVar2 != 0) {
      param_1[4] = iVar2;
      param_1[3] = *(int *)(iVar2 + 0x2c);
      memw();
      return param_1;
    }
  }
  (*(code *)&SUB_40094d80)(param_1);
  return (int *)0x0;
}

