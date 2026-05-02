// Function : FUN_4013ec50
// Address  : 0x4013ec50
// Size     : 40 bytes


void FUN_4013ec50(undefined1 *param_1)

{
  undefined1 *puVar1;
  
  if (param_1 != (undefined1 *)0x0) {
    if (*(int *)(param_1 + 0x5c) == 1) {
      FUN_40143664(0);
    }
    puVar1 = param_1 + 0x60;
    while (param_1 != puVar1) {
      memw();
      *param_1 = 0;
      param_1 = param_1 + 1;
      memw();
    }
  }
  return;
}

