// Function : FUN_401409a0
// Address  : 0x401409a0
// Size     : 56 bytes


void FUN_401409a0(undefined1 *param_1)

{
  undefined4 uVar1;
  undefined1 *puVar2;
  
  if (param_1 != (undefined1 *)0x0) {
    if (*(int *)(param_1 + 0xd4) == 1) {
      uVar1 = 3;
      if (*(int *)(param_1 + 0xd0) != 0) {
        uVar1 = 2;
      }
      FUN_40143664(uVar1);
    }
    puVar2 = param_1 + 0xd8;
    while (param_1 != puVar2) {
      memw();
      *param_1 = 0;
      param_1 = param_1 + 1;
      memw();
    }
  }
  return;
}

