// Function : FUN_400f76b4
// Address  : 0x400f76b4
// Size     : 130 bytes


undefined4 FUN_400f76b4(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  char *pcVar4;
  undefined4 uVar5;
  
  if (param_1 < 3) {
    piVar3 = (int *)(param_1 * 4 + 0x3ffc5588);
    if (*piVar3 != 0) {
      iVar2 = param_1 * 0x10 + 0x3ffbdc7c;
      (*(code *)&SUB_40092a98)(iVar2,0xffffffff);
      *param_2 = *(undefined4 *)(*piVar3 + 0x14);
      memw();
      (*(code *)&SUB_40092bec)(iVar2);
      return 0;
    }
    uVar1 = (*(code *)&SUB_40094b80)();
    uVar5 = 0x54f;
    pcVar4 = " error\n";
    memw();
  }
  else {
    uVar1 = (*(code *)&SUB_40094b80)();
    pcVar4 = "_select";
    uVar5 = 0x54e;
  }
  memw();
  FUN_4012113c(1,"th",pcVar4,uVar1,"th","ee_size",uVar5);
  return 0xffffffff;
}

