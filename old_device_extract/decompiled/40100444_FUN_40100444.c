// Function : FUN_40100444
// Address  : 0x40100444
// Size     : 286 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40100444(undefined4 param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  char *pcVar5;
  int iStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined1 auStack_44 [12];
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined1 uStack_24;
  
  FUN_40101634(param_1);
  uVar1 = (*(code *)&LAB_40184eea_2)(param_1);
  if ((uVar1 & 1) == 0) {
    return;
  }
  iVar2 = FUN_40184e98(param_1,&iStack_54);
  if (iVar2 == 0) {
    if (iStack_54 == 0) {
      FUN_401015c4(param_1);
      return;
    }
    if (iStack_54 != 2) {
      return;
    }
    FUN_4010173c(param_1,&uStack_50);
    FUN_40101710(param_1,auStack_44);
    iVar2 = (*(code *)&LAB_40184ed2_2)(&uStack_50);
    if (iVar2 == 0) {
      uVar3 = (*(code *)&SUB_40094b80)();
      FUN_4012113c(1,"H_EVENT","nnected",uVar3,"H_EVENT");
      return;
    }
    (*(code *)&SUB_4008b530)(&uStack_30,0,0x10);
    uStack_38 = 0xffffffff;
    memw();
    uStack_34 = param_1;
    iVar2 = (*(code *)&SUB_4008b33c)(&uStack_50,auStack_44,0xc);
    if (iVar2 != 0) {
      uStack_24 = 1;
      memw();
    }
    uStack_30 = uStack_50;
    uStack_2c = uStack_4c;
    uStack_28 = uStack_48;
    memw();
    FUN_40101988(param_1,&uStack_50);
    uVar3 = _DAT_3ffbde84;
    uVar4 = FUN_40184efc(param_1,1);
    iVar2 = FUN_401019d4(uVar3,uVar4,&uStack_38,0x18,0);
    if (iVar2 == 0) {
      return;
    }
    uVar3 = (*(code *)&SUB_40094b80)();
    pcVar5 = " failed";
    uVar4 = 0x52;
    memw();
  }
  else {
    uVar3 = (*(code *)&SUB_40094b80)();
    pcVar5 = "t=0x%X\n";
    uVar4 = 0x37;
  }
  memw();
  FUN_4012113c(1,"H_EVENT","andlers",uVar3,"H_EVENT","tic ip\n",uVar4,pcVar5,iVar2);
  return;
}

