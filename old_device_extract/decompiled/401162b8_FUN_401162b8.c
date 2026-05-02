// Function : FUN_401162b8
// Address  : 0x401162b8
// Size     : 53 bytes


void FUN_401162b8(int param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = *(int **)(param_1 + 0xcc);
  *(undefined4 *)(param_1 + 0xcc) = 0;
  while (piVar1 != (int *)0x0) {
    iVar2 = *piVar1;
    if (*(code **)(param_1 + 0xf4) != (code *)0x0) {
      (**(code **)(param_1 + 0xf4))(param_1,piVar1 + 1,0);
    }
    FUN_4010b078(0xb,piVar1);
    piVar1 = (int *)iVar2;
  }
  memw();
  return;
}

