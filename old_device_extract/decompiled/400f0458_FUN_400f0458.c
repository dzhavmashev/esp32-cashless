// Function : FUN_400f0458
// Address  : 0x400f0458
// Size     : 92 bytes


void FUN_400f0458(int param_1)

{
  uint uVar1;
  
  if (*(code **)(param_1 + 0x28) != (code *)0x0) {
    (**(code **)(param_1 + 0x28))(param_1 + 0x20,param_1 + 0x20,3);
    *(undefined4 *)(param_1 + 0x28) = 0;
    *(undefined4 *)(param_1 + 0x2c) = 0;
  }
  if (*(code **)(param_1 + 0x38) != (code *)0x0) {
    (**(code **)(param_1 + 0x38))(param_1 + 0x30,param_1 + 0x30,3);
    *(undefined4 *)(param_1 + 0x38) = 0;
    *(undefined4 *)(param_1 + 0x3c) = 0;
  }
  uVar1 = FUN_400f2204();
  if (*(byte *)(param_1 + 0x10) == uVar1) {
    FUN_400f21e8(0);
  }
  *(undefined1 *)(param_1 + 0x42) = 0;
  FUN_400f2888(*(undefined1 *)(param_1 + 0x10));
  FUN_400f0198(param_1);
  *(undefined4 *)(param_1 + 0x14) = 0;
  return;
}

