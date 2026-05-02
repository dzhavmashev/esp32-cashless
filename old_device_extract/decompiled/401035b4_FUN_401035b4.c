// Function : FUN_401035b4
// Address  : 0x401035b4
// Size     : 49 bytes


void FUN_401035b4(int param_1)

{
  if (param_1 != 0) {
    if (*(int *)(param_1 + 0x1c0) == 0) {
      *(undefined4 *)(param_1 + 0x40) = 0x40;
      memw();
      (*(code *)&SUB_4008b530)(param_1);
    }
    else {
      *(undefined4 *)(param_1 + 0x40) = *(undefined4 *)(*(int *)(param_1 + 0x1c0) + 0x54);
      memw();
      (*(code *)&SUB_4008b3d0)();
    }
  }
  return;
}

