// Function : FUN_40185484
// Address  : 0x40185484
// Size     : 21 bytes


void FUN_40185484(int param_1,int *param_2)

{
  int *piVar1;
  
  for (piVar1 = *(int **)(param_1 + 0xcc); (piVar1 != (int *)0x0 && (piVar1[1] != *param_2));
      piVar1 = (int *)*piVar1) {
  }
  return;
}

