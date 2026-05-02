// Function : FUN_4012121c
// Address  : 0x4012121c
// Size     : 66 bytes


void FUN_4012121c(int param_1)

{
  code *pcVar1;
  int iVar2;
  
  if (param_1 != 0) {
    iVar2 = *(int *)(param_1 + 0x14);
    while (iVar2 != 0) {
      iVar2 = *(int *)(iVar2 + 0x10);
      (*(code *)&SUB_40094d80)();
    }
    if (*(int *)(param_1 + 0x1c) != 0) {
      (*(code *)&SUB_40094d80)();
    }
    if ((*(int *)(param_1 + 8) != 0) &&
       (pcVar1 = *(code **)(*(int *)(param_1 + 8) + 8), pcVar1 != (code *)0x0)) {
      (*pcVar1)(*(undefined4 *)(param_1 + 0xc));
    }
    if (*(int *)(param_1 + 0x10) != 0) {
      (*(code *)&SUB_40094d80)();
    }
    (*(code *)&SUB_40094d80)(param_1);
  }
  return;
}

