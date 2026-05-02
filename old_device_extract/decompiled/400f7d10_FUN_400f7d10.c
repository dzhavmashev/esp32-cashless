// Function : FUN_400f7d10
// Address  : 0x400f7d10
// Size     : 176 bytes


undefined4 FUN_400f7d10(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  char *pcVar4;
  undefined4 uVar5;
  
  if (param_1 < 3) {
    if (param_2 - 1U < 0x7e) {
      if (*(int *)(param_1 * 4 + 0x3ffc5588) == 0) {
        uVar1 = (*(code *)&SUB_40094b80)();
        FUN_4012113c(1,"th"," error\n",uVar1,"th");
        return 0x103;
      }
      iVar2 = param_1 * 0x10 + 0x3ffbdc7c;
      (*(code *)&SUB_40092a98)(iVar2,0xffffffff);
      piVar3 = (int *)(param_1 * 0x10 + 0x3ffbdc78);
      memw();
      if ((*(uint *)(*piVar3 + 0xc) & 1) != 0) {
        FUN_40184d70(piVar3,param_2);
      }
      (*(code *)&SUB_40092bec)(iVar2);
      return 0;
    }
    uVar1 = (*(code *)&SUB_40094b80)();
    uVar5 = 0x6b3;
    pcVar4 = &DAT_3f40c1d0;
    memw();
  }
  else {
    uVar1 = (*(code *)&SUB_40094b80)();
    pcVar4 = "_select";
    uVar5 = 0x6b1;
  }
  memw();
  FUN_4012113c(1,"th",pcVar4,uVar1,"th","timeout",uVar5);
  return 0x102;
}

