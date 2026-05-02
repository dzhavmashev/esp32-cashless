// Function : FUN_400d37d8
// Address  : 0x400d37d8
// Size     : 154 bytes


void FUN_400d37d8(int param_1)

{
  FUN_400f0780(0x3ffc5490,"ivation");
  FUN_400d36e0(param_1,0);
  *(undefined2 *)(param_1 + 0x18) = 0;
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
  if (*(code **)(param_1 + 0x48) != (code *)0x0) {
    (**(code **)(param_1 + 0x48))(param_1 + 0x40,param_1 + 0x40,3);
    *(undefined4 *)(param_1 + 0x48) = 0;
    *(undefined4 *)(param_1 + 0x4c) = 0;
  }
  if (*(code **)(param_1 + 0x58) != (code *)0x0) {
    (**(code **)(param_1 + 0x58))(param_1 + 0x50,param_1 + 0x50,3);
    *(undefined4 *)(param_1 + 0x58) = 0;
    *(undefined4 *)(param_1 + 0x5c) = 0;
  }
  FUN_400f0d70(param_1 + 4,&DAT_3f42161d);
  *(undefined4 *)(param_1 + 0x14) = 0;
  FUN_400f0780(0x3ffc5490,"sources");
  return;
}

