// Function : FUN_400f7254
// Address  : 0x400f7254
// Size     : 201 bytes


undefined4 FUN_400f7254(int param_1,uint *param_2)

{
  undefined4 uVar1;
  int *piVar2;
  undefined1 uVar3;
  char *pcVar4;
  undefined4 uVar5;
  
  if (param_1 < 3) {
    if (param_2 != (uint *)0x0) {
      param_1 = param_1 * 0x10;
      piVar2 = (int *)(param_1 + 0x3ffbdc78);
      memw();
      *(undefined4 *)(*piVar2 + 0x10) = 0x7ffff;
      memw();
      (*(code *)&SUB_40092a98)(param_1 + 0x3ffbdc7c,0xffffffff);
      uVar3 = 0;
      if ((*param_2 & 0x100) != 0) {
        uVar3 = (undefined1)param_2[1];
      }
      FUN_400fe260(piVar2,uVar3);
      if ((*param_2 & 1) != 0) {
        FUN_40184d70(piVar2,*(undefined1 *)((int)param_2 + 6));
      }
      if ((*param_2 & 2) != 0) {
        FUN_400fe038(piVar2,*(undefined1 *)((int)param_2 + 5));
      }
      memw();
      memw();
      *(uint *)(*(int *)(param_1 + 0x3ffbdc78) + 0xc) =
           *(uint *)(*(int *)(param_1 + 0x3ffbdc78) + 0xc) | *param_2;
      memw();
      (*(code *)&SUB_40092bec)(param_1 + 0x3ffbdc7c);
      return 0;
    }
    uVar1 = (*(code *)&SUB_40094b80)();
    uVar5 = 0x310;
    pcVar4 = " error\n";
    memw();
  }
  else {
    uVar1 = (*(code *)&SUB_40094b80)();
    pcVar4 = "_select";
    uVar5 = 0x30f;
  }
  memw();
  FUN_4012113c(1,"th",pcVar4,uVar1,"th","tx_done",uVar5);
  return 0xffffffff;
}

