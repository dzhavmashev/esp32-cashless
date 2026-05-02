// Function : FUN_401184fc
// Address  : 0x401184fc
// Size     : 53 bytes


void FUN_401184fc(int param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = *(int **)(param_1 + 0xd0);
  *(undefined4 *)(param_1 + 0xd0) = 0;
  while (piVar1 != (int *)0x0) {
    iVar2 = *piVar1;
    if (*(code **)(param_1 + 0xf8) != (code *)0x0) {
      (**(code **)(param_1 + 0xf8))(param_1,piVar1 + 1,0);
    }
    FUN_4010b078(0xf,piVar1);
    piVar1 = (int *)iVar2;
  }
  memw();
  return;
}

