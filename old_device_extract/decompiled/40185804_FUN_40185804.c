// Function : FUN_40185804
// Address  : 0x40185804
// Size     : 22 bytes


void FUN_40185804(int param_1,uint param_2)

{
  if (*(code **)(param_1 + 0x5c) != (code *)0x0) {
    (**(code **)(param_1 + 0x5c))(*(undefined4 *)(param_1 + 0x58),param_2 >> 2,param_2);
  }
  return;
}

