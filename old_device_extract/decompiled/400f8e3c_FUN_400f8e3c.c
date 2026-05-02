// Function : FUN_400f8e3c
// Address  : 0x400f8e3c
// Size     : 70 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_400f8e3c(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  
  if (((_DAT_3ffc55a8 == 0) && (iVar2 = FUN_400f8bc4(), iVar2 != 0)) ||
     ((param_1 == 0xff && (param_2 != 0xff)))) {
    uVar1 = 0;
  }
  else {
    piVar3 = (int *)(*(code *)&SUB_40094d60)(0x14);
    *piVar3 = param_1;
    piVar3[3] = _DAT_3ffc55a8;
    piVar3[4] = 0;
    piVar3[1] = param_2;
    piVar3[2] = param_3;
    memw();
    uVar1 = FUN_400f8db8();
  }
  return uVar1;
}

