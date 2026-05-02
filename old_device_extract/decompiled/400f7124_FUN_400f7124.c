// Function : FUN_400f7124
// Address  : 0x400f7124
// Size     : 303 bytes


undefined4 FUN_400f7124(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  undefined4 uVar5;
  
  if (param_1 < 3) {
    if (param_2 == (undefined4 *)0x0) {
      uVar1 = (*(code *)&SUB_40094b80)();
      uVar5 = 0x2f4;
      pcVar4 = " error\n";
      memw();
    }
    else if ((*(byte *)(param_2 + 5) & 0x80) == 0) {
      if ((uint)param_2[4] < 4) {
        if ((uint)param_2[1] < 4) {
          FUN_400f5ccc(param_1);
          iVar3 = param_1 * 0x10 + 0x3ffbdc7c;
          iVar2 = param_1 * 0x10 + 0x3ffbdc78;
          (*(code *)&SUB_40092a98)(iVar3,0xffffffff);
          FUN_400fe144(iVar2,param_1);
          FUN_400fdee4(iVar2,param_2[6]);
          FUN_400fdf10(iVar2,*param_2);
          (*(code *)&LAB_40184d0e_2)(iVar2,param_2[2]);
          FUN_40184cd8(iVar2,param_2[1]);
          (*(code *)&LAB_40184c4f_1)(iVar2,param_2[3]);
          FUN_400fe010(iVar2,0);
          FUN_400fdfa8(iVar2,param_2[4],*(undefined1 *)(param_2 + 5));
          (*(code *)&SUB_40092bec)(iVar3);
          FUN_400fe324(iVar2);
          FUN_400fe2f0(iVar2);
          return 0;
        }
        uVar1 = (*(code *)&SUB_40094b80)();
        uVar5 = 0x2f7;
        pcVar4 = " error\n";
        memw();
      }
      else {
        uVar1 = (*(code *)&SUB_40094b80)();
        uVar5 = 0x2f6;
        pcVar4 = " error\n";
        memw();
      }
    }
    else {
      uVar1 = (*(code *)&SUB_40094b80)();
      uVar5 = 0x2f5;
      pcVar4 = " error\n";
      memw();
    }
  }
  else {
    uVar1 = (*(code *)&SUB_40094b80)();
    pcVar4 = "_select";
    uVar5 = 0x2f3;
  }
  memw();
  FUN_4012113c(1,"th",pcVar4,uVar1,"th","_config",uVar5);
  return 0xffffffff;
}

