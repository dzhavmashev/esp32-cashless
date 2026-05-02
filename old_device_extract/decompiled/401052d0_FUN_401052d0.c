// Function : FUN_401052d0
// Address  : 0x401052d0
// Size     : 31 bytes


int * FUN_401052d0(int param_1)

{
  int *piVar1;
  
  piVar1 = (int *)(*(code *)&SUB_40094dd8)(1,param_1 + 0x10);
  if (piVar1 != (int *)0x0) {
    *piVar1 = param_1;
    piVar1[2] = (int)(piVar1 + 4);
  }
  memw();
  return piVar1;
}

