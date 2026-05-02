// Function : FUN_401162f0
// Address  : 0x401162f0
// Size     : 31 bytes


void FUN_401162f0(int param_1)

{
  int *piVar1;
  
  if (*(int **)(param_1 + 0xcc) != (int *)0x0) {
    for (piVar1 = (int *)**(int **)(param_1 + 0xcc); piVar1 != (int *)0x0; piVar1 = (int *)*piVar1)
    {
      FUN_40116274(piVar1,5);
    }
  }
  return;
}

