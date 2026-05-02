// Function : FUN_4012d108
// Address  : 0x4012d108
// Size     : 101 bytes


void FUN_4012d108(int param_1)

{
  int iVar1;
  
  FUN_40131548(param_1 + 0xb4);
  FUN_40131548(param_1 + 0xc0);
  if (*(int *)(param_1 + 0xcc) != 0) {
    FUN_4013ae54(*(int *)(param_1 + 0xcc),*(undefined4 *)(param_1 + 0xd0));
    FUN_4013ae44(*(undefined4 *)(param_1 + 0xcc));
    *(undefined4 *)(param_1 + 0xcc) = 0;
    *(undefined4 *)(param_1 + 0xd0) = 0;
  }
  if (*(int *)(param_1 + 0xd4) != 0) {
    memw();
    FUN_4013ae54(*(int *)(param_1 + 0xd4),*(undefined4 *)(param_1 + 0xd8));
    FUN_4013ae44(*(undefined4 *)(param_1 + 0xd4));
    *(undefined4 *)(param_1 + 0xd4) = 0;
    *(undefined4 *)(param_1 + 0xd8) = 0;
  }
  iVar1 = *(int *)(param_1 + 0xa0);
  while (iVar1 != 0) {
    iVar1 = *(int *)(iVar1 + 8);
    FUN_4013ae44();
  }
  memw();
  FUN_4013ae54(param_1,0xe8);
  return;
}

