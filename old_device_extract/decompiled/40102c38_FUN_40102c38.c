// Function : FUN_40102c38
// Address  : 0x40102c38
// Size     : 67 bytes


void FUN_40102c38(int param_1)

{
  int *piVar1;
  
  piVar1 = (int *)(param_1 + 0x1c);
  do {
    if (*piVar1 != 0) {
      (*(code *)&SUB_40094d80)();
      *piVar1 = 0;
    }
    piVar1 = piVar1 + 4;
  } while (piVar1 != (int *)(param_1 + 0x5c));
  memw();
  (*(code *)&SUB_4008b530)((int *)(param_1 + 0x1c),0,0x40);
  *(undefined4 *)(param_1 + 0x7c) = 0;
  *(undefined4 *)(param_1 + 0x80) = 0;
  *(undefined4 *)(param_1 + 0x74) = 0;
  *(undefined4 *)(param_1 + 0xcc) = 0;
  memw();
  return;
}

