// Function : FUN_400f7738
// Address  : 0x400f7738
// Size     : 141 bytes


undefined4 FUN_400f7738(int param_1,int *param_2)

{
  undefined4 uVar1;
  int iVar2;
  char *pcVar3;
  undefined4 uVar4;
  
  if (param_1 < 3) {
    iVar2 = *(int *)(param_1 * 4 + 0x3ffc5588);
    if (iVar2 == 0) {
      uVar1 = (*(code *)&SUB_40094b80)();
      uVar4 = 0x559;
      pcVar3 = " error\n";
      memw();
    }
    else {
      if (param_2 != (int *)0x0) {
        *param_2 = *(int *)(iVar2 + 0xb4) - *(int *)(iVar2 + 0xc4);
        memw();
        return 0;
      }
      uVar1 = (*(code *)&SUB_40094b80)();
      uVar4 = 0x55a;
      pcVar3 = " error\n";
      memw();
    }
  }
  else {
    uVar1 = (*(code *)&SUB_40094b80)();
    pcVar3 = "_select";
    uVar4 = 0x558;
  }
  memw();
  FUN_4012113c(1,"th",pcVar3,uVar1,"th","h_input",uVar4);
  return 0x102;
}

