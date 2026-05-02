// Function : FUN_4013f7c4
// Address  : 0x4013f7c4
// Size     : 37 bytes


void FUN_4013f7c4(int param_1,int param_2)

{
  (*(code *)&SUB_4008b3d0)(param_1,param_2,0x70);
  if (*(int *)(param_2 + 0x6c) == 1) {
    FUN_401436b0(1,param_1 + 8);
    *(undefined4 *)(param_1 + 0x6c) = 2;
  }
  memw();
  return;
}

