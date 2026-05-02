// Function : FUN_400f7dc4
// Address  : 0x400f7dc4
// Size     : 133 bytes


undefined4 FUN_400f7dc4(int param_1,uint param_2)

{
  undefined4 uVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  char *pcVar5;
  char *pcVar6;
  
  pcVar3 = (char *)(param_2 & 0xff);
  if (param_1 < 3) {
    iVar4 = param_1 * 0x10 + 0x3ffbdc78;
    pcVar6 = (char *)FUN_400fe2c8(iVar4);
    if (pcVar3 <= pcVar6) {
      iVar2 = param_1 * 0x10 + 0x3ffbdc7c;
      (*(code *)&SUB_40092a98)(iVar2,0xffffffff);
      FUN_400fe260(iVar4,pcVar3);
      (*(code *)&SUB_40092bec)(iVar2);
      return 0;
    }
    uVar1 = (*(code *)&SUB_40094b80)();
    pcVar5 = " first\n";
    memw();
  }
  else {
    uVar1 = (*(code *)&SUB_40094b80)();
    pcVar3 = "e = %d\n";
    pcVar5 = "_select";
    pcVar6 = (char *)0x6d3;
  }
  memw();
  FUN_4012113c(1,"th",pcVar5,uVar1,"th",pcVar3,pcVar6);
  return 0x102;
}

