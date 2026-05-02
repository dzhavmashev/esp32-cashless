// Function : FUN_400f6794
// Address  : 0x400f6794
// Size     : 121 bytes


undefined4 FUN_400f6794(int param_1,uint param_2)

{
  undefined4 uVar1;
  int iVar2;
  char *pcVar3;
  undefined4 uVar4;
  
  if (param_1 < 3) {
    if (param_2 < 4) {
      iVar2 = param_1 * 0x10 + 0x3ffbdc7c;
      (*(code *)&SUB_40092a98)(iVar2,0xffffffff);
      (*(code *)&LAB_40184c4f_1)(param_1 * 0x10 + 0x3ffbdc78,param_2);
      (*(code *)&SUB_40092bec)(iVar2);
      return 0;
    }
    uVar1 = (*(code *)&SUB_40094b80)();
    uVar4 = 0x106;
    pcVar3 = " error\n";
    memw();
  }
  else {
    uVar1 = (*(code *)&SUB_40094b80)();
    pcVar3 = "_select";
    uVar4 = 0x105;
  }
  memw();
  FUN_4012113c(1,"th",pcVar3,uVar1,"th","op_bits",uVar4);
  return 0xffffffff;
}

