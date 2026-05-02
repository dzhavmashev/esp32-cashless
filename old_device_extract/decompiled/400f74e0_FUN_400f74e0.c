// Function : FUN_400f74e0
// Address  : 0x400f74e0
// Size     : 146 bytes


undefined4 FUN_400f74e0(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  char *pcVar2;
  undefined4 uVar3;
  
  if (param_1 < 3) {
    if (*(int *)(param_1 * 4 + 0x3ffc5588) == 0) {
      uVar1 = (*(code *)&SUB_40094b80)();
      uVar3 = 0x502;
      pcVar2 = " error\n";
      memw();
    }
    else {
      if (param_2 != 0) {
        if (param_3 == 0) {
          return 0;
        }
        uVar1 = FUN_400f6c4c(param_1,param_2,param_3,0,0);
        return uVar1;
      }
      uVar1 = (*(code *)&SUB_40094b80)();
      uVar3 = 0x503;
      pcVar2 = "/uart.c";
      memw();
    }
  }
  else {
    uVar1 = (*(code *)&SUB_40094b80)();
    pcVar2 = "_select";
    uVar3 = 0x501;
  }
  memw();
  FUN_4012113c(1,"th",pcVar2,uVar1,"th","d_bytes",uVar3);
  return 0xffffffff;
}

