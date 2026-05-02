// Function : FUN_4017415c
// Address  : 0x4017415c
// Size     : 228 bytes


void FUN_4017415c(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = (*(code *)&SUB_4009164c)();
  if (param_1 != iVar1) {
    if (*(int *)(param_1 + 0x24) != 0) {
      iVar1 = 0;
      if (*(int *)(*(int *)(param_1 + 0x24) + 0xc) != 0) {
        for (; iVar1 != 0x80; iVar1 = iVar1 + 4) {
          puVar2 = *(undefined4 **)(*(int *)(*(int *)(param_1 + 0x24) + 0xc) + iVar1);
          while (puVar2 != (undefined4 *)0x0) {
            puVar2 = (undefined4 *)*puVar2;
            (*(code *)&SUB_40094d98)(param_1);
          }
        }
        (*(code *)&SUB_40094d98)(param_1);
      }
      if (**(int **)(param_1 + 0x24) != 0) {
        (*(code *)&SUB_40094d98)(param_1);
      }
    }
    if (*(int *)(param_1 + 0x14) != 0) {
      (*(code *)&SUB_40094d98)(param_1);
    }
    if (*(int *)(param_1 + 0x24) != 0) {
      (*(code *)&SUB_40094d98)(param_1);
    }
    if (*(int *)(param_1 + 0x38) != 0) {
      (*(code *)&SUB_40094d98)(param_1);
    }
    if (*(int *)(param_1 + 0x3c) != 0) {
      (*(code *)&SUB_40094d98)(param_1);
    }
    if (*(int *)(param_1 + 0x40) != 0) {
      (*(code *)&SUB_40094d98)(param_1);
    }
    if (*(int *)(param_1 + 0xec) != 0) {
      (*(code *)&SUB_40094d98)(param_1);
    }
    if (*(int *)(param_1 + 0xe8) != 0) {
      (*(code *)&SUB_40094d98)(param_1);
    }
    if ((*(int *)(param_1 + 0x48) != 0) && (*(int *)(*(int *)(param_1 + 0x48) + 0x88) != 0)) {
      (*(code *)&SUB_40094d98)(param_1);
    }
    if (*(int *)(param_1 + 0x34) != 0) {
      (*(code *)&SUB_40094d98)(param_1);
    }
    if ((*(int *)(param_1 + 0x18) != 0) &&
       ((**(code **)(param_1 + 0x28))(param_1), *(int *)(param_1 + 0xd8) != 0)) {
      FUN_40174144(param_1);
    }
  }
  return;
}

