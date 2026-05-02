// Function : FUN_400f6b80
// Address  : 0x400f6b80
// Size     : 201 bytes


undefined4 FUN_400f6b80(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  char *pcVar4;
  undefined4 uVar5;
  
  if (param_1 < 3) {
    if (param_3 < 0x80) {
      iVar3 = param_1 * 0x10 + 0x3ffbdc7c;
      piVar2 = (int *)(param_1 * 0x10 + 0x3ffbdc78);
      if (param_2 == 0) {
        (*(code *)&SUB_40092a98)(iVar3,0xffffffff);
        memw();
        memw();
        *(uint *)(*piVar2 + 0xc) = *(uint *)(*piVar2 + 0xc) & 0xfffffffd;
        memw();
        (*(code *)&SUB_40092bec)(iVar3);
        return 0;
      }
      memw();
      *(undefined4 *)(*piVar2 + 0x10) = 2;
      memw();
      (*(code *)&SUB_40092a98)(iVar3,0xffffffff);
      FUN_400fe038(piVar2,param_3);
      memw();
      memw();
      *(uint *)(*piVar2 + 0xc) = *(uint *)(*piVar2 + 0xc) | 2;
      memw();
      (*(code *)&SUB_40092bec)(iVar3);
      return 0;
    }
    uVar1 = (*(code *)&SUB_40094b80)();
    uVar5 = 0x267;
    pcVar4 = " error\n";
    memw();
  }
  else {
    uVar1 = (*(code *)&SUB_40094b80)();
    pcVar4 = "_select";
    uVar5 = 0x266;
  }
  memw();
  FUN_4012113c(1,"th",pcVar4,uVar1,"th","egister",uVar5);
  return 0xffffffff;
}

