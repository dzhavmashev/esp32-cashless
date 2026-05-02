// Function : FUN_40103558
// Address  : 0x40103558
// Size     : 52 bytes


void FUN_40103558(int param_1,undefined4 param_2,int param_3)

{
  FUN_40103538(10);
  (**(code **)(param_1 + 0x308))();
  *(undefined1 *)(param_1 + 0x347) = 0;
  memw();
  *(undefined4 *)(param_1 + 0x2f0) = 0;
  if (param_3 != 0) {
    memw();
    FUN_401850b4(param_1,param_2,3,1);
  }
  return;
}

