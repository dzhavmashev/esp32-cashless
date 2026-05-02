// Function : FUN_4012357c
// Address  : 0x4012357c
// Size     : 245 bytes


int FUN_4012357c(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  char *pcVar4;
  undefined4 uStack_2c;
  undefined1 auStack_26 [38];
  
  iVar1 = FUN_400f9524("_update",1,&uStack_2c);
  uVar2 = uStack_2c;
  if (iVar1 != 0) {
    return iVar1;
  }
  iVar1 = FUN_400f97b4(uStack_2c,"x:%02x\n",param_1,0x770);
  if (iVar1 == 0) {
    iVar1 = FUN_4011ecfc(auStack_26);
    if (iVar1 != 0) {
      (*(code *)&SUB_4008effc)(iVar1,"ta_mac)",0x281,"nd_init","cal_mac");
    }
    iVar1 = FUN_400f97b4(uVar2,"version",auStack_26,6);
    if (iVar1 == 0) {
      uVar3 = FUN_4016b0ac();
      iVar1 = FUN_400f96f0(uVar2,"Fi/BT.\n",uVar3 & 0xfffeffff);
      if (iVar1 == 0) {
        iVar1 = FUN_400f9738(uVar2);
        if (iVar1 == 0) goto LAB_401235c2;
        uVar2 = (*(code *)&SUB_40094b80)();
        pcVar4 = "0x%x)\n\n";
        memw();
      }
      else {
        uVar2 = (*(code *)&SUB_40094b80)();
        pcVar4 = "0x%x)\n\n";
        memw();
      }
    }
    else {
      uVar2 = (*(code *)&SUB_40094b80)();
      pcVar4 = "0x%x)\n\n";
      memw();
    }
  }
  else {
    uVar2 = (*(code *)&SUB_40094b80)();
    pcVar4 = "(0x%x)\n";
  }
  memw();
  FUN_4012113c(1,"ate",pcVar4,uVar2,"ate","nd_init",iVar1);
LAB_401235c2:
  FUN_400f9a40(uStack_2c);
  return iVar1;
}

