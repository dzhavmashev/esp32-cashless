// Function : FUN_40118534
// Address  : 0x40118534
// Size     : 28 bytes


void FUN_40118534(int param_1)

{
  int *piVar1;
  
  for (piVar1 = *(int **)(param_1 + 0xd0); piVar1 != (int *)0x0; piVar1 = (int *)*piVar1) {
    FUN_40118498(piVar1,500);
  }
  return;
}

