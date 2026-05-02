// Function : FUN_401409dc
// Address  : 0x401409dc
// Size     : 41 bytes


void FUN_401409dc(int param_1,int param_2)

{
  (*(code *)&SUB_4008b3d0)(param_1,param_2,0xd8);
  if (*(int *)(param_2 + 0xd4) == 1) {
    FUN_401436b0(3,param_1 + 0x10);
    *(undefined4 *)(param_1 + 0xd4) = 2;
  }
  memw();
  return;
}

