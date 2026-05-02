// Function : FUN_401854d8
// Address  : 0x401854d8
// Size     : 48 bytes


void FUN_401854d8(int param_1,int *param_2)

{
  int *piVar1;
  
  for (piVar1 = *(int **)(param_1 + 0xd0);
      (piVar1 != (int *)0x0 &&
      ((((piVar1[1] != *param_2 || (piVar1[2] != param_2[1])) || (piVar1[3] != param_2[2])) ||
       ((piVar1[4] != param_2[3] || (*(char *)(piVar1 + 5) != (char)param_2[4]))))));
      piVar1 = (int *)*piVar1) {
  }
  return;
}

