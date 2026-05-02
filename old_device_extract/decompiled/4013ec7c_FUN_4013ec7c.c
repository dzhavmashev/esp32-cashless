// Function : FUN_4013ec7c
// Address  : 0x4013ec7c
// Size     : 41 bytes


void FUN_4013ec7c(int param_1,int param_2)

{
  (*(code *)&SUB_4008b3d0)(param_1,param_2,0x60);
  if (*(int *)(param_2 + 0x5c) == 1) {
    FUN_401436b0(0,param_1 + 8);
    *(undefined4 *)(param_1 + 0x5c) = 2;
  }
  memw();
  return;
}

