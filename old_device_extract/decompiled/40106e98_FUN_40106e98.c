// Function : FUN_40106e98
// Address  : 0x40106e98
// Size     : 162 bytes


void FUN_40106e98(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  char *pcVar4;
  undefined1 auStack_26 [38];
  
  uVar1 = FUN_40184e30(param_1);
  iVar2 = FUN_4010733c(uVar1,auStack_26);
  if (iVar2 == 0) {
    iVar2 = FUN_4018525c(uVar1);
    if ((iVar2 != 0) && (iVar2 = FUN_40107350(uVar1,0x40184e64,param_1), iVar2 != 0)) {
      uVar3 = (*(code *)&SUB_40094b80)();
      memw();
      FUN_4012113c(1,"I_EVENT","ith %d\n",uVar3,"I_EVENT",uVar1,iVar2);
      return;
    }
    iVar2 = FUN_40147560(0x40101590,0x4010159c);
    if (iVar2 == 0) {
      FUN_40101550(param_1,auStack_26);
      FUN_4010042c(param_1,param_2,param_3,param_4);
      return;
    }
    uVar1 = (*(code *)&SUB_40094b80)();
    pcVar4 = "ith %d\n";
  }
  else {
    uVar1 = (*(code *)&SUB_40094b80)();
    pcVar4 = "default";
  }
  FUN_4012113c(1,"I_EVENT",pcVar4,uVar1,"I_EVENT",iVar2);
  return;
}

