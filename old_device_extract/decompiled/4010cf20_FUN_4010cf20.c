// Function : FUN_4010cf20
// Address  : 0x4010cf20
// Size     : 46 bytes


void FUN_4010cf20(int param_1,undefined4 param_2,undefined1 param_3)

{
  if (param_1 != 0) {
    if (*(int *)(param_1 + 0x3c) == 1) {
      (*(code *)&SUB_40094c54)(" LISTEN",0x89f,"_remove","allback");
    }
    *(undefined4 *)(param_1 + 0xb8) = param_2;
    *(undefined1 *)(param_1 + 0x49) = param_3;
    memw();
  }
  memw();
  return;
}

