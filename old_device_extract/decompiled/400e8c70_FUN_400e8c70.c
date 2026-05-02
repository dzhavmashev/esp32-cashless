// Function : FUN_400e8c70
// Address  : 0x400e8c70
// Size     : 34 bytes


void FUN_400e8c70(int param_1,int param_2)

{
  *(undefined4 *)(param_1 + 8) = 0;
  if (*(code **)(param_2 + 8) != (code *)0x0) {
    (**(code **)(param_2 + 8))(param_1,param_2,2);
    *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(param_2 + 0xc);
    *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_2 + 8);
  }
  return;
}

