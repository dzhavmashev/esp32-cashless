// Function : FUN_4012cf14
// Address  : 0x4012cf14
// Size     : 176 bytes


void FUN_4012cf14(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_1 != 0) {
    if (*(int *)(param_1 + 0xb8) != 0) {
      FUN_4013ae54(*(int *)(param_1 + 0xb8),0x414d);
      FUN_4013ae44(*(undefined4 *)(param_1 + 0xb8));
      *(undefined4 *)(param_1 + 0xb8) = 0;
    }
    if (*(int *)(param_1 + 100) != 0) {
      memw();
      FUN_4013ae54(*(int *)(param_1 + 100),0x414d);
      FUN_4013ae44(*(undefined4 *)(param_1 + 100));
      *(undefined4 *)(param_1 + 100) = 0;
    }
    if (*(int *)(param_1 + 0x50) != 0) {
      memw();
      FUN_40129d74();
      FUN_4013ae44(*(undefined4 *)(param_1 + 0x50));
    }
    if (*(int *)(param_1 + 0x44) != 0) {
      FUN_4012ca14(param_1);
      FUN_40129d74(*(undefined4 *)(param_1 + 0x54));
      FUN_4012cacc(*(undefined4 *)(param_1 + 0x40));
      FUN_4013ae44(*(undefined4 *)(param_1 + 0x44));
      FUN_4013ae44(*(undefined4 *)(param_1 + 0x54));
      FUN_4013ae44(*(undefined4 *)(param_1 + 0x40));
    }
    if (*(int *)(param_1 + 0x3c) != 0) {
      FUN_4012cacc();
      FUN_4013ae44(*(undefined4 *)(param_1 + 0x3c));
    }
    iVar2 = *(int *)(param_1 + 0xec);
    if (iVar2 != 0) {
      uVar1 = (*(code *)&SUB_4008c01c)(iVar2);
      FUN_4013ae54(iVar2,uVar1);
      FUN_4013ae44(*(undefined4 *)(param_1 + 0xec));
    }
    FUN_4013ae44(*(undefined4 *)(param_1 + 0x1f8));
    FUN_4013ae54(param_1,0x220);
  }
  return;
}

